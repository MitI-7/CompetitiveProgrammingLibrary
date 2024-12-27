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
    const auto xs = solver.add_variables(N);
    const auto ys = solver.add_variables(M);

    for (int i = 0; i < N; ++i) {
        solver.add_unary_cost(xs[i], 1, A[i]);
    }
    for (int j = 0; j < M; ++j) {
        solver.add_unary_cost(ys[j], 1, -B[j]);
    }

    for (int j = 0; j < M; ++j) {
        for (const auto i : C[j]) {
            solver.add_pairwise_cost(xs[i], ys[j], 0, 1, INF);
        }
    }
    const auto ans = -solver.solve();
    cout << ans << endl;

    // check labels
    {
        long long tmp = 0;
        const auto labels = solver.get_labels();
        for (const auto label : labels) {
            assert(label != -1);
            // cout << "la:" << label << endl;
        }

        for (int i = 0; i < N; ++i) {
            if (labels[xs[i]] == 1) {
                tmp -= A[i];
            }
        }

        for (int j = 0; j < M; ++j) {
            bool ok = true;
            for (const auto i : C[j]) {
                ok &= labels[xs[i]] == 1;
            }
            if (ok) {
                assert(labels[ys[j]] == 1);
                tmp += B[j];
            }
        }
        assert(tmp == ans);
    }

    return 0;
}
