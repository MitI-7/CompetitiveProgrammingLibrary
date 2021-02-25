#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>


enum SENSE { MINIMIZE = 1, MAXIMIZE = -1};
enum STATUS { OPTIMAL = 1, NOT_SOLVED = 0, INFEASIBLE = -1, UNBOUNDED = -2, UNDEFINED = -3};

// min or max z = c x
// s.t.  A x = b
class SimplexMethod {
public:
    double objective;
    std::vector<std::vector<double>> tableau;

private:
    const int INF = 1u << 30u;
    const double EPS = 1e-9;

    int num_constraints;
    int num_variables;
    int column_b;
    SENSE sense;
    std::vector<int> base;   // base of row r is base[r]

public:
    SimplexMethod(SENSE sense=MINIMIZE): sense(sense) {

    }

    STATUS solve(const std::vector<std::vector<double>> &A, const std::vector<double> &b, const std::vector<double> &c) {
        this->num_constraints = A.size();
        this->num_variables = A[0].size();

        this->make_tableau(A, b, c);

        // set base
        this->base.resize(num_constraints + 2, -1);
        for (int i = 0; i < num_constraints; ++i) {
            base[i] = i + num_variables;
        }

        // phase1
        const auto status = this->phase1();
        if (status != OPTIMAL) {
            return status;
        }

        // remove artificial variables
        swap(this->tableau[num_constraints], this->tableau[num_constraints + 1]);
        for (int r = 0; r < this->tableau.size(); ++r) {
            std::swap(this->tableau[r][num_variables], this->tableau[r].back());
            this->tableau[r].resize(num_variables + 1);
        }

        return this->phase2();
    }

private:
    void make_tableau(const std::vector<std::vector<double>> &A, const std::vector<double> &b, const std::vector<double> &c) {
        this->tableau.resize(num_constraints + 2, std::vector<double>(num_variables + num_constraints + 1));

        // set A
        for (int i = 0; i < num_constraints; ++i) {
            for (int j = 0; j < num_variables; ++j) {
                this->tableau[i][j] = A[i][j];
            }
        }

        // set b
        for (int i = 0; i < num_constraints; ++i) {
            this->tableau[i][num_variables + num_constraints] = b[i];
        }

        // set c
        for (int i = 0; i < c.size(); ++i) {
            this->tableau[num_constraints][i] = sense * c[i];
        }

        for (int i = 0; i < num_constraints; ++i) {
            tableau.back()[i + num_variables] = 1;
        }
        for (int i = 0; i < num_constraints; ++i) {
            tableau[i][i + num_variables] = 1;
        }

        for (int i = 0; i < num_constraints; ++i) {
            for (int j = 0; j < tableau[0].size(); ++j) {
                tableau.back()[j] -= tableau[i][j];
            }
        }
    }

    STATUS phase1() {
        const auto status = simplex();
        if (status != OPTIMAL) {
            return status;
        }

        if (abs(this->tableau.back().back()) > this->EPS) {
            return INFEASIBLE;
        }

        return OPTIMAL;
    }

    STATUS phase2() {
        const auto status = simplex();
        this->objective = sense * -this->tableau.back().back();
        return status;
    }

    STATUS simplex() {
        int r, c;
        while (true) {
            std::tie(r, c) = bland();
            if (c == -1) {
                break;
            }
            if (r == -1 and c != -1) {
                return UNBOUNDED;
            }

            this->pivot(r, c);
        }

        this->objective = this->tableau.back().back() * sense;
        return OPTIMAL;
    }

    std::pair<int, int> bland() {
        int best_c = -1;
        for (int c = 0; c < this->tableau[0].size() - 1; ++c) {
            if (this->tableau.back()[c] < 0) {
                best_c = c;
                break;
            }
        }
        // optimal
        if (best_c == -1) {
            return std::make_pair(-1, -1);
        }

        int best_r = -1;
        for (int r = 0; r < this->tableau.size() - 2; ++r) {
            if (tableau[r][best_c] <= 0) {
                continue;
            }

            if (best_r == -1) {
                best_r = r;
            }
            else if (tableau[r].back() / tableau[r][best_c] < tableau[best_r].back() / tableau[best_r][best_c]) {
                best_r = r;
            }
        }

        return std::make_pair(best_r, best_c);
    }

    void pivot(const int row, const int col) {
        for (int r = 0; r < this->tableau.size(); ++r) {
            for (int c = 0; c < this->tableau[0].size(); ++c) {
                if (r != row and c != col) {
                    this->tableau[r][c] -= this->tableau[row][c] * this->tableau[r][col] / this->tableau[row][col];
                }
            }
        }

        for (int r = 0; r < this->tableau.size(); ++r) {
            if (r != row) {
                this->tableau[r][col] = 0;
            }
        }
        for (int c = 0; c < this->tableau[0].size(); ++c) {
            if (c != col) {
                this->tableau[row][c] /= this->tableau[row][col];
            }
        }

        this->tableau[row][col] = 1.0;
        this->base[row] = col;
    }

    void debug() {
        std::cout << "tableau:" << std::endl;
        for (int x = 0; x < tableau.size() - 1; ++x) {
            std::cout << std::fixed << std::setw(5) << "x" << x << " ";
        }
        std::cout << std::fixed << std::setw(5) << "b" << std::endl;
        for (int y = 0; y < tableau.size(); ++y) {
            std::cout << std::setw(2) << base[y] << " ";
            for (int x = 0; x < tableau[0].size(); ++x) {
                std::cout << std::fixed << std::setprecision(2) << std::setw(6) << tableau[y][x] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "base:" << std::endl;
        for (int i = 0; i < base.size(); ++i) {
            std::cout << base[i] << " ";
        }
        std::cout << std::endl;
    }
};