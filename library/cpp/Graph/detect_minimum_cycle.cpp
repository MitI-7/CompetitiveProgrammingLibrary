#include <vector>
#include <queue>


// sを含む最小の閉路を求める
std::vector<int> detect_minimum_cycle(const int s, const std::vector<std::vector<int>> &graph) {
    const int N = graph.size();
    const int infinit = 100000000;

    // sからの全頂点の距離を求める
    std::vector<int> dist(N, infinit);
    std::vector<int> pre(N, -1);
    std::queue<int> que;
    dist[s] = 0;
    que.push(s);
    while (not que.empty()) {
        int u = que.front(); que.pop();
        for (auto v : graph[u]) {

            if (dist[v] != infinit) {
                continue;
            }

            dist[v] = dist[u] + 1;
            pre[v] = u;
            que.push(v);
        }
    }

    int mini = -1;
    for (int u = 0; u < N; ++u) {
        if (u == s) {
            continue;
        }
        for (int v : graph[u]) {
            if (v == s) {
                if (mini == -1 or dist[mini] > dist[u]) {
                    mini = u;
                }
            }
        }
    }

    if (mini == -1 or dist[mini] == infinit) {
        return {};
    }

    int now = mini;
    std::vector<int> route;
    while (now != -1) {
        route.emplace_back(now);
        now = pre[now];
    }

    return route;
}