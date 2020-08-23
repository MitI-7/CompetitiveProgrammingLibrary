#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674"
#include "library/cpp/DataStructure/WaveletMatrix.hpp"

#include <iostream>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const long long BASE = 500000001;
    long long D, Q;

    cin >> D;
    vector<uint64_t> v(D);
    for (int i = 0; i < D; ++i) {
        long long x;
        cin >> x;
        assert(x + BASE >= 0);
        v[i] = x + BASE;
    }

    WaveletMatrix wm(v);

    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        long long l, r, e;
        cin >> l >> r >> e;
        l--; r--;
        long long a = min(v[l], v[r]);
        long long b = max(v[l], v[r]);
        long long ans = 0;
        assert(a - e >= 0);
        ans += wm.rankLessThan(a - e, 0, r + 1) - wm.rankLessThan(a - e, 0, l);
        ans += wm.rankMoreThan(b + e, 0, r + 1) - wm.rankMoreThan(b + e, 0, l);
        cout << ans << endl;
    }

    return 0;
}