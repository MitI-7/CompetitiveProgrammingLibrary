---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Math/Fraction1.test.cpp
    title: test/cpp/Math/Fraction1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Math/Fraction.hpp\"\ntemplate<typename T=long\
    \ long>\nclass Fraction {\npublic:\n    T numerator;\n    T denominator;\n\npublic:\n\
    \    Fraction() : numerator(0), denominator(1) {\n    }\n\n    Fraction(T n, T\
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
    };\n"
  code: "template<typename T=long long>\nclass Fraction {\npublic:\n    T numerator;\n\
    \    T denominator;\n\npublic:\n    Fraction() : numerator(0), denominator(1)\
    \ {\n    }\n\n    Fraction(T n, T d) : numerator(n), denominator(d) {\n      \
    \  // assert(d != 0);\n        auto c = this->gcd(n, d);\n        this->numerator\
    \ = n / c;\n        this->denominator = d / c;\n    }\n\n    Fraction<T> operator+(const\
    \ Fraction<T> &o) const {\n        auto n = this->numerator * o.denominator +\
    \ o.numerator * this->denominator;\n        auto d = this->denominator * o.denominator;\n\
    \        auto c = this->gcd(n, d);\n        return {n / c, d / c};\n//       \
    \ return {n, d};\n    }\n\n    Fraction<T> operator-(const Fraction<T> &o) const\
    \ {\n        auto n = this->numerator * o.denominator - o.numerator * this->denominator;\n\
    \        auto d = this->denominator * o.denominator;\n        auto c = this->gcd(n,\
    \ d);\n        return {n / c, d / c};\n    }\n\n    Fraction<T> operator*(const\
    \ Fraction<T> &o) const {\n        auto n = this->numerator * o.numerator;\n \
    \       auto d = this->denominator * o.denominator;\n        auto c = this->gcd(n,\
    \ d);\n        return {n / c, d / c};\n    }\n\n    Fraction<T> operator/(const\
    \ Fraction<T> &o) const {\n        auto n = this->numerator * o.denominator;\n\
    \        auto d = this->denominator * o.numerator;\n        auto c = this->gcd(n,\
    \ d);\n        return {n / c, d / c};\n    }\n\n    bool operator==(const Fraction<T>\
    \ &o) const {\n        return this->numerator * o.denominator == o.numerator *\
    \ this->denominator;\n    }\n\n    bool operator==(const T n) const {\n      \
    \  return this->numerator == n * this->denominator;\n    }\n\n    bool operator>(const\
    \ Fraction<T> &o) const {\n        return this->numerator * o.denominator > o.numerator\
    \ * this->denominator;\n    }\n\n    bool operator>=(const Fraction<T> &o) const\
    \ {\n        return this->numerator * o.denominator >= o.numerator * this->denominator;\n\
    \    }\n\n    bool operator>(const T n) const {\n        return this->numerator\
    \ > n * this->denominator;\n    }\n\n    bool operator>=(const T n) const {\n\
    \        return this->numerator >= n * this->denominator;\n    }\n\n    bool operator<(const\
    \ Fraction<T> &o) const {\n        return this->numerator * o.denominator < o.numerator\
    \ * this->denominator;\n    }\n\n    bool operator<=(const Fraction<T> &o) const\
    \ {\n        return this->numerator * o.denominator <= o.numerator * this->denominator;\n\
    \    }\n\n    bool operator<(const T n) const {\n        return this->numerator\
    \ < n * this->denominator;\n    }\n\n    bool operator<=(const T n) const {\n\
    \        return this->numerator <= n * this->denominator;\n    }\n\nprivate:\n\
    \    T gcd(const T a, const T b) {\n        if (b == 0) { return a; }\n      \
    \  return this->gcd(b, a % b);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Math/Fraction.hpp
  requiredBy: []
  timestamp: '2024-01-20 16:51:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Math/Fraction1.test.cpp
documentation_of: library/cpp/Math/Fraction.hpp
layout: document
redirect_from:
- /library/library/cpp/Math/Fraction.hpp
- /library/library/cpp/Math/Fraction.hpp.html
title: library/cpp/Math/Fraction.hpp
---
