#include <vector>
#include <functional>
#include <cassert>


template <typename T> class LazySegmentTree {
private:
    const int array_size;
    int n;
    std::vector<T> data, lazy;
    const std::function<T (T, T)> f;     // 要素に適用する演算
    const std::function<T (T, T)> g;     // 作用素の適用
    const std::function<T (T, T)> h;     // 作用素の合成
    const std::function<T (T, int)> p;
    const T unit;
    const T lazy_unit;

public:
    class Mode {
    public:
        std::function<T (T, T)> f;
        std::function<T (T, T)> g;
        std::function<T (T, T)> h;
        std::function<T (T, int)> p;
        T unit;
        T lazy_unit;
    };

    enum Query {
        RangeMinimumQuery,
        RangeMaximumQuery,
        RangeSummationQuery,
    };

    enum Operation {
        Update,
        Add,
    };

    LazySegmentTree(const std::vector<T> &v, const Mode mode) : array_size(v.size()),  f(mode.f), g(mode.g), h(mode.h), p(mode.p), unit(mode.unit), lazy_unit(mode.lazy_unit){
        n = 1;
        while (n < array_size) { n *= 2; }
        data.resize(2 * n - 1, unit);
        lazy.resize(2 * n - 1, lazy_unit);

        for (int i = 0; i < array_size; ++i) {
            data[i + n - 1] = v[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            data[i] = f(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    static Mode getMode(const Query query, const Operation operation) {
        Mode mode;
        if (query == RangeMinimumQuery) {
            mode.unit = std::numeric_limits<T>::max() / 3;

            mode.f = [](T a, T b) { return std::min(a, b); };
            if (operation == Update) {
                mode.lazy_unit = -1;
                mode.g = [&](T a, T b) { return b == mode.lazy_unit ? a : b; };
                mode.h = mode.g;
                mode.p = [&](T a, int len) { return a; };
            }
            else if (operation == Add) {
                mode.lazy_unit = 0;
                mode.g = [](T a, T b) { return a + b; };
                mode.h = mode.g;
                mode.p = [](T a, int len) { return a; };
            }
        }
        else if (query == RangeMaximumQuery) {
            mode.unit = std::numeric_limits<T>::min() / 3;

            mode.f = [](T a, T b) { return std::max(a, b); };
            if (operation == Update) {
                mode.lazy_unit = -1;
                mode.g = [&](T a, T b) { return b == mode.lazy_unit ? a : b; };
                mode.h = mode.g;
                mode.p = [](T a, int len) { return a; };
            }
            else if (operation == Add) {
                mode.lazy_unit = 0;
                mode.g = [](T a, T b) { return a + b; };
                mode.h = mode.g;
                mode.p = [](T a, int len) { return a; };
            }
        }
        else if (query == RangeSummationQuery) {
            mode.unit = 0;

            mode.f = [](T a, T b) { return a + b; };
            if (operation == Update) {
                mode.lazy_unit = std::numeric_limits<T>::max() / 3;
                mode.g = [&](T a, T b) { return b == mode.lazy_unit ? a : b;};
                mode.h = mode.g;
                mode.p = [&](T a, int len) {return a == mode.lazy_unit ? a : a * len;};
            }
            else if (operation == Add) {
                mode.lazy_unit = 0;
                mode.g = [](T a, T b) { return a + b;};
                mode.h = [](T a, T b) { return a + b;};
                mode.p = [](T a, int len) {return a * len;};
            }
        }
        return mode;
    }

    // array[idx]
    // log(N)
    T access(const int idx) {
        return query(idx, idx + 1, 0, 0, n);
    }

    // operation(array[idx], x)
    // log(N)
    void operation(const int idx, const T x) {
        operation(idx, idx + 1, x);
    }

    // operation(array[left, right), x)
    // log(N)
    void operation(const int left, const int right, const T x) {
        assert(0 <= left and left < right and right <= array_size);
        operation(left, right, x, 0, 0, n);
    }

    // op(array[a, b))
    // log(N)
    T query(const int left, const int right) {
        return query(left, right, 0, 0, n);
    }

private:
    T operation(const int a, const int b, const T x, const int k, const int l, const int r) {
        propagate(k, r - l);

        // 範囲外
        if (b <= l or r <= a) {
            return data[k];
        }
        // 完全に含む
        else if (a <= l and r <= b) {
            lazy[k] = h(lazy[k], x);
            propagate(k, r - l);
            return g(data[k], p(lazy[k], r - l));
        }
        // 一部含む
        else {
            T lv = operation(a, b, x, 2 * k + 1, l, (l + r) / 2);    // 左の子
            T rv = operation(a, b, x, 2 * k + 2, (l + r) / 2, r);    // 右の子
            return data[k] = f(lv, rv);
        }
    }

    // [a, b)の目的値をノードk（区間[l, r]）から検索
    T query(const int a, const int b, const int k, const int l, const int r) {
        propagate(k, r - l);

        // 範囲外
        if (b <= l or r <= a) {
            return unit;
        }
        // 完全に含む
        else if (a <= l && r <= b) {
            return data[k];
        }
        // 一部含む
        else {
            T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);    // 左の子
            T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);    // 右の子
            return f(vl, vr);
        }
    }

    void propagate(const int k, const int len) {
        if (lazy[k] == lazy_unit) {
            return;
        }

        if (len > 1) {
            lazy[k * 2 + 1] = h(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = h(lazy[k * 2 + 2], lazy[k]);
        }
        data[k] = g(data[k], p(lazy[k], len));
        lazy[k] = lazy_unit;
    }
};