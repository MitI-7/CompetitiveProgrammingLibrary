#include <vector>
#include <algorithm>
#include <numeric>

// 約数を列挙する(O(sqrt(n)))
// 約数の個数はO(root(n))
std::vector<long long> get_divisor(long long n) {
    std::vector<long long> ret;
    for(long long i = 1; i * i <= n; ++i) {
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

std::vector<long long> get_divisor(std::vector<long long> &v) {
    if (v.empty()) {
        return {};
    }
    long long g = v[0];
    for (int i = 1; i < v.size(); ++i) {
        g = std::gcd(g, v[i]);
    }
    return get_divisor(g);
}