#pragma once
#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

class TopologicalSort {
    const int num_nodes;
    std::vector<std::vector<int>> graph;

public:
    std::vector<int> result; // ソート結果（結果が複数ある場合は辞書順で最小のもの）

    explicit TopologicalSort(const int num_nodes) : num_nodes(num_nodes), graph(num_nodes) {}

    void add_directed_edge(const int u, const int v) {
        assert(u != v);
        this->graph[u].emplace_back(v);
    }

    // O(m + n log n)
    // sort ができたら true を返す
    bool sort() {
        // すべてのノードの入次数を算出
        std::vector<int> in_degree(this->num_nodes);
        for (int u = 0; u < this->num_nodes; ++u) {
            for (int v : this->graph[u]) {
                in_degree[v]++;
            }
        }

        std::priority_queue<int, std::vector<int>, std::greater<>> que;
        std::vector<bool> used(this->num_nodes);
        for (int u = 0; u < this->num_nodes; ++u) {
            if (in_degree[u] == 0) {
                que.push(u);
                used[u] = true;
            }
        }

        while (not que.empty()) {
            const int u = que.top();
            que.pop();
            this->result.emplace_back(u);

            for (int v : this->graph[u]) {
                in_degree[v]--;
                if (in_degree[v] == 0 and not used[v]) {
                    used[v] = true;
                    que.push(v);
                }
            }
        }

        return static_cast<int>(this->result.size()) == this->num_nodes;
    }

    // グラフの有向パスのうち最長のものの長さ
    // ソート結果が一意なら返り値はN - 1になり，元のグラフはハミルトン路を含むグラフである
    [[nodiscard]] int longest_distance() const {
        int ans = 0;
        std::vector distance(this->num_nodes, 0);
        for (const int u : this->result) {
            for (const int v : this->graph[u]) {
                distance[v] = std::max(distance[v], distance[u] + 1);
                ans = std::max(ans, distance[v]);
            }
        }

        return ans;
    }
};
