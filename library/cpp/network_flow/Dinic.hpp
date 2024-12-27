#pragma once
#include <cassert>
#include <cmath>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <vector>

// capacity scaling + dinic
// O(EV log U)
template <typename T>
class Dinic {
public:
    struct Edge {
        const int from;
        const int to;
        T flow;
        const T cap;
        const int rev;

        Edge(const int from, const int to, const T flow, const T cap, const int rev) : from(from), to(to), flow(flow), cap(cap), rev(rev) {
            assert(this->cap >= 0);
        }

        T residual_capacity() const {
            return this->cap - this->flow;
        }

    };

    int num_nodes;
    int num_edges;
    std::vector<std::vector<Edge>> graph;
    std::vector<int> level;
    std::vector<int> current_edge;
    std::vector<std::pair<int, int>> edge_id_memo;

    Dinic() : num_nodes(0), num_edges(0) {}

    int add_node() {
        this->add_nodes(1);
        return this->num_nodes - 1;
    }

    std::vector<int> add_nodes(const int num) {
        std::vector<int> nodes(num);
        std::iota(nodes.begin(), nodes.end(), this->num_nodes);
        this->num_nodes += num;
        this->graph.resize(this->num_nodes);
        return nodes;
    }

    int add_directed_edge(const int from, const int to, const T cap) {
        assert(0 <= from and from < this->num_nodes and 0 <= to and to < this->num_nodes);
        assert(cap >= 0);
        this->graph[from].emplace_back(from, to, 0, cap, static_cast<int>(graph[to].size()));
        this->graph[to].emplace_back(to, from, cap, cap, static_cast<int>(graph[from].size()) - 1);
        this->edge_id_memo.emplace_back(from, static_cast<int>(this->graph[from].size()) - 1);
        return this->num_edges++;
    }

    Edge get_edge(const int edge_id) {
        const auto [u, i] = this->edge_id_memo[edge_id];
        return this->graph[u][i];
    }

    T solve(const int source, const int sink) {
        assert(source < this->num_nodes and sink < this->num_nodes);
        this->level.resize(this->num_nodes);
        this->current_edge.resize(this->num_nodes);

        T max_capacity = 0;
        for (int u = 0; u < this->num_nodes; ++u) {
            for (const auto& e : this->graph[u]) {
                max_capacity = std::max(max_capacity, e.cap);
            }
        }
        T delta = 1;
        while (delta <= max_capacity) {
            delta *= 2;
        }
        delta /= 2;

        T upper = 0;
        for (const auto& e : this->graph[source]) {
            upper += e.cap;
        }

        T flow = 0;
        while (delta > 0) {
            // solve maximum flow in delta-residual network
            while (true) {
                this->bfs(source, sink, delta);

                // no s-t path
                if (this->level[source] >= this->num_nodes) {
                    break;
                }

                fill(this->current_edge.begin(), this->current_edge.end(), 0);
                flow += dfs(source, sink, upper, delta);
            }
            delta /= 2;
        }

        return flow;
    }

    std::vector<bool> minimum_cut(const int source) {
        std::vector<bool> visited(this->num_nodes);
        std::queue<int> que;
        que.emplace(source);
        visited[source] = true;

        while (not que.empty()) {
            const auto u = que.front();
            que.pop();

            for (const auto& e : this->graph[u]) {
                if (not visited[e.to] and e.residual_capacity() != 0) {
                    visited[e.to] = true;
                    que.emplace(e.to);
                }
            }
        }

        return visited;
    }

private:
    void bfs(int source, int sink, T delta) {
        fill(this->level.begin(), this->level.end(), this->num_nodes);
        std::queue<int> que;
        this->level[sink] = 0;
        que.push(sink);
        while (not que.empty()) {
            auto v = que.front();
            que.pop();

            for (const auto& e : this->graph[v]) {
                // check e.to -> v
                if (e.flow >= delta and level[e.to] == this->num_nodes) {
                    this->level[e.to] = this->level[v] + 1;
                    if (e.to != source) {
                        que.push(e.to);
                    }
                }
            }
        }
    }

    T dfs(const int u, const int sink, T upper, T delta) {
        if (u == sink) {
            return upper;
        }

        T flow = 0;
        for (int& i = this->current_edge[u]; i < static_cast<int>(this->graph[u].size()); ++i) {
            auto& e = this->graph[u][i];
            const auto residual_capacity = e.residual_capacity();
            if (residual_capacity >= delta and this->level[u] > this->level[e.to]) {
                const auto d = dfs(e.to, sink, std::min(upper - flow, residual_capacity), delta);
                // update flow
                e.flow += d;
                this->graph[e.to][e.rev].flow -= d;

                flow += d;
                if (flow == upper or d == 0) {
                    return flow;
                }
            }
        }
        this->level[u] = this->num_nodes;

        return flow;
    }
};
