#include <cassert>
#include <iostream>
#include <numeric>
#include <set>

// 区間を set で管理する
template<class T>
class RangeSet {
private:
    const T INF = std::numeric_limits<T>::max() / 2;
    T total;                                // カバーされている区間の合計
    std::set<std::pair<T, T>> range_set;    // 区間 [l, r) の集合

public:
    RangeSet() : total(0) {
        this->range_set.emplace(-INF, -INF);
        this->range_set.emplace(INF, INF);
    }

    // 区間の個数を取得する
    [[nodiscard]] int size() const {
        return (int) range_set.size() - 2;
    }

    // 区間 [l, r) を挿入する
    void insert(T l, T r) {
        assert(l <= r);

        if (l == r) {
            return;
        }

        // [l, r) がすでにカバーされている
        auto it = prev(this->range_set.upper_bound({l, this->INF}));
        if (it->first <= l and r <= it->second) {
            return;
        }

        T erased_total = 0;

        // [l, r) が追加されることで統合される区間を求めていく

        // l は it でカバーされている
        if (it->first <= l and l <= it->second) {
            l = it->first;
            // it を削除
            erased_total += it->second - it->first;
            it = this->range_set.erase(it);
        } else {
            it = next(it);
        }

        // r でカバーされているところを削除していく
        while (it->second < r) {
            erased_total += it->second - it->first;
            it = this->range_set.erase(it);
        }

        // r でカバーされている最後
        if (it->first <= r) {
            erased_total += it->second - it->first;
            r = it->second;
            this->range_set.erase(it);
        }

        this->range_set.emplace(l, r);
        this->total += r - l - erased_total;
    }

    // 区間[l, r) が完全にカバーされているか
    // O(lon n)
    bool is_covered(const T l, const T r) const {
        assert(l <= r);
        if (l == r) {
            return true;
        }
        const auto it = prev(this->range_set.upper_bound({l, this->INF}));
        return it->first <= l and r <= it->second;
    }

    // 区間 [l, r) を完全にカバーしている区間を求める
    // カバーされていない場合は {-INF, -INF} を返す
    std::pair<T, T> covered_by(const T l, const T r) const {
        assert(l <= r);
        if (l == r) {
            return {-INF, -INF};
        }
        const auto it = prev(this->range_set.upper_bound({l, this->INF}));

        if (it->first <= l and r <= it->second) {
            return *it;
        }
        return {-INF, -INF};
    }

    // 区間 [l, r) を削除する
    void erase(const T l, const T r) {
        assert(l <= r);
        if (l == r) {
            return;
        }
        auto it = prev(this->range_set.upper_bound({l, this->INF}));

        // [l, r) を完全に含む区間がある
        if (it->first <= l and r <= it->second) {
            if (it->first < l) {
                this->range_set.emplace(it->first, l);
            }
            if (r < it->second) {
                this->range_set.emplace(r, it->second);
            }
            this->range_set.erase(it);
            this->total -= r - l;
            return;
        }

        T erased_total = 0;
        if (it->first <= l and l < it->second) {
            erased_total += it->second - l;
            if (it->first < l) {
                this->range_set.emplace(it->first, l);
            }
            it = this->range_set.erase(it);
        } else {
            it = next(it);
        }

        while (it->second <= r) {
            erased_total += it->second - it->first;
            it = this->range_set.erase(it);
        }

        if (it->first < r) {
            erased_total += r - it->first;
            this->range_set.emplace(r, it->second);
            this->range_set.erase(it);
        }
        this->total -= erased_total;
    }

    // mex を求める
    // O(log n)
    T mex(const T x = 0) const {
        const auto it = prev(this->range_set.upper_bound({x, this->INF}));
        if (it->first <= x and x < it->second) {
            return it->second;
        } else {
            return x;
        }
    }

    // カバーしている区間の合計を取得する
    T get_total() const {
        return this->total;
    }

    // カバーの集合を取得する
    std::set<std::pair<T, T>> get_covers() const {
        std::set<std::pair<T, T>> covers;
        for (const auto &[l, r]: this->range_set) {
            if (l == this->INF or l == -INF) {
                continue;
            }
            covers.emplace(l, r);
        }
        return covers;
    }

    void dump() const {
        for (const auto &[l, r]: this->range_set) {
            if (l == -this->INF or l == this->INF) {
                continue;
            }
            std::cout << "[" << l << "," << r << ")" << std::endl;
        }
    }
};