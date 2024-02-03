#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_3_C"

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
        int B, E, K;
        cin >> B >> E >> K;
        cout << srf.range_count(B, E, K) << endl;
    }

    return 0;
}