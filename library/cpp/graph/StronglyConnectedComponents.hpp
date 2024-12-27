#pragma once
#include <cassert>
#include <set>
#include <unordered_set>
#include <vector>
#include "library/cpp/graph/Graph.hpp"

// 強連結成分分解(一意に定まりDAGになる)
class StronglyConnectedComponents {
public:
    int num_component = -1;

private:
    const int num_nodes;
    std::vector<std::vector<int>> graph;
    std::vector<std::vector<int>> rev_graph;
    std::vector<int> node_component; // 元のノード番号 -> コンポーネントのノード番号
    std::vector<std::unordered_set<int>> component_nodes; // コンポーネントのノード番号 -> 元のノードの集合

public:
    StronglyConnectedComponents(const int num_nodes) :
        num_nodes(num_nodes), graph(num_nodes), rev_graph(num_nodes), node_component(num_nodes) {}

    void add_directed_edge(const int from, const int to) {
        this->graph[from].emplace_back(to);
        this->rev_graph[to].emplace_back(from);
    }

    // ノードuがどのコンポーネントに所属するか
    [[nodiscard]] int get_component_no(const int u) const { return this->node_component[u]; }

    // コンポーネントnoに所属するノードのsetを返す
    // make_new_graph()を実行する必要がある
    [[nodiscard]] std::unordered_set<int> get_nodes(const int component_no) const {
        return this->component_nodes[component_no];
    }

    // O(|V| + |E|)
    // コンポーネント数を返す
    int build() {
        std::vector<int> vs; // 帰りがけ順の並び
        {
            std::vector<bool> used(this->num_nodes);
            for (int u = 0; u < this->num_nodes; ++u) {
                if (not used[u]) {
                    this->dfs(u, used, vs);
                }
            }
        }

        std::vector<bool> used(this->num_nodes);
        this->num_component = 0;
        for (int i = int(vs.size()) - 1; i >= 0; --i) {
            if (not used[vs[i]]) {
                this->rdfs(vs[i], this->num_component++, used);
            }
        }

        return this->num_component;
    }

    // 強連結成分をひとつのノードにまとめたグラフを返す
    // トポロジカル順
    Graph<int> make_new_graph() {
        Graph<int> dag(this->num_component);
        this->component_nodes.resize(this->num_component);

        std::set<std::pair<int, int>> used;

        for (int u = 0; u < this->num_nodes; ++u) {
            const int u_component_no = this->node_component[u];
            this->component_nodes[u_component_no].insert(u);

            for (const auto v : this->graph[u]) {
                const int v_component_no = this->node_component[v];
                this->component_nodes[v_component_no].insert(v);
                if (u_component_no == v_component_no) {
                    continue;
                }

                if (not used.contains({u_component_no, v_component_no})) {
                    assert(u_component_no < v_component_no);
                    dag.add_directed_edge(u_component_no, v_component_no);
                    used.insert({u_component_no, v_component_no});
                }
            }
        }

        return dag;
    }

private:
    void dfs(const int u, std::vector<bool>& used, std::vector<int>& vs) {
        used[u] = true;
        for (const int v : this->graph[u]) {
            if (not used[v]) {
                dfs(v, used, vs);
            }
        }
        vs.emplace_back(u);
    }

    void rdfs(const int v, const int component_no, std::vector<bool>& used) {
        used[v] = true;
        this->node_component[v] = component_no;
        for (const int u : this->rev_graph[v]) {
            if (not used[u]) {
                this->rdfs(u, component_no, used);
            }
        }
    }
};
