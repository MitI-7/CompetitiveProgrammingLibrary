#include <vector>
#include <algorithm>

// n の約数を列挙する
// O(sqrt(n))
// n <= 10^9 で最大 1344 個，n <= 10^18 で最大 103680 個の約数がある
std::vector<long long> make_divisor_list(long long n) {
    std::vector<long long> ret;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.emplace_back(i);
            if (i * i != n) {
                ret.emplace_back(n / i);
            }
        }
    }
    std::sort(ret.begin(), ret.end());
    return ret;
}