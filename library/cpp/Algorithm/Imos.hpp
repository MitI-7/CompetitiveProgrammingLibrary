#include <vector>
#include <iostream>
#include <cassert>


class Imos {
public:
    std::vector<int> line;
    std::vector<std::vector<int>> field;
    int mode = 0;

    // 1次元imos
    Imos(int N) {
        this->mode = 1;
        this->line.resize(N + 1, 0);
    }

    // 2次元imos
    Imos(int H, int W) {
        this->mode = 2;
        this->field.resize(H + 1, std::vector<int>(W + 1, 0));
    }

    // [left, right)に+1
    void add(int left, int right) {
        assert(left < right);
        line[left]++;
        line[right]--;
    }

    // 左上(y1, x1)から右下(y2, x2)に+1する
    // 半開区間なので(y2, x2)は含まない
    void add(int y1, int x1, int y2, int x2) {
        assert(y1 < y2);
        assert(x1 < x2);

        field[y1][x1]++;    // 左上
        field[y1][x2]--;    // 右上
        field[y2][x1]--;    // 左下
        field[y2][x2]++;    // 右下
    }

    void build() {
        if (mode == 1) {
            build1();
        }
        if (mode == 2) {
            build2();
        }
    }

    void debug() {
        if (mode == 1) {
            debug1();
        }
        if (mode == 2) {
            debug2();
        }
    }

private:
    void build1() {
        for (int i = 1; i < (int)line.size(); ++i) {
            line[i] += line[i - 1];
        }
    }

    void build2() {
        // 横方向への累積和
        for (int y = 0; y < (int)field.size(); ++y) {
            for (int x = 1; x < (int)field[0].size(); ++x) {
                field[y][x] += field[y][x - 1];
            }
        }
        // 縦方向の累積和
        for (int y = 1; y < (int)field.size(); ++y) {
            for (int x = 0; x < (int)field[0].size(); ++x) {
                field[y][x] += field[y - 1][x];
            }
        }
    }

    void debug1() const {
        for (int i = 0; i < (int)line.size(); ++i) {
            std::cout << line[i] << " ";
        }
        std::cout << std::endl;
    }

    void debug2() const {
        for (int y = 0; y < (int)field.size(); ++y) {
            for (int x = 0; x < (int)field[0].size(); ++x) {
                std::cout << field[y][x] << " ";
            }
            std::cout << std::endl;
        }
    }
};