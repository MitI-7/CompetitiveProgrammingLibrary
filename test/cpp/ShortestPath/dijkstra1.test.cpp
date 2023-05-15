#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include <iostream>
#include "library/cpp/ShortestPath/dijkstra.cpp"

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M, R;
    cin >> N >> M >> R;

    Graph<long long> graph(N);
    for (int i = 0; i < M; ++i) {
        int A, B;
        long long C;
        cin >> A >> B >> C;
        graph.add_directed_edge(A, B, C, i);
    }

    const auto infinity = std::numeric_limits<long long>::max();
    auto [distance, _] = dijkstra(R, graph, infinity);

    for (int u = 0; u < N; ++u) {
        if (distance[u] == infinity) {
            cout << "INF" << endl;
        } else {
            cout << distance[u] << endl;
        }
    }

    return 0;
}