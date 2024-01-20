#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"

#include "library/cpp/Math/pow_mod.cpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    long long M, N;
    cin >> M >> N;

    cout << pow_mod(M, N, 1000000007) << endl;

    return 0;
}