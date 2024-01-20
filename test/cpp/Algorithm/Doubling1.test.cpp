#define PROBLEM "https://atcoder.jp/contests/abc167/tasks/abc167_d"

#include "library/cpp/Algorithm/Doubling.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    long long K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        A[i]--;
    }

    Doubling<int> doubling(N, (long long) 1000000000000000100);
    for (int i = 0; i < N; ++i) {
        doubling.function(i, A[i]);
    }

    cout << doubling.query(0, K) + 1 << endl;

    return 0;
}
