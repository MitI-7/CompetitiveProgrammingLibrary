#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=ja"

#include "library/cpp/Tree/FenwickTreeRange.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    FenwickTreeRange<long long> ftr(N);
    for (int _ = 0; _ < Q; ++_) {
        int QUERY, S, T, X;
        cin >> QUERY >> S >> T;
        S--;
        T--;
        if (QUERY == 0) {
            cin >> X;
            ftr.add(S, T + 1, X);
        } else {
            cout << ftr.sum(S, T + 1) << endl;
        }
    }

    return 0;
}