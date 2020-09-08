#include <string>
#include <vector>


int levenshtein_distance(const std::string &a, const std::string &b) {
    std::vector<std::vector<int>> dp(a.size() + 1, std::vector<int>(b.size() + 1, 0));
    for (int i = 0; i < (int)a.size() + 1; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j < (int)b.size() + 1; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i < (int)a.size() + 1; ++i) {
        for (int j = 1; j < (int)b.size() + 1; ++j) {
            int x;
            if (a[i - 1] == b[j - 1]) {
                x = 0;
            }
            else {
                x = 1;
            }
            dp[i][j] = std::min(std::min(dp[i - 1][j] + 1, dp[i][ j - 1] + 1), dp[i - 1][j - 1] + x);
        }
    }

    return dp[a.size()][b.size()];
}