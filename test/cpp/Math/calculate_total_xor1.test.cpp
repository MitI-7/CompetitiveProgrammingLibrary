#define PROBLEM "https://atcoder.jp/contests/abc121/tasks/abc121_d"

#include "library/cpp/Math/calculate_total_xor.cpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    long long A, B;
    cin >> A >> B;

    cout << (calculate_total_xor(B) ^ calculate_total_xor(A) ^ A) << endl;

    return 0;
}