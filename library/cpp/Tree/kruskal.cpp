#include <algorithm>
#include <vector>
#include "library/cpp/Tree/UnionFind.hpp"


struct Edge {
    int no;
    int from;
    int to;
    long long cost;
    Edge() {}
    Edge(int from, int to, long long cost) : from(from), to(to), cost(cost) {}
    Edge(int no, int from, int to, long long cost) : no(no), from(from), to(to), cost(cost) {}
    bool operator<(const Edge& edge) const {
        return this->cost < edge.cost;
    }
    bool operator>(const Edge& edge) const {
        return this->cost > edge.cost;
    }
};

// グラフの最小全域木を求める。O(|E| log|V|)
long long kruskal(int num_of_node, std::vector<Edge> &edges) {
    sort(edges.begin(), edges.end());

    UnionFind uf(num_of_node);
    long long ans = 0;
    for (const auto e : edges) {
        if (!uf.is_same_set(e.from, e.to)) {
            uf.union_set(e.from, e.to);
            ans += e.cost;
        }
    }

    return ans;
}