---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/String/RollingHash1_hash.test.cpp
    title: test/cpp/String/RollingHash1_hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
  bundledCode: "#line 1 \"library/cpp/String/RollingHash.hpp\"\n#include <cassert>\n\
    #include <stdint.h>\n#include <string>\n#include <vector>\n\n// \u90E8\u5206\u6587\
    \u5B57\u5217\u306Ehash\u5024\u3092\u8A08\u7B97\n// https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    class RollingHash {\n    const uint_fast64_t  MASK30 = (1ull << 30ull) - 1;\n\
    \    const uint_fast64_t  MASK31 = (1ull << 31ull) - 1;\n    const uint_fast64_t\
    \  MOD = (1ull << 61ull) - 1;\n    const uint_fast64_t  POSITIVIZER = MOD * ((1ull\
    \ << 3ull) - 1);\n\n    int n;\n    uint_fast32_t Base;\n    std::vector<uint_fast64_t>\
    \ pow_memo;\n    std::vector<uint_fast64_t > has;\n\npublic:\n    RollingHash(const\
    \ std::string &s) : n(s.size()) {\n        this->pow_memo.resize(this->n + 1);\n\
    //        Base = (uint)new Random().Next(129, int.MaxValue);    // \u30C1\u30E3\
    \u30EC\u30F3\u30B8\u5BFE\u7B56\n        this->Base = 129;\n        this->pow_memo[0]\
    \ = 1;\n        for (int i = 1; i < int(this->pow_memo.size()); i++) {\n     \
    \       this->pow_memo[i] = calc_mod(mul(this->pow_memo[i - 1], this->Base));\n\
    \        }\n\n        this->has.resize(s.size() + 1);\n        for (int i = 0;\
    \ i < int(s.size()); i++)\n            this->has[i + 1] = calc_mod(mul(this->has[i],\
    \ this->Base) + s[i]);\n    }\n\n    // s[left, right)\u306Ehash\u5024 O(1)\n\
    \    uint_fast64_t hash(const int left, const int right) const {\n        assert(0\
    \ <= left and left < right and right <= n);\n\n        const int length = right\
    \ - left;\n        return calc_mod(this->has[right] + this->POSITIVIZER - mul(this->has[left],\
    \ this->pow_memo[length]));\n    }\n\nprivate:\n    uint_fast64_t mul(const uint_fast64_t\
    \ l, const uint_fast64_t r) const {\n        uint_fast64_t lu = l >> 31ull;\n\
    \        uint_fast64_t ld = l & this->MASK31;\n        uint_fast64_t ru = r >>\
    \ 31ull;\n        uint_fast64_t rd = r & this->MASK31;\n        uint_fast64_t\
    \ middleBit = ld * ru + lu * rd;\n        return ((lu * ru) << 1ull) + ld * rd\
    \ + ((middleBit & this->MASK30) << 31ull) + (middleBit >> 30ull);\n    }\n\n \
    \   uint_fast64_t calc_mod(uint_fast64_t val) const {\n        val = (val & this->MOD)\
    \ + (val >> 61ull);\n        if (val > this->MOD) {\n            val -= this->MOD;\n\
    \        }\n        return val;\n    }\n};\n"
  code: "#include <cassert>\n#include <stdint.h>\n#include <string>\n#include <vector>\n\
    \n// \u90E8\u5206\u6587\u5B57\u5217\u306Ehash\u5024\u3092\u8A08\u7B97\n// https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    class RollingHash {\n    const uint_fast64_t  MASK30 = (1ull << 30ull) - 1;\n\
    \    const uint_fast64_t  MASK31 = (1ull << 31ull) - 1;\n    const uint_fast64_t\
    \  MOD = (1ull << 61ull) - 1;\n    const uint_fast64_t  POSITIVIZER = MOD * ((1ull\
    \ << 3ull) - 1);\n\n    int n;\n    uint_fast32_t Base;\n    std::vector<uint_fast64_t>\
    \ pow_memo;\n    std::vector<uint_fast64_t > has;\n\npublic:\n    RollingHash(const\
    \ std::string &s) : n(s.size()) {\n        this->pow_memo.resize(this->n + 1);\n\
    //        Base = (uint)new Random().Next(129, int.MaxValue);    // \u30C1\u30E3\
    \u30EC\u30F3\u30B8\u5BFE\u7B56\n        this->Base = 129;\n        this->pow_memo[0]\
    \ = 1;\n        for (int i = 1; i < int(this->pow_memo.size()); i++) {\n     \
    \       this->pow_memo[i] = calc_mod(mul(this->pow_memo[i - 1], this->Base));\n\
    \        }\n\n        this->has.resize(s.size() + 1);\n        for (int i = 0;\
    \ i < int(s.size()); i++)\n            this->has[i + 1] = calc_mod(mul(this->has[i],\
    \ this->Base) + s[i]);\n    }\n\n    // s[left, right)\u306Ehash\u5024 O(1)\n\
    \    uint_fast64_t hash(const int left, const int right) const {\n        assert(0\
    \ <= left and left < right and right <= n);\n\n        const int length = right\
    \ - left;\n        return calc_mod(this->has[right] + this->POSITIVIZER - mul(this->has[left],\
    \ this->pow_memo[length]));\n    }\n\nprivate:\n    uint_fast64_t mul(const uint_fast64_t\
    \ l, const uint_fast64_t r) const {\n        uint_fast64_t lu = l >> 31ull;\n\
    \        uint_fast64_t ld = l & this->MASK31;\n        uint_fast64_t ru = r >>\
    \ 31ull;\n        uint_fast64_t rd = r & this->MASK31;\n        uint_fast64_t\
    \ middleBit = ld * ru + lu * rd;\n        return ((lu * ru) << 1ull) + ld * rd\
    \ + ((middleBit & this->MASK30) << 31ull) + (middleBit >> 30ull);\n    }\n\n \
    \   uint_fast64_t calc_mod(uint_fast64_t val) const {\n        val = (val & this->MOD)\
    \ + (val >> 61ull);\n        if (val > this->MOD) {\n            val -= this->MOD;\n\
    \        }\n        return val;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/String/RollingHash.hpp
  requiredBy: []
  timestamp: '2024-01-20 16:48:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/String/RollingHash1_hash.test.cpp
documentation_of: library/cpp/String/RollingHash.hpp
layout: document
redirect_from:
- /library/library/cpp/String/RollingHash.hpp
- /library/library/cpp/String/RollingHash.hpp.html
title: library/cpp/String/RollingHash.hpp
---
