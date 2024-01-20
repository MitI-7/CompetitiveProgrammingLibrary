#define PROBLEM "https://atcoder.jp/contests/abc172/tasks/abc172_d"

#include "library/cpp/Math/make_divisor_count_list.cpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    auto divisor_count_list = make_divisor_count_list(N);
    long long ans = 0;
    for (long long k = 1; k <= N; ++k) {
        ans += k * divisor_count_list[k];
    }
    cout << ans << endl;

    return 0;
}