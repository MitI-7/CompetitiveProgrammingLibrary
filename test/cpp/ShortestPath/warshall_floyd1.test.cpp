#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"

#include "library/cpp/ShortestPath/warshall_floyd.cpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;

    const auto infinity = std::numeric_limits<long long>::max();
    vector<vector<long long>> matrix(V, vector<long long>(V, infinity));
    for (int i = 0; i < E; ++i) {
        int S, T, D;
        cin >> S >> T >> D;
        matrix[S][T] = D;
    }

    auto ans = warshall_floyd(matrix, infinity);

    if (ans.empty()) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (j != 0) {
                    cout << " ";
                }

                if (ans[i][j] == infinity) {
                    cout << "INF";
                } else {
                    cout << ans[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}