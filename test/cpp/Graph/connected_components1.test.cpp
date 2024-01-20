#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D&lang=ja"

#include <iostream>
#include "library/cpp/Graph/connected_components.cpp"

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

    auto color = connected_components(graph);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int S, T;
        cin >> S >> T;
        if (color[S] == color[T]) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }

    return 0;
}