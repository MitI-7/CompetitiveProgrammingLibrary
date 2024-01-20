#include <string>
#include <vector>

std::vector<std::pair<char, int>> run_length_encoding(const std::string &s) {
    std::vector<std::pair<char, int>> ans;

    const int n = s.size();
    int num = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            num++;
        }
        else {
            ans.emplace_back(s[i], num);
            num = 1;
        }
    }
    ans.emplace_back(s.back(), num);

    return ans;
}