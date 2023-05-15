#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include "library/cpp/ShortestPath/bellman_ford.cpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int V, E, R;
    cin >> V >> E >> R;

    Graph<long long> graph(V);
    for (int i = 0; i < E; ++i) {
        int S, T, D;
        cin >> S >> T >> D;
        graph.add_directed_edge(S, T, D);
    }

    const auto infinity = std::numeric_limits<long long>::max();
    const auto [distance, _] = bellman_ford(R, graph, infinity);

    if (distance.empty()) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (auto a: distance) {
            if (a == std::numeric_limits<long long>::max()) {
                cout << "INF" << endl;
            } else {
                cout << a << endl;
            }
        }
    }

    return 0;
}