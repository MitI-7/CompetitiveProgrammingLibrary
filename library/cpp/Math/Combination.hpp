#include <cassert>
#include <cstdint>
#include <vector>
#include "library/cpp/Utility/mint.hpp"

// nCr
// O(r)
template<typename T>
T combination(long long n, long long r) {
    if (r < 0) {
        return 0;
    }
    T ans = 1;
    for (long long d = 1; d <= r; ++d) {
        ans *= n--;
        ans /= d;
    }
    return ans;
}

template<int MOD>
class Combination {
public:
    std::vector<mint<MOD>> fact;
    std::vector<mint<MOD>> inv;

    // O(n)
    Combination(int n) {
        assert(0 < n);
        this->fact.resize(n + 1, 1);
        this->inv.resize(n + 1, 1);

        for (int i = 1; i < int(fact.size()); ++i) {
            this->fact[i] = this->fact[i - 1] * i;
            this->inv[i] = this->fact[i].inv();
        }
    }

    mint<MOD> nCr(const int n, const int r) const {
        assert(0 <= n and 0 <= r);
        if (n < r) {
            return 0;
        }
        return this->fact[n] * (this->inv[r] * this->inv[n - r]);
    }

    mint<MOD> nPr(const int n, const int r) const {
        assert(0 <= n and 0 <= r);
        if (n < r) {
            return 0;
        }
        return this->fact[n] * this->inv[n - r];
    }

    // 重複組合せ
    // n 個のものから繰り返しをゆるして r 個とるときの場合の数
    // n 個の o と r - 1 個の | の並びの場合の数
    mint<MOD> nHr(const int n, const int r) const {
        return nCr(n + r - 1, r);
    }
};