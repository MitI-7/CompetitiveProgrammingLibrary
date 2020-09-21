#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include "library/cpp/NetworkFlow/BipartiteMatching.hpp"

#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int L, R, M;
    cin >> L >> R >> M;

    BipartiteMatching mb(L + R);
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        mb.add_edge(A, L + B);
    }
    mb.solve();

    auto ans = mb.get_maximum_matching_edges();
    cout << ans.size() << endl;
    for (auto p : ans) {
        cout << p.first << " " << p.second - L << endl;
    }

    return 0;
}