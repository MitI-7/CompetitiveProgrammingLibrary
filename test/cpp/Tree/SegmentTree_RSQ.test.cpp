#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
#include "library/cpp/Tree/SegmentTree.hpp"

#include <iostream>
using namespace std;


// RangeSummationQuery
int op(int a, int b) {
    return a + b;
}
int unit() {
    return 0;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    SegmentTree<int, op, unit> st(N);
    for (int i = 0; i < N; ++i) {
        st.update(i, 0);
    }

    for (int i = 0; i < Q; ++i) {
        int COM;
        cin >> COM;
        if (COM == 0) {
            int X, Y;
            cin >> X >> Y;
            X--;
            st.update(X, st.access(X) + Y);
        }
        else {
            int X, Y;
            cin >> X >> Y;
            X--; Y--;
            cout << st.query(X, Y + 1) << endl;
        }
    }

    return 0;
}