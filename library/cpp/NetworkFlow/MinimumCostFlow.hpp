#include <cassert>
#include <vector>
#include <queue>
#include <climits>


class MinimumCostFlow {
    struct Edge {
        const unsigned int to;    // 行き先のノードid
        long long flow;           // 流量
        const long long cap;      // 容量
        const long long cost;     // コスト
        const unsigned int rev;   // 逆辺のノードid
        const bool is_rev;        // 逆辺かどうか
        Edge(unsigned int to, long long flow, long long cap, long long cost, unsigned int rev, bool is_rev) : to(to), flow(flow), cap(cap), cost(cost), rev(rev), is_rev(is_rev) {
            assert(this->cap >= 0);
        }
    };

    const int num_node;                   // 頂点数
    std::vector<std::vector<Edge>> graph; // グラフの隣接リスト表現
    bool have_negative_cost = false;      // 負辺があるか

public:
    MinimumCostFlow(int num_node) : num_node(num_node) {
        this->graph.resize(num_node);
    }

    // fromからtoへ向かう容量cap、コストcostの辺をグラフに追加する
    void add_edge(unsigned int from, unsigned int to, long long cap, long long cost) {
        this->graph[from].emplace_back(Edge(to, 0, cap, cost, graph[to].size(), false));
        this->graph[to].emplace_back(Edge(from, cap, cap, -cost, graph[from].size() - 1, true));
        this->have_negative_cost |= cost < 0;
    }

    // sからtへの流量fの最小費用流を求める
    // 流せない場合はfalseを返す
    bool run(const int source, const int sink, long long flow) {

        // 負閉路がある場合、先に負閉路にそって流しておく
        // 負辺があっても負閉路ない場合はこの処理をskipしていい
        if (this->have_negative_cost) {
            remove_negative_cycles(source);
        }

        std::vector<int> prev_v(this->num_node, -1), prev_e(this->num_node, -1); // 直前の頂点と辺のidx
        std::vector<long long> potential(this->num_node, 0);                          // ポテンシャル

        // 負の辺がある場合、ポテンシャルをベルマンフォードで求めておく
        // 負の辺がない場合はこの処理をskipしていい
        if (this->have_negative_cost) {
            potential.assign(this->num_node, INT_MAX);
            potential[source] = 0;
            while (true) {
                bool updated = false;
                for (int v = 0; v < this->num_node; ++v) {
                    for (auto &e : this->graph[v]) {
                        if (e.cap - e.flow > 0) {
                            if (potential[v] == INT_MAX) {
                                continue;
                            }
                            if (potential[e.to] > potential[v] + e.cost) {
                                potential[e.to] = potential[v] + e.cost;
                                updated = true;
                            }
                        }
                    }
                }
                if (not updated) {
                    break;
                }
            }
        }

        while (flow > 0) {
            // ダイクストラ法を用いてポテンシャルを更新する
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;
            std::vector<long long> distance(this->num_node, LONG_LONG_MAX);      // 最短距離

            distance[source] = 0;
            que.push(std::make_pair(0, source));
            while (not que.empty()) {
                std::pair<int, int> p = que.top(); // firstは最短距離、secondは頂点の番号
                que.pop();
                int v = p.second;
                if (distance[v] < p.first) {
                    continue;
                }
                for (int i = 0; i < (int)this->graph[v].size(); ++i) {
                    Edge &e = this->graph[v][i];
                    if (e.cap - e.flow > 0 and
                        distance[e.to] > distance[v] + e.cost + potential[v] - potential[e.to]) {
                        distance[e.to] = distance[v] + e.cost + potential[v] - potential[e.to];
                        prev_v[e.to] = v;
                        prev_e[e.to] = i;
                        que.push(std::make_pair(distance[e.to], e.to));
                    }
                }
            }

            // これ以上流せない
            if (distance[sink] == LONG_LONG_MAX) {
                return false;
            }
            for (int v = 0; v < this->num_node; ++v) {
                potential[v] += distance[v];
            }

            // source-sink間で流せる量を求める
            long long d = flow;
            for (int v = sink; v != source; v = prev_v[v]) {
                auto &e = this->graph[prev_v[v]][prev_e[v]];
                d = std::min(d, e.cap - e.flow);
            }

            flow -= d;
            for (int v = sink; v != source; v = prev_v[v]) {
                Edge &e = this->graph[prev_v[v]][prev_e[v]];
                e.flow += d;
                this->graph[v][e.rev].flow -= d;
            }
        }
        return true;
    }

    // 最小費用を取得する
    long long minimum_cost_flow() {
        long long cost = 0;
        for (int u = 0; u < (int)this->graph.size(); ++u) {
            for (int i = 0; i < (int)this->graph[u].size(); ++i) {
                const Edge &e = this->graph[u][i];
                if (not e.is_rev) {
                    cost += e.flow * e.cost;
                }
            }
        }
        return cost;
    }

private:
    // 負閉路を除去する
    void remove_negative_cycles(const unsigned int source) {
        while (true) {
            // bellman-fordでsourceからの最短路を求める
            std::vector<int> prev_v(this->num_node, -1), prev_e(this->num_node, -1); // 直前の頂点と辺のidx
            std::vector<long long> distance(this->num_node, LONG_LONG_MAX);
            distance[source] = 0;

            int negative_cycle_idx = -1;
            for (int num = 0; num < this->num_node; ++num) {
                for (int u = 0; u < (int)graph.size(); ++u) {
                    for (int i = 0; i < (int)graph[u].size(); ++i) {
                        Edge &e = this->graph[u][i];

                        if (distance[u] == LONG_LONG_MAX) {
                            continue;
                        }

                        long long new_dist = distance[u] + e.cost;
                        if (e.cap - e.flow > 0 and distance[e.to] > new_dist) {
                            distance[e.to] = new_dist;
                            prev_v[e.to] = u;
                            prev_e[e.to] = i;

                            if (num == num_node - 1) {
                                negative_cycle_idx = e.to;
                            }
                        }
                    }
                }
            }

            // 負閉路がない
            if (negative_cycle_idx == -1) {
                return;
            }

            long long d = LONG_LONG_MAX;
            std::vector<bool> used(this->num_node, false);
            int u = negative_cycle_idx;
            while (not used[u]) {
                used[u] = true;
                const Edge &e = this->graph[prev_v[u]][prev_e[u]];
                d = std::min(d, e.cap - e.flow);
                u = prev_v[u];
            }

            assert(d != 0);

            std::fill(used.begin(), used.end(), false);
            // 閉路の開始点から見ていく
            while (not used[u]) {
                used[u] = true;
                Edge &e = graph[prev_v[u]][prev_e[u]];
                e.flow += d;
                this->graph[e.to][e.rev].flow -= d;
                u = prev_v[u];
            }
        }
    }
};