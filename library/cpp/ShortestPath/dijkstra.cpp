#include <functional>
#include <limits>
#include <queue>
#include <vector>
#include "library/cpp/Graph/Graph.hpp"

/**
 * s からすべての頂点への最短距離と，各頂点に接続する最短距離となる辺を求める
 * O(|E| log |V|)
 * 到達できない場合は infinity を格納する
 * 負辺はないものとする
 */
template<typename T>
std::pair<std::vector<T>, std::vector<Edge<T>>> dijkstra(const int s, const Graph<T> &graph, const T infinity = std::numeric_limits<T>::max() / 3) {

    // [(最短距離, node番号)]のque (距離が近い順にとりだす)
    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<>> que;
    que.push({0, s});

    std::vector<Edge<T>> prev_edge(graph.num_nodes);       // 経路復元用
    std::vector<bool> seen(graph.num_nodes);
    std::vector<T> distance(graph.num_nodes, infinity);   // startからの距離
    distance[s] = 0;

    while (not que.empty()) {
        const auto [now_dist, u] = que.top();
        que.pop();
        if (seen[u]) {
            continue;
        }
        seen[u] = true;

        for (auto edge: graph.graph[u]) {
            const auto new_dist = now_dist + edge.w;
            if (new_dist < distance[edge.to]) {
                prev_edge[edge.to] = edge;
                distance[edge.to] = new_dist;
                que.push({new_dist, edge.to});
            }
        }
    }

    return {distance, prev_edge};
}