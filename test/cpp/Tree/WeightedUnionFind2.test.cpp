#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B&lang=ja"

#include "library/cpp/Tree/WeightedUnionFind.hpp"
#include <iostream>

using namespace std;


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    WeightedUnionFind<long long> wuf(N);

    vector<int> ans;
    for (int i = 0; i < Q; ++i) {
        int T;
        cin >> T;
        if (T == 0) {
            int X, Y, Z;
            cin >> X >> Y >> Z;
            wuf.unite(X, Y, Z);
        } else {
            int X, Y;
            cin >> X >> Y;
            if (wuf.is_same_set(X, Y)) {
                cout << wuf.diff(X, Y) << endl;
            } else {
                cout << "?" << endl;
            }
        }
    }

    return 0;
}