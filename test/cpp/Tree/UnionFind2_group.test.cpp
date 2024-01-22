#define PROBLEM "https://atcoder.jp/contests/abc256/tasks/abc256_e"

#include "library/cpp/Tree/UnionFind.hpp"
#include <iostream>
#include <tuple>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> X(N), C(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
        X[i]--;
    }
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }

    vector<tuple<int, int, int>> c_u_v;
    for (int i = 0; i < N; ++i) {
        c_u_v.emplace_back(C[i], i, X[i]);
    }
    sort(c_u_v.rbegin(), c_u_v.rend());

    long long ans = 0;
    UnionFind uf(N);
    for (auto [c, u, v]: c_u_v) {
        if (not uf.unite(u, v)) {
            ans += c;
        }
    }
    cout << ans << endl;

    return 0;
}