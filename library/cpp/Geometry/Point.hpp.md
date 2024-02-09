---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Geometry/Line.hpp
    title: library/cpp/Geometry/Line.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/Geometry/Polygon.hpp
    title: library/cpp/Geometry/Polygon.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Geometry/Line1_is_parallel.test.cpp
    title: test/cpp/Geometry/Line1_is_parallel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Geometry/Line2_is_intersection.test.cpp
    title: test/cpp/Geometry/Line2_is_intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Geometry/Line3_oline.test.cpp
    title: test/cpp/Geometry/Line3_oline.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Geometry/Line4_slope.test.cpp
    title: test/cpp/Geometry/Line4_slope.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Geometry/Point1_rotate.test.cpp
    title: test/cpp/Geometry/Point1_rotate.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Geometry/Point2.test.cpp
    title: test/cpp/Geometry/Point2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Geometry/Polygon1_area.test.cpp
    title: test/cpp/Geometry/Polygon1_area.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Geometry/Polygon2_area.test.cpp
    title: test/cpp/Geometry/Polygon2_area.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Geometry/Polygon3_is_convex.test.cpp
    title: test/cpp/Geometry/Polygon3_is_convex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Geometry/Point.hpp\"\n#include <cmath>\n#include\
    \ <ostream>\n\ntemplate<class T>\nclass Point {\npublic:\n    T x;\n    T y;\n\
    \    int no;\n    double EPS = 1e-10;\n\n    Point() : x(0), y(0), no(0) {};\n\
    \n    Point(const T x, const T y, int no = 0, double eps = 1e-10) : x(x), y(y),\
    \ no(no), EPS(eps) {}\n\n    // \u539F\u70B9\u3092\u4E2D\u5FC3\u3068\u3057\u3066\
    \uFF0C\u53CD\u6642\u8A08\u56DE\u308A\u306B theta \u56DE\u8EE2\u3055\u305B\u305F\
    \u70B9\u3092\u6C42\u3081\u308B\n    Point<T> rotate(double theta) const {\n  \
    \      return Point<T>(this->x * std::cos(theta) - this->y * std::sin(theta),\n\
    \                        this->x * std::sin(theta) + this->y * std::cos(theta));\n\
    \    }\n\n    // \u5185\u7A4D (dot product) : a\u22C5b = |a||b|cos\u03B8\n   \
    \ double dot(const Point<T> &p) const {\n        return this->x * p.x + this->y\
    \ * p.y;\n    }\n\n    // \u5916\u7A4D (cross product) : a\xD7b = |a||b|sin\u03B8\
    \n    double cross(const Point<T> &p) const {\n        return this->y * p.x -\
    \ this->x * p.y;\n    }\n\n    T norm2() const {\n        return this->x * this->x\
    \ + this->y * this->y;\n    }\n\n    double radian() const {\n        return atan2(this->y,\
    \ this->x);\n    }\n\n    Point<T> &operator+=(const Point<T> &p) {\n        this->x\
    \ += p.x;\n        this->y += p.y;\n        return *this;\n    }\n\n    Point<T>\
    \ operator+(const Point<T> &p) const {\n        return Point<T>(this->x + p.x,\
    \ this->y + p.y);\n    }\n\n    Point<T> &operator-=(const Point<T> &p) {\n  \
    \      this->x -= p.x;\n        this->y -= p.y;\n        return *this;\n    }\n\
    \n    Point<T> operator-(const Point<T> &p) const {\n        return Point<T>(this->x\
    \ - p.x, this->y - p.y);\n    }\n\n    Point<T> &operator*=(const T d) {\n   \
    \     this->x *= d;\n        this->y *= d;\n        return *this;\n    }\n\n \
    \   Point<T> operator*(const T d) const {\n        return Point<T>(this->x * d,\
    \ this->y * d);\n    }\n\n    Point<T> operator/(const T d) const {\n        return\
    \ Point<T>(this->x / d, this->y / d);\n    }\n\n    bool operator==(const Point<T>\
    \ &p) const {\n        return std::abs(this->x - p.x) <= this->EPS and std::abs(this->y\
    \ - p.y) <= this->EPS;\n    }\n\n    // \u8C61\u9650\n    int orthant() const\
    \ {\n        if (std::abs(this->x) < this->EPS and std::abs(this->y) < this->EPS)\
    \ {\n            return 0;\n        }\n        if (this->y > 0) {\n          \
    \  return this->x > 0 ? 1 : 2;\n        } else {\n            return this->x <\
    \ 0 ? 3 : 4;\n        }\n    }\n\n    // \u504F\u89D2\u30BD\u30FC\u30C8\u7528\
    (\u53CD\u6642\u8A08\u56DE\u308A\u306B\u30BD\u30FC\u30C8)\n    // \u8AA4\u5DEE\u306B\
    \u6CE8\u610F\n    static bool radian_sort_cmp_key(const Point &l, const Point\
    \ &r) {\n        return l.adian() < r.radian();\n    }\n\n    // xy\u3067\u30BD\
    \u30FC\u30C8\n    static bool xy_sort_cmp_key(const Point &l, const Point &r)\
    \ {\n        if (fabs(l.x - r.x) < 1e-10) {\n            return l.y < r.y;\n \
    \       }\n        return l.x < r.x;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Point<T> &p) {\n        os << \"(x=\" << p.x << \", y=\" << p.y <<\
    \ \")\";\n        return os;\n    }\n};\n"
  code: "#include <cmath>\n#include <ostream>\n\ntemplate<class T>\nclass Point {\n\
    public:\n    T x;\n    T y;\n    int no;\n    double EPS = 1e-10;\n\n    Point()\
    \ : x(0), y(0), no(0) {};\n\n    Point(const T x, const T y, int no = 0, double\
    \ eps = 1e-10) : x(x), y(y), no(no), EPS(eps) {}\n\n    // \u539F\u70B9\u3092\u4E2D\
    \u5FC3\u3068\u3057\u3066\uFF0C\u53CD\u6642\u8A08\u56DE\u308A\u306B theta \u56DE\
    \u8EE2\u3055\u305B\u305F\u70B9\u3092\u6C42\u3081\u308B\n    Point<T> rotate(double\
    \ theta) const {\n        return Point<T>(this->x * std::cos(theta) - this->y\
    \ * std::sin(theta),\n                        this->x * std::sin(theta) + this->y\
    \ * std::cos(theta));\n    }\n\n    // \u5185\u7A4D (dot product) : a\u22C5b =\
    \ |a||b|cos\u03B8\n    double dot(const Point<T> &p) const {\n        return this->x\
    \ * p.x + this->y * p.y;\n    }\n\n    // \u5916\u7A4D (cross product) : a\xD7\
    b = |a||b|sin\u03B8\n    double cross(const Point<T> &p) const {\n        return\
    \ this->y * p.x - this->x * p.y;\n    }\n\n    T norm2() const {\n        return\
    \ this->x * this->x + this->y * this->y;\n    }\n\n    double radian() const {\n\
    \        return atan2(this->y, this->x);\n    }\n\n    Point<T> &operator+=(const\
    \ Point<T> &p) {\n        this->x += p.x;\n        this->y += p.y;\n        return\
    \ *this;\n    }\n\n    Point<T> operator+(const Point<T> &p) const {\n       \
    \ return Point<T>(this->x + p.x, this->y + p.y);\n    }\n\n    Point<T> &operator-=(const\
    \ Point<T> &p) {\n        this->x -= p.x;\n        this->y -= p.y;\n        return\
    \ *this;\n    }\n\n    Point<T> operator-(const Point<T> &p) const {\n       \
    \ return Point<T>(this->x - p.x, this->y - p.y);\n    }\n\n    Point<T> &operator*=(const\
    \ T d) {\n        this->x *= d;\n        this->y *= d;\n        return *this;\n\
    \    }\n\n    Point<T> operator*(const T d) const {\n        return Point<T>(this->x\
    \ * d, this->y * d);\n    }\n\n    Point<T> operator/(const T d) const {\n   \
    \     return Point<T>(this->x / d, this->y / d);\n    }\n\n    bool operator==(const\
    \ Point<T> &p) const {\n        return std::abs(this->x - p.x) <= this->EPS and\
    \ std::abs(this->y - p.y) <= this->EPS;\n    }\n\n    // \u8C61\u9650\n    int\
    \ orthant() const {\n        if (std::abs(this->x) < this->EPS and std::abs(this->y)\
    \ < this->EPS) {\n            return 0;\n        }\n        if (this->y > 0) {\n\
    \            return this->x > 0 ? 1 : 2;\n        } else {\n            return\
    \ this->x < 0 ? 3 : 4;\n        }\n    }\n\n    // \u504F\u89D2\u30BD\u30FC\u30C8\
    \u7528(\u53CD\u6642\u8A08\u56DE\u308A\u306B\u30BD\u30FC\u30C8)\n    // \u8AA4\u5DEE\
    \u306B\u6CE8\u610F\n    static bool radian_sort_cmp_key(const Point &l, const\
    \ Point &r) {\n        return l.adian() < r.radian();\n    }\n\n    // xy\u3067\
    \u30BD\u30FC\u30C8\n    static bool xy_sort_cmp_key(const Point &l, const Point\
    \ &r) {\n        if (fabs(l.x - r.x) < 1e-10) {\n            return l.y < r.y;\n\
    \        }\n        return l.x < r.x;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Point<T> &p) {\n        os << \"(x=\" << p.x << \", y=\" << p.y <<\
    \ \")\";\n        return os;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Geometry/Point.hpp
  requiredBy:
  - library/cpp/Geometry/Line.hpp
  - library/cpp/Geometry/Polygon.hpp
  timestamp: '2024-01-20 16:45:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Geometry/Point1_rotate.test.cpp
  - test/cpp/Geometry/Polygon2_area.test.cpp
  - test/cpp/Geometry/Line3_oline.test.cpp
  - test/cpp/Geometry/Polygon1_area.test.cpp
  - test/cpp/Geometry/Line2_is_intersection.test.cpp
  - test/cpp/Geometry/Line4_slope.test.cpp
  - test/cpp/Geometry/Point2.test.cpp
  - test/cpp/Geometry/Line1_is_parallel.test.cpp
  - test/cpp/Geometry/Polygon3_is_convex.test.cpp
documentation_of: library/cpp/Geometry/Point.hpp
layout: document
redirect_from:
- /library/library/cpp/Geometry/Point.hpp
- /library/library/cpp/Geometry/Point.hpp.html
title: library/cpp/Geometry/Point.hpp
---
