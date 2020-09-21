#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "library/cpp/Tree/Tree.hpp"

#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    Tree tree(N);
    for (int i = 0; i < N - 1; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        tree.add_undirected_edge(A, B, C);
    }
    tree.build1(0);
    tree.build2(0);

    int u, v;
    long long d;
    tie(u, v, d) = tree.diameter();
    auto route = tree.route(u, v);

    cout << d << " " << route.size() << endl;
    for (int i = 0; i < int(route.size()) - 1; ++i) {
        cout << route[i] << " ";
    }
    cout << route.back() << endl;

    return 0;
}