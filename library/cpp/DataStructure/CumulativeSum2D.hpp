#include <cassert>
#include <iostream>
#include <vector>

template<typename T>
class CumulativeSum2D {
public:
    std::vector<std::vector<T>> memo;
    std::vector<T> right_diagonal, left_diagonal;

    CumulativeSum2D() = default;

    explicit CumulativeSum2D(const std::vector<std::vector<T>> &grid) {
        this->build(grid);
    }

    // gridは左上が (0, 0)，右下が(H - 1, W - 1)
    // O(H * W)
    void build(const std::vector<std::vector<T>> &grid) {
        const int H = grid.size();
        const int W = grid[0].size();

        this->memo = std::vector<std::vector<T>>(H + 1, std::vector<T>(W + 1));
        this->right_diagonal.resize(H + W + 1);
        this->left_diagonal.resize(H + W + 1);

        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                this->memo[y + 1][x + 1] = grid[y][x] + this->memo[y + 1][x];
            }
            for (int x = 0; x < W; ++x) {
                this->memo[y + 1][x + 1] += this->memo[y][x + 1];
            }
        }
    }

    // 行 y の区間 [x1, x2) の合計
    T sum_row(const int y, const int x1, const int x2) const {
        return this->sum(y, x1, y + 1, x2);
    }

    // 列 x の区間 [y1, y2) の合計
    T sum_col(const int x, const int y1, const int y2) const {
        return this->sum(y1, x, y2, x + 1);
    }

    // 右斜め(y - x = d となる箇所) の合計
    T sum_right_diagonal(const int y1, const int x1, const int y2, const int x2) const {
        assert(y1 - x1 == y2 - x2);
        assert(y1 < y2);
        assert(x1 < x2);
    }

    // 左斜め(y + x = d となる直線) の合計
    T sum_left_diagonal(const int y1, const int x1, const int y2, const int x2) const {
        assert(y1 + x1 == y2 + x2);
        assert(y1 < y2);
        assert(x1 > x2);
    }

    // 左上 (y1, x1) から右下 (y2, x2) の合計を返す．(y2, x2)の行と列は含まない
    // 例えば， sum(0, 0, 2, 2) なら (0, 0), (0, 1), (1, 0), (1, 1) の合計を返す
    T sum(const int y1, const int x1, const int y2, const int x2) const {
        assert(y2 >= y1);
        assert(x2 >= x1);
        return this->memo[y2][x2] - this->memo[y2][x1] - this->memo[y1][x2] + this->memo[y1][x1];
    }

    void dump() const {
        for (const auto line: this->memo) {
            for (const auto a: line) {
                std::cout << a << " ";
            }
            std::cout << std::endl;
        }
    }
};