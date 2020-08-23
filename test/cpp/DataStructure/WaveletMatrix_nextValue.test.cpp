#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549"
#include "library/cpp/DataStructure/WaveletMatrix.hpp"

#include <iostream>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N;
    vector<uint64_t> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    WaveletMatrix wm(A);

    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        uint64_t L, R, D;
        cin >> L >> R >> D;
        R++;

        uint64_t ans = 1000100;
        // T[begin_pos, end_pos)でx <= c < yを満たす最大のcを返す
        auto a1 = wm.prevValue(L, R, 0, D);
        if (a1 != NOTFOUND) {
            ans = min(ans, D - a1);
        }
        // T[begin_pos, end_pos)でx <= c < yを満たす最小のcを返す
        auto a2 = wm.nextValue(L, R, D, 1000100);
        if (a2 != NOTFOUND) {
            ans = min(ans, a2 - D);
        }

        cout << ans << endl;
    }

    return 0;
}
