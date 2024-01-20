#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C"

#include "library/cpp/Math/is_prime.cpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int X;
        cin >> X;
        ans += is_prime(X);
    }
    cout << ans << endl;

    return 0;
}