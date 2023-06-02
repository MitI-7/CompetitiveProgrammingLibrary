---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Geometry/Point.hpp
    title: library/cpp/Geometry/Point.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-6
    PROBLEM: https://atcoder.jp/contests/abc259/tasks/abc259_b
    links:
    - https://atcoder.jp/contests/abc259/tasks/abc259_b
  bundledCode: "#line 1 \"test/cpp/Geometry/Point1_rotate.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc259/tasks/abc259_b\"\n#define ERROR 1e-6\n\n\
    #line 1 \"library/cpp/Geometry/Point.hpp\"\n#include <cmath>\n\ntemplate<class\
    \ T>\nclass Point {\npublic:\n    T x;\n    T y;\n    int no;\n\n    Point() :\
    \ x(0), y(0), no(0) {};\n\n    Point(const T x, const T y, int no = 0) : x(x),\
    \ y(y), no(no) {}\n\n    // \u539F\u70B9\u3092\u4E2D\u5FC3\u3068\u3057\u3066\uFF0C\
    \u53CD\u6642\u8A08\u56DE\u308A\u306B theta \u56DE\u8EE2\u3055\u305B\u305F\u70B9\
    \u3092\u6C42\u3081\u308B\n    Point<T> rotate(double theta) const {\n        return\
    \ Point<T>(this->x * std::cos(theta) - this->y * std::sin(theta),\n          \
    \              this->x * std::sin(theta) + this->y * std::cos(theta));\n    }\n\
    \n    // \u5185\u7A4D (dot product) : a\u22C5b = |a||b|cos\u03B8\n    double dot(const\
    \ Point<T> &p) const {\n        return this->x * p.x + this->y * p.y;\n    }\n\
    \n    // \u5916\u7A4D (cross product) : a\xD7b = |a||b|sin\u03B8\n    double cross(const\
    \ Point<T> &p) const {\n        return this->y * p.x - this->x * p.y;\n    }\n\
    \n    Point<T> operator+(const Point<T> a) const {\n        Point<T> res(*this);\n\
    \        res.y += a.y;\n        res.x += a.x;\n        return res;\n    }\n\n\
    \    Point<T> operator-(const Point<T> a) const {\n        Point<T> res(*this);\n\
    \        res.y -= a.y;\n        res.x -= a.x;\n        return res;\n    }\n};\n\
    #line 5 \"test/cpp/Geometry/Point1_rotate.test.cpp\"\n#include <iostream>\n#include\
    \ <iomanip>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n \
    \   ios::sync_with_stdio(false);\n\n    double A, B, D;\n    cin >> A >> B >>\
    \ D;\n\n    double theta = D * (M_PI / 180.0);\n\n    Point<double> p(A, B);\n\
    \    auto ans = p.rotate(theta);\n    cout << setprecision(10) << fixed << ans.x\
    \ << \" \" << ans.y << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc259/tasks/abc259_b\"\n#define\
    \ ERROR 1e-6\n\n#include \"library/cpp/Geometry/Point.hpp\"\n#include <iostream>\n\
    #include <iomanip>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    double A, B, D;\n    cin >> A >> B >>\
    \ D;\n\n    double theta = D * (M_PI / 180.0);\n\n    Point<double> p(A, B);\n\
    \    auto ans = p.rotate(theta);\n    cout << setprecision(10) << fixed << ans.x\
    \ << \" \" << ans.y << endl;\n\n    return 0;\n}\n"
  dependsOn:
  - library/cpp/Geometry/Point.hpp
  isVerificationFile: true
  path: test/cpp/Geometry/Point1_rotate.test.cpp
  requiredBy: []
  timestamp: '2023-06-02 16:47:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Geometry/Point1_rotate.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Geometry/Point1_rotate.test.cpp
- /verify/test/cpp/Geometry/Point1_rotate.test.cpp.html
title: test/cpp/Geometry/Point1_rotate.test.cpp
---
