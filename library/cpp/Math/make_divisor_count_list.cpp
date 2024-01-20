#include <vector>

// [1, n]の各値について約数の個数を格納した配列を作成
// O(n log n)
std::vector<int> make_divisor_count_list(const int n) {
    std::vector<int> divisor_count_list(n + 1);
    for (int d = 1; d <= n; ++d) {
        for (long long i = d; i <= n; i += d) {
            divisor_count_list[i]++;
        }
    }
    return divisor_count_list;
}