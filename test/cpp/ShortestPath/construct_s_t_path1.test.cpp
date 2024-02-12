#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <iostream>
#include "library/cpp/ShortestPath/construct_s_t_path.cpp"
#include "library/cpp/ShortestPath/dijkstra.cpp"

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M, S, T;
    cin >> N >> M >> S >> T;

    Graph<long long> graph(N);
    for (int i = 0; i < M; ++i) {
        int A, B;
        long long C;
        cin >> A >> B >> C;
        graph.add_directed_edge(A, B, C, i);
    }

    const auto infinity = std::numeric_limits<long long>::max();
    auto [distance, prev] = dijkstra(S, graph, infinity);

    if (distance[T] == infinity) {
        cout << -1 << endl;
        return 0;
    }

    const auto path = construct_s_t_path(S, T, prev);

    cout << distance[T] << " " << path.size() << endl;
    for (const auto e: path) {
        cout << e.from << " " << e.to << endl;
    }

    return 0;
}