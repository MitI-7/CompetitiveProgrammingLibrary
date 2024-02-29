#define PROBLEM "https://atcoder.jp/contests/abc106/tasks/abc106_d"

#include "library/cpp/Tree/SegmentTree2D.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M, Q;
    cin >> N >> M >> Q;

    vector grid(N, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        int L, R;
        cin >> L >> R;
        grid[L - 1][R - 1]++;
    }

    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].first--;
        queries[i].second--;
    }

    auto st2d = make_segment_tree_2d_sum(grid);
    for (const auto &[p, q]: queries) {
        cout << st2d.query(p, p, q + 1, q + 1) << endl;
    }

    return 0;
}