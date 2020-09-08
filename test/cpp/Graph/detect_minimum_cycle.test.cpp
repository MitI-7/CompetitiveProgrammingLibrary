#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"
#include "library/cpp/Graph/detect_minimum_cycle.cpp"

#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V);
    for (int i = 0; i < E; ++i) {
        int S, T;
        cin >> S >> T;
        graph[S].emplace_back(T);
    }

    for (int u = 0; u < V; ++u) {
        if (not detect_minimum_cycle(u, graph).empty()) {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    
    return 0;
}