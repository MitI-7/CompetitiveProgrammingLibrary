#define PROBLEM "https://atcoder.jp/contests/abc193/tasks/abc193_f"

#include "library/cpp/optimization/QPBO.hpp"
#include <cassert>
#include <iostream>

using namespace std;

const int INF = 1u << 30u; // 1,073,741,824
const std::vector<int> dy8 = {0, 1, 0, -1, -1, 1, 1, -1}, dx8 = {1, 0, -1, 0, 1, 1, -1, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<string> grid(N);
    for (int y = 0; y < N; ++y) {
        cin >> grid[y];
    }

    QPBO<long long> solver;
    vector xs(N, vector(N, 0));
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            xs[y][x] = solver.add_variable();
        }
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            const int p = y * N + x;
            if (grid[y][x] == 'W') {
                solver.add_unary_cost(p, 1, INF);
            }
            else if (grid[y][x] == 'B') {
                solver.add_unary_cost(p, 0, INF);
            }
        }
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            const int p1 = y * N + x;

            for (int i = 0; i < 4; ++i) {
                const int ny = dy8[i] + y;
                const int nx = dx8[i] + x;
                if (0 <= ny and ny < N and 0 <= nx and nx < N) {
                    const int p2 = ny * N + nx;
                    solver.add_pairwise_cost(p1, p2, 0, 1, -1);
                    solver.add_pairwise_cost(p1, p2, 1, 0, -1);
                }
            }
        }
    }
    const auto ans = -solver.solve() / 2;
    cout << ans << endl;

    // check labels
    {
        const auto labels = solver.get_labels();
        for (const auto label : labels) {
            assert(label != -1);
        }

        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < N; ++x) {
                if (grid[y][x] == '?') {
                    assert(labels[xs[y][x]] != -1);
                    grid[y][x] = labels[xs[y][x]] == 0 ? 'W' : 'B';
                }
            }
        }

        int tmp = 0;
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < N; ++x) {
                tmp += x + 1 < N and grid[y][x] != grid[y][x + 1];
                tmp += y + 1 < N and grid[y][x] != grid[y + 1][x];
            }
        }
        assert(tmp == ans);
    }

    return 0;
}
