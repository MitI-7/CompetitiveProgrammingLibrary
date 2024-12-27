#define PROBLEM "https://atcoder.jp/contests/abc245/tasks/abc245_f"

#include "library/cpp/graph/StronglyConnectedComponents.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    StronglyConnectedComponents scc(N);

    for (int i = 0; i < M; ++i) {
        int U, V;
        cin >> U >> V;
        U--;
        V--;
        scc.add_directed_edge(U, V);
    }

    const int num_component = scc.build();
    auto dag = scc.make_new_graph();

    int ans = 0;
    vector<bool> loop(num_component);
    for (int c = num_component - 1; c >= 0; --c) {
        const int num_nodes = (int) scc.get_nodes(c).size();
        if (num_nodes >= 2) {
            loop[c] = true;
        }

        for (const auto e: dag[c]) {
            if (loop[e.to]) {
                loop[c] = true;
            }
        }

        if (loop[c]) {
            ans += num_nodes;
        }
    }
    cout << ans << endl;

    return 0;
}