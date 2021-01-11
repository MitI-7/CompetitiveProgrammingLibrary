#include <vector>
#include <functional>
#include <cassert>



template <class S, S (*op)(S, S), S (*unit)()> class SegmentTree {
    const int array_size;       // もとの配列のサイズ
    int n;                      // セグ木で使う配列のサイズ
    std::vector<S> data;

public:
    SegmentTree(int array_size) : array_size(array_size) {
        this->n = 1;
        while (this->n < array_size) {
            this->n *= 2;    // array_size以上の最小の2冪
        }
        this->data.resize(2 * this->n - 1, unit());
    }

    S access(int idx) {
        return this->data[idx + this->n - 1];
    }

    // array[idx] = x
    // O(log N)
    void update(int idx, const S x) {
        assert(0 <= idx and idx < this->array_size);
        idx += this->n - 1;   // 木での対象のインデックス
        this->data[idx] = x;
        while (idx > 0) {
            idx = (idx - 1) / 2;                                    // 親のインデックス
            this->data[idx] = op(this->data[idx * 2 + 1], this->data[idx * 2 + 2]);   // 左の子と右の子
        }
    }

    // op(array[left, right))
    // O(log N)
    S query(const int left, const int right) const {
        assert(0 <= left and left < right and right <= this->array_size);
        return query(left, right, 0, 0, this->n);
    }

    // op(array[left, right))となるようなもっとも左のインデックスを取得
    int query_left_index(const int left, const int right) const {
        const auto t = query(left, right, 0, 0, this->n);

        if (t == access(left)) {
            return left;
        }

        auto low = left;
        auto high = right;
        while (high - low > 1) {
            int middle = (low + high) / 2;
            if (query(left, middle, 0, 0, this->n) == t) {
                high = middle;
            }
            else {
                low = middle;
            }
        }

        return high - 1;
    }

    // op(array[left, right))の結果となるようなもっとも右のインデックス(未検証)
    int query_right_index(int left, int right) const {
        const auto t = query(left, right, 0, 0, this->n);

        if (t == access(right - 1)) {
            return right;
        }

        auto low = left;
        auto high = right;
        while (high - low > 1) {
            auto middle = (low + high) / 2;
            if (query(left, middle, 0, 0, this->n) == t) {
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
    S query(int a, int b, int k, int l, int r) const {
        assert(a < b && l < r);
        // 範囲外
        if (r <= a || b <= l) {
            return unit();
        }
        // 完全に含む
        if (a <= l && r <= b) {
            return this->data[k];
        }
            // 一部含む
        else {
            S vl = query(a, b, k * 2 + 1, l, (l + r) / 2);    // 左の子
            S vr = query(a, b, k * 2 + 2, (l + r) / 2, r);    // 右の子
            return op(vl, vr);
        }
    }
};


// RangeMinimumQuery
//int op(int a, int b) {
//    return std::min(a, b);
//}
//int unit() {
//    return INT_MAX;
//}

// RangeMaximumQuery
//int op(int a, int b) {
//    return std::max(a, b);
//}
//int unit() {
//    return 0;
//}

// RangeSummationQuery
//int op(int a, int b) {
//    return a + b;
//}
//int unit() {
//    return 0;
//}

// RangeXorQuery
//LL op(LL a, LL b) {
//    return a ^ b;
//}
//LL unit() {
//    return 0;
//}