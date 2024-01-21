---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/cpp/Math/Combination.hpp
    title: library/cpp/Math/Combination.hpp
  - icon: ':x:'
    path: library/cpp/Math/derangement.cpp
    title: library/cpp/Math/derangement.cpp
  - icon: ':question:'
    path: library/cpp/Utility/mint.hpp
    title: library/cpp/Utility/mint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc172/tasks/abc172_e
    links:
    - https://atcoder.jp/contests/abc172/tasks/abc172_e
  bundledCode: "#line 1 \"test/cpp/Math/derangement1.test.cpp\"\n#define PROBLEM \"\
    https://atcoder.jp/contests/abc172/tasks/abc172_e\"\n\n#line 1 \"library/cpp/Math/derangement.cpp\"\
    \n#include <algorithm>\n#line 2 \"library/cpp/Utility/mint.hpp\"\n\n#include <iostream>\n\
    \ntemplate<int mod>\nstruct mint {\n    long long x;\n\n    mint(long long x =\
    \ 0) : x((x % mod + mod) % mod) {\n    }\n\n    mint &operator+=(const mint a)\
    \ {\n        if ((x += a.x) >= mod) {\n            x -= mod;\n        }\n    \
    \    return *this;\n    }\n\n    mint &operator-=(const mint a) {\n        if\
    \ ((x += mod - a.x) >= mod) {\n            x -= mod;\n        }\n        return\
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
    \        return res /= a;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const mint &obj) {\n        os << obj.x;\n        return os;\n    }\n};\n\
    \n\n//const int MOD = 1000000000 + 7; // 10^9 + 7\n//const int MOD = 998244353;\n\
    #line 1 \"library/cpp/Math/Combination.hpp\"\n#include <cassert>\n#include <cstdint>\n\
    #include <vector>\n#line 5 \"library/cpp/Math/Combination.hpp\"\n\n// nCr\n//\
    \ O(r)\ntemplate<typename T>\nT combination(long long n, long long r) {\n    T\
    \ ans = 1;\n    for (long long d = 1; d <= r; ++d) {\n        ans *= n--;\n  \
    \      ans /= d;\n    }\n    return ans;\n}\n\ntemplate<int MOD>\nclass Combination\
    \ {\npublic:\n    std::vector<mint<MOD>> fact;\n    std::vector<mint<MOD>> inv;\n\
    \n    // O(n)\n    Combination(int n) {\n        assert(0 < n);\n        this->fact.resize(n\
    \ + 1, 1);\n        this->inv.resize(n + 1, 1);\n\n        for (int i = 1; i <\
    \ int(fact.size()); ++i) {\n            this->fact[i] = this->fact[i - 1] * i;\n\
    \            this->inv[i] = this->fact[i].inv();\n        }\n    }\n\n    mint<MOD>\
    \ nCr(const int n, const int r) const {\n        assert(0 <= n and 0 <= r);\n\
    \        if (n < r) {\n            return 0;\n        }\n        return this->fact[n]\
    \ * (this->inv[r] * this->inv[n - r]);\n    }\n\n    mint<MOD> nPr(const int n,\
    \ const int r) const {\n        assert(0 <= n and 0 <= r);\n        if (n < r)\
    \ {\n            return 0;\n        }\n        return this->fact[n] * this->inv[n\
    \ - r];\n    }\n\n    // \u91CD\u8907\u7D44\u5408\u305B\n    // n \u500B\u306E\
    \u3082\u306E\u304B\u3089\u7E70\u308A\u8FD4\u3057\u3092\u3086\u308B\u3057\u3066\
    \ r \u500B\u3068\u308B\u3068\u304D\u306E\u5834\u5408\u306E\u6570\n    // n \u500B\
    \u306E o \u3068 r - 1 \u500B\u306E | \u306E\u4E26\u3073\u306E\u5834\u5408\u306E\
    \u6570\n    mint<MOD> nHr(const int n, const int r) const {\n        return nCr(n\
    \ + r - 1, r);\n    }\n};\n#line 4 \"library/cpp/Math/derangement.cpp\"\n\n//\
    \ \u5B8C\u5168\u9806\u5217\u306E m \u8272\u7248\u306E\u5834\u5408\u306E\u6570\n\
    // \u5024\u3068\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u304C\u3069\u3053\u3082\u4E00\
    \u81F4\u3057\u3066\u3044\u306A\u3044\u3088\u3046\u306A\u9806\u5217\u306E\u5834\
    \u5408\u306E\u6570\n// \u5024\u306F[0, m)\u306E\u7BC4\u56F2\u3092\u3068\u308B\uFF0E\
    n == m \u306E\u3068\u304D\uFF0C\u5B8C\u5168\u9806\u5217\n// O(n)\ntemplate<int\
    \ MOD>\nmint<MOD> derangement(const int n, const int m) {\n\n    Combination<MOD>\
    \ comb(std::max(n, m) + 100);\n\n    mint<MOD> ans = 0;\n    for (int i = 0; i\
    \ <= n; ++i) {\n        // i\u500B\u4EE5\u4E0A\u306E\u7B87\u6240\u304C\u6307\u5B9A\
    \u306E\u8272\u3068\u4E00\u81F4\u3057\u3066\u3057\u307E\u3063\u3066\u3044\u308B\
    \n        auto now = comb.nCr(n, i);\n        // n - i\u500B\u306E\u7B87\u6240\
    \u306F\u6307\u5B9A\u306E\u8272\u3068\u4E00\u81F4\u3057\u3066\u3082\u3057\u306A\
    \u304F\u3066\u3082\u3044\u3044\n        now *= comb.nPr(m - i, n - i);\n\n   \
    \     if (i % 2 == 0) {\n            ans += now;\n        }\n        else {\n\
    \            ans -= now;\n        }\n    }\n\n    return ans;\n}\n#line 6 \"test/cpp/Math/derangement1.test.cpp\"\
    \n\nusing namespace std;\n\nconst int MOD = 1000000007;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int N, M;\n    cin >> N >> M;\n\n   \
    \ mint<MOD> ans = 1;\n    for (int i = 0; i < N; ++i) {\n        ans *= M - i;\n\
    \    }\n    ans *= derangement<MOD>(N, M);\n    cout << ans.x << endl;\n\n   \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc172/tasks/abc172_e\"\n\n\
    #include \"library/cpp/Math/derangement.cpp\"\n#include \"library/cpp/Utility/mint.hpp\"\
    \n#include <iostream>\n\nusing namespace std;\n\nconst int MOD = 1000000007;\n\
    \nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n  \
    \  int N, M;\n    cin >> N >> M;\n\n    mint<MOD> ans = 1;\n    for (int i = 0;\
    \ i < N; ++i) {\n        ans *= M - i;\n    }\n    ans *= derangement<MOD>(N,\
    \ M);\n    cout << ans.x << endl;\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Math/derangement.cpp
  - library/cpp/Utility/mint.hpp
  - library/cpp/Math/Combination.hpp
  isVerificationFile: true
  path: test/cpp/Math/derangement1.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:50:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/cpp/Math/derangement1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Math/derangement1.test.cpp
- /verify/test/cpp/Math/derangement1.test.cpp.html
title: test/cpp/Math/derangement1.test.cpp
---
