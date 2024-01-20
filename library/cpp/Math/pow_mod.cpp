// a^n % mod
// O(log n)
// mod がでかいときは overflow に注意
long long pow_mod(long long a, long long n, long long mod) {
    long long x = 1, y = a % mod;
    while (n > 0) {
        if (n % 2 == 1) {
            x = (x * y) % mod;
        }
        y = (y * y) % mod;
        n /= 2;
    }

    return x % mod;
}