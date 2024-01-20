#define PROBLEM "https://atcoder.jp/contests/abc334/tasks/abc334_e"

#include "library/cpp/Tree/RollbackUnionFind.hpp"
#include "library/cpp/Utility/mint.hpp"
#include <iostream>

using namespace std;
const int MOD = 998244353;

inline bool inside(long long y, long long x, long long H, long long W) { return 0 <= y and y < H and 0 <= x and x < W; }

const std::vector<int> dy8 = {0, 1, 0, -1, -1, 1, 1, -1};
const std::vector<int> dx8 = {1, 0, -1, 0, 1, 1, -1, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for (int y = 0; y < H; ++y) {
        cin >> grid[y];
    }

    RollbackUnionFind ruf(H * W);
    int num_red = 0;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {

            if (grid[y][x] == '.') {
                num_red++;
                continue;
            }

            for (int i = 0; i < 4; ++i) {
                int ny = dy8[i] + y;
                int nx = dx8[i] + x;

                if (inside(ny, nx, H, W) and grid[ny][nx] == '#') {
                    ruf.unite(y * W + x, ny * W + nx);
                }
            }
        }
    }
    ruf.snapshot();

    mint<MOD> ans;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (grid[y][x] == '#') {
                continue;
            }

            for (int i = 0; i < 4; ++i) {
                int ny = dy8[i] + y;
                int nx = dx8[i] + x;

                if (inside(ny, nx, H, W) and grid[ny][nx] == '#') {
                    ruf.unite(y * W + x, ny * W + nx);
                }
            }

            ans += ruf.set_size - (num_red - 1);

            ruf.rollback();
        }
    }
    cout << ans / num_red << endl;

    return 0;
}