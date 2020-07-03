#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
#include "library/cpp/tree/FenwickTree.hpp"

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    FenwickTree ft(N + 2);

    for(int i = 0; i < Q; ++i) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            ft.add(x, y);
        }
        else {
            cout << ft.sum(x, y + 1) << endl;
        }
    }

    return 0;
}