#include <vector>
#include <unordered_map>
#include <cmath>
#include <stack>



class Tree {
public:
    int num_of_node;
    std::vector<std::vector<int>> tree;
    std::vector<std::vector<int>> children;

private:
    int log_v = 0;
    std::vector<std::vector<int>> parent;            // 2^k個上の親
    std::vector<std::vector<long long>> max_weight;  // 2^k個上の親までにでてくる最大の重み
    std::vector<int> depth;                          // 各頂点についての根からの深さ
    std::vector<long long> distance_from_root;       // 根からの距離
    std::vector<long long> weight_node;
    std::vector<std::unordered_map<int, long long>> weight_edge;

public:
    Tree(int n) : num_of_node(n) {
        this->log_v = int(log2(n)) + 1;
        this->tree.resize(n);
        this->children.resize(n);
        this->parent.resize(log_v, std::vector<int>(n));
        this->max_weight.resize(log_v, std::vector<long long>(n));
        this->depth.resize(n);
        this->distance_from_root.resize(n);
        this->weight_node.resize(n);
        this->weight_edge.resize(n);
    }

    // u <-> v
    void add_undirected_edge(const int u, const int v, const long long w=1) {
        this->tree[u].emplace_back(v);
        this->tree[v].emplace_back(u);
        this->weight_edge[u][v] = this->weight_edge[v][u] = w;
    }

    // u -> v
    void add_directed_edge(const int u, const int v, const long long w=1) {
        this->tree[u].emplace_back(v);
        this->weight_edge[u][v] = w;
    }

    void build1(const int root) {
        this->dfs(root, -1, 0, 0);
    }

    void build2(const int root) {

        this->distance_from_root[root] = 0;
        if (num_of_node == 0) {
            return ;
        }

        for (int k = 0; k + 1 < this->log_v; k++) {
            for (int u = 0; u < this->num_of_node; ++u) {
                if (this->parent[k][u] < 0) {
                    this->parent[k + 1][u] = -1;
                }
                else {
                    this->parent[k + 1][u] = this->parent[k][this->parent[k][u]]; // uの2^k個上のノードの2^k上のノードはuの2^(k+1)個上のノード
                    if (this->parent[k + 1][u] >= 0) {
                        this->max_weight[k + 1][u] = std::max(this->max_weight[k][u], this->max_weight[k][this->parent[k][u]]);
                    }
                }
            }
        }
    }

    // uとvの距離 O(log N)
    long long distance(const int u, const int v) const {
        return this->distance_from_root[u] + this->distance_from_root[v] - 2 * this->distance_from_root[this->lca(u, v)];
    }

    // 木の直径のうちのひとつのペア O(N log N)
    // 距離は辺の長さを考慮している点に注意
    std::tuple<int, int, long long> diameter() const {
        // node 0から一番遠いnode
        int u = 0;
        long long max_distance = -1;
        for (int node = 0; node < this->num_of_node; ++node) {
            auto dist = this->distance(0, node);
            if (dist > max_distance) {
                max_distance = dist;
                u = node;
            }
        }

        // node uから一番遠いnode
        int v = 0;
        long long diameter = 0;
        for (int node = 0; node < this->num_of_node; ++node) {
            auto dist = this->distance(u, node);
            if (dist > diameter) {
                diameter = dist;
                v = node;
            }
        }

        return std::make_tuple(u, v, diameter);
    }

    // fromからtoへいくルートを取得 O(N + M)
    std::vector<int> route(const int from, const int to) const {

        // get from -> to path
        std::unordered_map<int, int> prev;
        std::stack<int> nodes;
        nodes.push(to);
        while (not nodes.empty()) {
            const auto u = nodes.top(); nodes.pop();
            if (u == from) {
                break;
            }

            for (const auto v : this->tree[u]) {
                if (prev.find(v) == prev.end()) {
                    prev[v] = u;
                    nodes.push(v);
                }
            }
        }

        std::vector<int> route = {from};
        int now = from;
        while (prev[now] != to) {
            now = prev[now];
            route.emplace_back(now);
        }
        route.emplace_back(to);

        return route;
    }

    // 木の中心のノード
    int center() const {
        int u, v;
        long long d;
        std::tie(u, v, d) = this->diameter();
        std::vector<int> r = this->route(u, v);
        return r[r.size() / 2];
    }

    // uとvの間で出現する最大の重み
    long long maximum_weight(int u, int v) const {
        int lca = this->lca(u, v);
        return std::max(this->maximum_weight_ancestor(u, lca), this->maximum_weight_ancestor(v, lca));
    }

    // uとvの最近共通祖先のノード
    // O(log N)
    int lca(int u, int v) const {
        if (this->depth[u] > this->depth[v]) {
            std::swap(u, v);
        }
        for (int k = 0; k < this->log_v; ++k) {
            if ((this->depth[v] - this->depth[u]) >> k & 1u) {
                v = parent[k][v];
            }
        }

        if (u == v) {
            return u;
        }

        for (int k = this->log_v - 1; k >= 0; --k) {
            if (this->parent[k][u] != this->parent[k][v]) {
                u = this->parent[k][u];
                v = this->parent[k][v];
            }
        }
        return this->parent[0][u];
    }

    // 各ノードの子供の総数を取得 O(N + M)
    // num_children_dfs(root, num_children, tree)
    long long num_children_dfs(int u, std::vector<long long> &num_children) {
        long long total = 0;
        for (auto v : this->children[u]) {
            total += num_children_dfs(v, num_children) + 1;
        }

        return num_children[u] = total;
    }

    // 自分を含めた部分木の重みの合計を取得 O(N + M)
    // total_weight_dfs(root, children_total_weight, tree)
    long long total_weight_dfs(int u, std::vector<long long> &children_total_weight) {
        long long total = this->weight_node[u];
        for (auto v : this->children[u]) {
            total += total_weight_dfs(v, children_total_weight);
        }

        return children_total_weight[u] = total;
        //return children_total_weight[u] = max(0LL, total);
    }

private:
    // 各頂点について，1つ上の親，1つ上の重み，根からの深さ，根からの距離を求める
    void dfs(int u, int p, int d, long long w) {
        this->parent[0][u] = p;
        this->max_weight[0][u] = w;
        this->depth[u] = d;

        for (const auto v : this->tree[u]) {
            if (v != p) {
                const long long dist = this->weight_edge[u][v];
                this->distance_from_root[v] = this->distance_from_root[u] + this->weight_edge[u][v];
                this->children[u].emplace_back(v);
                dfs(v, u, d + 1, dist);
            }
        }
    }

    // uとuの祖先の間の最大の重みを取得
    long long maximum_weight_ancestor(int u, int ancestor) const {
        long long res = -10000000000;
        int d = this->depth[u] - this->depth[ancestor];
        for (int k = 0; k < this->log_v; k ++) {
            if ((d >> k) & 1) {
                res = std::max(res, this->max_weight[k][u]);
                u = this->parent[k][u];
            }
        }
        return res;
    }
};