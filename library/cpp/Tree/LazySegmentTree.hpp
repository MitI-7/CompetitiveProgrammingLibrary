#include <vector>
#include <functional>
#include <cassert>


template <typename T> struct Mode {
    std::function<T(T, T)> f;   // 要素に適用する演算
    std::function<T(T, T)> g;   // 作用素の適用
    std::function<T(T, T)> h;   // 作用素の合成
    std::function<T(T, int)> p;
    T unit;
    T lazy_unit;
};

template <typename T> class LazySegmentTree {
private:
    const int array_size;
    int n;
    std::vector<T> data, lazy;
    const Mode<T> mode;
public:
    LazySegmentTree(const std::vector<T> &v, const Mode<T> mode) : array_size(v.size()), mode(mode) {
        this->n = 1;
        while (this->n < this->array_size) { this->n *= 2; }
        this->data.resize(2 * this->n - 1, this->mode.unit);
        this->lazy.resize(2 * this->n - 1, this->mode.lazy_unit);

        for (int i = 0; i < this->array_size; ++i) {
            this->data[i + n - 1] = v[i];
        }
        for (int i = this->n - 2; i >= 0; i--) {
            this->data[i] = this->mode.f(this->data[i * 2 + 1], this->data[i * 2 + 2]);
        }
    }

    // array[idx]
    // log(N)
    T access(const int idx) const {
        return query(idx, idx + 1, 0, 0, this->n);
    }

    // operation(array[idx], x)
    // log(N)
    void operation(const int idx, const T x) {
        operation(idx, idx + 1, x);
    }

    // operation(array[left, right), x)
    // log(N)
    void operation(const int left, const int right, const T x) {
        assert(0 <= left and left < right and right <= this->array_size);
        operation(left, right, x, 0, 0, this->n);
    }

    // op(array[a, b))
    // log(N)
    T query(const int left, const int right) {
        return query(left, right, 0, 0, this->n);
    }

private:
    T operation(const int a, const int b, const T x, const int k, const int l, const int r) {
        propagate(k, r - l);

        // 範囲外
        if (b <= l or r <= a) {
            return this->data[k];
        }
            // 完全に含む
        else if (a <= l and r <= b) {
            this->lazy[k] = this->mode.h(this->lazy[k], x);
            propagate(k, r - l);
            return this->mode.g(this->data[k], this->mode.p(this->lazy[k], r - l));
        }
            // 一部含む
        else {
            auto lv = operation(a, b, x, 2 * k + 1, l, (l + r) / 2);    // 左の子
            auto rv = operation(a, b, x, 2 * k + 2, (l + r) / 2, r);    // 右の子
            return this->data[k] = this->mode.f(lv, rv);
        }
    }

    // [a, b)の目的値をノードk（区間[l, r]）から検索
    T query(const int a, const int b, const int k, const int l, const int r) {
        propagate(k, r - l);

        // 範囲外
        if (b <= l or r <= a) {
            return this->mode.unit;
        }
            // 完全に含む
        else if (a <= l && r <= b) {
            return this->data[k];
        }
            // 一部含む
        else {
            auto vl = query(a, b, k * 2 + 1, l, (l + r) / 2);    // 左の子
            auto vr = query(a, b, k * 2 + 2, (l + r) / 2, r);    // 右の子
            return this->mode.f(vl, vr);
        }
    }

    void propagate(const int k, const int len) {
        if (this->lazy[k] == this->mode.lazy_unit) {
            return;
        }

        if (len > 1) {
            this->lazy[k * 2 + 1] = this->mode.h(this->lazy[k * 2 + 1], this->lazy[k]);
            this->lazy[k * 2 + 2] = this->mode.h(this->lazy[k * 2 + 2], this->lazy[k]);
        }
        this->data[k] = this->mode.g(this->data[k], this->mode.p(this->lazy[k], len));
        this->lazy[k] = this->mode.lazy_unit;
    }
};

template <typename T> Mode<T> range_minimum_query_update() {
    const T lazy_unit = -1;
    return Mode<T>{
        [](T a, T b) { return std::min(a, b); },
        [=](T a, T b) { return b == lazy_unit ? a : b; },
        [=](T a, T b) { return b == lazy_unit ? a : b; },
        [=](T a, int len) { return a; },
        std::numeric_limits<T>::max() / 3,
        lazy_unit,
    };
}

template <typename T> Mode<T> range_minimum_query_add() {
    return Mode<T>{
        [](T a, T b) { return std::min(a, b); },
        [](T a, T b) { return a + b; },
        [](T a, T b) { return a + b; },
        [](T a, int len) { return a; },
        std::numeric_limits<T>::max() / 3,
        0,
    };
}

template <typename T> Mode<T> range_maximum_query_update() {
    const T lazy_unit = -1;
    return Mode<T>{
        [](T a, T b) { return std::max(a, b); },
        [=](T a, T b) { return b == lazy_unit ? a : b; },
        [=](T a, T b) { return b == lazy_unit ? a : b; },
        [](T a, int len) { return a; },
        std::numeric_limits<T>::min() / 3,
        lazy_unit,
    };
}

template <typename T> Mode<T> range_maximum_query_add() {
    return Mode<T>{
        [](T a, T b) { return std::max(a, b); },
        [](T a, T b) { return a + b; },
        [](T a, T b) { return a + b; },
        [](T a, int len) { return a; },
        std::numeric_limits<T>::min() / 3,
        0,
    };
}

template <typename T> Mode<T> range_summation_query_update() {
    const T lazy_unit = std::numeric_limits<T>::max() / 3;
    return Mode<T>{
        [](T a, T b) { return a + b; },
        [=](T a, T b) { return b == lazy_unit ? a : b;},
        [=](T a, T b) { return b == lazy_unit ? a : b;},
        [=](T a, int len) { return a == lazy_unit ? a : a * len;},
        0,
        lazy_unit,
    };
}

template <typename T> Mode<T> range_summation_query_add() {
    return Mode<T>{
        [](T a, T b) { return a + b; },
        [](T a, T b) { return a + b; },
        [](T a, T b) { return a + b; },
        [](T a, int len) { return a * len; },
        0,
        0,
    };
}

// 区間min更新
template<typename T> T &chmin(T &a, const T &b) { return a = std::min(a, b); }
template <typename T> Mode<T> range_minimum_query_min() {
    return Mode<T>{
        [](T a, T b) { return std::min(a, b); },
        [](T a, T b) { return chmin(a, b); },
        [](T a, T b) { return chmin(a, b); },
        [](T a, int len) { return a; },
        std::numeric_limits<T>::max() / 3,
        std::numeric_limits<T>::max() / 3,
    };
}
