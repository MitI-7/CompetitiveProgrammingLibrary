#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D"
#include "library/cpp/Math/get_divisor.cpp"

#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    long long A, B, C;
    cin >> A >> B >> C;

    auto divisors = get_divisor(C);
    long long ans = 0;
    for (int d : divisors) {
        ans += (A <= d and d <= B);
    }

    cout << ans << endl;

    return 0;
}