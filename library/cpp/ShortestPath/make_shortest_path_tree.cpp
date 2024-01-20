#include "library/cpp/Graph/Graph.hpp"
#include "library/cpp/ShortestPath/dijkstra.cpp"

// startを根とする最短路木をつくる
// 最短路木は有向木になることに注意
template<typename T>
Graph<T> make_shortest_path_tree(const int start, Graph<T> &graph) {

    const auto [_, prev] = dijkstra(start, graph);

    Graph<T> shortest_path_tree(graph.num_nodes);
    for (auto e: prev) {
        if (e.no != -1) {
            shortest_path_tree.add_directed_edge(e.from, e.to, e.w, e.no);
        }
    }

    return shortest_path_tree;
}