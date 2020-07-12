#include <vector>
#include <algorithm>
#include <climits>

// 最長増加部分列 strictがtrueなら狭義
// O(n log n)
int longest_increasing_subsequence(const std::vector<long long> &a, const bool strict=true) {
    std::vector<long long> dp(a.size() + 1, LONG_LONG_MAX);	// dp[i] = 長さiのLISの最後の値として最小の値
    for (const auto v : a) {
        int idx;
        if (strict) {
    	    idx = std::lower_bound(dp.begin(), dp.end(), v) - dp.begin();
        }
        else {
            idx = std::upper_bound(dp.begin(), dp.end(), v) - dp.begin();
        }

    	dp[idx] = v;
    }
    
    return std::lower_bound(dp.begin(), dp.end(), LONG_LONG_MAX) - dp.begin();
}
