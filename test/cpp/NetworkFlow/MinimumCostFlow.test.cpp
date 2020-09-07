#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"
#include "library/cpp/NetworkFlow/MinimumCostFlow.hpp"

#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int V, E, F;
    cin >> V >> E >> F;
    MinimumCostFlow mcf(V);
    for (int i = 0; i < E; i++) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        mcf.add_edge(u, v, c, d);
    }

    bool ok = mcf.run(0, V - 1, F);
    if (not ok) {
        cout << -1 << endl;
    }
    else {
        cout << mcf.minimum_cost_flow() << endl;
    }

    return 0;
}