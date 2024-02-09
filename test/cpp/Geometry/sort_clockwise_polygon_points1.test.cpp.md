---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Geometry/sort_clockwise_polygon_points.cpp
    title: library/cpp/Geometry/sort_clockwise_polygon_points.cpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/Tree/FenwickTree.hpp
    title: library/cpp/Tree/FenwickTree.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/Tree/FenwickTreeRange.hpp
    title: library/cpp/Tree/FenwickTreeRange.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc211/tasks/abc211_f
    links:
    - https://atcoder.jp/contests/abc211/tasks/abc211_f
  bundledCode: "#line 1 \"test/cpp/Geometry/sort_clockwise_polygon_points1.test.cpp\"\
    \n#define PROBLEM \"https://atcoder.jp/contests/abc211/tasks/abc211_f\"\n\n#line\
    \ 1 \"library/cpp/Geometry/sort_clockwise_polygon_points.cpp\"\n#include <algorithm>\n\
    #include <vector>\n\nstruct Point {\n    int x, y;\n};\n\n// \u591A\u89D2\u5F62\
    \u3092\u9023\u7D9A\u3059\u308B\u70B9\u306B\u3088\u3063\u3066\u8868\u3057\u3066\
    \u3044\u308B\u3068\u304D\uFF0C\n// \u5DE6\u4E0A(x\u304C\u6700\u5C0F\u306E\u4E2D\
    \u3067y\u304C\u6700\u5C0F\u306E\u3082\u306E)\u306E\u9802\u70B9\u304B\u3089\u958B\
    \u59CB\u3059\u308B\u53CD\u6642\u8A08\u56DE\u308A\u306E\u70B9\u306B\u30BD\u30FC\
    \u30C8\u3059\u308B\n// \u5168\u3066\u306E\u89D2\u304C 90 \u5EA6\u307E\u305F\u306F\
    \ 270 \u5EA6\u3067\u5358\u7D14\u3067\u3042\u308B\u3053\u3068\n// \u5076\u6570\u756A\
    \u76EE\u306F\u7E26\u7DDA\uFF0C\u5947\u6570\u756A\u76EE\u306F\u6A2A\u7DDA\u306B\
    \u306A\u308B\uFF0E(0-origin)\nvoid sort_clockwise_polygon_points(std::vector<Point>\
    \ &points) {\n    int left_up_idx = 0;\n    for (int i = 0; i < (int) points.size();\
    \ ++i) {\n        if (points[i].x < points[left_up_idx].x) {\n            left_up_idx\
    \ = i;\n        } else if (points[i].x == points[left_up_idx].x and points[i].y\
    \ > points[left_up_idx].y) {\n            left_up_idx = i;\n        }\n    }\n\
    \n    // left_up \u3092\u5148\u982D\u306B\u3082\u3063\u3066\u304F\u308B\n    std::rotate(points.begin(),\
    \ points.begin() + left_up_idx, points.end());\n\n    // points \u306E\u9806\u5E8F\
    \u304C\u6642\u8A08\u56DE\u308A\u306B\u306A\u3063\u3066\u3044\u308B\u5834\u5408\
    \uFF0C\u53CD\u6642\u8A08\u56DE\u308A\u306B\u3059\u308B\n    if (points[0].x !=\
    \ points[1].x) {\n        std::reverse(points.begin() + 1, points.end());\n  \
    \  }\n}\n#line 1 \"library/cpp/Tree/FenwickTree.hpp\"\n#include <cassert>\n#line\
    \ 3 \"library/cpp/Tree/FenwickTree.hpp\"\n\n// \u3059\u3079\u3066 0-origin\ntemplate<class\
    \ T>\nclass FenwickTree {\npublic:\n    const int n;\n    std::vector<T> v;\n\n\
    \    // n: \u8981\u7D20\u6570\n    explicit FenwickTree(const int n) : n(n) {\n\
    \        this->v.assign(n + 1, 0);\n    }\n\n    // v[i]\n    // O(log n)\n  \
    \  T access(const int i) const {\n        return this->sum(i, i + 1);\n    }\n\
    \n    // v[i] += x\n    // O(log n)\n    void add(int i, T x) {\n        assert(i\
    \ < this->n);\n\n        while (i < this->n) {\n            this->v[i] += x;\n\
    \            i |= i + 1;\n        }\n    }\n\n    // v[i] = x\n    // O(log n)\n\
    \    void update(int i, T x) {\n        assert(i < this->n);\n\n        const\
    \ T now = this->access(i);\n        this->add(i, x - now);\n    }\n\n    // sum(v[0,\
    \ i))\n    // O(log n)\n    T sum(int i) const {\n        assert(0 <= i and i\
    \ <= this->n);\n\n        T s = 0;\n        i -= 1;\n        while (i >= 0) {\n\
    \            s += this->v[i];\n            i = (i & (i + 1)) - 1;\n        }\n\
    \        return s;\n    }\n\n    // sum(v[left, right))\n    // O(log n)\n   \
    \ T sum(const int left, const int right) const {\n        if (left >= right) {\n\
    \            return 0;\n        }\n        return this->sum(right) - this->sum(left);\n\
    \    }\n};\n#line 2 \"library/cpp/Tree/FenwickTreeRange.hpp\"\n\n// \u533A\u9593\
    \u52A0\u7B97\uFF0C\u533A\u9593\u548C\u53D6\u5F97\n// \u3059\u3079\u3066 0-origin\n\
    template<typename T>\nclass FenwickTreeRange {\n    const int n;\n    FenwickTree<T>\
    \ ft0, ft1;\n\npublic:\n    explicit FenwickTreeRange(const int n) : n(n), ft0(n\
    \ + 1), ft1(n + 1) {}\n\n    // v[i]\n    // O(log n)\n    T access(const int\
    \ i) const {\n        assert(0 <= i and i < this->n);\n        return this->sum(i,\
    \ i + 1);\n    }\n\n    // v[i] += x\n    // O(log n)\n    void add(const int\
    \ i, const T x) {\n        assert(0 <= i and i < this->n);\n        this->add(i,\
    \ i + 1, x);\n    }\n\n    // v[left, right) += x\n    // O(log n)\n    void add(const\
    \ int left, const int right, const T x) {\n        assert(0 <= left and left <\
    \ right and right <= this->n);\n        this->ft0.add(left, x);\n        this->ft0.add(right,\
    \ -x);\n        this->ft1.add(left, -x * left);\n        this->ft1.add(right,\
    \ x * right);\n    }\n\n    // sum(v[0, i))\n    // O(log n)\n    T sum(const\
    \ int i) const {\n        assert(0 <= i and i <= this->n);\n        return ft0.sum(i)\
    \ * i + ft1.sum(i);\n    }\n\n    // sum(v[left, right))\n    // O(log n)\n  \
    \  T sum(const int left, const int right) const {\n        assert(0 <= left and\
    \ left < right and right <= this->n);\n        return this->sum(right) - this->sum(left);\n\
    \    }\n};\n#line 5 \"test/cpp/Geometry/sort_clockwise_polygon_points1.test.cpp\"\
    \n#include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int N;\n    cin >> N;\n\n    vector<tuple<int,\
    \ int, int, int>> events;\n    for (int i = 0; i < N; ++i) {\n        vector<Point>\
    \ points;\n        int M;\n        cin >> M;\n        for (int j = 0; j < M; ++j)\
    \ {\n            int X, Y;\n            cin >> X >> Y;\n            points.emplace_back(X,\
    \ Y);\n        }\n        sort_clockwise_polygon_points(points);\n        for\
    \ (int j = 0; j < M; j += 2) {\n            auto p1 = points[j];\n           \
    \ auto p2 = points[j + 1];\n            assert(p1.x == p2.x);\n            events.emplace_back(p1.x,\
    \ 0, p1.y, p2.y);\n        }\n    }\n\n    int Q;\n    cin >> Q;\n    for (int\
    \ i = 0; i < Q; ++i) {\n        int X, Y;\n        cin >> X >> Y;\n        events.emplace_back(X,\
    \ 1, Y, i);\n    }\n\n    vector<int> ans(Q);\n    FenwickTreeRange<int> ftr(100100);\n\
    \    sort(events.begin(), events.end());\n    for (auto [_, t, b, c]: events)\
    \ {\n        if (t == 0) {\n            if (b > c) {\n                ftr.add(c,\
    \ b, 1);\n            } else {\n                ftr.add(b, c, -1);\n         \
    \   }\n        } else {\n            ans[c] = ftr.access(b);\n        }\n    }\n\
    \n    for (auto a: ans) {\n        cout << a << endl;\n    }\n\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc211/tasks/abc211_f\"\n\n\
    #include \"library/cpp/Geometry/sort_clockwise_polygon_points.cpp\"\n#include\
    \ \"library/cpp/Tree/FenwickTreeRange.hpp\"\n#include <iostream>\n\nusing namespace\
    \ std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N;\n    cin >> N;\n\n    vector<tuple<int, int, int, int>> events;\n\
    \    for (int i = 0; i < N; ++i) {\n        vector<Point> points;\n        int\
    \ M;\n        cin >> M;\n        for (int j = 0; j < M; ++j) {\n            int\
    \ X, Y;\n            cin >> X >> Y;\n            points.emplace_back(X, Y);\n\
    \        }\n        sort_clockwise_polygon_points(points);\n        for (int j\
    \ = 0; j < M; j += 2) {\n            auto p1 = points[j];\n            auto p2\
    \ = points[j + 1];\n            assert(p1.x == p2.x);\n            events.emplace_back(p1.x,\
    \ 0, p1.y, p2.y);\n        }\n    }\n\n    int Q;\n    cin >> Q;\n    for (int\
    \ i = 0; i < Q; ++i) {\n        int X, Y;\n        cin >> X >> Y;\n        events.emplace_back(X,\
    \ 1, Y, i);\n    }\n\n    vector<int> ans(Q);\n    FenwickTreeRange<int> ftr(100100);\n\
    \    sort(events.begin(), events.end());\n    for (auto [_, t, b, c]: events)\
    \ {\n        if (t == 0) {\n            if (b > c) {\n                ftr.add(c,\
    \ b, 1);\n            } else {\n                ftr.add(b, c, -1);\n         \
    \   }\n        } else {\n            ans[c] = ftr.access(b);\n        }\n    }\n\
    \n    for (auto a: ans) {\n        cout << a << endl;\n    }\n\n    return 0;\n\
    }\n"
  dependsOn:
  - library/cpp/Geometry/sort_clockwise_polygon_points.cpp
  - library/cpp/Tree/FenwickTreeRange.hpp
  - library/cpp/Tree/FenwickTree.hpp
  isVerificationFile: true
  path: test/cpp/Geometry/sort_clockwise_polygon_points1.test.cpp
  requiredBy: []
  timestamp: '2024-02-05 23:19:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Geometry/sort_clockwise_polygon_points1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Geometry/sort_clockwise_polygon_points1.test.cpp
- /verify/test/cpp/Geometry/sort_clockwise_polygon_points1.test.cpp.html
title: test/cpp/Geometry/sort_clockwise_polygon_points1.test.cpp
---
