#define PROBLEM "https://atcoder.jp/contests/arc090/tasks/arc090_d"

#include "library/cpp/Tree/WeightedUnionFind.hpp"
#include <iostream>

using namespace std;


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    WeightedUnionFind<int> wuf(N);
    bool ok = true;
    for (int i = 0; i < M; ++i) {
        int L, R, D;
        cin >> L >> R >> D;
        L--;
        R--;

        ok &= wuf.unite(L, R, D);
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}