#include "library/cpp/Graph/Graph.hpp"

// u から到達できるノードを色 c で塗る
template<typename T>
void coloring(const int u, const int c, std::vector<int> &color, Graph<T> &graph) {
    color[u] = c;
    for (const auto &edge: graph[u]) {
        if (color[edge.to] == -1) {
            coloring(edge.to, c, color, graph);
        }
    }
}

// 無向グラフの連結成分ごとに色を塗る
template<typename T>
std::vector<int> connected_components(Graph<T> &graph) {
    std::vector<int> color(graph.num_nodes, -1);
    int c = 0;
    for (int u = 0; u < graph.num_nodes; ++u) {
        if (color[u] == -1) {
            coloring(u, c, color, graph);
            c++;
        }
    }

    return color;
}