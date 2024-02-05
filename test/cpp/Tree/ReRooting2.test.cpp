#define PROBLEM "https://atcoder.jp/contests/dp/tasks/dp_v"

#include "library/cpp/Tree/ReRooting.hpp"
#include <iostream>

using namespace std;


int M;

template<typename T>
T merge(const T accum, const T t) {
    return (accum * t) % M;
}

template<typename T>
T add_node(const T accum, const int u) {
    return accum + 1;
}

template<typename T, typename W>
T add_edge(const T d, Edge<W> e) {
    return d;
}

template<typename T>
T unit() {
    return 1;
}

using namespace std;


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N >> M;

    ReRooting<long long, int, merge, add_node, add_edge, unit> rr(N);
    for (int i = 0; i < N - 1; ++i) {
        int U, V;
        cin >> U >> V;
        U--;
        V--;
        rr.add_undirected_edge(U, V);
    }
    rr.build();

    for (int u = 0; u < N; ++u) {
        cout << rr.query(u) - 1 << endl;
    }

    return 0;
}