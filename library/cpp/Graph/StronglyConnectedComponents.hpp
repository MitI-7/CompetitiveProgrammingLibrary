#include <vector>
#include <set>
#include <unordered_set>


// 強連結成分分解(一意に定まりDAGになる)
class StronglyConnectedComponents {
public:
    int num_component = -1;

private:
    const int N;
    std::vector<std::vector<int>> graph;
    std::vector<std::vector<int>> rev_graph;
    std::vector<int> node_component;                       // 元のノード番号 -> コンポーネントのノード番号
    std::vector<std::unordered_set<int>> component_node;   // コンポーネントのノード番号 -> 元のノード番号

public:
    // N: 頂点数
    StronglyConnectedComponents(int N) : N(N) {
        this->graph.resize(N);
        this->rev_graph.resize(N);
        this->node_component.resize(N);
    }

    void add_directed_edge(const int from, const int to) {
        this->graph[from].push_back(to);
        this->rev_graph[to].push_back(from);
    }

    // ノードuがどのコンポーネントに所属するか
    int get_component_no(int u) const {
        return this->node_component[u];
    }

    // コンポーネントnoに所属するノードのsetを返す
    // make_new_graph()を実行する必要がある
    std::unordered_set<int> get_nodes(int component_no) const {
        return this->component_node[component_no];
    }

    // O(|V| + |E|)
    // コンポーネント数を返す
    int build() {
        std::vector<int> vs; // 帰りがけ順の並び
        {
            std::vector<bool> used(this->N);
            for (int u = 0; u < this->N; ++u) {
                if (not used[u]) {
                    this->dfs(u, used, vs);
                }
            }
        }

        std::vector<bool> used(N);
        this->num_component = 0;
        for (int i = int(vs.size()) - 1; i >= 0; --i) {
            if (not used[vs[i]]) {
                this->rdfs(vs[i], this->num_component++, used);
            }
        }

        this->component_node.resize(this->num_component);
        return this->num_component;
    }

    // 強連結成分をひとつのノードにまとめたグラフを返す
    std::vector<std::vector<int>> make_new_graph() {
        std::vector<std::vector<int>> new_graph(this->num_component);
        std::set<std::pair<int, int>> used;

        for (int u = 0; u < N; ++u) {
            for(auto v : this->graph[u]) {
                const int new_u = this->node_component[u];
                const int new_v = this->node_component[v];

                this->component_node[new_u].insert(u);
                this->component_node[new_v].insert(v);
                if (new_u == new_v) {
                    continue;
                }
                if (used.find(std::make_pair(new_u, new_v)) == used.end()) {
                    new_graph[new_u].emplace_back(new_v);
                    used.insert(std::make_pair(new_u, new_v));
                }
            }
        }

        return new_graph;
    }

private:
    void dfs(int u, std::vector<bool> &used, std::vector<int> &vs) {
        used[u] = true;
        for (int i = 0; i < (int)graph[u].size(); ++i) {
            if (not used[graph[u][i]]) {
                dfs(graph[u][i], used, vs);
            }
        }
        vs.emplace_back(u);
    }

    void rdfs(int v, int k, std::vector<bool> &used) {
        used[v] = true;
        this->node_component[v] = k;
        for (int i = 0; i < (int)rev_graph[v].size(); i++) {
            if (not used[rev_graph[v][i]]) {
                this->rdfs(rev_graph[v][i], k, used);
            }
        }
    }
};