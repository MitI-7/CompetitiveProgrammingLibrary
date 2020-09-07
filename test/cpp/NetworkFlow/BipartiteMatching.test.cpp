#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A"
#include "library/cpp/NetworkFlow/BipartiteMatching.hpp"

#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int X, Y, E;
    cin >> X >> Y >> E;

    BipartiteMatching bm(X + Y + 2);
    for (int i = 0; i < E; ++i) {
        int x, y;
        cin >> x >> y;
        bm.add_edge(x, X + y);
    }
    bm.solve();

    cout << bm.get_maximum_matching() << endl;

    return 0;
}