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
    #line 1 \"library/cpp/Geometry/Point.hpp\"\n#include <cmath>\n#include <ostream>\n\
    \ntemplate<class T>\nclass Point {\npublic:\n    T x;\n    T y;\n    int no;\n\
    \    double EPS = 1e-10;\n\n    Point() : x(0), y(0), no(0) {};\n\n    Point(const\
    \ T x, const T y, int no = 0, double eps = 1e-10) : x(x), y(y), no(no), EPS(eps)\
    \ {}\n\n    // \u539F\u70B9\u3092\u4E2D\u5FC3\u3068\u3057\u3066\uFF0C\u53CD\u6642\
    \u8A08\u56DE\u308A\u306B theta \u56DE\u8EE2\u3055\u305B\u305F\u70B9\u3092\u6C42\
    \u3081\u308B\n    Point<T> rotate(double theta) const {\n        return Point<T>(this->x\
    \ * std::cos(theta) - this->y * std::sin(theta),\n                        this->x\
    \ * std::sin(theta) + this->y * std::cos(theta));\n    }\n\n    // \u5185\u7A4D\
    \ (dot product) : a\u22C5b = |a||b|cos\u03B8\n    double dot(const Point<T> &p)\
    \ const {\n        return this->x * p.x + this->y * p.y;\n    }\n\n    // \u5916\
    \u7A4D (cross product) : a\xD7b = |a||b|sin\u03B8\n    double cross(const Point<T>\
    \ &p) const {\n        return this->y * p.x - this->x * p.y;\n    }\n\n    T norm2()\
    \ const {\n        return this->x * this->x + this->y * this->y;\n    }\n\n  \
    \  double radian() const {\n        return atan2(this->y, this->x);\n    }\n\n\
    \    Point<T> &operator+=(const Point<T> &p) {\n        this->x += p.x;\n    \
    \    this->y += p.y;\n        return *this;\n    }\n\n    Point<T> operator+(const\
    \ Point<T> &p) const {\n        return Point<T>(this->x + p.x, this->y + p.y);\n\
    \    }\n\n    Point<T> &operator-=(const Point<T> &p) {\n        this->x -= p.x;\n\
    \        this->y -= p.y;\n        return *this;\n    }\n\n    Point<T> operator-(const\
    \ Point<T> &p) const {\n        return Point<T>(this->x - p.x, this->y - p.y);\n\
    \    }\n\n    Point<T> &operator*=(const T d) {\n        this->x *= d;\n     \
    \   this->y *= d;\n        return *this;\n    }\n\n    Point<T> operator*(const\
    \ T d) const {\n        return Point<T>(this->x * d, this->y * d);\n    }\n\n\
    \    Point<T> operator/(const T d) const {\n        return Point<T>(this->x /\
    \ d, this->y / d);\n    }\n\n    bool operator==(const Point<T> &p) const {\n\
    \        return std::abs(this->x - p.x) <= this->EPS and std::abs(this->y - p.y)\
    \ <= this->EPS;\n    }\n\n    // \u8C61\u9650\n    int orthant() const {\n   \
    \     if (std::abs(this->x) < this->EPS and std::abs(this->y) < this->EPS) {\n\
    \            return 0;\n        }\n        if (this->y > 0) {\n            return\
    \ this->x > 0 ? 1 : 2;\n        } else {\n            return this->x < 0 ? 3 :\
    \ 4;\n        }\n    }\n\n    // \u504F\u89D2\u30BD\u30FC\u30C8\u7528(\u53CD\u6642\
    \u8A08\u56DE\u308A\u306B\u30BD\u30FC\u30C8)\n    // \u8AA4\u5DEE\u306B\u6CE8\u610F\
    \n    static bool radian_sort_cmp_key(const Point &l, const Point &r) {\n    \
    \    return l.adian() < r.radian();\n    }\n\n    // (x, y)\u3067\u30BD\u30FC\u30C8\
    \n    static bool xy_sort_cmp_key(const Point &l, const Point &r) {\n        if\
    \ (fabs(l.x - r.x) < 1e-10) {\n            return l.y < r.y;\n        }\n    \
    \    return l.x < r.x;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Point<T> &p) {\n        os << \"(x=\" << p.x << \", y=\" << p.y <<\
    \ \")\";\n        return os;\n    }\n};\n#line 5 \"test/cpp/Geometry/Point1_rotate.test.cpp\"\
    \n#include <iomanip>\n#include <iostream>\n\nusing namespace std;\n\nint main()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    double A,\
    \ B, D;\n    cin >> A >> B >> D;\n\n    double theta = D * (M_PI / 180.0);\n\n\
    \    Point<double> p(A, B);\n    auto ans = p.rotate(theta);\n    cout << setprecision(10)\
    \ << fixed << ans.x << \" \" << ans.y << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc259/tasks/abc259_b\"\n#define\
    \ ERROR 1e-6\n\n#include \"library/cpp/Geometry/Point.hpp\"\n#include <iomanip>\n\
    #include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    double A, B, D;\n    cin >> A >> B >>\
    \ D;\n\n    double theta = D * (M_PI / 180.0);\n\n    Point<double> p(A, B);\n\
    \    auto ans = p.rotate(theta);\n    cout << setprecision(10) << fixed << ans.x\
    \ << \" \" << ans.y << endl;\n\n    return 0;\n}\n"
  dependsOn:
  - library/cpp/Geometry/Point.hpp
  isVerificationFile: true
  path: test/cpp/Geometry/Point1_rotate.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:45:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Geometry/Point1_rotate.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Geometry/Point1_rotate.test.cpp
- /verify/test/cpp/Geometry/Point1_rotate.test.cpp.html
title: test/cpp/Geometry/Point1_rotate.test.cpp
---
