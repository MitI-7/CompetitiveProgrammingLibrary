---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/DataStructure/CumulativeSum2D1.test.cpp
    title: test/cpp/DataStructure/CumulativeSum2D1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Tree/SegmentTree2D2_max.test.cpp
    title: test/cpp/Tree/SegmentTree2D2_max.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/DataStructure/CumulativeSum2D.hpp\"\n#include\
    \ <cassert>\n#include <iostream>\n#include <vector>\n\ntemplate<typename T>\n\
    class CumulativeSum2D {\npublic:\n    std::vector<std::vector<T>> memo;\n    std::vector<T>\
    \ right_diagonal, left_diagonal;\n\n    CumulativeSum2D() = default;\n\n    explicit\
    \ CumulativeSum2D(const std::vector<std::vector<T>> &grid) {\n        this->build(grid);\n\
    \    }\n\n    // grid\u306F\u5DE6\u4E0A\u304C (0, 0)\uFF0C\u53F3\u4E0B\u304C(H\
    \ - 1, W - 1)\n    // O(H * W)\n    void build(const std::vector<std::vector<T>>\
    \ &grid) {\n        const int H = grid.size();\n        const int W = grid[0].size();\n\
    \n        this->memo = std::vector<std::vector<T>>(H + 1, std::vector<T>(W + 1));\n\
    \        this->right_diagonal.resize(H + W + 1);\n        this->left_diagonal.resize(H\
    \ + W + 1);\n\n        for (int y = 0; y < H; ++y) {\n            for (int x =\
    \ 0; x < W; ++x) {\n                this->memo[y + 1][x + 1] = grid[y][x] + this->memo[y\
    \ + 1][x];\n            }\n            for (int x = 0; x < W; ++x) {\n       \
    \         this->memo[y + 1][x + 1] += this->memo[y][x + 1];\n            }\n \
    \       }\n    }\n\n    // \u884C y \u306E\u533A\u9593 [x1, x2) \u306E\u5408\u8A08\
    \n    T sum_row(const int y, const int x1, const int x2) const {\n        return\
    \ this->sum(y, x1, y + 1, x2);\n    }\n\n    // \u5217 x \u306E\u533A\u9593 [y1,\
    \ y2) \u306E\u5408\u8A08\n    T sum_col(const int x, const int y1, const int y2)\
    \ const {\n        return this->sum(y1, x, y2, x + 1);\n    }\n\n    // \u53F3\
    \u659C\u3081(y - x = d \u3068\u306A\u308B\u7B87\u6240) \u306E\u5408\u8A08\n  \
    \  T sum_right_diagonal(const int y1, const int x1, const int y2, const int x2)\
    \ const {\n        assert(y1 - x1 == y2 - x2);\n        assert(y1 < y2);\n   \
    \     assert(x1 < x2);\n    }\n\n    // \u5DE6\u659C\u3081(y + x = d \u3068\u306A\
    \u308B\u76F4\u7DDA) \u306E\u5408\u8A08\n    T sum_left_diagonal(const int y1,\
    \ const int x1, const int y2, const int x2) const {\n        assert(y1 + x1 ==\
    \ y2 + x2);\n        assert(y1 < y2);\n        assert(x1 > x2);\n    }\n\n   \
    \ // \u5DE6\u4E0A (y1, x1) \u304B\u3089\u53F3\u4E0B (y2, x2) \u306E\u5408\u8A08\
    \u3092\u8FD4\u3059\uFF0E(y2, x2)\u306E\u884C\u3068\u5217\u306F\u542B\u307E\u306A\
    \u3044\n    // \u4F8B\u3048\u3070\uFF0C sum(0, 0, 2, 2) \u306A\u3089 (0, 0), (0,\
    \ 1), (1, 0), (1, 1) \u306E\u5408\u8A08\u3092\u8FD4\u3059\n    T sum(const int\
    \ y1, const int x1, const int y2, const int x2) const {\n        assert(y2 >=\
    \ y1);\n        assert(x2 >= x1);\n        return this->memo[y2][x2] - this->memo[y2][x1]\
    \ - this->memo[y1][x2] + this->memo[y1][x1];\n    }\n\n    void dump() const {\n\
    \        for (const auto line: this->memo) {\n            for (const auto a: line)\
    \ {\n                std::cout << a << \" \";\n            }\n            std::cout\
    \ << std::endl;\n        }\n    }\n};\n"
  code: "#include <cassert>\n#include <iostream>\n#include <vector>\n\ntemplate<typename\
    \ T>\nclass CumulativeSum2D {\npublic:\n    std::vector<std::vector<T>> memo;\n\
    \    std::vector<T> right_diagonal, left_diagonal;\n\n    CumulativeSum2D() =\
    \ default;\n\n    explicit CumulativeSum2D(const std::vector<std::vector<T>> &grid)\
    \ {\n        this->build(grid);\n    }\n\n    // grid\u306F\u5DE6\u4E0A\u304C\
    \ (0, 0)\uFF0C\u53F3\u4E0B\u304C(H - 1, W - 1)\n    // O(H * W)\n    void build(const\
    \ std::vector<std::vector<T>> &grid) {\n        const int H = grid.size();\n \
    \       const int W = grid[0].size();\n\n        this->memo = std::vector<std::vector<T>>(H\
    \ + 1, std::vector<T>(W + 1));\n        this->right_diagonal.resize(H + W + 1);\n\
    \        this->left_diagonal.resize(H + W + 1);\n\n        for (int y = 0; y <\
    \ H; ++y) {\n            for (int x = 0; x < W; ++x) {\n                this->memo[y\
    \ + 1][x + 1] = grid[y][x] + this->memo[y + 1][x];\n            }\n          \
    \  for (int x = 0; x < W; ++x) {\n                this->memo[y + 1][x + 1] +=\
    \ this->memo[y][x + 1];\n            }\n        }\n    }\n\n    // \u884C y \u306E\
    \u533A\u9593 [x1, x2) \u306E\u5408\u8A08\n    T sum_row(const int y, const int\
    \ x1, const int x2) const {\n        return this->sum(y, x1, y + 1, x2);\n   \
    \ }\n\n    // \u5217 x \u306E\u533A\u9593 [y1, y2) \u306E\u5408\u8A08\n    T sum_col(const\
    \ int x, const int y1, const int y2) const {\n        return this->sum(y1, x,\
    \ y2, x + 1);\n    }\n\n    // \u53F3\u659C\u3081(y - x = d \u3068\u306A\u308B\
    \u7B87\u6240) \u306E\u5408\u8A08\n    T sum_right_diagonal(const int y1, const\
    \ int x1, const int y2, const int x2) const {\n        assert(y1 - x1 == y2 -\
    \ x2);\n        assert(y1 < y2);\n        assert(x1 < x2);\n    }\n\n    // \u5DE6\
    \u659C\u3081(y + x = d \u3068\u306A\u308B\u76F4\u7DDA) \u306E\u5408\u8A08\n  \
    \  T sum_left_diagonal(const int y1, const int x1, const int y2, const int x2)\
    \ const {\n        assert(y1 + x1 == y2 + x2);\n        assert(y1 < y2);\n   \
    \     assert(x1 > x2);\n    }\n\n    // \u5DE6\u4E0A (y1, x1) \u304B\u3089\u53F3\
    \u4E0B (y2, x2) \u306E\u5408\u8A08\u3092\u8FD4\u3059\uFF0E(y2, x2)\u306E\u884C\
    \u3068\u5217\u306F\u542B\u307E\u306A\u3044\n    // \u4F8B\u3048\u3070\uFF0C sum(0,\
    \ 0, 2, 2) \u306A\u3089 (0, 0), (0, 1), (1, 0), (1, 1) \u306E\u5408\u8A08\u3092\
    \u8FD4\u3059\n    T sum(const int y1, const int x1, const int y2, const int x2)\
    \ const {\n        assert(y2 >= y1);\n        assert(x2 >= x1);\n        return\
    \ this->memo[y2][x2] - this->memo[y2][x1] - this->memo[y1][x2] + this->memo[y1][x1];\n\
    \    }\n\n    void dump() const {\n        for (const auto line: this->memo) {\n\
    \            for (const auto a: line) {\n                std::cout << a << \"\
    \ \";\n            }\n            std::cout << std::endl;\n        }\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/DataStructure/CumulativeSum2D.hpp
  requiredBy: []
  timestamp: '2024-01-28 17:02:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/DataStructure/CumulativeSum2D1.test.cpp
  - test/cpp/Tree/SegmentTree2D2_max.test.cpp
documentation_of: library/cpp/DataStructure/CumulativeSum2D.hpp
layout: document
redirect_from:
- /library/library/cpp/DataStructure/CumulativeSum2D.hpp
- /library/library/cpp/DataStructure/CumulativeSum2D.hpp.html
title: library/cpp/DataStructure/CumulativeSum2D.hpp
---
