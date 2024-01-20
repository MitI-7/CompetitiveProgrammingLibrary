#include <cassert>
#include <stdint.h>
#include <string>
#include <vector>

// 部分文字列のhash値を計算
// https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
class RollingHash {
    const uint_fast64_t  MASK30 = (1ull << 30ull) - 1;
    const uint_fast64_t  MASK31 = (1ull << 31ull) - 1;
    const uint_fast64_t  MOD = (1ull << 61ull) - 1;
    const uint_fast64_t  POSITIVIZER = MOD * ((1ull << 3ull) - 1);

    int n;
    uint_fast32_t Base;
    std::vector<uint_fast64_t> pow_memo;
    std::vector<uint_fast64_t > has;

public:
    RollingHash(const std::string &s) : n(s.size()) {
        this->pow_memo.resize(this->n + 1);
//        Base = (uint)new Random().Next(129, int.MaxValue);    // チャレンジ対策
        this->Base = 129;
        this->pow_memo[0] = 1;
        for (int i = 1; i < int(this->pow_memo.size()); i++) {
            this->pow_memo[i] = calc_mod(mul(this->pow_memo[i - 1], this->Base));
        }

        this->has.resize(s.size() + 1);
        for (int i = 0; i < int(s.size()); i++)
            this->has[i + 1] = calc_mod(mul(this->has[i], this->Base) + s[i]);
    }

    // s[left, right)のhash値 O(1)
    uint_fast64_t hash(const int left, const int right) const {
        assert(0 <= left and left < right and right <= n);

        const int length = right - left;
        return calc_mod(this->has[right] + this->POSITIVIZER - mul(this->has[left], this->pow_memo[length]));
    }

private:
    uint_fast64_t mul(const uint_fast64_t l, const uint_fast64_t r) const {
        uint_fast64_t lu = l >> 31ull;
        uint_fast64_t ld = l & this->MASK31;
        uint_fast64_t ru = r >> 31ull;
        uint_fast64_t rd = r & this->MASK31;
        uint_fast64_t middleBit = ld * ru + lu * rd;
        return ((lu * ru) << 1ull) + ld * rd + ((middleBit & this->MASK30) << 31ull) + (middleBit >> 30ull);
    }

    uint_fast64_t calc_mod(uint_fast64_t val) const {
        val = (val & this->MOD) + (val >> 61ull);
        if (val > this->MOD) {
            val -= this->MOD;
        }
        return val;
    }
};