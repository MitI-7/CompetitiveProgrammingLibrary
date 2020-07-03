#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D"
#include "library/cpp/Math/Matrix.hpp"

#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, L;
    cin >> N >> M >> L;

    Matrix a(N, M), b(M, L);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> a.matrix[i][j];
        }
    }
    for(int i = 0; i < M; ++i) {
        for (int j = 0; j < L; ++j) {
            cin >> b.matrix[i][j];
        }
    }

    a.multiple(b);
    a.show();

    return 0;
}