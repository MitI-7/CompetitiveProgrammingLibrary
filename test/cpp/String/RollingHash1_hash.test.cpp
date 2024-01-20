#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=ja"

#include "library/cpp/String/RollingHash.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string T, P;
    cin >> T >> P;

    RollingHash rh_t(T);
    RollingHash rh_p(P);

    const auto p = rh_p.hash(0, int(P.size()));

    for (int left = 0; left < int(T.size() - P.size() + 1); ++left) {
        const auto right = left + int(P.size());
        if (rh_t.hash(left, right) == p) {
            cout << left << endl;
        }
    }

    return 0;
}