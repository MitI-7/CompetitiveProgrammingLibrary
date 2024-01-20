#include <cassert>
#include <stack>
#include <tuple>
#include <vector>

class RollbackUnionFind {
public:
    int set_size;   // 集合の個数

private:
    std::vector<int> parent;
    std::stack<std::tuple<int, int, int, int, int>> history;
    int snap_no;

public:
    explicit RollbackUnionFind(const int num_nodes) : set_size(num_nodes), parent(num_nodes, -1), snap_no(0) {
    }

    // u と v が同じ集合に属するか判定する
    // O(log n)
    int is_same_set(const int u, const int v) {
        return this->find_root(u) == this->find_root(v);
    }

    // u と v の属する集合を併合する
    // O(log n)
    bool unite(int u, int v) {
        u = this->find_root(u);
        v = this->find_root(v);

        // u と v の現在の親を記録
        this->history.emplace(u, this->parent[u], v, this->parent[v], this->set_size);

        if (u == v) {
            return false;
        }

        // 集合のサイズが大きい方を u とする
        if (this->parent[u] > this->parent[v]) {
            std::swap(u, v);
        }

        // u の下に v をつける
        this->parent[u] += this->parent[v];
        this->parent[v] = u;
        this->set_size--;

        return true;
    }

    // u の属する集合の要素数を求める
    // O(log n)
    int size(const int u) {
        return (-this->parent[this->find_root(u)]);
    }

    // u の属する集合の leader を取得
    // O(log n)
    int leader(const int u) {
        return this->find_root(u);
    }

    // 直前に行った unite 操作を取り消す
    // 取り消した (u, v) を返す
    // O(1)
    std::pair<int, int> undo() {
        assert(not this->history.empty());

        const auto [u, u_p, v, v_p, s] = history.top();
        this->history.pop();
        this->parent[u] = u_p;
        this->parent[v] = v_p;
        this->set_size = s;

        return {u, v};
    }

    // 現在の状態を保存
    // undo をよんで，snapshot を呼び出した状態より前に戻ったとき，意味のない状態になることに注意
    // O(1)
    void snapshot() {
        this->snap_no = this->get_snap_no();
    }

    int get_snap_no() {
        return int(history.size());
    }

    // snapshot を撮った状態に戻す
    // num を指定した場合，unite 関数を num 回呼び出した時の状態に戻す
    // O(戻す回数)
    void rollback(int num = -1) {
        if (num == -1) {
            num = this->snap_no;
        }
        while (num < int(this->history.size())) {
            this->undo();
        }
    }

private:
    // u の根を求める
    // O(log n)
    int find_root(int u) {
        if (this->parent[u] < 0) {
            return u;
        }
        // 経路圧縮はしない
        return this->find_root(this->parent[u]);
    }
};