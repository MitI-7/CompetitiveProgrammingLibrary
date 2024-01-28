---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Math/Combination.hpp
    title: library/cpp/Math/Combination.hpp
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
  - icon: ':x:'
    path: test/cpp/Tree/RollbackUnionFind1.test.cpp
    title: test/cpp/Tree/RollbackUnionFind1.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/cpp/Utility/mint.hpp\"\n\n#include <iostream>\n\n\
    template<int mod>\nstruct mint {\n    long long x;\n\n    mint(long long x = 0)\
    \ : x((x % mod + mod) % mod) {\n    }\n\n    mint &operator+=(const mint a) {\n\
    \        if ((x += a.x) >= mod) {\n            x -= mod;\n        }\n        return\
    \ *this;\n    }\n\n    mint &operator-=(const mint a) {\n        if ((x += mod\
    \ - a.x) >= mod) {\n            x -= mod;\n        }\n        return *this;\n\
    \    }\n\n    mint &operator*=(const mint a) {\n        (x *= a.x) %= mod;\n \
    \       return *this;\n    }\n\n    mint operator+(const mint a) const {\n   \
    \     mint res(*this);\n        return res += a;\n    }\n\n    mint operator-(const\
    \ mint a) const {\n        mint res(*this);\n        return res -= a;\n    }\n\
    \n    mint operator*(const mint a) const {\n        mint res(*this);\n       \
    \ return res *= a;\n    }\n\n    mint pow(long long t) const {\n        if (!t)\
    \ {\n            return 1;\n        }\n        mint a = pow(t >> 1);\n       \
    \ a *= a;\n        if (t & 1) {\n            a *= *this;\n        }\n        return\
    \ a;\n    }\n\n    // mod \u304C\u7D20\u6570\u306E\u3068\u304D\u306E\u307F\u5229\
    \u7528\u53EF\u80FD\n    mint inv() const {\n        return pow(mod - 2);\n   \
    \ }\n\n    mint &operator/=(const mint a) {\n        return (*this) *= a.inv();\n\
    \    }\n\n    mint operator/(const mint a) const {\n        mint res(*this);\n\
    \        return res /= a;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const mint &obj) {\n        os << obj.x;\n        return os;\n    }\n};\n\
    \n\n//const int MOD = 1000000000 + 7; // 10^9 + 7\n//const int MOD = 998244353;\n"
  code: "#pragma once\n\n#include <iostream>\n\ntemplate<int mod>\nstruct mint {\n\
    \    long long x;\n\n    mint(long long x = 0) : x((x % mod + mod) % mod) {\n\
    \    }\n\n    mint &operator+=(const mint a) {\n        if ((x += a.x) >= mod)\
    \ {\n            x -= mod;\n        }\n        return *this;\n    }\n\n    mint\
    \ &operator-=(const mint a) {\n        if ((x += mod - a.x) >= mod) {\n      \
    \      x -= mod;\n        }\n        return *this;\n    }\n\n    mint &operator*=(const\
    \ mint a) {\n        (x *= a.x) %= mod;\n        return *this;\n    }\n\n    mint\
    \ operator+(const mint a) const {\n        mint res(*this);\n        return res\
    \ += a;\n    }\n\n    mint operator-(const mint a) const {\n        mint res(*this);\n\
    \        return res -= a;\n    }\n\n    mint operator*(const mint a) const {\n\
    \        mint res(*this);\n        return res *= a;\n    }\n\n    mint pow(long\
    \ long t) const {\n        if (!t) {\n            return 1;\n        }\n     \
    \   mint a = pow(t >> 1);\n        a *= a;\n        if (t & 1) {\n           \
    \ a *= *this;\n        }\n        return a;\n    }\n\n    // mod \u304C\u7D20\u6570\
    \u306E\u3068\u304D\u306E\u307F\u5229\u7528\u53EF\u80FD\n    mint inv() const {\n\
    \        return pow(mod - 2);\n    }\n\n    mint &operator/=(const mint a) {\n\
    \        return (*this) *= a.inv();\n    }\n\n    mint operator/(const mint a)\
    \ const {\n        mint res(*this);\n        return res /= a;\n    }\n\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const mint &obj) {\n        os <<\
    \ obj.x;\n        return os;\n    }\n};\n\n\n//const int MOD = 1000000000 + 7;\
    \ // 10^9 + 7\n//const int MOD = 998244353;"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Utility/mint.hpp
  requiredBy:
  - library/cpp/Math/Combination.hpp
  - library/cpp/Math/derangement.cpp
  timestamp: '2024-01-20 16:48:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/cpp/Tree/RollbackUnionFind1.test.cpp
  - test/cpp/Math/derangement1.test.cpp
  - test/cpp/Math/Combination1_nCr.test.cpp
documentation_of: library/cpp/Utility/mint.hpp
layout: document
redirect_from:
- /library/library/cpp/Utility/mint.hpp
- /library/library/cpp/Utility/mint.hpp.html
title: library/cpp/Utility/mint.hpp
---
