---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Geometry/SmallestEnclosingCircle.hpp
    title: library/cpp/Geometry/SmallestEnclosingCircle.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-10
    PROBLEM: https://atcoder.jp/contests/abc151/tasks/abc151_f
    links:
    - https://atcoder.jp/contests/abc151/tasks/abc151_f
  bundledCode: "#line 1 \"test/cpp/Geometry/SmallestEnclosingCircle1.test.cpp\"\n\
    #define PROBLEM \"https://atcoder.jp/contests/abc151/tasks/abc151_f\"\n#define\
    \ ERROR 1e-10\n\n#line 1 \"library/cpp/Geometry/SmallestEnclosingCircle.hpp\"\n\
    #include <cmath>\n#include <vector>\n\nclass Point {\npublic:\n    double x;\n\
    \    double y;\n\n    Point() : x(0), y(0) {}\n\n    Point(double x, double y)\
    \ : x(x), y(y) {}\n};\n\n// \u70B9\u3092\u542B\u3080\u6700\u5C0F\u534A\u5F84\u306E\
    \u5186\u3092\u6C42\u3081\u308B\nclass SmallestEnclosingCircle {\nprivate:\n  \
    \  double min_x;\n    double max_x;\n    double min_y;\n    double max_y;\n  \
    \  std::vector<Point> points;\n\npublic:\n    SmallestEnclosingCircle(const std::vector<Point>\
    \ &points) : points(points) {\n        this->min_x = this->max_x = points[0].x;\n\
    \        this->min_y = this->max_y = points[0].y;\n\n        for (const auto &p:\
    \ points) {\n            this->min_x = std::min(this->min_x, p.x);\n         \
    \   this->max_x = std::max(this->max_x, p.x);\n            this->min_y = std::min(this->min_y,\
    \ p.y);\n            this->max_y = std::max(this->max_y, p.y);\n        }\n  \
    \  }\n\n    // \u6700\u5C0F\u5305\u542B\u5186\u306E\u4E2D\u5FC3\u70B9\u3068\u534A\
    \u5F84\n    std::pair<Point, double> solve() const {\n        // x \u5EA7\u6A19\
    \u3067 3 \u5206\u63A2\u7D22\n        double l = this->min_x - 1.0;\n        double\
    \ r = this->max_x + 1.0;\n        for (int _ = 0; _ < 100; ++_) {\n          \
    \  const double x1 = (l * 2 + r) / 3.0;\n            const double x2 = (l + r\
    \ * 2) / 3.0;\n\n            if (this->g(x1).second > this->g(x2).second) {\n\
    \                l = x1;\n            }\n            else {\n                r\
    \ = x2;\n            }\n        }\n\n        const double x = l;\n        const\
    \ auto [y, d] = this->g(x);\n        return {Point(x, y), std::sqrt(d)};\n   \
    \ }\n\nprivate:\n    // \u70B9a\u3068\u70B9b\u306E\u30E6\u30FC\u30AF\u30EA\u30C3\
    \u30C9\u8DDD\u96E2\u306E2\u4E57\n    double euclidean_distance2(const Point &a,\
    \ const Point &b) const {\n        const double dx = a.x - b.x;\n        const\
    \ double dy = a.y - b.y;\n        return dx * dx + dy * dy;\n    }\n\n    // \u70B9\
    p \u304B\u3089\u6700\u3082\u9060\u3044\u70B9\u307E\u3067\u306E\u8DDD\u96E2\n \
    \   double max_distance(const Point &p) const {\n        double res = 0;\n   \
    \     for (const auto q: points) {\n            res = std::max(res, this->euclidean_distance2(p,\
    \ q));\n        }\n        return res;\n    }\n\n    // x\u5EA7\u6A19\u3092\u6C7A\
    \u3081\u305F\u3068\u304D\u306E\uFF0Cy\u8EF8\u306E\u8DDD\u96E2\u3092\u6700\u5C0F\
    \u5316\n    // {y, \u6700\u9577\u8DDD\u96E2\u306E2\u4E57}\u3092\u8FD4\u3059\n\
    \    std::pair<double, double> g(const double x) const {\n        double l = this->min_y\
    \ - 1.0;\n        double r = this->max_y + 1.0;\n\n        for (int _ = 0; _ <\
    \ 100; ++_) {\n            const double y1 = (l * 2 + r) / 3.0;\n            const\
    \ double y2 = (l + r * 2) / 3.0;\n\n            if (this->max_distance(Point(x,\
    \ y1)) > this->max_distance(Point(x, y2))) {\n                l = y1;\n      \
    \      }\n            else {\n                r = y2;\n            }\n       \
    \ }\n\n        const auto y = l;\n        return {y, this->max_distance(Point(x,\
    \ y))};\n    }\n};\n#line 5 \"test/cpp/Geometry/SmallestEnclosingCircle1.test.cpp\"\
    \n\n#include <algorithm>\n#include <iomanip>\n#include <iostream>\n\nusing namespace\
    \ std;\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    cout.tie(nullptr);\n\n    int N;\n    cin >> N;\n\n    vector<Point> v;\n\
    \    for (int i = 0; i < N; ++i) {\n        int X, Y;\n        cin >> X >> Y;\n\
    \        v.emplace_back(X, Y);\n    }\n\n    SmallestEnclosingCircle sec(v);\n\
    \    auto [p, r] = sec.solve();\n    cout << fixed << setprecision(18) << r <<\
    \ endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc151/tasks/abc151_f\"\n#define\
    \ ERROR 1e-10\n\n#include \"library/cpp/Geometry/SmallestEnclosingCircle.hpp\"\
    \n\n#include <algorithm>\n#include <iomanip>\n#include <iostream>\n\nusing namespace\
    \ std;\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    cout.tie(nullptr);\n\n    int N;\n    cin >> N;\n\n    vector<Point> v;\n\
    \    for (int i = 0; i < N; ++i) {\n        int X, Y;\n        cin >> X >> Y;\n\
    \        v.emplace_back(X, Y);\n    }\n\n    SmallestEnclosingCircle sec(v);\n\
    \    auto [p, r] = sec.solve();\n    cout << fixed << setprecision(18) << r <<\
    \ endl;\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Geometry/SmallestEnclosingCircle.hpp
  isVerificationFile: true
  path: test/cpp/Geometry/SmallestEnclosingCircle1.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:50:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Geometry/SmallestEnclosingCircle1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Geometry/SmallestEnclosingCircle1.test.cpp
- /verify/test/cpp/Geometry/SmallestEnclosingCircle1.test.cpp.html
title: test/cpp/Geometry/SmallestEnclosingCircle1.test.cpp
---
