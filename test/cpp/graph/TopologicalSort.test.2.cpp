#define PROBLEM "https://atcoder.jp/contests/abc291/tasks/abc291_e"

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
        int X, Y;
        cin >> X >> Y;
        X--;
        Y--;
        ts.add_directed_edge(X, Y);
    }

    if (ts.sort() and ts.longest_distance() == N - 1) {
        vector<int> ans(N);
        for (int i = 0; i < N; ++i) {
            ans[ts.result[i]] = i + 1;
        }
        cout << "Yes" << endl;
        for (int i = 0; i < N; ++i) {
            if (i != 0) {
                cout << " ";
            }
            cout << ans[i];
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}