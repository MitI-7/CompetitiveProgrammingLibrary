#define PROBLEM "https://atcoder.jp/contests/abc296/tasks/abc296_e"

#include "library/cpp/Graph/FunctionalGraph.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    FunctionalGraph<int> fg(N);
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        fg.add_directed_edge(i, A - 1);
    }
    fg.build();

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += fg.in_cycle[i];
    }
    cout << ans << endl;

    return 0;
}