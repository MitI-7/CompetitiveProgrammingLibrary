#include <vector>

class UnionFind {
public:
    const int n;        // 要素の個数
    int set_size;       // 集合の個数
    
private:
    std::vector<int> parent;	// 親の番号(親だった場合は-(その集合のサイズ))

public:
    UnionFind(int n) : n(n), set_size(n), parent(n, -1) {
    }

    // xとyが同じ集合に属するか
    bool is_same_set(int x, int y) {
        return this->find_root(x) == this->find_root(y);
    }

    // xとyの属する集合を併合
    void union_set(int x, int y) {
        x = this->find_root(x);
        y = this->find_root(y);
        if (x == y) {
            return;
        }
        if (this->parent[x] > this->parent[y]) {
            std::swap(x, y);
        }

		// 小さい方(x)に大きい方(y)をくっつける
		// 両方ともrootなので-(集合のサイズ)が入っている
        this->parent[x] += this->parent[y];
        // yの親をxにする
        this->parent[y] = x;
        set_size--;
    }

    // xの属する集合の要素数
    int size(int x) {
        return (-this->parent[find_root(x)]);
    }

private:
    // 木の根を求める
    int find_root(int x) {
        if (this->parent[x] < 0) {
            return x;
        }
        else {
            return this->parent[x] = find_root(this->parent[x]);
        }
    }
};