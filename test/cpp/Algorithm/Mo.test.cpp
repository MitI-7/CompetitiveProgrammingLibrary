#define PROBLEM "https://www.hackerrank.com/contests/university-codesprint-4/challenges/unique-art/problem"
#include "library/cpp/Algorithm/Mo.hpp"

#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    {
        unordered_map<int, int> m;
        int id = 0;
        for (int i = 0; i < N; ++i) {
            if (m.count(A[i]) == 0) {
                m[A[i]] = id++;
            }
            A[i] = m[A[i]];
        }
    }

    cin >> Q;

    Mo mo(N, Q);
    for(int i = 0; i < Q; ++i) {
        int L, R;
        cin >> L >> R;
        mo.add_query(i, L - 1, R);
    }
    mo.build();

    auto ans = mo.solve();
    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}