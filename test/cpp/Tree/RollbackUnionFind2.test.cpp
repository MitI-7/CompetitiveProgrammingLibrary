#define PROBLEM "https://atcoder.jp/contests/abc120/tasks/abc120_d"

#include "library/cpp/Tree/RollbackUnionFind.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> vec(M);
    for (int i = 0; i < M; ++i) {
        cin >> vec[i].first >> vec[i].second;
        vec[i].first--;
        vec[i].second--;
    }
    reverse(vec.begin(), vec.end());

    RollbackUnionFind ruf(N);
    for (auto [u, v]: vec) {
        ruf.unite(u, v);
    }

    long long ans = 0;
    for (int i = 0; i < M; ++i) {
        auto [u, v] = ruf.undo();
        if (not ruf.is_same_set(u, v)) {
            ans += ruf.size(u) * ruf.size(v);
        }
        cout << ans << endl;
    }

    return 0;
}