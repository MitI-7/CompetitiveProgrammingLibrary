#define PROBLEM "https://atcoder.jp/contests/abc223/tasks/abc223_g"

#include "library/cpp/Tree/ReRooting.hpp"
#include <iostream>

using namespace std;


template<typename T>
T merge(const T accum, const T t) {
    return {accum.first + t.first, accum.second + t.second};
}

template<typename T>
T add_node(const T accum, const int u) {
    // マッチングに使っていない子がいる
    if (accum.second >= 1) {
        return {accum.first + 1, 0};
    }
    return {accum.first, 1};
}

template<typename T, typename W>
T add_edge(const T t, Edge<W> e) {
    return t;
}

template<typename T>
T unit() {
    return {0, 0};
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    ReRooting<pair<int, int>, int, merge, add_node, add_edge, unit> rr(N);
    for (int i = 0; i < N - 1; ++i) {
        int U, V;
        cin >> U >> V;
        U--;
        V--;
        rr.add_undirected_edge(U, V);
    }
    rr.build();

    int ans = 0;
    for (int u = 0; u < N; ++u) {
        auto [a, b] = rr.query(u);
        ans += (b == 1);
    }
    cout << ans << endl;

    return 0;
}