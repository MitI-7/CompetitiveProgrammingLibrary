#define PROBLEM "https://atcoder.jp/contests/abc222/tasks/abc222_f"

#include "library/cpp/Tree/ReRooting.hpp"
#include <iostream>

using namespace std;

vector<long long> D;

// 累積 accum と t を結合する関数
// （子供達の結合のみ考慮し，親に結合するときのことは考えないことに注意）
template<typename T>
T merge(const T accum, const T t) {
    return max(accum, t);
}

// 子供達の結果と頂点 u を結合する関数
template<typename T>
T add_node(const T accum, const int u) {
    return accum;
}

// 結果 t に 辺 e を影響させる
template<typename T, typename W>
T add_edge(const T t, Edge<W> e) {
    return max(t + e.w, D[e.to] + e.w);
}

// 単位元
template<typename T>
T unit() {
    return 0;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    ReRooting<long long, long long, merge, add_node, add_edge, unit> rr(N);
    for (int i = 0; i < N - 1; ++i) {
        int A, B;
        long long C;
        cin >> A >> B >> C;
        A--;
        B--;
        rr.add_undirected_edge(A, B, C);
    }

    D.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
    }

    rr.build();
    for (int u = 0; u < N; ++u) {
        cout << rr.query(u) << endl;
    }

    return 0;
}