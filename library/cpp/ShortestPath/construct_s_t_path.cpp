#include "library/cpp/Graph/Graph.hpp"

// 経路復元
// s-t 経路がない場合は空を返す
// prev: prev[u] = u へたどる辺
// O(M)
template<typename T>
std::vector<Edge<T>> construct_s_t_path(const int s, const int t, const std::vector<Edge<T>> &prev) {
    std::vector<Edge<T>> path;
    int now = t;
    while (now != s) {
        path.emplace_back(prev[now]);
        now = prev[now].from;
        if (now == -1) {
            return {};
        }
    }
    std::reverse(path.begin(), path.end());

    return path;
}