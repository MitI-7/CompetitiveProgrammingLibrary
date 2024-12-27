#pragma once
#include <array>
#include <cassert>
#include <map>
#include <numeric>
#include <vector>
#include "library/cpp/graph/StronglyConnectedComponents.hpp"
#include "library/cpp/network_flow/Dinic.hpp"

// Quadratic pseudo-Boolean optimization
// Reference: Minimizing Nonsubmodular Functions: A Review, DOI: 10.1109/TPAMI.2007.1031
// 関数が劣モジュラのとき最適解を求めることができる
template <class COST>
class QPBO {
    int num_variables;
    std::vector<std::array<COST, 2>> unary_costs;
    std::map<std::pair<int, int>, std::array<COST, 4>> pair_wise_costs;
    Dinic<COST> dinic;
    std::vector<int> labels;
    std::vector<int> xs, ys;
    int source, sink;

public:
    QPBO() : num_variables(0), source(-1), sink(-1) {}

    int add_variable() {
        this->add_variables(1);
        return this->num_variables - 1;
    }

    std::vector<int> add_variables(const int num) {
        std::vector<int> nodes(num);
        std::iota(nodes.begin(), nodes.end(), this->num_variables);
        this->num_variables += num;
        this->unary_costs.resize(this->num_variables);
        this->labels.resize(this->num_variables, -1);
        return nodes;
    }

    // f(i = b) = cost
    void add_unary_cost(const int i, const int b, const COST cost) {
        assert(0 <= i and i < this->num_variables);
        assert(0 == b or b == 1);
        this->unary_costs[i][b] += cost;
    }

    // f(i = 0) = cost_0, f(i = 1) = cost_1
    void add_unary_cost_all(const int i, const COST cost_0, const COST cost_1) {
        assert(0 <= i and i < this->num_variables);
        this->unary_costs[i][0b0] += cost_0;
        this->unary_costs[i][0b1] += cost_1;
    }

    // f(i = b1, j = b2) = cost
    void add_pairwise_cost(const int i, const int j, const int b1, const int b2, const COST cost) {
        assert(0 <= i and i < this->num_variables and 0 <= j and j < this->num_variables);
        assert((0 == b1 or b1 == 1) and (0 == b2 or b2 == 1));
        this->pair_wise_costs[{i, j}][static_cast<int>(b1) << 1 | b2] += cost;
    }

    // f(i = 0, j = 0) = cost_00, f(i = 0, j = 1) = cost_01, f(i = 1, j = 0) = cost_10, f(i = 1, j = 1) = cost_11
    void add_pairwise_cost_all(const int i, const int j, const COST cost_00, const COST cost_01, const COST cost_10,
                               const COST cost_11) {
        assert(0 <= i and i < this->num_variables and 0 <= j and j < this->num_variables);
        this->pair_wise_costs[{i, j}][0b00] += cost_00;
        this->pair_wise_costs[{i, j}][0b01] += cost_01;
        this->pair_wise_costs[{i, j}][0b10] += cost_10;
        this->pair_wise_costs[{i, j}][0b11] += cost_11;
    }

    [[nodiscard]] int get_label(int i) const { return this->labels[i]; }

    [[nodiscard]] std::vector<int> get_labels() const { return this->labels; }

    COST solve() {
        const auto offset = this->re_parameterization();

        this->xs = this->dinic.add_nodes(this->num_variables);
        this->ys = this->dinic.add_nodes(this->num_variables);
        this->source = this->dinic.add_node();
        this->sink = this->dinic.add_node();

        for (int p = 0; p < this->num_variables; ++p) {
            const auto& cost = this->unary_costs[p];
            assert(std::min(cost[0b0], cost[0b1]) == 0);
            if (cost[0b0] != 0) {
                this->dinic.add_directed_edge(this->xs[p], sink, cost[0b0]);
                this->dinic.add_directed_edge(source, this->ys[p], cost[0b0]);
            }
            if (cost[0b1] != 0) {
                this->dinic.add_directed_edge(source, this->xs[p], cost[0b1]);
                this->dinic.add_directed_edge(this->ys[p], sink, cost[0b1]);
            }
        }

        for (const auto& [key, cost] : this->pair_wise_costs) {
            const auto [p, q] = key;
            assert(std::min(cost[0b00], cost[0b10]) == 0);
            assert(std::min(cost[0b01], cost[0b11]) == 0);

            if (cost[0b00] != 0) {
                this->dinic.add_directed_edge(this->xs[p], this->ys[q], cost[0b00]);
                this->dinic.add_directed_edge(this->xs[q], this->ys[p], cost[0b00]);
            }
            if (cost[0b01] != 0) {
                this->dinic.add_directed_edge(this->xs[p], this->xs[q], cost[0b01]);
                this->dinic.add_directed_edge(this->ys[q], this->ys[p], cost[0b01]);
            }
            if (cost[0b10] != 0) {
                this->dinic.add_directed_edge(this->xs[q], this->xs[p], cost[0b10]);
                this->dinic.add_directed_edge(this->ys[p], this->ys[q], cost[0b10]);
            }
            if (cost[0b11] != 0) {
                this->dinic.add_directed_edge(this->ys[q], this->xs[p], cost[0b11]);
                this->dinic.add_directed_edge(this->ys[p], this->xs[q], cost[0b11]);
            }
        }
        const auto cost = this->dinic.solve(this->source, this->sink) / 2 + offset;

        // ラベルを求める
        StronglyConnectedComponents scc(this->dinic.num_nodes);
        scc.add_directed_edge(this->sink, this->source);
        for (const auto& edges : this->dinic.graph) {
            for (const auto& e : edges) {
                if (e.residual_capacity() > 0) {
                    scc.add_directed_edge(e.from, e.to);
                }
            }
        }
        scc.build();

        for (int i = 0; i < this->num_variables; ++i) {
            // コンポーネント番号はトポロジカルソート順
            const int u = scc.get_component_no(this->xs[i]);
            const int v = scc.get_component_no(this->ys[i]);

            if (u > v) {
                this->labels[i] = 0;
            }
            else if (u < v) {
                this->labels[i] = 1;
            }
        }

        return cost;
    }

private:
    COST re_parameterization() {
        for (auto& [key, cost] : this->pair_wise_costs) {
            const auto [p, q] = key;
            for (int b = 0; b <= 1; ++b) {
                const auto delta = std::min(cost[0b00 | b], cost[0b10 | b]);
                cost[0b00 | b] -= delta;
                cost[0b10 | b] -= delta;
                this->unary_costs[q][b] += delta;
            }
        }

        COST offset = 0;
        for (int p = 0; p < this->num_variables; ++p) {
            auto& cost = this->unary_costs[p];
            const auto delta = std::min(cost[0b0], cost[0b1]);
            cost[0b0] -= delta;
            cost[0b1] -= delta;
            offset += delta;
        }

        return offset;
    }
};
