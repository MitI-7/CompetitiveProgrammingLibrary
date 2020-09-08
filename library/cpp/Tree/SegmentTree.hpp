#include <vector>
#include <functional>
#include <cassert>


template <typename T> class SegmentTree {
    const int array_size;        // もとの配列のサイズ
    int n;
    std::vector<T> data;
    std::function<T (T,T)> op;
    T unit;

public:
    enum Mode {
        RangeMinimumQuery,
        RangeMaximumQuery,
        RangeSummationQuery,
    };

    SegmentTree(int array_size, Mode mode) : array_size(array_size) {
        if (mode == RangeMinimumQuery) {
            unit = std::numeric_limits<T>::max() / 3;;
            op = [](T a, T b) { return std::min(a, b); };
        }
        else if (mode == RangeMaximumQuery) {
            unit = 0;
            op = [](T a, T b) { return std::max(a, b); };
        }
        else if (mode == RangeSummationQuery) {
            unit = 0;
            op = [](T a, T b) { return a + b; };
        }
        else {
            assert(false);
        }

        n = 1;
        while (n < array_size) { n *= 2; }   // _n以上の最小の2冪
        data.resize(2 * n - 1, unit);
    }

    template <typename F> SegmentTree(int array_size, T unit, F op) : array_size(array_size), unit(unit), op(op) {
        while (n < array_size) { n *= 2; }   // _n以上の最小の2冪
        data.resize(2 * n - 1, unit);
    }

    T access(const int idx) const {
        return data[idx + n - 1];
    }

    // array[idx] = x
    // O(log N)
    void update(int idx, T x) {
        assert(0 <= idx and idx < array_size);
        idx += n - 1;   // 木での対象のインデックス
        data[idx] = x;
        while (idx > 0) {
            idx = (idx - 1) / 2;                                    // 親のインデックス
            data[idx] = op(data[idx * 2 + 1], data[idx * 2 + 2]);   // 左の子と右の子
        }
    }

    // op(array[left, right))
    // O(log N)
    T query(int left, int right) {
        assert(0 <= left and left < right and right <= array_size);
        return query(left, right, 0, 0, n);
    }

    // op(array[left, right))となるようなもっとも左のインデックス
    int query_left_index(const int left, const int right) {
        const auto t = query(left, right, 0, 0, n);

        if (t == access(left)) {
            return left;
        }

        auto low = left;
        auto high = right;
        while (high - low > 1) {
            int middle = (low + high) / 2;
            if (query(left, middle, 0, 0, n) == t) {
                high = middle;
            }
            else {
                low = middle;
            }
        }

        return high - 1;
    }

    // op(array[left, right))となるようなもっとも右のインデックス(未検証)
    int query_right_index(int left, int right) {
        const auto t = query(left, right, 0, 0, n);

        if (t == access(right - 1)) {
            return right;
        }

        auto low = left;
        auto high = right;
        while (high - low > 1) {
            auto middle = (low + high) / 2;
            if (query(left, middle, 0, 0, n) == t) {
                low = middle;
            }
            else {
                high = middle;
            }
        }

        return low;
    }

private:
    // [a, b)の目的値をノードk（区間[l, r]）から検索
    T query(int a, int b, int k, int l, int r) {
        assert(a < b && l < r);
        // 範囲外
        if (r <= a || b <= l) {
            return unit;
        }
        // 完全に含む
        if (a <= l && r <= b) {
            return this->data[k];
        }
            // 一部含む
        else {
            T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);    // 左の子
            T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);    // 右の子
            return op(vl, vr);
        }
    }
};