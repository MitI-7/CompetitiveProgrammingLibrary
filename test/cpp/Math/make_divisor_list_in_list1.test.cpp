#define PROBLEM "https://atcoder.jp/contests/abc215/tasks/abc215_d"

#include "library/cpp/Math/make_divisor_list_in_list.cpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    const auto divisor_list = make_divisor_list_in_list(A, 100001);

    vector<bool> ok(100001, true);
    for (const auto d: divisor_list) {
        if (d == 1) {
            continue;
        }
        for (int i = d; i <= M; i += d) {
            ok[i] = false;
        }
    }

    vector<int> ans;
    for (int i = 1; i <= M; ++i) {
        if (ok[i]) {
            ans.emplace_back(i);
        }
    }

    cout << ans.size() << endl;
    for (const auto a: ans) {
        cout << a << endl;
    }

    return 0;
}