#define PROBLEM "https://atcoder.jp/contests/abc220/tasks/abc220_f"

#include "library/cpp/Tree/ReRooting.hpp"
#include <iostream>

using namespace std;

template<typename T>
T merge(const T accum, const T t) {
    const auto [d0, c0] = accum;    // [dis(i, j)の合計，子供の数]
    const auto [d1, c1] = t;
    return {d0 + d1, c0 + c1};
}

template<typename T>
T add_node(const T accum, const int u) {
    return {accum.first + accum.second, accum.second + 1};
}

template<typename T, typename W>
T add_edge(const T d, Edge<W> e) {
    return d;
}

template<typename T>
T unit() {
    return {0, 0};
}

using namespace std;


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    ReRooting<pair<long long, long long>, int, merge, add_node, add_edge, unit> rr(N);
    for (int i = 0; i < N - 1; ++i) {
        int U, V;
        cin >> U >> V;
        U--;
        V--;
        rr.add_undirected_edge(U, V);
    }
    rr.build();

    for (int u = 0; u < N; ++u) {
        auto p = rr.query(u);
        cout << p.first << endl;
    }

    return 0;
}