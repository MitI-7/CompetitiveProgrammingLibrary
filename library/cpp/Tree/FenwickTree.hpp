#include <cassert>
#include <vector>

// すべて 0-origin
template<class T>
class FenwickTree {
public:
    const int n;
    std::vector<T> v;

    // n: 要素数
    explicit FenwickTree(const int n) : n(n) {
        this->v.assign(n + 1, 0);
    }

    // v[i]
    // O(log n)
    T access(const int i) const {
        return this->sum(i, i + 1);
    }

    // v[i] += x
    // O(log n)
    void add(int i, T x) {
        assert(i < this->n);

        while (i < this->n) {
            this->v[i] += x;
            i |= i + 1;
        }
    }

    // v[i] = x
    // O(log n)
    void update(int i, T x) {
        assert(i < this->n);

        const T now = this->access(i);
        this->add(i, x - now);
    }

    // sum(v[0, i))
    // O(log n)
    T sum(int i) const {
        assert(0 <= i and i <= this->n);

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
    T sum(const int left, const int right) const {
        if (left >= right) {
            return 0;
        }
        return this->sum(right) - this->sum(left);
    }
};