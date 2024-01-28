#define PROBLEM "https://atcoder.jp/contests/abc223/tasks/abc223_f"

#include "library/cpp/Tree/SegmentTree.hpp"
#include <iostream>

using namespace std;


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    string S;
    cin >> N >> Q;
    cin >> S;

    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; ++i) {
        if (S[i] == '(') {
            v[i] = parenthesis_left;
        } else {
            v[i] = parenthesis_right;
        }
    }

    SegmentTree<pair<int, int>, parenthesis_op, parenthesis_unit> st(N);
    for (int i = 0; i < N; ++i) {
        st.update(i, v[i]);
    }

    for (int i = 0; i < Q; ++i) {
        int T, L, R;
        cin >> T >> L >> R;
        L--;
        R--;
        if (T == 1) {
            swap(v[L], v[R]);
            st.update(L, v[L]);
            st.update(R, v[R]);
        } else {
            auto [t, m] = st.query(L, R + 1);
            if (t == 0 and m == 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}