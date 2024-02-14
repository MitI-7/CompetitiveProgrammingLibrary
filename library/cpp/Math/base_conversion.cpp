#include <algorithm>
#include <cassert>
#include <vector>
#include <limits>

// base 進数から10進数に変える
// v[0]が最上位の桁を表す
// 6 = 110 なら {0, 1, 1}
long long to_base_10(const std::vector<int> &v, const long long base) {
    auto inf = std::numeric_limits<long long>::max();
    long long ans = 0;
    for (int x: v) {
        assert(x >= 0);
        assert(x < base);

        // overflow が起きたときの処理
        if (ans > inf / base) {
            return inf;
        }

        ans = ans * base + x;
    }
    return ans;
}

// 10 進数から base 進数に変える
std::vector<int> to_base_n(long long x, const int base) {
    if (x == 0) {
        return {0};
    }

    std::vector<int> ans;
    while (x > 0) {
        auto t = x % base;
        ans.emplace_back(t);
        x /= base;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}