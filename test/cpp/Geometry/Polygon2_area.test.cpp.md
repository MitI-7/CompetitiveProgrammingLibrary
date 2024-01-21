---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/cpp/Geometry/Point.hpp
    title: library/cpp/Geometry/Point.hpp
  - icon: ':x:'
    path: library/cpp/Geometry/Polygon.hpp
    title: library/cpp/Geometry/Polygon.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1100
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1100
  bundledCode: "#line 1 \"test/cpp/Geometry/Polygon2_area.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1100\"\n\n#line\
    \ 1 \"library/cpp/Geometry/Polygon.hpp\"\n#include <cmath>\n#include <vector>\n\
    #line 2 \"library/cpp/Geometry/Point.hpp\"\n\ntemplate<class T>\nclass Point {\n\
    public:\n    T x;\n    T y;\n    int no;\n\n    Point() : x(0), y(0), no(0) {};\n\
    \n    Point(const T x, const T y, int no = 0) : x(x), y(y), no(no) {}\n\n    //\
    \ \u539F\u70B9\u3092\u4E2D\u5FC3\u3068\u3057\u3066\uFF0C\u53CD\u6642\u8A08\u56DE\
    \u308A\u306B theta \u56DE\u8EE2\u3055\u305B\u305F\u70B9\u3092\u6C42\u3081\u308B\
    \n    Point<T> rotate(double theta) const {\n        return Point<T>(this->x *\
    \ std::cos(theta) - this->y * std::sin(theta),\n                        this->x\
    \ * std::sin(theta) + this->y * std::cos(theta));\n    }\n\n    // \u5185\u7A4D\
    \ (dot product) : a\u22C5b = |a||b|cos\u03B8\n    double dot(const Point<T> &p)\
    \ const {\n        return this->x * p.x + this->y * p.y;\n    }\n\n    // \u5916\
    \u7A4D (cross product) : a\xD7b = |a||b|sin\u03B8\n    double cross(const Point<T>\
    \ &p) const {\n        return this->y * p.x - this->x * p.y;\n    }\n\n    T norm2()\
    \ const {\n        return this->x * this->x + this->y * this->y;\n    }\n\n  \
    \  Point<T> operator+(const Point<T> &p) const {\n        return Point<T>(this->x\
    \ + p.x, this->y + p.y);\n    }\n\n    Point<T> operator-(const Point<T> p) const\
    \ {\n        return Point<T>(this->x - p.x, this->y - p.y);\n    }\n\n    Point<T>\
    \ operator*(const T d) const {\n        return Point<T>(this->x * d, this->y *\
    \ d);\n    }\n\n    Point<T> operator/(const T d) const {\n        return Point<T>(this->x\
    \ / d, this->y / d);\n    }\n};\n#line 4 \"library/cpp/Geometry/Polygon.hpp\"\n\
    \ntemplate<class T>\nclass Polygon {\npublic:\n    const int n;\n    const std::vector<Point<T>>\
    \ points;\n\n    // points: \u591A\u89D2\u5F62\u306E\u96A3\u308A\u5408\u3063\u305F\
    \u70B9\u3092\u53CD\u6642\u8A08\u56DE\u308A\u306E\u9806\u756A\u3067\u683C\u7D0D\
    \u3057\u305F\u3082\u306E\n    explicit Polygon(const std::vector<Point<T>> &points)\
    \ : n(points.size()), points(points) {}\n\n    // \u591A\u89D2\u5F62\u306E\u9762\
    \u7A4D\u306E 2 \u500D\u3092\u6C42\u3081\u308B\n    // \u51F8\u3067\u306A\u304F\
    \u3066\u3082\u3044\u3044\n    // 1/2 |sum_i x_i * y_(i+1) - x_(i+1) * y_i|\n \
    \   T double_polygon_area() const {\n        T area = 0;\n        for (int i =\
    \ 0; i < this->n; ++i) {\n            area += this->points[i].x * this->points[(i\
    \ + 1) % this->n].y\n                    - this->points[(i + 1) % this->n].x *\
    \ this->points[i].y;\n        }\n        return std::abs(area);\n    }\n\n   \
    \ // \u51F8\u591A\u89D2\u5F62\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B\n\
    \    [[nodiscard]] bool is_convex() const {\n        for (int i = 0; i < this->n;\
    \ ++i) {\n            auto a = this->points[i % this->n];\n            auto b\
    \ = this->points[(i + 1) % this->n];\n            auto c = this->points[(i + 2)\
    \ % this->n];\n\n            const auto y1 = b.y - a.y;\n            const auto\
    \ x1 = b.x - a.x;\n            const auto y2 = c.y - b.y;\n            const auto\
    \ x2 = c.x - b.x;\n\n            const auto p1 = Point<T>(x1, y1);\n         \
    \   const auto p2 = Point<T>(x2, y2);\n\n            if (p1.cross(p2) > 0) {\n\
    \                return false;\n            }\n        }\n\n        return true;\n\
    \    }\n};\n#line 4 \"test/cpp/Geometry/Polygon2_area.test.cpp\"\n#include <iomanip>\n\
    #include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int no = 1;\n    while (true) {\n   \
    \     int N;\n        cin >> N;\n        if (N == 0) {\n            break;\n \
    \       }\n\n        vector <Point<double>> points(N);\n        for (int i = 0;\
    \ i < N; ++i) {\n            double X, Y;\n            cin >> X >> Y;\n      \
    \      points[i] = {X, Y};\n        }\n\n        Polygon<double> polygon(points);\n\
    \        cout << no++ << \" \" << setprecision(1) << fixed << polygon.double_polygon_area()\
    \ / 2.0 << endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1100\"\
    \n\n#include \"library/cpp/Geometry/Polygon.hpp\"\n#include <iomanip>\n#include\
    \ <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int no = 1;\n    while (true) {\n   \
    \     int N;\n        cin >> N;\n        if (N == 0) {\n            break;\n \
    \       }\n\n        vector <Point<double>> points(N);\n        for (int i = 0;\
    \ i < N; ++i) {\n            double X, Y;\n            cin >> X >> Y;\n      \
    \      points[i] = {X, Y};\n        }\n\n        Polygon<double> polygon(points);\n\
    \        cout << no++ << \" \" << setprecision(1) << fixed << polygon.double_polygon_area()\
    \ / 2.0 << endl;\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - library/cpp/Geometry/Polygon.hpp
  - library/cpp/Geometry/Point.hpp
  isVerificationFile: true
  path: test/cpp/Geometry/Polygon2_area.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:46:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/cpp/Geometry/Polygon2_area.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Geometry/Polygon2_area.test.cpp
- /verify/test/cpp/Geometry/Polygon2_area.test.cpp.html
title: test/cpp/Geometry/Polygon2_area.test.cpp
---
