#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include "library/cpp/network_flow/Dinic.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;

    Dinic<int> dinic;
    const auto nodes = dinic.add_nodes(V);
    for (int i = 0; i < E; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        dinic.add_directed_edge(nodes[u], nodes[v], c);
    }
    cout << dinic.solve(0, V - 1) << endl;

    return 0;
}
