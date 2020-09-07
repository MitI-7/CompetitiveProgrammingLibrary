#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"
#include "library/cpp/Graph/StronglyConnectedComponents.hpp"

#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;

    StronglyConnectedComponents scc(V);
    for (int i = 0; i < E; ++i) {
        int S, T;
        cin >> S >> T;
        scc.add_directed_edge(S, T);
    }
    scc.build();

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int u, v;
        cin >> u >> v;
        if (scc.get_component_no(u) == scc.get_component_no(v)) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
    
    return 0;
}