#define PROBLEM "https://atcoder.jp/contests/abc178/tasks/abc178_d"

#include "library/cpp/Math/Combination.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    const int MOD = 1000000000 + 7;

    int S;
    cin >> S;

    Combination<MOD> comb(10000);

    mint<MOD> ans;
    for (int i = 0; i < S; ++i) {
        if (S >= (i + 1) * 3) {
            ans += comb.nCr(S - (i + 1) * 3 + i, i);
        }
    }
    cout << ans.x << endl;

    return 0;
}