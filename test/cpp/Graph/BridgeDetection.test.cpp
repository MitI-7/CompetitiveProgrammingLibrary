#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"
#include "library/cpp/Graph/BridgeDetection.hpp"

#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;

    BridgeDetection bd(V);
    for (int i = 0; i < E; ++i) {
        int S, T;
        cin >> S >> T;
        bd.add_undirected_edge(S, T);
    }
    bd.build();

    for (auto p : bd.bridge_set) {
        cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}