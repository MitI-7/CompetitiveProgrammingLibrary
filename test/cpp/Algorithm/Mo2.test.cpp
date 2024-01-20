#define PROBLEM "https://atcoder.jp/contests/abc293/tasks/abc293_g"

#include "library/cpp/Algorithm/Mo.hpp"
#include <iostream>

long long comb(long long n) {
    return n * (n - 1) * (n - 2) / 6;
}

// 問題特有のデータ
std::vector<int> A;
std::vector<int> count;

// A[idx] が追加されたときの状態の変化と答えを計算
template<class T>
T add(const int idx, T query_ans) {
    query_ans -= comb(count[A[idx]]);
    count[A[idx]]++;
    query_ans += comb(count[A[idx]]);
    return query_ans;
}

// A[idx] が削除されたときの状態の変化と答えを計算
template<class T>
T del(const int idx, T query_ans) {
    query_ans -= comb(count[A[idx]]);
    count[A[idx]]--;
    query_ans += comb(count[A[idx]]);
    return query_ans;
}

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    A.resize(N);
    ::count.resize(200100);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    Mo<long long, add, del> mo(N, Q);
    for (int i = 0; i < Q; ++i) {
        int L, R;
        cin >> L >> R;
        L--;
        R--;
        mo.add_query(i, L, R + 1);
    }

    auto ans = mo.solve();
    for (const auto a: ans) {
        cout << a << endl;
    }

    return 0;
}