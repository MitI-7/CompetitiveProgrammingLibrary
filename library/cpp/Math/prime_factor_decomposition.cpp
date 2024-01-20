#include <map>

// nを素因数分解する
// O(n^(1/2))
// prime_factor_decomposition(12) : {2:2, 3:1}
std::map<long long, long long> prime_factor_decomposition(long long n) {
    std::map<long long, long long> m;
    while (n > 1) {
        bool findFactor = false;
        for (long long i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                m[i]++;
                n /= i;
                findFactor = true;
                break;
            }
        }
        if (not findFactor) {
            m[n]++;
            break;
        }
    }
    return m;
}