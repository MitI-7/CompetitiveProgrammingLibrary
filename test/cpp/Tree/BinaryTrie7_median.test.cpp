#define PROBLEM "https://atcoder.jp/contests/abc218/tasks/abc218_g"

#include "library/cpp/Tree/BinaryTrie.hpp"
#include "library/cpp/Tree/Tree.hpp"
#include <iostream>

using namespace std;

vector<int> A;

int dfs(int u, int no, int p, BinaryTrie<unsigned int, 32> &bt, Tree<int> &tree) {

    int ans = no % 2 == 0 ? 0 : 1000000100;
    bt.insert(A[u]);

    for (auto e: tree[u]) {
        if (e.to != p) {
            auto m = dfs(e.to, no + 1, u, bt, tree);
            ans = (no % 2 == 0) ? max(ans, m) : min(ans, m);
        }
    }

    // 葉
    if (ans == 0 or ans == 1000000100) {
        const auto [a, b] = bt.find_median();
        ans = (a + b) / 2;
    }
    bt.erase(A[u]);

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

    BinaryTrie<unsigned int, 32> bt;
    cout << dfs(0, 0, -1, bt, tree) << endl;

    return 0;
}
