#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "library/cpp/DataStructure/WaveletMatrix.hpp"

#include <iostream>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<uint64_t> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    WaveletMatrix wm(A);
    for (int i = 0; i < Q; ++i) {
        uint64_t L, R, K;
        cin >> L >> R >> K;
        cout << wm.quantileRange(L, R, K) << endl;
    }

    return 0;
}