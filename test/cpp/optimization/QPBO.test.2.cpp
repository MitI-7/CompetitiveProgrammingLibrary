#define PROBLEM "https://yukicoder.me/problems/no/2713"

#include "library/cpp/optimization/QPBO.hpp"
#include <iostream>

using namespace std;

const int INF = 1u << 30u; // 1,073,741,824

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<long long> A(N), B(M);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }

    vector<vector<long long>> C(M);
    for (int i = 0; i < M; ++i) {
        int K;
        cin >> K;
        for (int _ = 0; _ < K; ++_) {
            long long c;
            cin >> c;
            c--;
            C[i].emplace_back(c);
        }
    }

    QPBO<long long> solver;
    auto xs = solver.add_variables(N);
    auto ys = solver.add_variables(M);

    for (int i = 0; i < N; ++i) {
        solver.add_unary_1_cost(xs[i], A[i]);
    }
    for (int i = 0; i < M; ++i) {
        solver.add_unary_1_cost(ys[i], -B[i]);
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < static_cast<int>(C[i].size()); ++j) {
            solver.add_pairwise_01_cost(xs[C[i][j]], ys[i], INF);
        }
    }

    cout << -solver.solve() << endl;

    return 0;
}
