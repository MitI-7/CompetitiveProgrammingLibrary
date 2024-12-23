#pragma once
#include <array>
#include <cassert>
#include <map>
#include <numeric>
#include <vector>
#include "library/cpp/network_flow/dinic.hpp"

// Minimizing Nonsubmodular Functions: A Review, DOI: 10.1109/TPAMI.2007.1031
// Quadratic pseudo-Boolean optimization
template <class COST>
class QPBO {
    int num_variables;
    std::vector<std::array<COST, 2>> unary_costs;
    std::map<std::pair<int, int>, std::array<COST, 4>> pair_wise_costs;

public:
    QPBO() : num_variables(0) {}

    int add_variable() {
        this->add_variables(1);
        return this->num_variables - 1;
    }

    std::vector<int> add_variables(const int num) {
        std::vector<int> nodes(num);
        std::iota(nodes.begin(), nodes.end(), this->num_variables);
        this->num_variables += num;
        this->unary_costs.resize(this->num_variables);
        return nodes;
    }

    void add_unary_0_cost(int p, COST cost) {
        assert(0 <= p and p < this->num_variables);
        this->unary_costs[p][0b0] += cost;
    }

    void add_unary_1_cost(int p, COST cost) {
        assert(0 <= p and p < this->num_variables);
        this->unary_costs[p][0b1] += cost;
    }

    void add_pairwise_00_cost(int p, int q, COST cost) {
        assert(0 <= p and p < this->num_variables and 0 <= q and q < this->num_variables);
        if (p > q) {
            std::swap(p, q);
        }
        this->pair_wise_costs[{p, q}][0b00] += cost;
    }

    void add_pairwise_01_cost(int p, int q, COST cost) {
        assert(0 <= p and p < this->num_variables and 0 <= q and q < this->num_variables);
        this->pair_wise_costs[{p, q}][0b01] += cost;
    }

    void add_pairwise_10_cost(int p, int q, COST cost) {
        assert(0 <= p and p < this->num_variables and 0 <= q and q < this->num_variables);
        this->pair_wise_costs[{p, q}][0b10] += cost;
    }

    void add_pairwise_11_cost(int p, int q, COST cost) {
        assert(0 <= p and p < this->num_variables and 0 <= q and q < this->num_variables);
        if (p > q) {
            std::swap(p, q);
        }
        this->pair_wise_costs[{p, q}][0b11] += cost;
    }

    COST solve() {
        const auto offset = this->re_parameterization();

        Dinic<COST> dinic;
        const auto xs = dinic.add_nodes(this->num_variables);
        const auto ys = dinic.add_nodes(this->num_variables);
        const int s = dinic.add_node();
        const int t = dinic.add_node();

        for (int p = 0; p < num_variables; ++p) {
            const auto& cost = this->unary_costs[p];
            assert(std::min(cost[0b0], cost[0b1]) == 0);
            if (cost[0b0] != 0) {
                dinic.add_directed_edge(xs[p], t, cost[0b0]);
                dinic.add_directed_edge(s, ys[p], cost[0b0]);
            }
            if (cost[0b1] != 0) {
                dinic.add_directed_edge(s, xs[p], cost[0b1]);
                dinic.add_directed_edge(ys[p], t, cost[0b1]);
            }
        }

        for (const auto& [key, cost] : this->pair_wise_costs) {
            const auto [p, q] = key;
            assert(std::min(cost[0b00], cost[0b10]) == 0);
            assert(std::min(cost[0b01], cost[0b11]) == 0);

            if (cost[0b00] != 0) {
                dinic.add_directed_edge(xs[p], ys[q], cost[0b00]);
                dinic.add_directed_edge(xs[q], ys[p], cost[0b00]);
            }
            if (cost[0b01] != 0) {
                dinic.add_directed_edge(xs[p], xs[q], cost[0b01]);
                dinic.add_directed_edge(ys[q], ys[p], cost[0b01]);
            }
            if (cost[0b10] != 0) {
                dinic.add_directed_edge(xs[q], xs[p], cost[0b10]);
                dinic.add_directed_edge(ys[p], ys[q], cost[0b10]);
            }
            if (cost[0b11] != 0) {
                dinic.add_directed_edge(ys[q], xs[p], cost[0b11]);
                dinic.add_directed_edge(ys[p], xs[q], cost[0b11]);
            }
        }

        return dinic.solve(s, t) / 2 + offset;
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
