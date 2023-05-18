#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include "library/cpp/Graph/kruskal.cpp"

#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;

    vector<Edge> edges;
    for (int i = 0; i < E; ++i) {
        int s, t, w;
        cin >> s >> t >> w;
        edges.emplace_back(s, t, w);
    }

    cout << kruskal(V, edges) << endl;

    return 0;
}