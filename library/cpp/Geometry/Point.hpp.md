---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Geometry/Polygon.hpp
    title: library/cpp/Geometry/Polygon.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Geometry/Point1_rotate.test.cpp
    title: test/cpp/Geometry/Point1_rotate.test.cpp
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
  bundledCode: "#line 1 \"library/cpp/Geometry/Point.hpp\"\n#include <cmath>\n\ntemplate<class\
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
    \n    T norm2() const {\n        return this->x * this->x + this->y * this->y;\n\
    \    }\n\n    Point<T> operator+(const Point<T> &p) const {\n        return Point<T>(this->x\
    \ + p.x, this->y + p.y);\n    }\n\n    Point<T> operator-(const Point<T> p) const\
    \ {\n        return Point<T>(this->x - p.x, this->y - p.y);\n    }\n\n    Point<T>\
    \ operator*(const T d) const {\n        return Point<T>(this->x * d, this->y *\
    \ d);\n    }\n\n    Point<T> operator/(const T d) const {\n        return Point<T>(this->x\
    \ / d, this->y / d);\n    }\n};\n"
  code: "#include <cmath>\n\ntemplate<class T>\nclass Point {\npublic:\n    T x;\n\
    \    T y;\n    int no;\n\n    Point() : x(0), y(0), no(0) {};\n\n    Point(const\
    \ T x, const T y, int no = 0) : x(x), y(y), no(no) {}\n\n    // \u539F\u70B9\u3092\
    \u4E2D\u5FC3\u3068\u3057\u3066\uFF0C\u53CD\u6642\u8A08\u56DE\u308A\u306B theta\
    \ \u56DE\u8EE2\u3055\u305B\u305F\u70B9\u3092\u6C42\u3081\u308B\n    Point<T> rotate(double\
    \ theta) const {\n        return Point<T>(this->x * std::cos(theta) - this->y\
    \ * std::sin(theta),\n                        this->x * std::sin(theta) + this->y\
    \ * std::cos(theta));\n    }\n\n    // \u5185\u7A4D (dot product) : a\u22C5b =\
    \ |a||b|cos\u03B8\n    double dot(const Point<T> &p) const {\n        return this->x\
    \ * p.x + this->y * p.y;\n    }\n\n    // \u5916\u7A4D (cross product) : a\xD7\
    b = |a||b|sin\u03B8\n    double cross(const Point<T> &p) const {\n        return\
    \ this->y * p.x - this->x * p.y;\n    }\n\n    T norm2() const {\n        return\
    \ this->x * this->x + this->y * this->y;\n    }\n\n    Point<T> operator+(const\
    \ Point<T> &p) const {\n        return Point<T>(this->x + p.x, this->y + p.y);\n\
    \    }\n\n    Point<T> operator-(const Point<T> p) const {\n        return Point<T>(this->x\
    \ - p.x, this->y - p.y);\n    }\n\n    Point<T> operator*(const T d) const {\n\
    \        return Point<T>(this->x * d, this->y * d);\n    }\n\n    Point<T> operator/(const\
    \ T d) const {\n        return Point<T>(this->x / d, this->y / d);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Geometry/Point.hpp
  requiredBy:
  - library/cpp/Geometry/Polygon.hpp
  timestamp: '2023-06-02 16:47:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Geometry/Polygon3_is_convex.test.cpp
  - test/cpp/Geometry/Polygon2_area.test.cpp
  - test/cpp/Geometry/Polygon1_area.test.cpp
  - test/cpp/Geometry/Point1_rotate.test.cpp
documentation_of: library/cpp/Geometry/Point.hpp
layout: document
redirect_from:
- /library/library/cpp/Geometry/Point.hpp
- /library/library/cpp/Geometry/Point.hpp.html
title: library/cpp/Geometry/Point.hpp
---
