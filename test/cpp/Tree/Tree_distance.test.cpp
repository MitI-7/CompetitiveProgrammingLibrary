#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B"
#include "library/cpp/Tree/Tree.hpp"

#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    Tree tree(N);
    for (int i = 0; i < N - 1; ++i) {
        int S, T, W;
        cin >> S >> T >> W;

        tree.add_undirected_edge(S, T, W);
    }
    tree.build1(0);
    tree.build2(0);

    int d1, d2;
    long long d;
    tie(d1, d2, d) = tree.diameter();

    for (int u = 0; u < N; ++u) {
        long long ans = 0;
        ans = max(ans, tree.distance(u, d1));
        ans = max(ans, tree.distance(u, d2));

        cout << ans << endl;
    }

    return 0;
}