#define PROBLEM "https://atcoder.jp/contests/abc237/tasks/abc237_g"

#include "library/cpp/Tree/LazySegmentTree_template.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q, X;
    cin >> N >> Q >> X;

    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    for (int i = 0; i < N; ++i) {
        if (P[i] == X) {
            P[i] = 1;
        } else if (P[i] < X) {
            P[i] = 0;
        } else {
            P[i] = 2;
        }
    }

    auto lst = make_range_sum_query_range_update_operation(P);

    for (int i = 0; i < Q; ++i) {
        int C, L, R;
        cin >> C >> L >> R;
        L--;

        auto sum = lst.query(L, R);
        const int num = R - L;
        int num_1 = 0;

        if (sum % 2 == 1) {
            num_1 = 1;
            sum--;
        }

        const int num_2 = sum / 2;
        const int num_0 = num - num_1 - num_2;

        if (C == 1) {
            lst.operation(L, L + num_0, 0);
            lst.operation(L + num_0, L + num_0 + num_1, 1);
            lst.operation(L + num_0 + num_1, L + num_0 + num_1 + num_2, 2);
        } else {
            lst.operation(L, L + num_2, 2);
            lst.operation(L + num_2, L + num_2 + num_1, 1);
            lst.operation(L + num_2 + num_1, L + num_2 + num_1 + num_0, 0);
        }
    }

    for (int i = 0; i < N; ++i) {
        if (lst.access(i) == 1) {
            cout << i + 1 << endl;
        }
    }

    return 0;
}
