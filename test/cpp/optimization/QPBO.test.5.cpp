#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/UOA/UAPC/3058"

#include "library/cpp/optimization/QPBO.hpp"
#include <iostream>
#include <tuple>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    string U;
    cin >> U;

    QPBO<int> solver;
    auto xs = solver.add_variables(N);

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<tuple<int, int, int>> STB;
    for (int i = 0; i < M; ++i) {
        int S, T, B;
        cin >> S >> T >> B;
        S--;
        T--;
        if (S > T) {
            swap(S, T);
        }
        STB.emplace_back(S, T, B);
    }

    for (int i = 0; i < N; ++i) {
        if (U[i] == 'L') {
            solver.add_unary_cost(xs[i], 1, A[i]);
        }
        if (U[i] == 'R') {
            solver.add_unary_cost(xs[i], 0, A[i]);
        }
    }

    for (const auto& [S, T, B] : STB) {
        solver.add_pairwise_cost(xs[S], xs[T], 1, 0, B);
    }

    const auto ans = solver.solve();
    cout << ans << endl;

    // check labels
    {
        const auto labels = solver.get_labels();
        for (const auto label : labels) {
            assert(label != -1);
        }

        long long tmp = 0;
        for (int i = 0; i < N; ++i) {
            if ((U[i] == 'L' and labels[xs[i]] == 1) or (U[i] == 'R' and labels[xs[i]] == 0)) {
                tmp += A[i];
            }
        }

        for (const auto& [S, T, B] : STB) {
            if (labels[xs[S]] == 1 and labels[xs[T]] == 0) {
                tmp += B;
            }
        }
        assert(tmp == ans);
    }

    return 0;
}
