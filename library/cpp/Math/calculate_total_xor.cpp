// [0, n] の総 xor を求める
long long calculate_total_xor(long long n) {
    if (n < 0) {
        return 0;
    }

    switch (n % 4) {
        case 0:
            return n;
        case 1:
            return 1;
        case 2:
            return n + 1;
        case 3:
            return 0;
    }

    // ここにはこない
    return -1;
}