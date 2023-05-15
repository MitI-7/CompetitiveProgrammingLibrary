#include <limits>
#include <vector>

/**
 * 全ノード間の最短距離をもとめる
 * matrix[i][j] には辺 (i,j) のコスト(辺が存在しない場合は inf)
 * 負の閉路がある場合は空を返す
 * O(|V|^3)
 */
template<typename T>
std::vector<std::vector<T>>
warshall_floyd(std::vector<std::vector<T>> matrix, const T infinity = std::numeric_limits<T>::max() / 3) {
    const int num_node = (int) matrix.size();

    // 自分の距離は0
    for (int i = 0; i < num_node; ++i) {
        matrix[i][i] = 0;
    }

    // m まで考慮したときの最短路が入る
    for (int m = 0; m < num_node; ++m) {
        for (int s = 0; s < num_node; ++s) {
            for (int e = 0; e < num_node; ++e) {
                // s -> m -> e
                if (matrix[s][m] != infinity and matrix[m][e] != infinity) {
                    if (matrix[s][e] > matrix[s][m] + matrix[m][e]) {
                        matrix[s][e] = matrix[s][m] + matrix[m][e];
                    }
                }
            }
        }
    }

    // 負閉路チェック
    for (int u = 0; u < num_node; ++u) {
        if (matrix[u][u] < 0) {
            return {};
        }
    }

    return matrix;
}