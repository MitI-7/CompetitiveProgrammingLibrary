#include <cassert>
#include <functional>
#include <numeric>
#include <vector>

template<typename T>
T op(const T left_value, const T right_value) {
    return std::min(left_value, right_value);
}

template<typename T>
T mapping(const T value, const T lazy_value, const int len) {
    return value + lazy_value;
}

template<typename T>
T composition(const T old_lazy_value, const T new_lazy_value) {
    return old_lazy_value + new_lazy_value;
}

template<typename T>
T unit() {
    return std::numeric_limits<T>::max() / 3;
}

template<typename T>
T lazy_unit() {
    return 0;
}

template<typename T, T (*op)(T, T), T (*mapping)(T, T, int), T (*composition)(T, T), T (*unit)(), T (*lazy_unit)()>
class LazySegmentTree {
private:
    int n;
    std::vector<T> data, lazy;
public:
    LazySegmentTree(const int array_size, const T initial_value) : n(1) {
        while (this->n < array_size) {
            this->n <<= 1;
        }
        this->data.resize(2 * this->n - 1);
        this->lazy.resize(2 * this->n - 1, lazy_unit());

        for (int u = 0; u < array_size; ++u) {
            this->data[this->n - 1 + u] = initial_value;
        }
        for (int u = this->n - 2; u >= 0; --u) {
            this->data[u] = op(this->data[u * 2 + 1], this->data[u * 2 + 2]);
        }
    }

    LazySegmentTree(const std::vector<T> &v) : n(1) {
        while (this->n < (int) v.size()) {
            this->n <<= 1;
        }
        this->data.resize(2 * this->n - 1);
        this->lazy.resize(2 * this->n - 1, lazy_unit());

        for (int u = 0; u < (int) v.size(); ++u) {
            this->data[this->n - 1 + u] = v[u];
        }
        for (int u = this->n - 2; u >= 0; --u) {
            this->data[u] = op(this->data[u * 2 + 1], this->data[u * 2 + 2]);
        }
    }

    // array[idx]
    // log(N)
    T access(const int idx) {
        return this->query(idx, idx + 1);
    }

    // idx に x を適用する
    // log(N)
    void operation(const int idx, const T x) {
        this->operation(idx, idx + 1, x);
    }

    // 区間 [left, right) に x を適用する
    // log(N)
    void operation(const int left, const int right, const T x) {
        if (left >= right) {
            return;
        }
        this->operation(left, right, x, 0, 0, this->n);
    }

    // 区間 [left, right) から値を求める
    // log(N)
    T query(const int left, const int right) {
        return this->query(left, right, 0, 0, this->n);
    }

private:
    // 区間 [l, r) に x を適用する
    // ノード u は[start, end) をカバーする
    T operation(const int l, const int r, const T x, const int u, const int start, const int end) {
        this->propagate(u, end - start);

        // 範囲外
        if (r <= start or end <= l) {
            // クエリではなく更新なので unit() ではなく，data[u] を返す
            return this->data[u];
        }

        // 完全に含む
        if (l <= start and end <= r) {
            this->lazy[u] = composition(this->lazy[u], x);
            this->propagate(u, end - start);
            return this->data[u] = mapping(this->data[u], this->lazy[u], end - start);
        }

        // 部分的に含む
        const auto m = (start + end) / 2;
        const auto lv = this->operation(l, r, x, 2 * u + 1, start, m);  // 左の子
        const auto rv = this->operation(l, r, x, 2 * u + 2, m, end);    // 右の子
        return this->data[u] = op(lv, rv);
    }

    // 区間 [l, r) から値を検索する
    // ノード u は[start, end) をカバーする
    T query(const int l, const int r, const int u, const int start, const int end) {
        this->propagate(u, end - start);

        // 範囲外
        if (r <= start or end <= l) {
            return unit();
        }

        // 完全に含む
        if (l <= start and end <= r) {
            return this->data[u];
        }

        // 一部含む
        const auto m = (start + end) / 2;
        const auto vl = this->query(l, r, u * 2 + 1, start, m);  // 左の子
        const auto vr = this->query(l, r, u * 2 + 2, m, end);    // 右の子
        return op(vl, vr);
    }

    // u の値を更新し，u の子供に遅延情報を伝える
    void propagate(const int u, const int len) {
        // 伝播済み
        if (this->lazy[u] == lazy_unit()) {
            return;
        }

        if (len > 1) {
            this->lazy[u * 2 + 1] = composition(this->lazy[u * 2 + 1], this->lazy[u]);
            this->lazy[u * 2 + 2] = composition(this->lazy[u * 2 + 2], this->lazy[u]);
        }
        this->data[u] = mapping(this->data[u], this->lazy[u], len);
        this->lazy[u] = lazy_unit();
    }
};
