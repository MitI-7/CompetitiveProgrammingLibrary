#include <vector>
#include <algorithm>

// sとtの最長共通部分列の長さを算出
// O(|s||t|)
int longest_common_subsequence(const std::string &s, const std::string &t) {
    int ans = 0;
    std::vector<std::vector<int>> dp(s.size() + 1, std::vector<int>(t.size() + 1, 0));

    for (int i = 1; i < (int)dp.size(); ++i) {
        for (int j = 1; j < (int)dp[0].size(); ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            else {
                dp[i][j] = std::max(dp[i][j], std::max(dp[i - 1][j], dp[i][j - 1]));
            }

            ans = std::max(ans, dp[i][j]);
        }
    }

    // 復元(一意に定まるわけではない)
    std::string a = "";
    int i = s.size(), j = t.size();
    while (i > 0 and j > 0) {
        if (s[i - 1] == t[j - 1]) {
            a += s[i - 1];
            i--;
            j--;
        }
        else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            }
            else {
                j--;
            }
        }
    }
    std::reverse(a.begin(), a.end());

    return ans;
}
