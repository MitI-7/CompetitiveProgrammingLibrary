#define PROBLEM "https://atcoder.jp/contests/abc248/tasks/abc248_d"

#include "library/cpp/Range/StaticRangeFrequency.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    StaticRangeFrequency srf(A);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int L, R, X;
        cin >> L >> R >> X;
        L--;
        R--;
        cout << srf.range_count(L, R + 1, X) << endl;
    }

    return 0;
}