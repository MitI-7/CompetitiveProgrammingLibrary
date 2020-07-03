#include <vector>
#include <cassert>


template <class T=long long> class FenwickTree {
public:
    const int n;
    std::vector<T> v;

    FenwickTree(const int n) : n(n) {
        this->v.assign(n + 1, 0);
    }

    // O(log n)
    T access(const int i) {
        return this->sum(i, i + 1);
    }

    // sum(v[0, i))
    // O(log n)
    T sum(int i) {
        assert(0 <= i && i <= this->n);

        T s = 0;
        i -= 1;
        while (i >= 0) {
            s += this->v[i];
            i = (i & (i + 1)) - 1;
        }
        return s;
    }

    // sum(v[left, right))
    // O(log n)
    T sum(const int left, const int right) {
        assert(left <= right);
        return this->sum(right) - this->sum(left);
    }

    // v[i] += x
    // 0-origin
    // O(log n)
    void add(int i, T x) {
        assert(i < this->n);

        while (i < this->n) {
            this->v.at(i) += x;
            i |= i + 1;
        }
    }
};
