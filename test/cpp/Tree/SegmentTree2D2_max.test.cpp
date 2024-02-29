#define PROBLEM "https://atcoder.jp/contests/abc228/tasks/abc228_f"

#include "library/cpp/Tree/SegmentTree2D.hpp"
#include "library/cpp/DataStructure/CumulativeSum2D.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int H, W, H1, W1, H2, W2;
    cin >> H >> W >> H1 >> W1 >> H2 >> W2;
    H2 = min(H2, H1);
    W2 = min(W2, W1);

    vector A(H, vector<long long>(W));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            cin >> A[y][x];
        }
    }

    CumulativeSum2D<long long> cs(A);

    vector B(H, vector<long long>(W));
    for (int y = 0; y < H - H2 + 1; ++y) {
        for (int x = 0; x < W - W2 + 1; ++x) {
            B[y][x] = cs.sum(y, x, y + H2, x + W2);
        }
    }
    SegmentTree2D<long long, max_op, max_unit> st2d(B);

    long long ans = 0;
    for (int y = 0; y < H - H1 + 1; ++y) {
        for (int x = 0; x < W - W1 + 1; ++x) {
            const int y1 = y + H1;
            const int x1 = x + W1;

            const int y2 = y1 - H2 + 1;
            const int x2 = x1 - W2 + 1;

            ans = max(ans, cs.sum(y, x, y1, x1) - st2d.query(y, x, y2, x2));
        }
    }
    cout << ans << endl;

    return 0;
}