#include <cmath>
#include <vector>
#include <queue>
#include <cassert>


// 最大流問題を解く O(|E||V|^2)
class Dinic {
public:
    struct Edge {
        const unsigned int to;   // 行き先のノードid
        long long flow;          // 流量
        const long long cap;     // 容量
        const unsigned int rev;  // 逆辺のノードid
        const bool is_rev;       // 逆辺かどうか
        Edge(int to, long long flow, long long cap, int rev, bool is_rev) : to(to), flow(flow), cap(cap), rev(rev), is_rev(is_rev) {
            assert(this->cap >= 0);
        }
    };

    std::vector<std::vector<Edge>> graph; // グラフの隣接リスト表現
    std::vector<int> level;               // sからの距離
    std::vector<unsigned int> iter;       // どこまで調べ終わったか

    Dinic(unsigned int num_of_node) {
        assert(num_of_node > 0);
        this->graph.resize(num_of_node);
        this->level.resize(num_of_node);
        this->iter.resize(num_of_node);
    }

    // fromからtoへ向かう容量capの辺をグラフに追加する
    void add_edge(unsigned int from, unsigned int to, long long cap) {
        this->graph[from].emplace_back(Edge(to, 0, cap, (unsigned int)graph[to].size(), false));
        this->graph[to].emplace_back(Edge(from, cap, cap, (unsigned int)graph[from].size() - 1, true));
    }

    // sからtへの最大流を求める
    long long max_flow(unsigned int s, unsigned int t) {
        long long flow = 0;
        while (true) {
            this->bfs(s);
            if (this->level[t] < 0) {
                return flow;
            }
            fill(this->iter.begin(), this->iter.end(), 0);
            long long f;

            while ((f = dfs(s, t, 10000000000ll)) > 0) {
                flow += f;
            }
        }
    }

private:
    // sからの最短距離をBFSで計算する
    void bfs(unsigned int s) {
        fill(this->level.begin(), this->level.end(), -1);
        std::queue<unsigned int> que;
        this->level[s] = 0;
        que.push(s);
        while (not que.empty()) {
            unsigned int v = que.front();
            que.pop();
            for (int i = 0; i < (int)this->graph[v].size(); ++i) {
                Edge &e = this->graph[v][i];
                if ((e.cap - e.flow) > 0 and level[e.to] < 0) {
                    this->level[e.to] = this->level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    // 増加パスをDFSで探す
    long long dfs(unsigned int v, unsigned int t, long long f) {
        if (v == t) {
            return f;
        }
        for (unsigned int &i = this->iter[v]; i < this->graph[v].size(); ++i) {
            Edge &e = this->graph[v][i];
            if ((e.cap - e.flow) > 0 and this->level[v] < this->level[e.to]) {
                long long d = dfs(e.to, t, std::min(f, e.cap - e.flow));
                if (d > 0) {
                    e.flow += d;
                    this->graph[e.to][e.rev].flow -= d;
                    return d;
                }
            }
        }

        return 0;
    }
};