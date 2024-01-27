#define PROBLEM "https://atcoder.jp/contests/abc331/tasks/abc331_f"

#include "library/cpp/Tree/SegmentTree.hpp"
#include <iostream>

using namespace std;


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    SegmentTree<tuple<uint_fast64_t, long long, int>, rh_op, rh_unit> st1(N), st2(N);
    for (int i = 0; i < N; ++i) {
        st1.update(i, {S[i] - 'a', base, P});
        st2.update(i, {S[N - 1 - i] - 'a', base, P});
    }

    for (int i = 0; i < Q; ++i) {
        int T;
        cin >> T;
        if (T == 1) {
            int X;
            char C;
            cin >> X >> C;
            X--;
            C -= 'a';
            st1.update(X, {C, base, P});
            st2.update(N - 1 - X, {C, base, P});
        } else {
            int L, R;
            cin >> L >> R;
            L--;
            R--;
            auto [h0, x0, p0] = st1.query(L, R + 1);
            auto [h1, x1, p1] = st2.query(N - (R + 1), N - L);
            if (h0 == h1) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}