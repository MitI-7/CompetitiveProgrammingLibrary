---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Math/LinearExpression1.test.cpp
    title: test/cpp/Math/LinearExpression1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Math/LinearExpression.hpp\"\n#include <ostream>\n\
    \n// 1\u6B21\u5F0F\u3000ax + b\ntemplate<typename T>\nclass LinearExpression {\n\
    public:\n    T a;\n    T b;\n\n    LinearExpression(T a = 0, T b = 0) : a(a),\
    \ b(b) {}\n\n    T evaluate(T x) const {\n        return this->a * x + this->b;\n\
    \    }\n\n    // ax + b == cx + d \u306E\u3068\u304D\uFF0Cx \u3092\u6C42\u3081\
    \u308B\n    T find_x(const LinearExpression &obj) const {\n        return (obj.b\
    \ - this->b) / (this->a - obj.a);\n    }\n\n    LinearExpression operator+(const\
    \ LinearExpression &obj) const {\n        return LinearExpression(this->a + obj.a,\
    \ this->b + obj.b);\n    }\n\n    LinearExpression &operator+=(const LinearExpression\
    \ &obj) {\n        this->a + obj.a;\n        this->b + obj.b;\n        return\
    \ *this;\n    }\n\n    LinearExpression operator-(const LinearExpression &obj)\
    \ const {\n        return LinearExpression(a - obj.a, b - obj.b);\n    }\n\n \
    \   LinearExpression &operator-=(const LinearExpression &obj) {\n        this->a\
    \ - obj.a;\n        this->b - obj.b;\n        return *this;\n    }\n\n    LinearExpression\
    \ operator*(const T c) const {\n        return LinearExpression(a * c, b * c);\n\
    \    }\n\n    LinearExpression &operator*=(const T c) {\n        this->a *= c;\n\
    \        this->b *= c;\n        return *this;\n    }\n\n    LinearExpression operator/(const\
    \ T c) const {\n        return LinearExpression(a / c, b / c);\n    }\n\n    LinearExpression\
    \ &operator/=(const T c) {\n        this->a /= c;\n        this->b /= c;\n   \
    \     return *this;\n    }\n\n    bool operator==(const LinearExpression &obj)\
    \ const {\n        return this->a == obj.a and this->b == obj.b;\n    }\n\n  \
    \  friend std::ostream &operator<<(std::ostream &os, const LinearExpression &obj)\
    \ {\n        os << obj.a << \"x\" << \" + \" << obj.b;\n        return os;\n \
    \   }\n};\n"
  code: "#include <ostream>\n\n// 1\u6B21\u5F0F\u3000ax + b\ntemplate<typename T>\n\
    class LinearExpression {\npublic:\n    T a;\n    T b;\n\n    LinearExpression(T\
    \ a = 0, T b = 0) : a(a), b(b) {}\n\n    T evaluate(T x) const {\n        return\
    \ this->a * x + this->b;\n    }\n\n    // ax + b == cx + d \u306E\u3068\u304D\uFF0C\
    x \u3092\u6C42\u3081\u308B\n    T find_x(const LinearExpression &obj) const {\n\
    \        return (obj.b - this->b) / (this->a - obj.a);\n    }\n\n    LinearExpression\
    \ operator+(const LinearExpression &obj) const {\n        return LinearExpression(this->a\
    \ + obj.a, this->b + obj.b);\n    }\n\n    LinearExpression &operator+=(const\
    \ LinearExpression &obj) {\n        this->a + obj.a;\n        this->b + obj.b;\n\
    \        return *this;\n    }\n\n    LinearExpression operator-(const LinearExpression\
    \ &obj) const {\n        return LinearExpression(a - obj.a, b - obj.b);\n    }\n\
    \n    LinearExpression &operator-=(const LinearExpression &obj) {\n        this->a\
    \ - obj.a;\n        this->b - obj.b;\n        return *this;\n    }\n\n    LinearExpression\
    \ operator*(const T c) const {\n        return LinearExpression(a * c, b * c);\n\
    \    }\n\n    LinearExpression &operator*=(const T c) {\n        this->a *= c;\n\
    \        this->b *= c;\n        return *this;\n    }\n\n    LinearExpression operator/(const\
    \ T c) const {\n        return LinearExpression(a / c, b / c);\n    }\n\n    LinearExpression\
    \ &operator/=(const T c) {\n        this->a /= c;\n        this->b /= c;\n   \
    \     return *this;\n    }\n\n    bool operator==(const LinearExpression &obj)\
    \ const {\n        return this->a == obj.a and this->b == obj.b;\n    }\n\n  \
    \  friend std::ostream &operator<<(std::ostream &os, const LinearExpression &obj)\
    \ {\n        os << obj.a << \"x\" << \" + \" << obj.b;\n        return os;\n \
    \   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Math/LinearExpression.hpp
  requiredBy: []
  timestamp: '2024-02-03 20:15:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Math/LinearExpression1.test.cpp
documentation_of: library/cpp/Math/LinearExpression.hpp
layout: document
redirect_from:
- /library/library/cpp/Math/LinearExpression.hpp
- /library/library/cpp/Math/LinearExpression.hpp.html
title: library/cpp/Math/LinearExpression.hpp
---
