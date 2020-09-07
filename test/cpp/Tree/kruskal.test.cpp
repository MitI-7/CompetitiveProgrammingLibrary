#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include "library/cpp/Tree/kruskal.cpp"

#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;

    vector<Edge> edges;
    for (int i = 0; i < E; ++i) {
        int s, t, w;
        cin >> s >> t >> w;
        edges.emplace_back(Edge(s, t, w));
        edges.emplace_back(Edge(t, s, w));
    }

    cout << kruskal(V, edges) << endl;

    return 0;
}