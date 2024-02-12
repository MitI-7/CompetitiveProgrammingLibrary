#define PROBLEM "https://atcoder.jp/contests/abc218/tasks/abc218_g"

#include "library/cpp/DataStructure/DynamicMedian.hpp"
#include "library/cpp/Tree/Tree.hpp"
#include <iostream>

using namespace std;

vector<int> A;

int dfs(int u, int no, int p, DynamicMedian<int> &dm, Tree<int> &tree) {

    int ans = no % 2 == 0 ? 0 : 1000000100;
    dm.insert(A[u]);

    for (auto e: tree[u]) {
        if (e.to != p) {
            auto m = dfs(e.to, no + 1, u, dm, tree);
            ans = (no % 2 == 0) ? max(ans, m) : min(ans, m);
        }
    }

    // 葉
    if (ans == 0 or ans == 1000000100) {
        auto [a, b] = dm.find_median();
        ans = (a + b) / 2;
    }
    dm.erase(A[u]);

    return ans;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    Tree<int> tree(N);
    for (int i = 0; i < N - 1; ++i) {
        int U, V;
        cin >> U >> V;
        U--;
        V--;
        tree.add_undirected_edge(U, V);
    }

    DynamicMedian<int> dm;
    cout << dfs(0, 0, -1, dm, tree) << endl;

    return 0;
}
