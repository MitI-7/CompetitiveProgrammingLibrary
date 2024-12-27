#define PROBLEM "https://atcoder.jp/contests/abc223/tasks/abc223_d"

#include "library/cpp/graph/TopologicalSort.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    TopologicalSort ts(N);

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        ts.add_directed_edge(A - 1, B - 1);
    }

    if (ts.sort()) {
        auto ans = ts.result;
        for (int i = 0; i < N; ++i) {
            if (i != 0) {
                cout << " ";
            }
            cout << ts.result[i] + 1;
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}