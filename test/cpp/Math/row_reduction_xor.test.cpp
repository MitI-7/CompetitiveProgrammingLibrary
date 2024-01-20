#define PROBLEM "https://atcoder.jp/contests/abc141/tasks/abc141_f"

#include "library/cpp/Math/row_reduction_xor.cpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    bitset<60> S = 0;
    vector<bitset<60>> A(N);
    for (int i = 0; i < N; ++i) {
        unsigned long long a;
        cin >> a;
        A[i] = a;
        S ^= A[i];
    }

    for (int i = 0; i < N; ++i) {
        A[i] &= ~S;
    }

    row_reduction_xor(A);

    bitset<60> a_and_b = 0;
    for (int i = 0; i < N; ++i) {
        a_and_b ^= A[i];
    }
    cout << S.to_ullong() + 2 * a_and_b.to_ullong() << endl;
    
    return 0;
}