#define PROBLEM "https://atcoder.jp/contests/abc357/tasks/abc357_e"

#include "library/cpp/graph/StronglyConnectedComponents.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    StronglyConnectedComponents scc(N);
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        A--;
        scc.add_directed_edge(i, A);
    }
    scc.build();
    auto g = scc.make_new_graph();

    long long ans = 0;
    vector<long long> dp(g.num_nodes);
    for (int c = g.num_nodes - 1; c >= 0; --c) {
        const auto n = scc.get_nodes(c).size();
        dp[c] = n;
        for (const auto &e: g[c]) {
            dp[c] += dp[e.to];
        }
        ans += n * dp[c];
    }
    cout << ans << endl;

    return 0;
}