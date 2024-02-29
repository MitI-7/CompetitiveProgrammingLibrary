#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068"

#include "library/cpp/Tree/SegmentTree2D.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while (true) {
        int H, W, Q;
        cin >> H >> W >> Q;
        if (H == 0 and W == 0 and Q == 0) {
            break;
        }

        vector grid(H, vector<long long>(W));
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                cin >> grid[y][x];
            }
        }

        auto st2d = make_segment_tree_2d_min(grid);
        for (int i = 0; i < Q; ++i) {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << st2d.query(y1, x1, y2 + 1, x2 + 1) << endl;
        }
    }
    
    return 0;
}