---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Math/Combination.hpp
    title: library/cpp/Math/Combination.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/Utility/mint.hpp
    title: library/cpp/Utility/mint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc178/tasks/abc178_d
    links:
    - https://atcoder.jp/contests/abc178/tasks/abc178_d
  bundledCode: "#line 1 \"test/cpp/Math/Combination1_nCr.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc178/tasks/abc178_d\"\n\n#line 1 \"library/cpp/Math/Combination.hpp\"\
    \n#include <cassert>\n#include <cstdint>\n#include <vector>\n#line 2 \"library/cpp/Utility/mint.hpp\"\
    \n\ntemplate<int mod>\nstruct mint {\n    long long x;\n\n    mint(long long x\
    \ = 0) : x((x % mod + mod) % mod) {\n    }\n\n    mint &operator+=(const mint\
    \ a) {\n        if ((x += a.x) >= mod) {\n            x -= mod;\n        }\n \
    \       return *this;\n    }\n\n    mint &operator-=(const mint a) {\n       \
    \ if ((x += mod - a.x) >= mod) {\n            x -= mod;\n        }\n        return\
    \ *this;\n    }\n\n    mint &operator*=(const mint a) {\n        (x *= a.x) %=\
    \ mod;\n        return *this;\n    }\n\n    mint operator+(const mint a) const\
    \ {\n        mint res(*this);\n        return res += a;\n    }\n\n    mint operator-(const\
    \ mint a) const {\n        mint res(*this);\n        return res -= a;\n    }\n\
    \n    mint operator*(const mint a) const {\n        mint res(*this);\n       \
    \ return res *= a;\n    }\n\n    mint pow(long long t) const {\n        if (!t)\
    \ {\n            return 1;\n        }\n        mint a = pow(t >> 1);\n       \
    \ a *= a;\n        if (t & 1) {\n            a *= *this;\n        }\n        return\
    \ a;\n    }\n\n    // mod \u304C\u7D20\u6570\u306E\u3068\u304D\u306E\u307F\u5229\
    \u7528\u53EF\u80FD\n    mint inv() const {\n        return pow(mod - 2);\n   \
    \ }\n\n    mint &operator/=(const mint a) {\n        return (*this) *= a.inv();\n\
    \    }\n\n    mint operator/(const mint a) const {\n        mint res(*this);\n\
    \        return res /= a;\n    }\n};\n\n\n//const int MOD = 1000000000 + 7; //\
    \ 10^9 + 7\n//const int MOD = 998244353;\n#line 5 \"library/cpp/Math/Combination.hpp\"\
    \n\n// nCr\n// O(r)\ntemplate<typename T>\nT combination(long long n, long long\
    \ r) {\n    T ans = 1;\n    for (long long d = 1; d <= r; ++d) {\n        ans\
    \ *= n--;\n        ans /= d;\n    }\n    return ans;\n}\n\ntemplate<int MOD>\n\
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
    \ int r) const {\n        return nCr(n + r - 1, r);\n    }\n};\n#line 4 \"test/cpp/Math/Combination1_nCr.test.cpp\"\
    \n#include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    const int MOD = 1000000000 + 7;\n\n \
    \   int S;\n    cin >> S;\n\n    Combination<MOD> comb(10000);\n\n    mint<MOD>\
    \ ans;\n    for (int i = 0; i < S; ++i) {\n        if (S >= (i + 1) * 3) {\n \
    \           ans += comb.nCr(S - (i + 1) * 3 + i, i);\n        }\n    }\n    cout\
    \ << ans.x << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc178/tasks/abc178_d\"\n\n\
    #include \"library/cpp/Math/Combination.hpp\"\n#include <iostream>\n\nusing namespace\
    \ std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    const int MOD = 1000000000 + 7;\n\n    int S;\n    cin >> S;\n\n    Combination<MOD>\
    \ comb(10000);\n\n    mint<MOD> ans;\n    for (int i = 0; i < S; ++i) {\n    \
    \    if (S >= (i + 1) * 3) {\n            ans += comb.nCr(S - (i + 1) * 3 + i,\
    \ i);\n        }\n    }\n    cout << ans.x << endl;\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Math/Combination.hpp
  - library/cpp/Utility/mint.hpp
  isVerificationFile: true
  path: test/cpp/Math/Combination1_nCr.test.cpp
  requiredBy: []
  timestamp: '2023-06-12 12:36:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Math/Combination1_nCr.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Math/Combination1_nCr.test.cpp
- /verify/test/cpp/Math/Combination1_nCr.test.cpp.html
title: test/cpp/Math/Combination1_nCr.test.cpp
---
