#include <cassert>
#include <numeric>
#include <vector>

template<class T, T (*op)(T, T), T (*unit)()>
class SegmentTree2D {
private:
    int H;
    int W;
    int H2;
    int W2;
    std::vector<std::vector<T>> data;

public:
    SegmentTree2D(const std::vector<std::vector<T>> &grid) : H(grid.size()), W(grid[0].size()), H2(1), W2(1) {
        while (this->H2 < this->H) {
            this->H2 <<= 1;
        }
        while (this->W2 < this->W) {
            this->W2 <<= 1;
        }

        this->data.resize(this->H2 * 2 - 1, std::vector<T>(this->W2 * 2 - 1, unit()));
        for (int y = 0; y < this->H; ++y) {
            for (int x = 0; x < this->W; ++x) {
                this->data[this->H2 + y - 1][this->W2 + x - 1] = grid[y][x];
            }
        }
        this->build();
    }

    // O(1)
    T access(const int y, const int x) const {
        return this->data[this->H2 + y - 1][this->W2 + x - 1];
    }

    T query(const int y1, const int x1, const int y2, const int x2) const {
        return this->query(y1, x1, y2, x2, 0, 0, this->H2);
    }

    // O(log H * log W)
    void update(const int y, const int x, const T v) {
        int i = y + this->H2;
        int j = x + this->W2;
        this->data[i][j] = v;
        while (j > 1) {
            j >>= 1;
            const auto lv = this->data[i][j * 2 + 1];
            const auto rv = this->data[i][j * 2 + 2];
            this->data[i][j] = op(lv, rv);
        }

        j = x + this->W2;
        while (i > 1) {
            i >>= 1;
            this->data[i][j] = op(this->data[i * 2 + 1][j], this->data[i * 2 + 2][j]);
            while (j > 1) {
                j >>= 1;
                this->data[i][j] = op(this->data[i][j * 2 + 1], this->data[i][j * 2 + 2]);
            }
            j = x + this->W2;
        }
    }

private:
    // O(HW)
    void build() {
        // 列を埋める
        for (int x = 0; x < this->W; ++x) {
            for (int y = this->H2 - 2; y >= 0; --y) {
                const auto lv = this->data[y * 2 + 1][this->W2 + x - 1];
                const auto rv = this->data[y * 2 + 2][this->W2 + x - 1];
                this->data[y][this->W2 + x - 1] = op(lv, rv);
            }
        }

        // 各行の値を求める
        for (int y = 0; y < (int) this->data.size(); ++y) {
            for (int x = this->W2 - 2; x >= 0; --x) {
                const auto lv = this->data[y][x * 2 + 1];
                const auto rv = this->data[y][x * 2 + 2];
                this->data[y][x] = op(lv, rv);
            }
        }
    }

    // [(y1, x1), (y2, x2)) の値をノード u から検索
    // ノード u は y の区間 [start, end) をカバー
    T query(const int y1, const int x1, const int y2, const int x2, const int u, const int start, const int end) const {
        assert(y1 < y2 and start < end);
        // 範囲外
        if (end <= y1 or y2 <= start) {
            return unit();
        }

        if (y1 <= start and end <= y2) {
            // 完全に含むので，x についての探索をする
            return this->query_x(x1, x2, 0, 0, this->W2, u);
        } else {
            const int m = (start + end) / 2;
            auto vl = query(y1, x1, y2, x2, 2 * u + 1, start, m);  // 左の子
            auto vr = query(y1, x1, y2, x2, 2 * u + 2, m, end);   // 右の子
            return op(vl, vr);
        }
    }

    T query_x(const int x1, const int x2, const int u, const int start, const int end, const int node) const {
        assert(x1 < x2 and start < end);
        // 範囲外
        if (end <= x1 or x2 <= start) {
            return unit();
        }

        // 完全に含む
        if (x1 <= start and end <= x2) {
            return this->data[node][u];
        } else {
            const int m = (start + end) / 2;
            auto vl = query_x(x1, x2, u * 2 + 1, start, m, node);   // 左の子
            auto vr = query_x(x1, x2, u * 2 + 2, m, end, node);    // 右の子
            return op(vl, vr);
        }
    }
};

// range minimum query
template<typename T>
T min_op(T a, T b) {
    return std::min(a, b);
}

template<typename T>
T min_unit() {
    return std::numeric_limits<T>::max();
}

template<typename T>
SegmentTree2D<T, min_op, min_unit> make_segment_tree_2d_min(const std::vector<std::vector<T>> &grid) {
    return SegmentTree2D<T, min_op, min_unit>(grid);
}

// range maximum query
template<typename T>
T max_op(T a, T b) {
    return std::max(a, b);
}

template<typename T>
T max_unit() {
    return std::numeric_limits<T>::min();
}

template<typename T>
SegmentTree2D<T, max_op, max_unit> make_segment_tree_2d_max(const std::vector<std::vector<T>> &grid) {
    return SegmentTree2D<T, max_op, max_unit>(grid);
}

// range sum query
template<typename T>
T sum_op(T a, T b) {
    return a + b;
}

template<typename T>
T sum_unit() {
    return 0;
}

template<typename T>
SegmentTree2D<T, sum_op, sum_unit> make_segment_tree_2d_sum(const std::vector<std::vector<T>> &grid) {
    return SegmentTree2D<T, sum_op, sum_unit>(grid);
}
