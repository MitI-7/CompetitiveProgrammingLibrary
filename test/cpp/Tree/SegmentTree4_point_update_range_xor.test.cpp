#define PROBLEM "https://atcoder.jp/contests/abc185/tasks/abc185_f"

#include "library/cpp/Tree/SegmentTree.hpp"
#include <iostream>

using namespace std;


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    auto st = make_segment_tree_xor<long long>(N);
    for (int i = 0; i < N; ++i) {
        long long A;
        cin >> A;
        st.update(i, A);
    }

    for (int i = 0; i < Q; ++i) {
        int T, X, Y;
        cin >> T >> X >> Y;
        if (T == 1) {
            X--;
            st.update(X, st.access(X) ^ Y);
        } else {
            X--;
            Y--;
            cout << st.query(X, Y + 1) << endl;
        }
    }

    return 0;
}