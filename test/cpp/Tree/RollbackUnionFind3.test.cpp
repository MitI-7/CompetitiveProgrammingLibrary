#define PROBLEM "https://atcoder.jp/contests/abc264/tasks/abc264_e"

#include "library/cpp/Tree/RollbackUnionFind.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M, E;
    cin >> N >> M >> E;

    vector<pair<int, int>> vec(E);
    for (int i = 0; i < E; ++i) {
        int U, V;
        cin >> U >> V;
        U--;
        V--;
        U = min(U, N);
        V = min(V, N);
        vec[i] = {U, V};
    }

    int Q;
    cin >> Q;
    vector<int> X(Q);
    vector<bool> exist(E, true);    // 電線が切断されるかどうか
    for (int i = 0; i < Q; ++i) {
        cin >> X[i];
        X[i]--;
        exist[X[i]] = false;
    }

    RollbackUnionFind ruf(N + 1);
    // 切断されない電線をつなげておく
    for (int i = 0; i < E; ++i) {
        if (exist[i]) {
            auto [u, v] = vec[i];
            ruf.unite(u, v);
        }
    }

    reverse(X.begin(), X.end());
    for (auto x: X) {
        auto [u, v] = vec[x];
        ruf.unite(u, v);
    }

    for (int i = 0; i < Q; ++i) {
        ruf.undo();
        cout << ruf.size(N) - 1 << endl;
    }
    
    return 0;
}