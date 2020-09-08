#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"
#include "library/cpp/Tree/LazySegmentTree.hpp"

#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    const auto query = LazySegmentTree<long long>::RangeMinimumQuery;
    const auto operation = LazySegmentTree<long long>::Add;
    const auto mode = LazySegmentTree<long long>::getMode(query, operation);

    vector<long long> v(N, 0);
    LazySegmentTree<long long> lst(v, mode);
    for (int i = 0; i < Q; ++i) {
        int TYPE;
        cin >> TYPE;
        if (TYPE == 0) {
            int S, T, X;
            cin >> S >> T >> X;
            lst.operation(S, T + 1, X);
        }
        else {
            int S, T;
            cin >> S >> T;
            cout << lst.query(S, T + 1) << endl;
        }
    }

    return 0;
}