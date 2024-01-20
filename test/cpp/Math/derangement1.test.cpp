#define PROBLEM "https://atcoder.jp/contests/abc172/tasks/abc172_e"

#include "library/cpp/Math/derangement.cpp"
#include "library/cpp/Utility/mint.hpp"
#include <iostream>

using namespace std;

const int MOD = 1000000007;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    mint<MOD> ans = 1;
    for (int i = 0; i < N; ++i) {
        ans *= M - i;
    }
    ans *= derangement<MOD>(N, M);
    cout << ans.x << endl;

    return 0;
}