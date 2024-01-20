#include <cassert>
#include <vector>

// 各頂点がちょうど 1 の出自数をもつ有向グラフ
// グラフは連結とは限らない
template<typename T>
class FunctionalGraph {
public:
    const int num_nodes;
    std::vector<int> to;            // to[u] = u の行き先
    std::vector<bool> in_cycle;     // in_cycle[u] = u がサイクルに含まれる
    std::vector<T> value;           // 各ノードの値
    std::vector<int> component_no;  // 各ノードの所属コンポーネント番号
    int num_component = 0;          // コンポーネントの個数
    std::vector<int> cycle_size;    // コンポーネントごとのサイクルのサイズ
    std::vector<T> cycle_sum;       // コンポーネントごとのサイクルの値の合計

    explicit FunctionalGraph(const int num_nodes) : num_nodes(num_nodes) {
        this->to.resize(num_nodes, -1);
        this->in_cycle.resize(num_nodes, false);
        this->value.resize(num_nodes, 0);
        this->component_no.resize(num_nodes, -1);
    }

    // u -> v
    void add_directed_edge(const int u, const int v) {
        this->to[u] = v;
    }

    void set_value(const int u, const T x) {
        this->value[u] = x;
    }

    // u から k step 遷移したときの(ノード, ノードの設定値の合計)を求める
    // O(N)
    std::pair<int, T> k_step(const int u, long long k) const {
        T total = 0;

        // サイクルに入るまで進む
        int now = u;
        while (not this->in_cycle[now] and k > 0) {
            total += this->value[now];
            now = this->to[now];
            k--;
        }

        // サイクルをショートカット
        const int no = this->component_no[now];
        total += this->cycle_sum[no] * (k / this->cycle_size[no]);
        k %= this->cycle_size[no];

        for (int i = 0; i < k; ++i) {
            total += this->value[now];
            now = this->to[now];
        }

        return {now, total};
    }

    void build() {
        // 各サイクルに属するノード 1 つ と 各ノードの component no を求める
        {
            int no = 0;
            std::vector<bool> seen(this->num_nodes, false);
            for (int u = 0; u < this->num_nodes; ++u) {
                if (component_no[u] == -1) {
                    this->dfs(u, no++, seen);
                }
            }
            this->num_component = no;
            this->cycle_size.resize(no);
            this->cycle_sum.resize(no);
        }

        // 各サイクルのサイズとノードの値の合計を求める
        std::vector<bool> used(this->num_nodes, false);
        for (int u = 0; u < this->num_nodes; ++u) {
            // サイクルをみつけたら，そこから到達できるノードに印をつける
            if (this->in_cycle[u] and not used[u]) {
                used[u] = true;
                const int no = this->component_no[u];

                this->cycle_sum[no] += this->value[u];
                this->cycle_size[no]++;

                int v = this->to[u];
                while (v != u) {
                    used[v] = true;
                    this->cycle_sum[no] += this->value[v];
                    this->cycle_size[no]++;

                    this->in_cycle[v] = true;
                    v = this->to[v];
                }
            }
        }
    }

private:
    int dfs(const int u, const int c, std::vector<bool> &seen) {

        // すでに探索済み
        if (this->component_no[u] != -1) {
            return this->component_no[u];
        }

        // 自己ループをみつけた
        if (this->to[u] == u) {
            this->in_cycle[u] = true;
            return this->component_no[u] = c;
        }

        // ループをみつけた
        if (seen[u]) {
            this->in_cycle[u] = true;
            return this->component_no[u] = c;
        }

        seen[u] = true;
        return this->component_no[u] = this->dfs(this->to[u], c, seen);
    }
};