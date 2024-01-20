#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"

#include "library/cpp/Math/prime_factor_decomposition.cpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    auto pfd = prime_factor_decomposition(N);
    cout << N << ":";
    for (const auto [p, n]: pfd) {
        for (int _ = 0; _ < n; ++_) {
            cout << " " << p;
        }
    }
    cout << endl;

    return 0;
}