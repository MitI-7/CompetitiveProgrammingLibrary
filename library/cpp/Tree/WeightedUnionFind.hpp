#include <cassert>
#include <vector>

template<class T>
class WeightedUnionFind {
public:
    std::vector<int> parent;
    std::vector<T> diff_weight;

    explicit WeightedUnionFind(const int num_nodes) {
        this->parent.resize(num_nodes, -1);
        this->diff_weight.resize(num_nodes);
    }

    // u と v が同じ集合に属するか判定する
    bool is_same_set(const int u, const int v) {
        return this->find_root(u) == this->find_root(v);
    }

    // u と v の属する集合を併合する
    // weight(u) + w = weight(v) となるようにする
    // u と v が同じ集合で，整合性が保たれるとき true を返す
    bool unite(int u, int v, const T w) {
        T new_w = this->weight(u) + w - this->weight(v);
        u = this->find_root(u);
        v = this->find_root(v);

        if (u == v) {
            return new_w == 0;
        }

        // 集合のサイズが小さい方を u とする
        if (this->parent[u] > this->parent[v]) {
            std::swap(u, v);
            new_w = -new_w;
        }

        // u の下に v をつける
        this->parent[u] += this->parent[v];
        this->parent[v] = u;
        this->diff_weight[v] = new_w;

        return true;
    }

    T weight(const int u) {
        this->find_root(u);
        return this->diff_weight[u];
    }

    // u と v とが同じグループにいるとき、weight(v) - weight(u)
    T diff(const int u, const int v) {
        assert(this->is_same_set(u, v));
        return this->weight(v) - this->weight(u);
    }

private:
    // 木の根を求める
    int find_root(const int u) {
        if (this->parent[u] < 0) {
            return u;
        }

        const int root = this->find_root(this->parent[u]);
        // u は root の直下につくので，u の weight は u から root までの累積和となる
        this->diff_weight[u] += this->diff_weight[this->parent[u]];
        // 経路圧縮
        return this->parent[u] = root;
    }
};