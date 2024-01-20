#define PROBLEM "https://atcoder.jp/contests/abc174/tasks/abc174_f"

#include "library/cpp/Algorithm/Mo.hpp"
#include <iostream>

using namespace std;

std::vector<int> A;
std::vector<int> color;

// A[idx]が追加されたときの操作
template<class T>
T add(const int idx, T query_ans) {
    color[A[idx]]++;
    query_ans += (color[A[idx]] == 1);
    return query_ans;
}

// A[idx]が削除されたときの操作
template<class T>
T del(const int idx, T query_ans) {
    color[A[idx]]--;
    query_ans -= (color[A[idx]] == 0);
    return query_ans;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    A.resize(N);
    color.resize(500100);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    Mo<long long, add, del> mo(N, Q);
    for (int i = 0; i < Q; ++i) {
        int L, R;
        cin >> L >> R;
        L--;
        mo.add_query(i, L, R);
    }

    auto ans = mo.solve();
    for (auto a: ans) {
        cout << a << endl;
    }

    return 0;
}