#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"
#include "library/cpp/Tree/UnionFind.hpp"

#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    UnionFind uf(n);
    for (int i = 0; i < q; ++i) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            uf.union_set(x, y);
        }
        else {
            cout << uf.is_same_set(x, y) << endl;
        }

    }

    return 0;
}