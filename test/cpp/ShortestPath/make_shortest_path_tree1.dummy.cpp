#define PROBLEM "https://atcoder.jp/contests/abc252/tasks/abc252_e"

#include <iostream>
#include "library/cpp/ShortestPath/make_shortest_path_tree.cpp"

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    Graph<long long> graph(N);
    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        A--;
        B--;
        graph.add_undirected_edge(A, B, C, i + 1);
    }

    auto spt = make_shortest_path_tree(0, graph);

    for (int u = 0; u < N; ++u) {
        for (auto e: spt[u]) {
            cout << e.no << " ";
        }
    }
    cout << endl;

    return 0;
}