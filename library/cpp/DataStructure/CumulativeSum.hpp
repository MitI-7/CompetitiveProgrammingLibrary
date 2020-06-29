#include <vector>
#include <cassert>

template<typename T> class CumulativeSum {
public:
    std::vector<T> memo1;               // 1次元用の累積和表
    std::vector<std::vector<T>> memo2;  // 2次元用の累積和表

    CumulativeSum() {}

    CumulativeSum(const std::vector<T> &line) {
        this->build(line);
    }

    CumulativeSum(const std::vector<std::vector<T>> &matrix) {
        this->build(matrix);
    }

    void build(const std::vector<T> &line) {
        this->memo1 = std::vector<T>(line.size() + 1, 0);
        for (int i = 0; i < line.size(); ++i) {
            this->memo1[i + 1] = this->memo1[i] + line[i];
        }
    }

    // 2次元の累積和表を作成
    void build(const std::vector<std::vector<T>> &board) {
        const int height = board.size();
        const int width = board[0].size();

        this->memo2 = std::vector<std::vector<T>>(height + 1, std::vector<T>(width + 1));

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                this->memo2[y + 1][x + 1] = board[y][x] + this->memo2[y + 1][x];
            }
            for (int x = 0; x < width; ++x) {
                this->memo2[y + 1][x + 1] += this->memo2[y][x + 1];
            }
        }
    }

    // sum[left, right)
    T sum(int left, int right) {
        assert(right >= left);
        return this->memo1[right] - this->memo1[left];
    }

    /*
    左上(y1, x1)から右下(y2, x2)の合計を返す．(y2, x2)の行と列は含まない
    座標はmemoを作成したboard準拠
    (ex, sum(0, 0, 2, 2)なら(0, 0), (0, 1), (1, 0), (1, 1)の合計を返す)
    */
    T sum(int y1, int x1, int y2, int x2) {
        assert(y2 >= y1);
        assert(x2 >= x1);
        return this->memo2[y2][x2] - this->memo2[y2][x1] - this->memo2[y1][x2] + this->memo2[y1][x1];
    }
};