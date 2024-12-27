#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903"

#include "library/cpp/optimization/QPBO.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;

    vector<string> grid(H);
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }

    QPBO<long long> solver;
    vector vs(H, vector<int>(W));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (grid[y][x] == '#') {
                vs[y][x] = solver.add_variable();
            }
        }
    }

    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (grid[y][x] != '#') {
                continue;
            }
            solver.add_unary_cost(vs[y][x], 0, 1);
            solver.add_unary_cost(vs[y][x], 1, 1);

            // right
            if (x + 1 < W and grid[y][x + 1] == '#') {
                solver.add_pairwise_cost(vs[y][x], vs[y][x + 1], 0, 0, -1);
            }
            // down
            if (y + 1 < H and grid[y + 1][x] == '#') {
                solver.add_pairwise_cost(vs[y][x], vs[y + 1][x], 1, 1, -1);
            }
        }
    }

    cout << solver.solve() << endl;

    return 0;
}
