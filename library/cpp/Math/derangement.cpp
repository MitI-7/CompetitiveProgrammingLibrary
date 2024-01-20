#include <algorithm>
#include "library/cpp/Utility/mint.hpp"
#include "library/cpp/Math/Combination.hpp"

// 完全順列の m 色版の場合の数
// 値とインデックスがどこも一致していないような順列の場合の数
// 値は[0, m)の範囲をとる．n == m のとき，完全順列
// O(n)
template<int MOD>
mint<MOD> derangement(const int n, const int m) {

    Combination<MOD> comb(std::max(n, m) + 100);

    mint<MOD> ans = 0;
    for (int i = 0; i <= n; ++i) {
        // i個以上の箇所が指定の色と一致してしまっている
        auto now = comb.nCr(n, i);
        // n - i個の箇所は指定の色と一致してもしなくてもいい
        now *= comb.nPr(m - i, n - i);

        if (i % 2 == 0) {
            ans += now;
        }
        else {
            ans -= now;
        }
    }

    return ans;
}