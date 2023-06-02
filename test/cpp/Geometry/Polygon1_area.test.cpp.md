---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Geometry/Point.hpp
    title: library/cpp/Geometry/Point.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/Geometry/Polygon.hpp
    title: library/cpp/Geometry/Polygon.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-1
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A
  bundledCode: "#line 1 \"test/cpp/Geometry/Polygon1_area.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A\"\n#define\
    \ ERROR 1e-1\n\n#line 1 \"library/cpp/Geometry/Polygon.hpp\"\n#include <cmath>\n\
    #include <vector>\n#line 2 \"library/cpp/Geometry/Point.hpp\"\n\ntemplate<class\
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
    \ / d, this->y / d);\n    }\n};\n#line 4 \"library/cpp/Geometry/Polygon.hpp\"\n\
    \ntemplate<class T>\nclass Polygon {\npublic:\n    int n;\n    const std::vector<Point<T>>\
    \ points;\n\n    explicit Polygon(const std::vector<Point<T>> &points) : n(points.size()),\
    \ points(points) {}\n\n    // \u591A\u89D2\u5F62\u306E\u9762\u7A4D\u306E 2 \u500D\
    \u3092\u6C42\u3081\u308B\n    // \u51F8\u3067\u306A\u304F\u3066\u3082\u3044\u3044\
    \n    // 1/2 |sum_i x_i * y_(i+1) - x_(i+1) * y_i|\n    T double_polygon_area()\
    \ const {\n        T area = 0;\n        for (int i = 0; i < this->n; ++i) {\n\
    \            area += this->points[i].x * this->points[(i + 1) % this->n].y\n \
    \                   - this->points[(i + 1) % this->n].x * this->points[i].y;\n\
    \        }\n        return std::abs(area);\n    }\n};\n#line 5 \"test/cpp/Geometry/Polygon1_area.test.cpp\"\
    \n#include <iomanip>\n#include <iostream>\n\nusing namespace std;\n\nint main()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    int N;\n \
    \   cin >> N;\n    vector<Point<double>> points(N);\n    for (int i = 0; i < N;\
    \ ++i) {\n        double X, Y;\n        cin >> X >> Y;\n        points[i] = {X,\
    \ Y};\n    }\n\n    Polygon<double> polygon(points);\n    cout << setprecision(1)\
    \ << fixed << polygon.double_polygon_area() / 2.0 << endl;\n\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A\"\
    \n#define ERROR 1e-1\n\n#include \"library/cpp/Geometry/Polygon.hpp\"\n#include\
    \ <iomanip>\n#include <iostream>\n\nusing namespace std;\n\nint main() {\n   \
    \ cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    int N;\n    cin >>\
    \ N;\n    vector<Point<double>> points(N);\n    for (int i = 0; i < N; ++i) {\n\
    \        double X, Y;\n        cin >> X >> Y;\n        points[i] = {X, Y};\n \
    \   }\n\n    Polygon<double> polygon(points);\n    cout << setprecision(1) <<\
    \ fixed << polygon.double_polygon_area() / 2.0 << endl;\n\n    return 0;\n}\n"
  dependsOn:
  - library/cpp/Geometry/Polygon.hpp
  - library/cpp/Geometry/Point.hpp
  isVerificationFile: true
  path: test/cpp/Geometry/Polygon1_area.test.cpp
  requiredBy: []
  timestamp: '2023-06-02 17:18:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Geometry/Polygon1_area.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Geometry/Polygon1_area.test.cpp
- /verify/test/cpp/Geometry/Polygon1_area.test.cpp.html
title: test/cpp/Geometry/Polygon1_area.test.cpp
---
