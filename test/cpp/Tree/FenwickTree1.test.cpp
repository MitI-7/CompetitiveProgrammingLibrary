#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=ja"

#include "library/cpp/Tree/FenwickTree.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    FenwickTree<int> ft(N);
    for (int i = 0; i < Q; ++i) {
        int COM, X, Y;
        cin >> COM >> X >> Y;
        if (COM == 0) {
            X--;
            ft.add(X, Y);
        } else {
            X--;
            Y--;
            cout << ft.sum(X, Y + 1) << endl;
        }
    }

    return 0;
}