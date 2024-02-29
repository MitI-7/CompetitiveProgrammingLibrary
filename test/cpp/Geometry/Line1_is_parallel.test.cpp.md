---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Geometry/Line.hpp
    title: library/cpp/Geometry/Line.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
  bundledCode: "#line 1 \"test/cpp/Geometry/Line1_is_parallel.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A\"\
    \n\n#line 1 \"library/cpp/Geometry/Point.hpp\"\n#include <cmath>\n#include <numeric>\n\
    #include <ostream>\n\ntemplate<class T>\nclass Point {\npublic:\n    T x;\n  \
    \  T y;\n    int no;\n    double EPS = 1e-10;\n\n    Point() : x(0), y(0), no(0)\
    \ {};\n\n    Point(const T x, const T y, int no = 0, double eps = 1e-10) : x(x),\
    \ y(y), no(no), EPS(eps) {}\n\n    // \u539F\u70B9\u3092\u4E2D\u5FC3\u3068\u3057\
    \u3066\uFF0C\u53CD\u6642\u8A08\u56DE\u308A\u306B theta \u56DE\u8EE2\u3055\u305B\
    \u305F\u70B9\u3092\u6C42\u3081\u308B\n    Point<T> rotate(double theta) const\
    \ {\n        return Point<T>(this->x * std::cos(theta) - this->y * std::sin(theta),\n\
    \                        this->x * std::sin(theta) + this->y * std::cos(theta));\n\
    \    }\n\n    // \u5185\u7A4D (dot product) : a\u22C5b = |a||b|cos\u03B8\n   \
    \ double dot(const Point<T> &p) const {\n        return this->x * p.x + this->y\
    \ * p.y;\n    }\n\n    // \u5916\u7A4D (cross product) : a\xD7b = |a||b|sin\u03B8\
    \n    double cross(const Point<T> &p) const {\n        return this->y * p.x -\
    \ this->x * p.y;\n    }\n\n    T norm2() const {\n        return this->x * this->x\
    \ + this->y * this->y;\n    }\n\n    double radian() const {\n        return atan2(this->y,\
    \ this->x);\n    }\n\n    // \u50BE\u304D\u3092\u6709\u7406\u6570\u3067\u8FD4\u3059\
    (first / second)\n    // \u50BE\u304D\u304C\u7121\u9650\u306B\u306A\u3063\u3066\
    \u3057\u307E\u3046\u5834\u5408\u306F (1, 0) \u3068\u3059\u308B\n    std::pair<T,\
    \ T> slope() {\n        auto dx = this->x;\n        auto dy = this->y;\n     \
    \   if (dx < 0) {\n            dx = -dx;\n            dy = -dy;\n        }\n\n\
    \        // \u7E26\n        if (dx == 0) {\n            dy = 1;\n        } else\
    \ {\n            auto g = std::gcd(dx, dy);\n            dx /= g;\n          \
    \  dy /= g;\n        }\n\n        return {dy, dx};\n    }\n\n    Point<T> &operator+=(const\
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
    \ Point &r) {\n        return l.adian() < r.radian();\n    }\n\n    // (x, y)\u3067\
    \u30BD\u30FC\u30C8\n    static bool xy_sort_cmp_key(const Point &l, const Point\
    \ &r) {\n        if (fabs(l.x - r.x) < 1e-10) {\n            return l.y < r.y;\n\
    \        }\n        return l.x < r.x;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Point<T> &p) {\n        os << \"(x=\" << p.x << \", y=\" << p.y <<\
    \ \")\";\n        return os;\n    }\n};\n#line 3 \"library/cpp/Geometry/Line.hpp\"\
    \n#include <utility>\n\n// \u5E73\u9762\u4E0A\u306E\u7DDA\u5206\ntemplate<class\
    \ T=long long>\nclass Line {\npublic:\n    constexpr static const double epsilon\
    \ = 1e-9;\n    Point<T> a;\n    Point<T> b;\n\n    Line() = default;\n\n    Line(const\
    \ Point<T> a, const Point<T> b) : a(a), b(b) {}\n\n    // line \u306E\u50BE\u304D\
    \uFF0E\u6709\u7406\u6570\u3067\u8FD4\u3059\n    // line \u304C\u7E26\u3067\u50BE\
    \u304D\u304C\u7121\u9650\u306B\u306A\u3063\u3066\u3057\u307E\u3046\u5834\u5408\
    \u306F (1, 0) \u3068\u3059\u308B\n    std::pair<T, T> slope() {\n        auto\
    \ dx = this->a.x - this->b.x;\n        auto dy = this->a.y - this->b.y;\n    \
    \    if (dx < 0) {\n            dx = -dx;\n            dy = -dy;\n        }\n\n\
    \        // \u7E26\n        if (dx == 0) {\n            dy = 1;\n        } else\
    \ {\n            auto g = std::gcd(dx, dy);\n            dx /= g;\n          \
    \  dy /= g;\n        }\n\n        return {dy, dx};\n    }\n\n    // y \u5207\u7247\
    \uFF0E\u6709\u7406\u6570\u3067\u8FD4\u3059\n    // line \u304C\u7E26\u3067 y \u5207\
    \u7247\u304C\u306A\u3044\u5834\u5408\u306F {-start.x, 0} \u3092\u8FD4\u3059\n\
    \    std::pair<T, T> y_intercept() {\n        auto [dy, dx] = this->slope();\n\
    \        return {dx * this->a.y - dy * this->a.x, dx};\n    }\n\n    // \u7DDA\
    \u5206\u4E0A\u306B point \u304C\u3042\u308B\u304B\u5224\u5B9A\n    bool on_line(const\
    \ Point<T> &point) const {\n        const auto ax = this->a.x;\n        const\
    \ auto ay = this->a.y;\n        const auto bx = this->b.x;\n        const auto\
    \ by = this->b.y;\n\n        const auto px = point.x;\n        const auto py =\
    \ point.y;\n\n        const auto l1 = (bx - ax) * (bx - ax) + (by - ay) * (by\
    \ - ay);\n        const auto l2 = (px - ax) * (px - ax) + (py - ay) * (py - ay);\n\
    \        const auto c = (bx - ax) * (px - ax) + (by - ay) * (py - ay);\n\n   \
    \     return c >= 0 and c * c == l1 * l2 and l1 >= l2;\n    };\n\n    // line\
    \ \u3068\u4E26\u884C\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B\n    bool\
    \ is_parallel(const Line<T> &line) const {\n        const auto y1 = this->a.y\
    \ - this->b.y;\n        const auto x1 = this->a.x - this->b.x;\n        const\
    \ auto y2 = line.a.y - line.b.y;\n        const auto x2 = line.a.x - line.b.x;\n\
    \        const auto p1 = Point<T>(y1, x1);\n        const auto p2 = Point<T>(y2,\
    \ x2);\n\n        // \u5916\u7A4D\u304C0\u306A\u3089\u5E73\u884C\n        return\
    \ p1.cross(p2) == 0;\n    }\n\n    // line \u3068\u76F4\u884C\u304B\u3069\u3046\
    \u304B\u5224\u5B9A\u3059\u308B\n    bool is_orthogonal(const Line<T> &line) const\
    \ {\n        const auto y1 = this->a.y - this->b.y;\n        const auto x1 = this->a.x\
    \ - this->b.x;\n        const auto y2 = line.a.y - line.b.y;\n        const auto\
    \ x2 = line.a.x - line.b.x;\n        const auto p1 = Point<T>(y1, x1);\n     \
    \   const auto p2 = Point<T>(y2, x2);\n\n        // \u5185\u7A4D\u304C0\u306A\u3089\
    \u76F4\u884C\n        return p1.dot(p2) == 0;\n    }\n\n    // line \u3068\u4EA4\
    \u308F\u3063\u3066\u3044\u308B\u304B\u5224\u5B9A\u3059\u308B\n    bool is_intersection(const\
    \ Line<T> &line) const {\n        T ay1 = this->a.y;\n        T ax1 = this->a.x;\n\
    \        T ay2 = this->b.y;\n        T ax2 = this->b.x;\n        T by1 = line.a.y;\n\
    \        T bx1 = line.a.x;\n        T by2 = line.b.y;\n        T bx2 = line.b.x;\n\
    \n        const auto ta = (bx1 - bx2) * (ay1 - by1) + (by1 - by2) * (bx1 - ax1);\n\
    \        const auto tb = (bx1 - bx2) * (ay2 - by1) + (by1 - by2) * (bx1 - ax2);\n\
    \        const auto tc = (ax1 - ax2) * (by1 - ay1) + (ay1 - ay2) * (ax1 - bx1);\n\
    \        const auto td = (ax1 - ax2) * (by2 - ay1) + (ay1 - ay2) * (ax1 - bx2);\n\
    \n        // \u4E00\u65B9\u306E\u7DDA\u5206\u4E0A\u306B\u3082\u3046\u4E00\u65B9\
    \u306E\u7AEF\u70B9\u304C\u306E\u3063\u3066\u3044\u308B\n        if (this->on_line(line.a)\
    \ or on_line(line.b)) {\n            return true;\n        }\n        if (line.on_line(this->a)\
    \ or line.on_line(this->b)) {\n            return true;\n        }\n\n       \
    \ // \u7AEF\u70B9\u3092\u542B\u307E\u306A\u3044\u3067\u4EA4\u308F\u308B\n    \
    \    // tc * td < 0 && ta * tb < 0\n        bool a = (ta != 0 and tb != 0 and\
    \ ((ta < 0) != (tb < 0)));\n        bool b = (tc != 0 and td != 0 and ((tc < 0)\
    \ != (td < 0)));\n\n        return a and b;\n    }\n    \n    // \u4EA4\u70B9\n\
    };\n#line 4 \"test/cpp/Geometry/Line1_is_parallel.test.cpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N;\n    cin >> N;\n    for (int t = 0; t < N; ++t) {\n        int x0,\
    \ y0, x1, y1, x2, y2, x3, y3;\n        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2\
    \ >> x3 >> y3;\n        Line line1(Point(x0, y0), Point(x1, y1));\n        Line\
    \ line2(Point(x2, y2), Point(x3, y3));\n\n        if (line1.is_parallel(line2))\
    \ {\n            cout << 2 << endl;\n        }\n        else if (line1.is_orthogonal(line2))\
    \ {\n            cout << 1 << endl;\n        }\n        else {\n            cout\
    \ << 0 << endl;\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A\"\
    \n\n#include \"library/cpp/Geometry/Line.hpp\"\n#include <iostream>\n\nusing namespace\
    \ std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N;\n    cin >> N;\n    for (int t = 0; t < N; ++t) {\n        int x0,\
    \ y0, x1, y1, x2, y2, x3, y3;\n        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2\
    \ >> x3 >> y3;\n        Line line1(Point(x0, y0), Point(x1, y1));\n        Line\
    \ line2(Point(x2, y2), Point(x3, y3));\n\n        if (line1.is_parallel(line2))\
    \ {\n            cout << 2 << endl;\n        }\n        else if (line1.is_orthogonal(line2))\
    \ {\n            cout << 1 << endl;\n        }\n        else {\n            cout\
    \ << 0 << endl;\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - library/cpp/Geometry/Line.hpp
  - library/cpp/Geometry/Point.hpp
  isVerificationFile: true
  path: test/cpp/Geometry/Line1_is_parallel.test.cpp
  requiredBy: []
  timestamp: '2024-02-09 11:37:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Geometry/Line1_is_parallel.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Geometry/Line1_is_parallel.test.cpp
- /verify/test/cpp/Geometry/Line1_is_parallel.test.cpp.html
title: test/cpp/Geometry/Line1_is_parallel.test.cpp
---
