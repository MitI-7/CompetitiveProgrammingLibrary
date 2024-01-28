#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include "library/cpp/Range/StaticRangeFrequency.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    StaticRangeFrequency srf(A);
    for (int i = 0; i < Q; ++i) {
        int L, R, X;
        cin >> L >> R >> X;
        cout << srf.range_count(L, R, X) << endl;
    }

    return 0;
}