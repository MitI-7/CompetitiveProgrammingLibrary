---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Tree/SegmentTree2D.hpp
    title: library/cpp/Tree/SegmentTree2D.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc106/tasks/abc106_d
    links:
    - https://atcoder.jp/contests/abc106/tasks/abc106_d
  bundledCode: "#line 1 \"test/cpp/Tree/SegmentTree2D1_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc106/tasks/abc106_d\"\n\n#line 1 \"library/cpp/Tree/SegmentTree2D.hpp\"\
    \n#include <cassert>\n#include <numeric>\n#include <vector>\n\ntemplate<class\
    \ T, T (*op)(T, T), T (*unit)()>\nclass SegmentTree2D {\nprivate:\n    int H;\n\
    \    int W;\n    int H2;\n    int W2;\n    std::vector<std::vector<T>> data;\n\
    \npublic:\n    SegmentTree2D(const std::vector<std::vector<T>> &grid) : H(grid.size()),\
    \ W(grid[0].size()), H2(1), W2(1) {\n        while (this->H2 < this->H) {\n  \
    \          this->H2 <<= 1;\n        }\n        while (this->W2 < this->W) {\n\
    \            this->W2 <<= 1;\n        }\n\n        this->data.resize(this->H2\
    \ * 2 - 1, std::vector<T>(this->W2 * 2 - 1, unit()));\n        for (int y = 0;\
    \ y < this->H; ++y) {\n            for (int x = 0; x < this->W; ++x) {\n     \
    \           this->data[this->H2 + y - 1][this->W2 + x - 1] = grid[y][x];\n   \
    \         }\n        }\n        this->build();\n    }\n\n    // O(1)\n    T access(const\
    \ int y, const int x) const {\n        return this->data[this->H2 + y - 1][this->W2\
    \ + x - 1];\n    }\n\n    T query(const int y1, const int x1, const int y2, const\
    \ int x2) const {\n        return this->query(y1, x1, y2, x2, 0, 0, this->H2);\n\
    \    }\n\n    // O(log H * log W)\n    void update(const int y, const int x, const\
    \ T v) {\n        int i = y + this->H2;\n        int j = x + this->W2;\n     \
    \   this->data[i][j] = v;\n        while (j > 1) {\n            j >>= 1;\n   \
    \         const auto lv = this->data[i][j * 2 + 1];\n            const auto rv\
    \ = this->data[i][j * 2 + 2];\n            this->data[i][j] = op(lv, rv);\n  \
    \      }\n\n        j = x + this->W2;\n        while (i > 1) {\n            i\
    \ >>= 1;\n            this->data[i][j] = op(this->data[i * 2 + 1][j], this->data[i\
    \ * 2 + 2][j]);\n            while (j > 1) {\n                j >>= 1;\n     \
    \           this->data[i][j] = op(this->data[i][j * 2 + 1], this->data[i][j *\
    \ 2 + 2]);\n            }\n            j = x + this->W2;\n        }\n    }\n\n\
    private:\n    // O(HW)\n    void build() {\n        // \u5217\u3092\u57CB\u3081\
    \u308B\n        for (int x = 0; x < this->W; ++x) {\n            for (int y =\
    \ this->H2 - 2; y >= 0; --y) {\n                const auto lv = this->data[y *\
    \ 2 + 1][this->W2 + x - 1];\n                const auto rv = this->data[y * 2\
    \ + 2][this->W2 + x - 1];\n                this->data[y][this->W2 + x - 1] = op(lv,\
    \ rv);\n            }\n        }\n\n        // \u5404\u884C\u306E\u5024\u3092\u6C42\
    \u3081\u308B\n        for (int y = 0; y < (int) this->data.size(); ++y) {\n  \
    \          for (int x = this->W2 - 2; x >= 0; --x) {\n                const auto\
    \ lv = this->data[y][x * 2 + 1];\n                const auto rv = this->data[y][x\
    \ * 2 + 2];\n                this->data[y][x] = op(lv, rv);\n            }\n \
    \       }\n    }\n\n    // [(y1, x1), (y2, x2)) \u306E\u5024\u3092\u30CE\u30FC\
    \u30C9 u \u304B\u3089\u691C\u7D22\n    // \u30CE\u30FC\u30C9 u \u306F y \u306E\
    \u533A\u9593 [start, end) \u3092\u30AB\u30D0\u30FC\n    T query(const int y1,\
    \ const int x1, const int y2, const int x2, const int u, const int start, const\
    \ int end) const {\n        assert(y1 < y2 and start < end);\n        // \u7BC4\
    \u56F2\u5916\n        if (end <= y1 or y2 <= start) {\n            return unit();\n\
    \        }\n\n        if (y1 <= start and end <= y2) {\n            // \u5B8C\u5168\
    \u306B\u542B\u3080\u306E\u3067\uFF0Cx \u306B\u3064\u3044\u3066\u306E\u63A2\u7D22\
    \u3092\u3059\u308B\n            return this->query_x(x1, x2, 0, 0, this->W2, u);\n\
    \        } else {\n            const int m = (start + end) / 2;\n            auto\
    \ vl = query(y1, x1, y2, x2, 2 * u + 1, start, m);  // \u5DE6\u306E\u5B50\n  \
    \          auto vr = query(y1, x1, y2, x2, 2 * u + 2, m, end);   // \u53F3\u306E\
    \u5B50\n            return op(vl, vr);\n        }\n    }\n\n    T query_x(const\
    \ int x1, const int x2, const int u, const int start, const int end, const int\
    \ node) const {\n        assert(x1 < x2 and start < end);\n        // \u7BC4\u56F2\
    \u5916\n        if (end <= x1 or x2 <= start) {\n            return unit();\n\
    \        }\n\n        // \u5B8C\u5168\u306B\u542B\u3080\n        if (x1 <= start\
    \ and end <= x2) {\n            return this->data[node][u];\n        } else {\n\
    \            const int m = (start + end) / 2;\n            auto vl = query_x(x1,\
    \ x2, u * 2 + 1, start, m, node);   // \u5DE6\u306E\u5B50\n            auto vr\
    \ = query_x(x1, x2, u * 2 + 2, m, end, node);    // \u53F3\u306E\u5B50\n     \
    \       return op(vl, vr);\n        }\n    }\n};\n\n// range minimum query\ntemplate<typename\
    \ T>\nT min_op(T a, T b) {\n    return std::min(a, b);\n}\n\ntemplate<typename\
    \ T>\nT min_unit() {\n    return std::numeric_limits<T>::max();\n}\n\ntemplate<typename\
    \ T>\nSegmentTree2D<T, min_op, min_unit> make_segment_tree_2d_min(const std::vector<std::vector<T>>\
    \ &grid) {\n    return SegmentTree2D<T, min_op, min_unit>(grid);\n}\n\n// range\
    \ maximum query\ntemplate<typename T>\nT max_op(T a, T b) {\n    return std::max(a,\
    \ b);\n}\n\ntemplate<typename T>\nT max_unit() {\n    return std::numeric_limits<T>::min();\n\
    }\n\ntemplate<typename T>\nSegmentTree2D<T, max_op, max_unit> make_segment_tree_2d_max(const\
    \ std::vector<std::vector<T>> &grid) {\n    return SegmentTree2D<T, max_op, max_unit>(grid);\n\
    }\n\n// range sum query\ntemplate<typename T>\nT sum_op(T a, T b) {\n    return\
    \ a + b;\n}\n\ntemplate<typename T>\nT sum_unit() {\n    return 0;\n}\n\ntemplate<typename\
    \ T>\nSegmentTree2D<T, sum_op, sum_unit> make_segment_tree_2d_sum(const std::vector<std::vector<T>>\
    \ &grid) {\n    return SegmentTree2D<T, sum_op, sum_unit>(grid);\n}\n#line 4 \"\
    test/cpp/Tree/SegmentTree2D1_sum.test.cpp\"\n#include <iostream>\n\nusing namespace\
    \ std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, M, Q;\n    cin >> N >> M >> Q;\n\n    vector grid(N, vector<int>(N));\n\
    \    for (int i = 0; i < M; ++i) {\n        int L, R;\n        cin >> L >> R;\n\
    \        grid[L - 1][R - 1]++;\n    }\n\n    vector<pair<int, int>> queries(Q);\n\
    \    for (int i = 0; i < Q; ++i) {\n        cin >> queries[i].first >> queries[i].second;\n\
    \        queries[i].first--;\n        queries[i].second--;\n    }\n\n    auto\
    \ st2d = make_segment_tree_2d_sum(grid);\n    for (const auto &[p, q]: queries)\
    \ {\n        cout << st2d.query(p, p, q + 1, q + 1) << endl;\n    }\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc106/tasks/abc106_d\"\n\n\
    #include \"library/cpp/Tree/SegmentTree2D.hpp\"\n#include <iostream>\n\nusing\
    \ namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, M, Q;\n    cin >> N >> M >> Q;\n\n    vector grid(N, vector<int>(N));\n\
    \    for (int i = 0; i < M; ++i) {\n        int L, R;\n        cin >> L >> R;\n\
    \        grid[L - 1][R - 1]++;\n    }\n\n    vector<pair<int, int>> queries(Q);\n\
    \    for (int i = 0; i < Q; ++i) {\n        cin >> queries[i].first >> queries[i].second;\n\
    \        queries[i].first--;\n        queries[i].second--;\n    }\n\n    auto\
    \ st2d = make_segment_tree_2d_sum(grid);\n    for (const auto &[p, q]: queries)\
    \ {\n        cout << st2d.query(p, p, q + 1, q + 1) << endl;\n    }\n\n    return\
    \ 0;\n}"
  dependsOn:
  - library/cpp/Tree/SegmentTree2D.hpp
  isVerificationFile: true
  path: test/cpp/Tree/SegmentTree2D1_sum.test.cpp
  requiredBy: []
  timestamp: '2024-02-29 16:40:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Tree/SegmentTree2D1_sum.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Tree/SegmentTree2D1_sum.test.cpp
- /verify/test/cpp/Tree/SegmentTree2D1_sum.test.cpp.html
title: test/cpp/Tree/SegmentTree2D1_sum.test.cpp
---
