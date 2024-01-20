#include "FenwickTree.hpp"
#include <iostream>

// 区間加算，区間和取得
// すべて 0-origin
template<typename T>
class FenwickTreeRange {
    const int n;
    FenwickTree<T> ft0, ft1;

public:
    explicit FenwickTreeRange(const int n) : n(n), ft0(n + 1), ft1(n + 1) {}

    // v[i]
    // O(log n)
    T access(const int i) const {
        assert(0 <= i and i < this->n);
        return this->sum(i, i + 1);
    }

    // v[i] += x
    // O(log n)
    void add(const int i, const T x) {
        assert(0 <= i and i < this->n);
        this->add(i, i + 1, x);
    }

    // v[left, right) += x
    // O(log n)
    void add(const int left, const int right, const T x) {
        if (left == right) {
            return;
        }
        assert(0 <= left and left < right and right <= this->n);
        this->ft0.add(left, x);
        this->ft0.add(right, -x);
        this->ft1.add(left, -x * left);
        this->ft1.add(right, x * right);
    }

    // v[left, right) += x
    // 加算位置が n 以上の場合は 0 に戻って加算される
    // O(log n)
    void add_circle(long long left, long long right, const T x) {
        assert(left < right);

        const long long num_loop = (right - left) / this->n;
        this->add(0, this->n, x * num_loop);

        // ループで終わり
        if ((right - left) % this->n == 0) {
            return;
        }

        left %= this->n;
        right %= this->n;

        if (left < right) {
            this->add(left, right, x);
        } else {
            this->add(left, this->n, x);
            this->add(0, right, x);
        }
    }

    // sum(v[0, i))
    // O(log n)
    T sum(const int i) const {
        assert(0 <= i and i <= this->n);
        return ft0.sum(i) * i + ft1.sum(i);
    }

    // sum(v[left, right))
    // O(log n)
    T sum(const int left, const int right) const {
        assert(0 <= left and left < right and right <= this->n);
        return this->sum(right) - this->sum(left);
    }

    // sum(v[left, right))
    // O(log n)
    T sum_circle(const int left, const int right) const {
        // TODO
        return 0;
    }

    void dump() {
        for (int i = 0; i < this->n; ++i) {
            if (i != 0) {
                std::cout << " ";
            }
            std::cout << this->access(i);
        }
        std::cout << std::endl;
    }
};