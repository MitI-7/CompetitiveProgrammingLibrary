#include <vector>
#include <functional>
#include <limits>
#include "library/cpp/Graph/Graph.hpp"

/**
 * startから他のすべてのnodeへの最短距離(到達できないnodeはinf)をもとめる
 * 負の閉路がある場合は空を返す
 * startから到達できないような負の閉路は無視されるが、目的地に到達できない負の閉路がある場合も空になることに注意
 * 目的地に到達できない負の閉路を無視したい場合は，目的地に到達できないようなノードに入る辺を除去しておけばいい
 * O(|V||E|)
 */
template<typename T>
std::pair<std::vector<T>, std::vector<Edge<T>>> bellman_ford(const int start, Graph<T> &graph, const T infinity = std::numeric_limits<T>::max() / 3) {
    const int num_nodes = graph.num_nodes;
    std::vector<T> distance(num_nodes, infinity);
    distance[start] = 0;
    std::vector<Edge<T>> prev_edge(graph.num_nodes);       // 経路復元用

    int i;
    for (i = 0; i < num_nodes; ++i) {
        bool update = false;
        for (int u = 0; u < num_nodes; ++u) {
            for (const auto &edge: graph[u]) {
                if (distance[u] != infinity and distance[edge.to] > distance[u] + edge.w) {
                    distance[edge.to] = distance[u] + edge.w;
                    prev_edge[edge.to] = edge;
                    update = true;
                }
            }
        }
        if (not update) {
            break;
        }
    }

    if (i == num_nodes) {
        return {{},
                {}};
    } else {
        return {distance, prev_edge};
    }
}