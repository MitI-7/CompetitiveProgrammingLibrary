#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "library/cpp/DataStructure/CumulativeSum.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    CumulativeSum<long long> cs(A);

    for (int i = 0; i < Q; ++i) {
        int L, R;
        cin >> L >> R;
        cout << cs.sum(L, R) << endl;
    }

    return 0;
}