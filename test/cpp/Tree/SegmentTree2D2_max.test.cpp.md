---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/DataStructure/CumulativeSum2Dim.hpp
    title: library/cpp/DataStructure/CumulativeSum2Dim.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc228/tasks/abc228_f
    links:
    - https://atcoder.jp/contests/abc228/tasks/abc228_f
  bundledCode: "#line 1 \"test/cpp/Tree/SegmentTree2D2_max.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc228/tasks/abc228_f\"\n\n#line 1 \"library/cpp/Tree/SegmentTree2D.hpp\"\
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
    \ &grid) {\n    return SegmentTree2D<T, sum_op, sum_unit>(grid);\n}\n#line 2 \"\
    library/cpp/DataStructure/CumulativeSum2Dim.hpp\"\n#include <iostream>\n#line\
    \ 4 \"library/cpp/DataStructure/CumulativeSum2Dim.hpp\"\n\ntemplate<typename T>\n\
    class CumulativeSum2Dim {\npublic:\n    std::vector<std::vector<T>> memo;\n\n\
    \    CumulativeSum2Dim() = default;\n\n    explicit CumulativeSum2Dim(const std::vector<std::vector<T>>\
    \ &grid) {\n        this->build(grid);\n    }\n\n    // grid\u306F\u5DE6\u4E0A\
    \u304C (0, 0)\uFF0C\u53F3\u4E0B\u304C(H - 1, W - 1)\n    // O(H * W)\n    void\
    \ build(const std::vector<std::vector<T>> &grid) {\n        const int height =\
    \ grid.size();\n        const int width = grid[0].size();\n\n        this->memo\
    \ = std::vector<std::vector<T>>(height + 1, std::vector<T>(width + 1));\n\n  \
    \      for (int y = 0; y < height; ++y) {\n            for (int x = 0; x < width;\
    \ ++x) {\n                this->memo[y + 1][x + 1] = grid[y][x] + this->memo[y\
    \ + 1][x];\n            }\n            for (int x = 0; x < width; ++x) {\n   \
    \             this->memo[y + 1][x + 1] += this->memo[y][x + 1];\n            }\n\
    \        }\n    }\n\n    // \u884C y \u306E\u533A\u9593 [x1, x2) \u306E\u5408\u8A08\
    \n    T sum_row(const int y, const int x1, const int x2) const {\n        return\
    \ this->sum(y, x1, y + 1, x2);\n    }\n\n    // \u5217 x \u306E\u533A\u9593 [y1,\
    \ y2) \u306E\u5408\u8A08\n    T sum_col(const int x, const int y1, const int y2)\
    \ const {\n        return this->sum(y1, x, y2, x + 1);\n    }\n\n    // \u5DE6\
    \u4E0A (y1, x1) \u304B\u3089\u53F3\u4E0B (y2, x2) \u306E\u5408\u8A08\u3092\u8FD4\
    \u3059\uFF0E(y2, x2)\u306E\u884C\u3068\u5217\u306F\u542B\u307E\u306A\u3044\n \
    \   // \u4F8B\u3048\u3070\uFF0C sum(0, 0, 2, 2) \u306A\u3089 (0, 0), (0, 1), (1,\
    \ 0), (1, 1) \u306E\u5408\u8A08\u3092\u8FD4\u3059\n    T sum(const int y1, const\
    \ int x1, const int y2, const int x2) const {\n        assert(y2 >= y1);\n   \
    \     assert(x2 >= x1);\n        return this->memo[y2][x2] - this->memo[y2][x1]\
    \ - this->memo[y1][x2] + this->memo[y1][x1];\n    }\n\n    void dump() const {\n\
    \        for (const auto line: this->memo) {\n            for (const auto a: line)\
    \ {\n                std::cout << a << \" \";\n            }\n            std::cout\
    \ << std::endl;\n        }\n    }\n};\n#line 6 \"test/cpp/Tree/SegmentTree2D2_max.test.cpp\"\
    \n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int H, W, H1, W1, H2, W2;\n    cin >> H >> W >> H1 >> W1 >> H2 >> W2;\n\
    \    H2 = min(H2, H1);\n    W2 = min(W2, W1);\n\n    vector A(H, vector<long long>(W));\n\
    \    for (int y = 0; y < H; ++y) {\n        for (int x = 0; x < W; ++x) {\n  \
    \          cin >> A[y][x];\n        }\n    }\n\n    CumulativeSum2Dim<long long>\
    \ cs(A);\n\n    vector B(H, vector<long long>(W));\n    for (int y = 0; y < H\
    \ - H2 + 1; ++y) {\n        for (int x = 0; x < W - W2 + 1; ++x) {\n         \
    \   B[y][x] = cs.sum(y, x, y + H2, x + W2);\n        }\n    }\n    SegmentTree2D<long\
    \ long, max_op, max_unit> st2d(B);\n\n    long long ans = 0;\n    for (int y =\
    \ 0; y < H - H1 + 1; ++y) {\n        for (int x = 0; x < W - W1 + 1; ++x) {\n\
    \            const int y1 = y + H1;\n            const int x1 = x + W1;\n\n  \
    \          const int y2 = y1 - H2 + 1;\n            const int x2 = x1 - W2 + 1;\n\
    \n            ans = max(ans, cs.sum(y, x, y1, x1) - st2d.query(y, x, y2, x2));\n\
    \        }\n    }\n    cout << ans << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc228/tasks/abc228_f\"\n\n\
    #include \"library/cpp/Tree/SegmentTree2D.hpp\"\n#include \"library/cpp/DataStructure/CumulativeSum2Dim.hpp\"\
    \n#include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int H, W, H1, W1, H2, W2;\n    cin >>\
    \ H >> W >> H1 >> W1 >> H2 >> W2;\n    H2 = min(H2, H1);\n    W2 = min(W2, W1);\n\
    \n    vector A(H, vector<long long>(W));\n    for (int y = 0; y < H; ++y) {\n\
    \        for (int x = 0; x < W; ++x) {\n            cin >> A[y][x];\n        }\n\
    \    }\n\n    CumulativeSum2Dim<long long> cs(A);\n\n    vector B(H, vector<long\
    \ long>(W));\n    for (int y = 0; y < H - H2 + 1; ++y) {\n        for (int x =\
    \ 0; x < W - W2 + 1; ++x) {\n            B[y][x] = cs.sum(y, x, y + H2, x + W2);\n\
    \        }\n    }\n    SegmentTree2D<long long, max_op, max_unit> st2d(B);\n\n\
    \    long long ans = 0;\n    for (int y = 0; y < H - H1 + 1; ++y) {\n        for\
    \ (int x = 0; x < W - W1 + 1; ++x) {\n            const int y1 = y + H1;\n   \
    \         const int x1 = x + W1;\n\n            const int y2 = y1 - H2 + 1;\n\
    \            const int x2 = x1 - W2 + 1;\n\n            ans = max(ans, cs.sum(y,\
    \ x, y1, x1) - st2d.query(y, x, y2, x2));\n        }\n    }\n    cout << ans <<\
    \ endl;\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Tree/SegmentTree2D.hpp
  - library/cpp/DataStructure/CumulativeSum2Dim.hpp
  isVerificationFile: true
  path: test/cpp/Tree/SegmentTree2D2_max.test.cpp
  requiredBy: []
  timestamp: '2024-02-29 16:40:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Tree/SegmentTree2D2_max.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Tree/SegmentTree2D2_max.test.cpp
- /verify/test/cpp/Tree/SegmentTree2D2_max.test.cpp.html
title: test/cpp/Tree/SegmentTree2D2_max.test.cpp
---
