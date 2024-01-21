---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/cpp/Math/Fraction.hpp
    title: library/cpp/Math/Fraction.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc225/tasks/abc225_e
    links:
    - https://atcoder.jp/contests/abc225/tasks/abc225_e
  bundledCode: "#line 1 \"test/cpp/Math/Fraction1.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc225/tasks/abc225_e\"\
    \n\n#line 1 \"library/cpp/Math/Fraction.hpp\"\ntemplate<typename T=long long>\n\
    class Fraction {\npublic:\n    T numerator;\n    T denominator;\n\npublic:\n \
    \   Fraction() : numerator(0), denominator(1) {\n    }\n\n    Fraction(T n, T\
    \ d) : numerator(n), denominator(d) {\n        // assert(d != 0);\n        auto\
    \ c = this->gcd(n, d);\n        this->numerator = n / c;\n        this->denominator\
    \ = d / c;\n    }\n\n    Fraction<T> operator+(const Fraction<T> &o) const {\n\
    \        auto n = this->numerator * o.denominator + o.numerator * this->denominator;\n\
    \        auto d = this->denominator * o.denominator;\n        auto c = this->gcd(n,\
    \ d);\n        return {n / c, d / c};\n//        return {n, d};\n    }\n\n   \
    \ Fraction<T> operator-(const Fraction<T> &o) const {\n        auto n = this->numerator\
    \ * o.denominator - o.numerator * this->denominator;\n        auto d = this->denominator\
    \ * o.denominator;\n        auto c = this->gcd(n, d);\n        return {n / c,\
    \ d / c};\n    }\n\n    Fraction<T> operator*(const Fraction<T> &o) const {\n\
    \        auto n = this->numerator * o.numerator;\n        auto d = this->denominator\
    \ * o.denominator;\n        auto c = this->gcd(n, d);\n        return {n / c,\
    \ d / c};\n    }\n\n    Fraction<T> operator/(const Fraction<T> &o) const {\n\
    \        auto n = this->numerator * o.denominator;\n        auto d = this->denominator\
    \ * o.numerator;\n        auto c = this->gcd(n, d);\n        return {n / c, d\
    \ / c};\n    }\n\n    bool operator==(const Fraction<T> &o) const {\n        return\
    \ this->numerator * o.denominator == o.numerator * this->denominator;\n    }\n\
    \n    bool operator==(const T n) const {\n        return this->numerator == n\
    \ * this->denominator;\n    }\n\n    bool operator>(const Fraction<T> &o) const\
    \ {\n        return this->numerator * o.denominator > o.numerator * this->denominator;\n\
    \    }\n\n    bool operator>=(const Fraction<T> &o) const {\n        return this->numerator\
    \ * o.denominator >= o.numerator * this->denominator;\n    }\n\n    bool operator>(const\
    \ T n) const {\n        return this->numerator > n * this->denominator;\n    }\n\
    \n    bool operator>=(const T n) const {\n        return this->numerator >= n\
    \ * this->denominator;\n    }\n\n    bool operator<(const Fraction<T> &o) const\
    \ {\n        return this->numerator * o.denominator < o.numerator * this->denominator;\n\
    \    }\n\n    bool operator<=(const Fraction<T> &o) const {\n        return this->numerator\
    \ * o.denominator <= o.numerator * this->denominator;\n    }\n\n    bool operator<(const\
    \ T n) const {\n        return this->numerator < n * this->denominator;\n    }\n\
    \n    bool operator<=(const T n) const {\n        return this->numerator <= n\
    \ * this->denominator;\n    }\n\nprivate:\n    T gcd(const T a, const T b) {\n\
    \        if (b == 0) { return a; }\n        return this->gcd(b, a % b);\n    }\n\
    };\n#line 4 \"test/cpp/Math/Fraction1.test.cpp\"\n#include <vector>\n#include\
    \ <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int N;\n    cin >> N;\n    vector<pair<Fraction<long\
    \ long>, Fraction<long long>>> v(N);\n    for (int i = 0; i < N; ++i) {\n    \
    \    long long X, Y;\n        cin >> X >> Y;\n        v[i].first = Fraction(Y,\
    \ X - 1);\n        v[i].second = Fraction(Y - 1, X);\n    }\n    sort(v.begin(),\
    \ v.end());\n\n    int ans = 1;\n    Fraction now = v[0].first;\n    for(int i\
    \ = 1; i < N; ++i) {\n        if (v[i].second >= now) {\n            now = v[i].first;\n\
    \            ans++;\n        }\n    }\n    cout << ans << endl;\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc225/tasks/abc225_e\"\n\n\
    #include \"library/cpp/Math/Fraction.hpp\"\n#include <vector>\n#include <iostream>\n\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N;\n    cin >> N;\n    vector<pair<Fraction<long long>, Fraction<long\
    \ long>>> v(N);\n    for (int i = 0; i < N; ++i) {\n        long long X, Y;\n\
    \        cin >> X >> Y;\n        v[i].first = Fraction(Y, X - 1);\n        v[i].second\
    \ = Fraction(Y - 1, X);\n    }\n    sort(v.begin(), v.end());\n\n    int ans =\
    \ 1;\n    Fraction now = v[0].first;\n    for(int i = 1; i < N; ++i) {\n     \
    \   if (v[i].second >= now) {\n            now = v[i].first;\n            ans++;\n\
    \        }\n    }\n    cout << ans << endl;\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Math/Fraction.hpp
  isVerificationFile: true
  path: test/cpp/Math/Fraction1.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:51:52+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/cpp/Math/Fraction1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Math/Fraction1.test.cpp
- /verify/test/cpp/Math/Fraction1.test.cpp.html
title: test/cpp/Math/Fraction1.test.cpp
---
