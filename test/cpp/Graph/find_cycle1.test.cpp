#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection_undirected"

#include <iostream>
#include "library/cpp/Graph/find_cycle.cpp"

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    Graph<int> graph(N);
    for (int i = 0; i < M; ++i) {
        int U, V;
        cin >> U >> V;
        graph.add_undirected_edge(U, V, 0, i);
    }

    auto cycle = find_cycle(graph);

    if (cycle.empty()) {
        cout << -1 << endl;
        return 0;
    }

    cout << cycle.size() << endl;
    for (auto e: cycle) {
        cout << e.from << " ";
    }
    cout << endl;
    for (auto e: cycle) {
        cout << e.no << " ";
    }
    cout << endl;
    
    return 0;
}