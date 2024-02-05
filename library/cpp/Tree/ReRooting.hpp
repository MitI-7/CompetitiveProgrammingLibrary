#include <cassert>
#include <functional>
#include <stack>
#include <vector>

template<typename W>
class Edge {
public:
    int to;
    W w;
    int rev;
    int no;

    Edge() : to(-1), w(-1), rev(-1), no(-1) {}

    Edge(int to, W w, int rev, int no = -1) : to(to), w(w), rev(rev), no(no) {
    }
};

// モノイドを乗せることができる
// 結合則: a * (b * c) = (a * b) * c
// 単位元: e * a = a * e = a
template<class T, typename W, T (*marge)(T, T), T (*add_node)(T, int), T (*add_edge)(T, Edge<W>), T (*unit)()>
class ReRooting {
public:
    const int num_nodes;

private:
    std::vector<std::vector<Edge<W>>> graph;

    std::vector<std::vector<T>> dp; // dp[u][i] = 頂点 u の i 番目の子供を部分木の根とした答え
    std::vector<T> ans;

    bool initialized;
public:
    explicit ReRooting(const int num_nodes) : num_nodes(num_nodes), graph(num_nodes), dp(num_nodes), ans(num_nodes), initialized(false) {

    }

    void add_undirected_edge(const int u, const int v, const W w = 1) {
        assert(not this->initialized);
        assert(u != v);
        const int rev_u = this->graph[v].size();
        const int rev_v = this->graph[u].size();
        this->graph[u].emplace_back(Edge(v, w, rev_u));
        this->graph[v].emplace_back(Edge(u, w, rev_v));
    }

    T query(const int u) const {
        assert(this->initialized);
        assert(0 <= u and u < this->num_nodes);
        return this->ans[u];
    }

    void build() {
        this->initialized = true;

        for (int i = 0; i < (int) this->graph.size(); i++) {
            this->dp[i].resize(this->graph[i].size());
        }

        // 頂点が 1 個しなかない
        if (this->num_nodes == 1) {
            this->ans[0] = add_node(unit(), 0);
            return;
        }

        std::vector<int> parents(num_nodes);
        std::vector<int> order;

        // 頂点 0 を根とした dfs 順と各ノードの親を求める
        {
            std::stack<int> stack;
            stack.push(0);
            parents[0] = -1;
            while (not stack.empty()) {
                const auto u = stack.top();
                stack.pop();
                order.emplace_back(u);
                for (const auto e: this->graph[u]) {
                    if (e.to == parents[u]) {
                        continue;
                    }
                    stack.push(e.to);
                    parents[e.to] = u;
                }
            }
        }

        // 葉から根へ部分木の値を求めていく
        for (int i = (int) order.size() - 1; i >= 1; --i) {
            const auto u = order[i];
            const auto parent = parents[u];

            // u の子供達の結果をまとめる
            T accum = unit();
            int rev = -1;
            for (int j = 0; j < (int) this->graph[u].size(); ++j) {
                const auto &edge = this->graph[u][j];
                if (edge.to == parent) {
                    rev = edge.rev;
                    continue;
                }
                accum = marge(accum, add_edge(this->dp[u][j], edge));
            }
            assert(rev != -1);

            // u を部分木の根としたときの答えを求める
            this->dp[parent][rev] = add_node(accum, u);
            assert(this->graph[parent][rev].to == u);
        }

        // u を木の根としたときの値を求める
        for (const auto u: order) {

            // 右ろからの累積和を求める(dp[u] の先頭は入っていない)
            std::vector<T> accums_left(this->graph[u].size());
            accums_left[accums_left.size() - 1] = unit();
            for (int j = (int) accums_left.size() - 1; j >= 1; --j) {
                const auto &edge = this->graph[u][j];
                auto val = add_edge(this->dp[u][j], edge);
                accums_left[j - 1] = marge(val, accums_left[j]);
            }

            // 左からの累積和を求める
            T accum = unit();
            for (int j = 0; j < (int) accums_left.size(); j++) {
                const auto &edge = graph[u][j];
                // j が入っていない
                this->dp[edge.to][edge.rev] = add_node(marge(accum, accums_left[j]), u);
                const auto val = add_edge(this->dp[u][j], edge);
                accum = marge(accum, val);
            }

            this->ans[u] = add_node(accum, u);
        }
    }
};

/*
// 累積 accum と t を結合する関数
// （子供達の結合のみ考慮し，親に結合するときのことは考えないことに注意）
template<typename T>
T merge(const T accum, const T t) {
    return max(accum, t);
}

// 子供達の結果と頂点 u を結合する関数
template<typename T>
T add_node(const T accum, const int u) {
    return accum;
}

// 結果 t に 辺 e を影響させる
template<typename T, typename W>
T add_edge(const T t, Edge<W> e) {
    return t + e.w;
}

// 単位元
template<typename T>
T unit() {
    return 0;
}

ReRooting<int, int, merge, add_node, add_edge, unit> rr(N);
 */