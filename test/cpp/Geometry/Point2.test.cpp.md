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
    PROBLEM: https://atcoder.jp/contests/abc207/tasks/abc207_d
    links:
    - https://atcoder.jp/contests/abc207/tasks/abc207_d
  bundledCode: "#line 1 \"test/cpp/Geometry/Point2.test.cpp\"\n#define PROBLEM \"\
    https://atcoder.jp/contests/abc207/tasks/abc207_d\"\n\n#line 1 \"library/cpp/Geometry/Point.hpp\"\
    \n#include <cmath>\n#include <ostream>\n\ntemplate<class T>\nclass Point {\npublic:\n\
    \    T x;\n    T y;\n    int no;\n    double EPS = 1e-10;\n\n    Point() : x(0),\
    \ y(0), no(0) {};\n\n    Point(const T x, const T y, int no = 0, double eps =\
    \ 1e-10) : x(x), y(y), no(no), EPS(eps) {}\n\n    // \u539F\u70B9\u3092\u4E2D\u5FC3\
    \u3068\u3057\u3066\uFF0C\u53CD\u6642\u8A08\u56DE\u308A\u306B theta \u56DE\u8EE2\
    \u3055\u305B\u305F\u70B9\u3092\u6C42\u3081\u308B\n    Point<T> rotate(double theta)\
    \ const {\n        return Point<T>(this->x * std::cos(theta) - this->y * std::sin(theta),\n\
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
    \ \")\";\n        return os;\n    }\n};\n#line 4 \"test/cpp/Geometry/Point2.test.cpp\"\
    \n#include <iostream>\n#include <vector>\n\nusing namespace std;\n\nint main()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    int N;\n \
    \   cin >> N;\n    vector<Point<double>> S(N), T(N);\n    Point<double> s_m, t_m;\n\
    \n    for (int i = 0; i < N; ++i) {\n        cin >> S[i].x >> S[i].y;\n      \
    \  s_m += S[i];\n        S[i] *= N;\n    }\n\n    for (int i = 0; i < N; ++i)\
    \ {\n        cin >> T[i].x >> T[i].y;\n        t_m += T[i];\n        T[i] *= N;\n\
    \    }\n\n    for (int i = 0; i < N; ++i) {\n        S[i] -= s_m;\n        T[i]\
    \ -= t_m;\n    }\n\n    for (int i = 0; i < N; ++i) {\n        if (S[i].x != 0\
    \ || S[i].y != 0) {\n            swap(S[i], S[0]);\n        }\n    }\n\n    sort(T.begin(),\
    \ T.end(), Point<double>::xy_sort_cmp_key);\n    for (int i = 0; i < N; ++i) {\n\
    \        // T[i] \u3068 S[0] \u3092\u4E00\u81F4\u3055\u305B\u308B\n        const\
    \ double r = T[i].radian() - S[0].radian();\n\n        vector<Point<double>> s2(N);\n\
    \        for (int j = 0; j < N; ++j) {\n            s2[j] = S[j].rotate(r);\n\
    \        }\n        sort(s2.begin(), s2.end(), Point<double>::xy_sort_cmp_key);\n\
    \n        if (s2 == T) {\n            cout << \"Yes\" << endl;\n            return\
    \ 0;\n        }\n    }\n    cout << \"No\" << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc207/tasks/abc207_d\"\n\n\
    #include \"library/cpp/Geometry/Point.hpp\"\n#include <iostream>\n#include <vector>\n\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N;\n    cin >> N;\n    vector<Point<double>> S(N), T(N);\n    Point<double>\
    \ s_m, t_m;\n\n    for (int i = 0; i < N; ++i) {\n        cin >> S[i].x >> S[i].y;\n\
    \        s_m += S[i];\n        S[i] *= N;\n    }\n\n    for (int i = 0; i < N;\
    \ ++i) {\n        cin >> T[i].x >> T[i].y;\n        t_m += T[i];\n        T[i]\
    \ *= N;\n    }\n\n    for (int i = 0; i < N; ++i) {\n        S[i] -= s_m;\n  \
    \      T[i] -= t_m;\n    }\n\n    for (int i = 0; i < N; ++i) {\n        if (S[i].x\
    \ != 0 || S[i].y != 0) {\n            swap(S[i], S[0]);\n        }\n    }\n\n\
    \    sort(T.begin(), T.end(), Point<double>::xy_sort_cmp_key);\n    for (int i\
    \ = 0; i < N; ++i) {\n        // T[i] \u3068 S[0] \u3092\u4E00\u81F4\u3055\u305B\
    \u308B\n        const double r = T[i].radian() - S[0].radian();\n\n        vector<Point<double>>\
    \ s2(N);\n        for (int j = 0; j < N; ++j) {\n            s2[j] = S[j].rotate(r);\n\
    \        }\n        sort(s2.begin(), s2.end(), Point<double>::xy_sort_cmp_key);\n\
    \n        if (s2 == T) {\n            cout << \"Yes\" << endl;\n            return\
    \ 0;\n        }\n    }\n    cout << \"No\" << endl;\n\n    return 0;\n}\n"
  dependsOn:
  - library/cpp/Geometry/Point.hpp
  isVerificationFile: true
  path: test/cpp/Geometry/Point2.test.cpp
  requiredBy: []
  timestamp: '2024-01-30 19:48:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Geometry/Point2.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Geometry/Point2.test.cpp
- /verify/test/cpp/Geometry/Point2.test.cpp.html
title: test/cpp/Geometry/Point2.test.cpp
---
