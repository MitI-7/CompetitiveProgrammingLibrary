#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"
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
    for (int i = 0; i < N; ++i) {
        int K;
        cin >> K;

        for (int j = 0; j < K; ++j) {
            int C;
            cin >> C;
            tree.add_directed_edge(i, C, 1);
        }
    }
    tree.build1(0);
    tree.build2(0);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int U, V;
        cin >> U >> V;

        cout << tree.lca(U, V) << endl;
    }

    return 0;
}