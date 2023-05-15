#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "library/cpp/Tree/UnionFind.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);
    for (int i = 0; i < Q; ++i) {
        int T, U, V;
        cin >> T >> U >> V;
        if (T == 0) {
            uf.unite(U, V);
        } else {
            cout << uf.is_same_set(U, V) << endl;
        }
    }

    return 0;
}