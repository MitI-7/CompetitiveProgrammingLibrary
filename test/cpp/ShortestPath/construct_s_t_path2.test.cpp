#define PROBLEM "https://atcoder.jp/contests/abc218/tasks/abc218_f"

#include "library/cpp/ShortestPath/construct_s_t_path.cpp"
#include "library/cpp/ShortestPath/dijkstra.cpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    Graph<int> graph(N);
    for (int i = 0; i < M; ++i) {
        int S, T;
        cin >> S >> T;
        S--;
        T--;
        graph.add_directed_edge(S, T, 1, i);
    }

    const auto infinity = 1000;
    const auto [dist, prev] = dijkstra(0, graph, infinity);

    const auto path = construct_s_t_path(0, N - 1, prev);

    vector<int> ans(M, dist[N - 1]);
    for (auto &edge: path) {
        auto [u, i] = graph.no_edge[edge.no];
        graph.graph[u][i].w = infinity;

        auto [d, _] = dijkstra(0, graph, infinity);

        ans[edge.no] = d[N - 1];
        graph.graph[u][i].w = edge.w;
    }

    for (auto a: ans) {
        if (a >= infinity) {
            a = -1;
        }
        cout << a << endl;
    }

    return 0;
}