#define PROBLEM "https://atcoder.jp/contests/abc259/tasks/abc259_g"

#include "library/cpp/optimization/QPBO.hpp"
#include <iostream>

using namespace std;

const int INF = 1u << 30u; // 1,073,741,824

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector A(H, vector<int>(W));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            cin >> A[y][x];
        }
    }

    QPBO<long long> solver;
    const auto ys = solver.add_variables(H);
    const auto xs = solver.add_variables(W);

    for (int y = 0; y < H; ++y) {
        long long total = 0;
        for (int x = 0; x < W; ++x) {
            total += A[y][x];
        }
        solver.add_unary_cost(ys[y], 1, -total);
    }
    for (int x = 0; x < W; ++x) {
        long long total = 0;
        for (int y = 0; y < H; ++y) {
            total += A[y][x];
        }
        solver.add_unary_cost(xs[x], 1, -total);
    }

    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (A[y][x] < 0) {
                solver.add_pairwise_cost(ys[y], xs[x], 1, 1, INF);
            }
            else {
                solver.add_pairwise_cost(ys[y], xs[x], 1, 1, A[y][x]);
            }
        }
    }

    const auto ans = -solver.solve();
    cout << ans << endl;

    // check labels
    {
        const auto labels = solver.get_labels();
        for (const auto label : labels) {
            assert(label != -1);
        }

        long long tmp = 0;
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                if (labels[ys[y]] == 1 or labels[xs[x]] == 1) {
                    tmp += A[y][x];
                }
                if (labels[ys[y]] == 1 and labels[xs[x]] == 1) {
                    assert(A[y][x] >= 0);
                }
            }
        }
        assert(tmp == ans);
    }

    return 0;
}
