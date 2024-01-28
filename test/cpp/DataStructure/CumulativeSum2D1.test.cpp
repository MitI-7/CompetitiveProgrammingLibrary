#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560"

#include "library/cpp/DataStructure/CumulativeSum2D.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int M, N, K;
    cin >> M >> N >> K;

    vector<vector<int>> J(M, vector<int>(N)), O(M, vector<int>(N)), I(M, vector<int>(N));
    for (int y = 0; y < M; ++y) {
        string S;
        cin >> S;
        for (int x = 0; x < N; ++x) {
            if (S[x] == 'J') {
                J[y][x] = 1;
            } else if (S[x] == 'O') {
                O[y][x] = 1;
            } else {
                I[y][x] = 1;
            }
        }
    }

    CumulativeSum2D cs_j(J), cs_o(O), cs_i(I);
    for (int i = 0; i < K; ++i) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        A--;
        B--;
        cout << cs_j.sum(A, B, C, D) << " " << cs_o.sum(A, B, C, D) << " " << cs_i.sum(A, B, C, D) << endl;
    }

    return 0;
}
