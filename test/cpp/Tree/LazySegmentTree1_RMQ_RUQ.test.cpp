#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include "library/cpp/Tree/LazySegmentTree_template.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    auto lst = make_range_minimum_query_range_update_operation(N, (1ull << 31u) - 1);
    for (int i = 0; i < Q; ++i) {
        int TYPE;
        cin >> TYPE;
        if (TYPE == 0) {
            int S, T, X;
            cin >> S >> T >> X;
            lst.operation(S, T + 1, X);
        } else {
            int S, T;
            cin >> S >> T;
            cout << lst.query(S, T + 1) << endl;
        }
    }

    return 0;
}