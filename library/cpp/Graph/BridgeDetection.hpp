#include <vector>
#include <set>


// グラフの橋(削除するとグラフの連結成分の数が増える辺)を検出する．
class BridgeDetection {
    int N;
    std::vector<std::vector<int>> graph;
    std::vector<int> state;
    std::vector<int> val;
    std::vector<int> color;

public:
    std::set<std::pair<int, int>> bridge_set;

    BridgeDetection(int n) : N(n) {
        this->graph.resize(N);
        this->state.resize(N);
        this->val.resize(N);
        this->color.resize(N);
        for (int u = 0; u < this->N; ++u) {
            color[u] = -1;
        }
    }

    // 非連結，自己ループ，多重辺も可
    void add_undirected_edge(int u, int v) {
        this->graph[u].emplace_back(v);
        this->graph[v].emplace_back(u);
    }

    // O(|V| + |E|)
    void build() {
        // 連結成分ごとに同じ色を塗る
        int c = 0;
        for (int u = 0; u < this->N; ++u) {
            if (color[u] == -1) {
                dfs2(u, c);
                c++;
            }
        }

        std::vector<bool> used_color(c);

        for (int u = 0; u < this->N; ++u) {
            if (not used_color[color[u]]) {
                this->dfs(u, -1);
                used_color[color[u]] = true;
            }
        }
    }

private:
    int dfs(const int u, const int pre) {
        int res = 0;
        int count = 0;
        this->state[u] = 1; // searching
        for (int v : this->graph[u]) {
            if (v == u) {
                continue;
            }
            if (v == pre) {
                if (count > 0) {
                    // (pre, u): multiple edges
                    res += 1;
                    this->val[v] += 1;
                }
                ++count;
                continue;
            }
            if (not this->state[v]) {
                res += dfs(v, u);
            } else if (this->state[v] == 1) {
                res += 1;
                this->val[v] += 1;
            }
        }
        this->state[u] = 2; // searched
        res -= this->val[u];

        if (pre != -1 and res == 0) {
            if (pre < u) {
                this->bridge_set.insert(std::make_pair(pre, u));
            }
            else {
                this->bridge_set.insert(std::make_pair(u, pre));
            }
        }

        return res;
    }

    void dfs2(int u, int c) {
        this->color[u] = c;
        for (int v : this->graph[u]) {
            if (this->color[v] == -1) {
                dfs2(v, c);
            }
        }
    }
};