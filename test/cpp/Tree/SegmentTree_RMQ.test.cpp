#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"
#include "library/cpp/Tree/SegmentTree.hpp"

#include <iostream>
using namespace std;


// RangeMinimumQuery
int op(int a, int b) {
    return std::min(a, b);
}
int unit() {
    return (1ull << 31u) - 1;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    SegmentTree<int, op, unit> st(N);
    for (int i = 0; i < N; ++i) {
        st.update(i, (1ull << 31u) - 1);
    }

    for (int i = 0; i < Q; ++i) {
        int COM;
        cin >> COM;
        if (COM == 0) {
            int X, Y;
            cin >> X >> Y;
            st.update(X, Y);
        }
        else {
            int X, Y;
            cin >> X >> Y;
            cout << st.query(X, Y + 1) << endl;
        }
    }

    return 0;
}