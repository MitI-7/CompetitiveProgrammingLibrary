#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A"
#include "library/cpp/Algorithm/Imos.hpp"

#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, T;
    cin >> N >> T;

    Imos imos(T + 100);
    for (int i = 0; i < N; ++i) {
        int L, R;
        cin >> L >> R;
        imos.add(L, R);
    }
    imos.build();

    int ans = 0;
    for (int i = 0; i <= T; ++i) {
        ans = max(ans, imos.line[i]);
    }
    cout << ans << endl;

    return 0;
}