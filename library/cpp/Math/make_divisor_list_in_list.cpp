#include <vector>

// 配列 v の要素の約数を列挙
// O(maxi log maxi)
std::vector<int> make_divisor_list_in_list(const std::vector<int> &v, const int maxi) {
    if (v.empty()) {
        return {};
    }

    std::vector<bool> used(maxi + 1);
    for (const auto a: v) {
        used[a] = true;
    }

    std::vector<int> divisor_list = {1};
    for (int i = 2; i <= maxi; ++i) {
        bool is_divisor = false;
        for (int j = i; j <= maxi; j += i) {
            if (used[j]) {
                is_divisor = true;
                break;
            }
        }
        if (is_divisor) {
            divisor_list.emplace_back(i);
        }
    }

    return divisor_list;
}