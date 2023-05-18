#include <algorithm>
#include <vector>
#include "library/cpp/Tree/UnionFind.hpp"


struct Edge {
    int from;
    int to;
    long long cost;
    int no;

    Edge() {}

    Edge(int from, int to, long long cost, int no = 0) : from(from), to(to), cost(cost), no(no) {}

    bool operator<(const Edge &edge) const {
        return this->cost < edge.cost;
    }

    bool operator>(const Edge &edge) const {
        return this->cost > edge.cost;
    }
};

// グラフの最小全域木を求める。O(|E| log|V|)
long long kruskal(int num_of_node, std::vector<Edge> &edges) {
    // コストの小さい順にソート
    sort(edges.begin(), edges.end());

    UnionFind uf(num_of_node);
    long long ans = 0;
    for (const auto e: edges) {
        if (!uf.is_same_set(e.from, e.to)) {
            uf.unite(e.from, e.to);
            ans += e.cost;
        }
    }

    return ans;
}