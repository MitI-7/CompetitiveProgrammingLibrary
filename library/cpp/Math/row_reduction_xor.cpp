#include <vector>
#include <bitset>

// xor の掃き出し法
// O(nm)
int row_reduction_xor(std::vector<std::bitset<60>> &matrix) {
    const int n = int(matrix.size());
    const int m = int(matrix[0].size());

    int pos = 0;    // 最後の未定の行
    // 列(bit)ごとに決めていく
    for (int b = m - 1; b >= 0; --b) {
        bool found = false;

        // b bit 目が 1 となっている行を探す
        for (int y = pos; y < n; ++y) {
            if (matrix[y][b]) {
                if (y != pos) {
                    swap(matrix[y], matrix[pos]);
                }
                found = true;
                break;
            }
        }
        if (found) {
            // pos とそれ以外のすべての行とで xor をとり，b bit 目は pos のみが 1 になるようにする
            for (int y = 0; y < n; ++y) {
                if (y != pos and matrix[y][b] == 1) {
                    matrix[y] ^= matrix[pos];
                }
            }
            ++pos;
        }
    }

    return pos;
}