#include <set>
#include "library/cpp/NetworkFlow/Dinic.hpp"


// 2部グラフ上での最大マッチング
class BipartiteMatching {
    int n;
    Dinic dinic;
    std::set<unsigned int> left_nodes;
    std::set<unsigned int> right_nodes;

    long long maximum_matching = 0;

public:
    // n: leftとrightの両方をあわせたノードの数
    BipartiteMatching(unsigned int n) : n(n), dinic(n + 2) {}

    void add_edge(unsigned int left, unsigned int right) {
        this->left_nodes.insert(left);
        this->right_nodes.insert(right);
        this->dinic.add_edge(left, right, 1);
    }

    void solve() {
        const int source = this->n;
        const int sink = source + 1;

        // sourceからleftにエッジをはる
        for (auto left : this->left_nodes) {
            this->dinic.add_edge(source, left, 1);
        }

        // rightからsinkにエッジをはる
        for (auto right : this->right_nodes) {
            this->dinic.add_edge(right, sink, 1);
        }

        this->maximum_matching = this->dinic.max_flow(source, sink);
    }

    // 最大マッチング
    long long get_maximum_matching() {
        return maximum_matching;
    }

    // 最大安定集合のサイズ
    long long get_maximum_independent_set() {
        return this->n - this->maximum_matching;
    }
};
