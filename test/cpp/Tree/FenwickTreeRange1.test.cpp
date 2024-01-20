#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=ja"

#include "library/cpp/Tree/FenwickTreeRange.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    FenwickTreeRange<int> ftr(N);
    for (int _ = 0; _ < Q; ++_) {
        int QUERY, S, T, X, I;
        cin >> QUERY;
        if (QUERY == 0) {
            cin >> S >> T >> X;
            S--;
            T--;
            ftr.add(S, T + 1, X);
        } else {
            cin >> I;
            I--;
            cout << ftr.access(I) << endl;
        }
    }

    return 0;
}