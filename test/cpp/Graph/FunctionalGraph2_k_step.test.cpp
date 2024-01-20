#define PROBLEM "https://atcoder.jp/contests/abc179/tasks/abc179_e"

#include "library/cpp/Graph/FunctionalGraph.hpp"

#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    long long N;
    int X, M;
    cin >> N >> X >> M;

    FunctionalGraph<long long> fg(M);
    for (int u = 0; u < M; ++u) {
        fg.set_value(u, u);
        fg.add_directed_edge(u, int(((long long) u * u) % M));
    }
    fg.build();

    auto [u, ans] = fg.k_step(X, N);
    cout << ans << endl;

    return 0;
}