#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"

#include "library/cpp/Math/inversion_number.cpp"
#include "library/cpp/Compression/CoordinateCompression.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    CoordinateCompression cc;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        cc.add(A[i]);
    }

    for (int i = 0; i < N; ++i) {
        A[i] = cc.zip(A[i]);
    }

    cout << inversion_number(A) << endl;

    return 0;
}