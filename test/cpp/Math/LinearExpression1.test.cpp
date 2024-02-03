#define PROBLEM "https://atcoder.jp/contests/abc133/tasks/abc133_d"

#include "library/cpp/Math/LinearExpression.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<LinearExpression<long long>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].b;
    }

    vector<LinearExpression<long long>> ans(N + 1);
    ans[0] = LinearExpression<long long>(1, 0);
    for (int i = 0; i < N; ++i) {
        ans[i + 1] = A[i] * 2 - ans[i];
    }
    // ans[0] == ans[N] == x
    const auto x = ans[N].find_x(ans[0]);

    for (int i = 0; i < N; ++i) {
        if (i != 0) {
            cout << " ";
        }
        cout << ans[i].evaluate(x);
    }
    cout << endl;

    return 0;
}