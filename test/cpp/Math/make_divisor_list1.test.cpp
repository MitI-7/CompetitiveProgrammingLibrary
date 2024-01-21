#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D"

#include "library/cpp/Math/make_divisor_list.cpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    long long A, B, C;
    cin >> A >> B >> C;

    auto divisor_list = make_divisor_list(C);
    int ans = 0;
    for (const auto d: divisor_list) {
        ans += (A <= d and d <= B);
    }
    cout << ans << endl;

    return 0;
}