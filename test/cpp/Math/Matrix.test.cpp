#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
#include "library/cpp/Math/Matrix.hpp"

#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    const int MOD = 998244353;

    int N;
    cin >> N;

    Matrix matrix(N, N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix.matrix[i][j];
        }
    }

    cout << matrix.determinant_mod(MOD) << endl;

    return 0;
}