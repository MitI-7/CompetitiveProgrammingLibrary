---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/String/RollingHash.hpp
    title: library/cpp/String/RollingHash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=ja
  bundledCode: "#line 1 \"test/cpp/String/RollingHash1_hash.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=ja\"\
    \n\n#line 1 \"library/cpp/String/RollingHash.hpp\"\n#include <cassert>\n#include\
    \ <stdint.h>\n#include <string>\n#include <vector>\n\n// \u90E8\u5206\u6587\u5B57\
    \u5217\u306Ehash\u5024\u3092\u8A08\u7B97\n// https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
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
    \        }\n        return val;\n    }\n};\n#line 4 \"test/cpp/String/RollingHash1_hash.test.cpp\"\
    \n#include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    string T, P;\n    cin >> T >> P;\n\n\
    \    RollingHash rh_t(T);\n    RollingHash rh_p(P);\n\n    const auto p = rh_p.hash(0,\
    \ int(P.size()));\n\n    for (int left = 0; left < int(T.size() - P.size() + 1);\
    \ ++left) {\n        const auto right = left + int(P.size());\n        if (rh_t.hash(left,\
    \ right) == p) {\n            cout << left << endl;\n        }\n    }\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=ja\"\
    \n\n#include \"library/cpp/String/RollingHash.hpp\"\n#include <iostream>\n\nusing\
    \ namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    string T, P;\n    cin >> T >> P;\n\n    RollingHash rh_t(T);\n    RollingHash\
    \ rh_p(P);\n\n    const auto p = rh_p.hash(0, int(P.size()));\n\n    for (int\
    \ left = 0; left < int(T.size() - P.size() + 1); ++left) {\n        const auto\
    \ right = left + int(P.size());\n        if (rh_t.hash(left, right) == p) {\n\
    \            cout << left << endl;\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/String/RollingHash.hpp
  isVerificationFile: true
  path: test/cpp/String/RollingHash1_hash.test.cpp
  requiredBy: []
  timestamp: '2023-06-09 11:17:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/String/RollingHash1_hash.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/String/RollingHash1_hash.test.cpp
- /verify/test/cpp/String/RollingHash1_hash.test.cpp.html
title: test/cpp/String/RollingHash1_hash.test.cpp
---
