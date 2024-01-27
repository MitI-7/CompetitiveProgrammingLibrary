#include <cassert>
#include <cstdint>
#include <functional>
#include <numeric>
#include <tuple>
#include <vector>

// モノイドを乗せることができる
// 結合則: a * (b * c) = (a * b) * c
// 単位元: e * a = a * e = a
// すべて 0-origin
template<class T, T (*op)(T, T), T (*unit)()>
class SegmentTree {
    int n;                      // セグ木で使う配列のサイズ
    std::vector<T> data;

public:
    SegmentTree(const int array_size) : n(1) {
        // n は array_size 以上の最小の 2 冪
        while (this->n < array_size) {
            this->n <<= 1;
        }
        this->data.resize(2 * this->n - 1, unit());
    }

    SegmentTree(const std::vector<T> &v) : n(1) {
        while (this->n < (int) v.size()) {
            this->n <<= 1;
        }
        this->data.resize(2 * this->n - 1, unit());

        for (int i = 0; i < this->array_size; ++i) {
            this->data[i + n - 1] = v[i];
        }

        for (int u = this->n - 2; u >= 0; --u) {
            this->data[u] = op(this->data[u * 2 + 1], this->data[u * 2 + 2]);
        }
    }

    T access(const int idx) const {
        return this->data[idx + this->n - 1];
    }

    // data[idx] = x
    // O(log N)
    void update(int idx, const T x) {
//        assert(0 <= idx and idx < this->array_size);
        idx += this->n - 1;   // 木での対象のインデックス
        this->data[idx] = x;
        while (idx > 0) {
            idx = (idx - 1) / 2;                                                      // 親のインデックス
            this->data[idx] = op(this->data[idx * 2 + 1], this->data[idx * 2 + 2]);   // 左の子と右の子
        }
    }

    // op(data[left, right))
    // O(log N)
    T query(const int left, const int right) const {
//        assert(0 <= left and left < right and right <= this->array_size);
        return query(left, right, 0, 0, this->n);
    }

    // op(data[left, right)) = op(data[left, i)) となる最小のi
    int query_left() {
        return 0;
    }

private:
    // 区間 [l, r)の値をノード u から検索
    // ノード u は[start, end) をカバーする
    T query(const int l, const int r, const int u, const int start, const int end) const {
        assert(l < r && start < end);
        // 範囲外
        if (end <= l or r <= start) {
            return unit();
        }

        // 完全に含む
        if (l <= start and end <= r) {
            return this->data[u];
        } else {
            const int m = (start + end) / 2;
            auto vl = query(l, r, u * 2 + 1, start, m);  // 左の子
            auto vr = query(l, r, u * 2 + 2, m, end);    // 右の子
            return op(vl, vr);
        }
    }
};


// range minimum query
template<typename T>
T min_op(T a, T b) {
    return std::min(a, b);
}

template<typename T>
T min_unit() {
    return std::numeric_limits<T>::max();
}

template<typename T>
SegmentTree<T, min_op, min_unit> make_segment_tree_min(const int n) {
    return SegmentTree<T, min_op, min_unit>(n);
}

// range maximum query
template<typename T>
T max_op(T a, T b) {
    return std::max(a, b);
}

template<typename T>
T max_unit() {
    return 0;
}

template<typename T>
SegmentTree<T, min_op, min_unit> make_segment_tree_max(const int n) {
    return SegmentTree<T, max_op, max_unit>(n);
}

// range summation query
template<typename T>
T sum_op(T a, T b) {
    return a + b;
}

template<typename T>
T sum_unit() {
    return 0;
}

template<typename T>
SegmentTree<T, sum_op, sum_unit> make_segment_tree_sum(const int n) {
    return SegmentTree<T, sum_op, sum_unit>(n);
}

// range xor query
template<typename T>
T xor_op(T a, T b) {
    return a ^ b;
}

template<typename T>
T xor_unit() {
    return 0;
}

template<typename T>
SegmentTree<T, xor_op, xor_unit> make_segment_tree_xor(const int n) {
    return SegmentTree<T, xor_op, xor_unit>(n);
}

// Rolling Hash query
const int P = 998244353;
const long long base = 129;

std::tuple<uint_fast64_t, long long, int>
rh_op(std::tuple<uint_fast64_t, long long, int> a, std::tuple<uint_fast64_t, long long, int> b) {
    auto [h0, x0, p0] = a;
    auto [h1, x1, p1] = b;
    return {(h0 + h1 * x0) % p0, (x0 * x1) % p0, p0};
}

std::tuple<uint_fast64_t, long long, int> rh_unit() {
    return {(uint_fast64_t) 0, 1, P};
}


// カッコ列
// 「(」を +1，「)」を -1 とする
// (合計，区間最小)
const std::pair<int, int> parenthesis_left = {1, 0};
const std::pair<int, int> parenthesis_right = {-1, -1};

std::pair<int, int> parenthesis_op(std::pair<int, int> a, std::pair<int, int> b) {
    const auto [t0, m0] = a;
    const auto [t1, m1] = b;
    return {t0 + t1, std::min(m0, t0 + m1)};
}

std::pair<int, int> parenthesis_unit() {
    return {0, 0};
}