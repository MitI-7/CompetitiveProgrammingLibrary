#define PROBLEM "https://judge.yosupo.jp/problem/scc"

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
        int A, B;
        cin >> A >> B;
        scc.add_directed_edge(A, B);
    }
    scc.build();
    scc.make_new_graph();

    cout << scc.num_component << endl;
    for (int c = 0; c < scc.num_component; ++c) {
        auto s = scc.get_nodes(c);
        int num = (int) s.size();
        cout << num << " ";
        for (int u: s) {
            num--;
            cout << u;
            if (num > 0) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}