#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include "library/cpp/Tree/ReRooting.hpp"
#include <iostream>

using namespace std;


template<typename T>
T merge(const T accum, const T t) {
    return max(accum, t);
}

template<typename T>
T add_node(const T accum, const int u) {
    return accum;
}

template<typename T, typename W>
T add_edge(const T d, Edge<W> e) {
    return d + e.w;
}

template<typename T>
T unit() {
    return 0;
}

using namespace std;


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    ReRooting<int, int, merge, add_node, add_edge, unit> rr(N);
    for (int i = 0; i < N - 1; ++i) {
        int U, V, W;
        cin >> U >> V >> W;
        rr.add_undirected_edge(U, V, W);
    }
    rr.build();

    int ans = 0;
    for (int u = 0; u < N; ++u) {
        ans = max(ans, rr.query(u));
    }
    cout << ans << endl;

    return 0;
}