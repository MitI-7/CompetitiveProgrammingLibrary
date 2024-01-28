---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/Utility/mint.hpp
    title: library/cpp/Utility/mint.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Math/derangement.cpp
    title: library/cpp/Math/derangement.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Math/Combination1_nCr.test.cpp
    title: test/cpp/Math/Combination1_nCr.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Math/derangement1.test.cpp
    title: test/cpp/Math/derangement1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Math/Combination.hpp\"\n#include <cassert>\n\
    #include <cstdint>\n#include <vector>\n#line 2 \"library/cpp/Utility/mint.hpp\"\
    \n\n#include <iostream>\n\ntemplate<int mod>\nstruct mint {\n    long long x;\n\
    \n    mint(long long x = 0) : x((x % mod + mod) % mod) {\n    }\n\n    mint &operator+=(const\
    \ mint a) {\n        if ((x += a.x) >= mod) {\n            x -= mod;\n       \
    \ }\n        return *this;\n    }\n\n    mint &operator-=(const mint a) {\n  \
    \      if ((x += mod - a.x) >= mod) {\n            x -= mod;\n        }\n    \
    \    return *this;\n    }\n\n    mint &operator*=(const mint a) {\n        (x\
    \ *= a.x) %= mod;\n        return *this;\n    }\n\n    mint operator+(const mint\
    \ a) const {\n        mint res(*this);\n        return res += a;\n    }\n\n  \
    \  mint operator-(const mint a) const {\n        mint res(*this);\n        return\
    \ res -= a;\n    }\n\n    mint operator*(const mint a) const {\n        mint res(*this);\n\
    \        return res *= a;\n    }\n\n    mint pow(long long t) const {\n      \
    \  if (!t) {\n            return 1;\n        }\n        mint a = pow(t >> 1);\n\
    \        a *= a;\n        if (t & 1) {\n            a *= *this;\n        }\n \
    \       return a;\n    }\n\n    // mod \u304C\u7D20\u6570\u306E\u3068\u304D\u306E\
    \u307F\u5229\u7528\u53EF\u80FD\n    mint inv() const {\n        return pow(mod\
    \ - 2);\n    }\n\n    mint &operator/=(const mint a) {\n        return (*this)\
    \ *= a.inv();\n    }\n\n    mint operator/(const mint a) const {\n        mint\
    \ res(*this);\n        return res /= a;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const mint &obj) {\n        os << obj.x;\n        return os;\n    }\n};\n\
    \n\n//const int MOD = 1000000000 + 7; // 10^9 + 7\n//const int MOD = 998244353;\n\
    #line 5 \"library/cpp/Math/Combination.hpp\"\n\n// nCr\n// O(r)\ntemplate<typename\
    \ T>\nT combination(long long n, long long r) {\n    if (r < 0) {\n        return\
    \ 0;\n    }\n    T ans = 1;\n    for (long long d = 1; d <= r; ++d) {\n      \
    \  ans *= n--;\n        ans /= d;\n    }\n    return ans;\n}\n\ntemplate<int MOD>\n\
    class Combination {\npublic:\n    std::vector<mint<MOD>> fact;\n    std::vector<mint<MOD>>\
    \ inv;\n\n    // O(n)\n    Combination(int n) {\n        assert(0 < n);\n    \
    \    this->fact.resize(n + 1, 1);\n        this->inv.resize(n + 1, 1);\n\n   \
    \     for (int i = 1; i < int(fact.size()); ++i) {\n            this->fact[i]\
    \ = this->fact[i - 1] * i;\n            this->inv[i] = this->fact[i].inv();\n\
    \        }\n    }\n\n    mint<MOD> nCr(const int n, const int r) const {\n   \
    \     assert(0 <= n and 0 <= r);\n        if (n < r) {\n            return 0;\n\
    \        }\n        return this->fact[n] * (this->inv[r] * this->inv[n - r]);\n\
    \    }\n\n    mint<MOD> nPr(const int n, const int r) const {\n        assert(0\
    \ <= n and 0 <= r);\n        if (n < r) {\n            return 0;\n        }\n\
    \        return this->fact[n] * this->inv[n - r];\n    }\n\n    // \u91CD\u8907\
    \u7D44\u5408\u305B\n    // n \u500B\u306E\u3082\u306E\u304B\u3089\u7E70\u308A\u8FD4\
    \u3057\u3092\u3086\u308B\u3057\u3066 r \u500B\u3068\u308B\u3068\u304D\u306E\u5834\
    \u5408\u306E\u6570\n    // n \u500B\u306E o \u3068 r - 1 \u500B\u306E | \u306E\
    \u4E26\u3073\u306E\u5834\u5408\u306E\u6570\n    mint<MOD> nHr(const int n, const\
    \ int r) const {\n        return nCr(n + r - 1, r);\n    }\n};\n"
  code: "#include <cassert>\n#include <cstdint>\n#include <vector>\n#include \"library/cpp/Utility/mint.hpp\"\
    \n\n// nCr\n// O(r)\ntemplate<typename T>\nT combination(long long n, long long\
    \ r) {\n    if (r < 0) {\n        return 0;\n    }\n    T ans = 1;\n    for (long\
    \ long d = 1; d <= r; ++d) {\n        ans *= n--;\n        ans /= d;\n    }\n\
    \    return ans;\n}\n\ntemplate<int MOD>\nclass Combination {\npublic:\n    std::vector<mint<MOD>>\
    \ fact;\n    std::vector<mint<MOD>> inv;\n\n    // O(n)\n    Combination(int n)\
    \ {\n        assert(0 < n);\n        this->fact.resize(n + 1, 1);\n        this->inv.resize(n\
    \ + 1, 1);\n\n        for (int i = 1; i < int(fact.size()); ++i) {\n         \
    \   this->fact[i] = this->fact[i - 1] * i;\n            this->inv[i] = this->fact[i].inv();\n\
    \        }\n    }\n\n    mint<MOD> nCr(const int n, const int r) const {\n   \
    \     assert(0 <= n and 0 <= r);\n        if (n < r) {\n            return 0;\n\
    \        }\n        return this->fact[n] * (this->inv[r] * this->inv[n - r]);\n\
    \    }\n\n    mint<MOD> nPr(const int n, const int r) const {\n        assert(0\
    \ <= n and 0 <= r);\n        if (n < r) {\n            return 0;\n        }\n\
    \        return this->fact[n] * this->inv[n - r];\n    }\n\n    // \u91CD\u8907\
    \u7D44\u5408\u305B\n    // n \u500B\u306E\u3082\u306E\u304B\u3089\u7E70\u308A\u8FD4\
    \u3057\u3092\u3086\u308B\u3057\u3066 r \u500B\u3068\u308B\u3068\u304D\u306E\u5834\
    \u5408\u306E\u6570\n    // n \u500B\u306E o \u3068 r - 1 \u500B\u306E | \u306E\
    \u4E26\u3073\u306E\u5834\u5408\u306E\u6570\n    mint<MOD> nHr(const int n, const\
    \ int r) const {\n        return nCr(n + r - 1, r);\n    }\n};"
  dependsOn:
  - library/cpp/Utility/mint.hpp
  isVerificationFile: false
  path: library/cpp/Math/Combination.hpp
  requiredBy:
  - library/cpp/Math/derangement.cpp
  timestamp: '2024-01-20 16:48:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Math/derangement1.test.cpp
  - test/cpp/Math/Combination1_nCr.test.cpp
documentation_of: library/cpp/Math/Combination.hpp
layout: document
redirect_from:
- /library/library/cpp/Math/Combination.hpp
- /library/library/cpp/Math/Combination.hpp.html
title: library/cpp/Math/Combination.hpp
---
