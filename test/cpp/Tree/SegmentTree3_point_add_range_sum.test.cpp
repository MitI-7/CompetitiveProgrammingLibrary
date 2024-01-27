#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

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
        long long A;
        cin >> A;
        st.update(i, A);
    }

    for (int i = 0; i < Q; ++i) {
        int T;
        cin >> T;
        if (T == 0) {
            int P, X;
            cin >> P >> X;
            st.update(P, st.access(P) + X);
        } else {
            int L, R;
            cin >> L >> R;
            cout << st.query(L, R) << endl;
        }
    }

    return 0;
}