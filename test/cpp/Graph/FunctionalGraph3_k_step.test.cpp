#define PROBLEM "https://atcoder.jp/contests/abc167/tasks/abc167_d"

#include "library/cpp/Graph/FunctionalGraph.hpp"
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

    FunctionalGraph<long long> fg(N);
    for (int u = 0; u < N; ++u) {
        fg.add_directed_edge(u, A[u]);
    }
    fg.build();

    auto [u, _] = fg.k_step(0, K);
    cout << u + 1 << endl;

    return 0;
}