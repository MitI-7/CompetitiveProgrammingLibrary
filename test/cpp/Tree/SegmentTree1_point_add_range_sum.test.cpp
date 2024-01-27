#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include "library/cpp/Tree/SegmentTree.hpp"
#include <iostream>

using namespace std;


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    auto st = make_segment_tree_sum<long long>(N);
    for (int i = 0; i < N; ++i) {
        st.update(i, 0);
    }

    for (int i = 0; i < Q; ++i) {
        int COM, X, Y;
        cin >> COM >> X >> Y;
        if (COM == 0) {
            X--;
            st.update(X, Y + st.access(X));
        } else {
            X--;
            Y--;
            cout << st.query(X, Y + 1) << endl;
        }
    }

    return 0;
}