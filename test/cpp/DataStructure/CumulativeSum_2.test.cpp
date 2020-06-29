#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560"
#include "library/cpp/DataStructure/CumulativeSum.hpp"

#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int M, N, K;
    cin >> M >> N;
    cin >> K;

    vector<vector<long long>> J(M, vector<long long>(N));
    vector<vector<long long>> O(M, vector<long long>(N));
    vector<vector<long long>> I(M, vector<long long>(N));
    for(int y = 0; y < M; ++y) {
        string S;
        cin >> S;
        for(int x = 0; x < N; ++x) {
            if (S[x] == 'J') {
                J[y][x] = 1;
            } else if (S[x] == 'O') {
                O[y][x] = 1;
            } else {
                I[y][x] = 1;
            }
        }
    }


    CumulativeSum<long long> cs_j(J);
    CumulativeSum<long long> cs_o(O);
    CumulativeSum<long long> cs_i(I);

    for(int i = 0; i < K; ++i) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        A--;
        B--;
        cout << cs_j.sum(A, B, C, D) << " " << cs_o.sum(A, B, C, D) << " " << cs_i.sum(A, B, C, D) << endl;
    }

    return 0;
}
