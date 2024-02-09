---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Math/LinearExpression.hpp
    title: library/cpp/Math/LinearExpression.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc133/tasks/abc133_d
    links:
    - https://atcoder.jp/contests/abc133/tasks/abc133_d
  bundledCode: "#line 1 \"test/cpp/Math/LinearExpression1.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc133/tasks/abc133_d\"\n\n#line 1 \"library/cpp/Math/LinearExpression.hpp\"\
    \n#include <ostream>\n\n// 1\u6B21\u5F0F\u3000ax + b\ntemplate<typename T>\nclass\
    \ LinearExpression {\npublic:\n    T a;\n    T b;\n\n    LinearExpression(T a\
    \ = 0, T b = 0) : a(a), b(b) {}\n\n    T evaluate(T x) const {\n        return\
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
    \   }\n};\n#line 4 \"test/cpp/Math/LinearExpression1.test.cpp\"\n#include <iostream>\n\
    #include <vector>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int N;\n    cin >> N;\n    vector<LinearExpression<long\
    \ long>> A(N);\n    for (int i = 0; i < N; ++i) {\n        cin >> A[i].b;\n  \
    \  }\n\n    vector<LinearExpression<long long>> ans(N + 1);\n    ans[0] = LinearExpression<long\
    \ long>(1, 0);\n    for (int i = 0; i < N; ++i) {\n        ans[i + 1] = A[i] *\
    \ 2 - ans[i];\n    }\n    // ans[0] == ans[N] == x\n    const auto x = ans[N].find_x(ans[0]);\n\
    \n    for (int i = 0; i < N; ++i) {\n        if (i != 0) {\n            cout <<\
    \ \" \";\n        }\n        cout << ans[i].evaluate(x);\n    }\n    cout << endl;\n\
    \n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc133/tasks/abc133_d\"\n\n\
    #include \"library/cpp/Math/LinearExpression.hpp\"\n#include <iostream>\n#include\
    \ <vector>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n  \
    \  ios::sync_with_stdio(false);\n\n    int N;\n    cin >> N;\n    vector<LinearExpression<long\
    \ long>> A(N);\n    for (int i = 0; i < N; ++i) {\n        cin >> A[i].b;\n  \
    \  }\n\n    vector<LinearExpression<long long>> ans(N + 1);\n    ans[0] = LinearExpression<long\
    \ long>(1, 0);\n    for (int i = 0; i < N; ++i) {\n        ans[i + 1] = A[i] *\
    \ 2 - ans[i];\n    }\n    // ans[0] == ans[N] == x\n    const auto x = ans[N].find_x(ans[0]);\n\
    \n    for (int i = 0; i < N; ++i) {\n        if (i != 0) {\n            cout <<\
    \ \" \";\n        }\n        cout << ans[i].evaluate(x);\n    }\n    cout << endl;\n\
    \n    return 0;\n}"
  dependsOn:
  - library/cpp/Math/LinearExpression.hpp
  isVerificationFile: true
  path: test/cpp/Math/LinearExpression1.test.cpp
  requiredBy: []
  timestamp: '2024-02-03 20:15:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Math/LinearExpression1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Math/LinearExpression1.test.cpp
- /verify/test/cpp/Math/LinearExpression1.test.cpp.html
title: test/cpp/Math/LinearExpression1.test.cpp
---
