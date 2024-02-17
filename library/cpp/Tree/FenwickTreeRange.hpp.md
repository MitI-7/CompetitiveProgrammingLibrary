---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Tree/FenwickTree.hpp
    title: library/cpp/Tree/FenwickTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Geometry/sort_clockwise_polygon_points1.test.cpp
    title: test/cpp/Geometry/sort_clockwise_polygon_points1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Tree/FenwickTreeRange1.test.cpp
    title: test/cpp/Tree/FenwickTreeRange1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Tree/FenwickTreeRange2.test.cpp
    title: test/cpp/Tree/FenwickTreeRange2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Tree/FenwickTree.hpp\"\n#include <cassert>\n\
    #include <vector>\n\n// \u3059\u3079\u3066 0-origin\ntemplate<class T>\nclass\
    \ FenwickTree {\npublic:\n    const int n;\n    std::vector<T> v;\n\n    // n:\
    \ \u8981\u7D20\u6570\n    explicit FenwickTree(const int n) : n(n) {\n       \
    \ this->v.assign(n + 1, 0);\n    }\n\n    // v[i]\n    // O(log n)\n    T access(const\
    \ int i) const {\n        return this->sum(i, i + 1);\n    }\n\n    // v[i] +=\
    \ x\n    // O(log n)\n    void add(int i, T x) {\n        assert(i < this->n);\n\
    \n        while (i < this->n) {\n            this->v[i] += x;\n            i |=\
    \ i + 1;\n        }\n    }\n\n    // v[i] = x\n    // O(log n)\n    void update(int\
    \ i, T x) {\n        assert(i < this->n);\n\n        const T now = this->access(i);\n\
    \        this->add(i, x - now);\n    }\n\n    // sum(v[0, i))\n    // O(log n)\n\
    \    T sum(int i) const {\n        assert(0 <= i and i <= this->n);\n\n      \
    \  T s = 0;\n        i -= 1;\n        while (i >= 0) {\n            s += this->v[i];\n\
    \            i = (i & (i + 1)) - 1;\n        }\n        return s;\n    }\n\n \
    \   // sum(v[left, right))\n    // O(log n)\n    T sum(const int left, const int\
    \ right) const {\n        if (left >= right) {\n            return 0;\n      \
    \  }\n        return this->sum(right) - this->sum(left);\n    }\n};\n#line 2 \"\
    library/cpp/Tree/FenwickTreeRange.hpp\"\n#include <iostream>\n\n// \u533A\u9593\
    \u52A0\u7B97\uFF0C\u533A\u9593\u548C\u53D6\u5F97\n// \u3059\u3079\u3066 0-origin\n\
    template<typename T>\nclass FenwickTreeRange {\n    const int n;\n    FenwickTree<T>\
    \ ft0, ft1;\n\npublic:\n    explicit FenwickTreeRange(const int n) : n(n), ft0(n\
    \ + 1), ft1(n + 1) {}\n\n    // v[i]\n    // O(log n)\n    T access(const int\
    \ i) const {\n        assert(0 <= i and i < this->n);\n        return this->sum(i,\
    \ i + 1);\n    }\n\n    // v[i] += x\n    // O(log n)\n    void add(const int\
    \ i, const T x) {\n        assert(0 <= i and i < this->n);\n        this->add(i,\
    \ i + 1, x);\n    }\n\n    // v[left, right) += x\n    // O(log n)\n    void add(const\
    \ int left, const int right, const T x) {\n        if (left == right) {\n    \
    \        return;\n        }\n        assert(0 <= left and left < right and right\
    \ <= this->n);\n        this->ft0.add(left, x);\n        this->ft0.add(right,\
    \ -x);\n        this->ft1.add(left, -x * left);\n        this->ft1.add(right,\
    \ x * right);\n    }\n\n    // v[left, right) += x\n    // \u52A0\u7B97\u4F4D\u7F6E\
    \u304C n \u4EE5\u4E0A\u306E\u5834\u5408\u306F 0 \u306B\u623B\u3063\u3066\u52A0\
    \u7B97\u3055\u308C\u308B\n    // O(log n)\n    void add_circle(long long left,\
    \ long long right, const T x) {\n        assert(left < right);\n\n        const\
    \ long long num_loop = (right - left) / this->n;\n        this->add(0, this->n,\
    \ x * num_loop);\n\n        // \u30EB\u30FC\u30D7\u3067\u7D42\u308F\u308A\n  \
    \      if ((right - left) % this->n == 0) {\n            return;\n        }\n\n\
    \        left %= this->n;\n        right %= this->n;\n\n        if (left < right)\
    \ {\n            this->add(left, right, x);\n        } else {\n            this->add(left,\
    \ this->n, x);\n            this->add(0, right, x);\n        }\n    }\n\n    //\
    \ sum(v[0, i))\n    // O(log n)\n    T sum(const int i) const {\n        assert(0\
    \ <= i and i <= this->n);\n        return ft0.sum(i) * i + ft1.sum(i);\n    }\n\
    \n    // sum(v[left, right))\n    // O(log n)\n    T sum(const int left, const\
    \ int right) const {\n        assert(0 <= left and left < right and right <= this->n);\n\
    \        return this->sum(right) - this->sum(left);\n    }\n\n    // sum(v[left,\
    \ right))\n    // O(log n)\n    T sum_circle(const int left, const int right)\
    \ const {\n        // TODO\n        return 0;\n    }\n\n    void dump() {\n  \
    \      for (int i = 0; i < this->n; ++i) {\n            if (i != 0) {\n      \
    \          std::cout << \" \";\n            }\n            std::cout << this->access(i);\n\
    \        }\n        std::cout << std::endl;\n    }\n};\n"
  code: "#include \"FenwickTree.hpp\"\n#include <iostream>\n\n// \u533A\u9593\u52A0\
    \u7B97\uFF0C\u533A\u9593\u548C\u53D6\u5F97\n// \u3059\u3079\u3066 0-origin\ntemplate<typename\
    \ T>\nclass FenwickTreeRange {\n    const int n;\n    FenwickTree<T> ft0, ft1;\n\
    \npublic:\n    explicit FenwickTreeRange(const int n) : n(n), ft0(n + 1), ft1(n\
    \ + 1) {}\n\n    // v[i]\n    // O(log n)\n    T access(const int i) const {\n\
    \        assert(0 <= i and i < this->n);\n        return this->sum(i, i + 1);\n\
    \    }\n\n    // v[i] += x\n    // O(log n)\n    void add(const int i, const T\
    \ x) {\n        assert(0 <= i and i < this->n);\n        this->add(i, i + 1, x);\n\
    \    }\n\n    // v[left, right) += x\n    // O(log n)\n    void add(const int\
    \ left, const int right, const T x) {\n        if (left == right) {\n        \
    \    return;\n        }\n        assert(0 <= left and left < right and right <=\
    \ this->n);\n        this->ft0.add(left, x);\n        this->ft0.add(right, -x);\n\
    \        this->ft1.add(left, -x * left);\n        this->ft1.add(right, x * right);\n\
    \    }\n\n    // v[left, right) += x\n    // \u52A0\u7B97\u4F4D\u7F6E\u304C n\
    \ \u4EE5\u4E0A\u306E\u5834\u5408\u306F 0 \u306B\u623B\u3063\u3066\u52A0\u7B97\u3055\
    \u308C\u308B\n    // O(log n)\n    void add_circle(long long left, long long right,\
    \ const T x) {\n        assert(left < right);\n\n        const long long num_loop\
    \ = (right - left) / this->n;\n        this->add(0, this->n, x * num_loop);\n\n\
    \        // \u30EB\u30FC\u30D7\u3067\u7D42\u308F\u308A\n        if ((right - left)\
    \ % this->n == 0) {\n            return;\n        }\n\n        left %= this->n;\n\
    \        right %= this->n;\n\n        if (left < right) {\n            this->add(left,\
    \ right, x);\n        } else {\n            this->add(left, this->n, x);\n   \
    \         this->add(0, right, x);\n        }\n    }\n\n    // sum(v[0, i))\n \
    \   // O(log n)\n    T sum(const int i) const {\n        assert(0 <= i and i <=\
    \ this->n);\n        return ft0.sum(i) * i + ft1.sum(i);\n    }\n\n    // sum(v[left,\
    \ right))\n    // O(log n)\n    T sum(const int left, const int right) const {\n\
    \        assert(0 <= left and left < right and right <= this->n);\n        return\
    \ this->sum(right) - this->sum(left);\n    }\n\n    // sum(v[left, right))\n \
    \   // O(log n)\n    T sum_circle(const int left, const int right) const {\n \
    \       // TODO\n        return 0;\n    }\n\n    void dump() {\n        for (int\
    \ i = 0; i < this->n; ++i) {\n            if (i != 0) {\n                std::cout\
    \ << \" \";\n            }\n            std::cout << this->access(i);\n      \
    \  }\n        std::cout << std::endl;\n    }\n};"
  dependsOn:
  - library/cpp/Tree/FenwickTree.hpp
  isVerificationFile: false
  path: library/cpp/Tree/FenwickTreeRange.hpp
  requiredBy: []
  timestamp: '2024-01-20 16:46:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Tree/FenwickTreeRange1.test.cpp
  - test/cpp/Tree/FenwickTreeRange2.test.cpp
  - test/cpp/Geometry/sort_clockwise_polygon_points1.test.cpp
documentation_of: library/cpp/Tree/FenwickTreeRange.hpp
layout: document
redirect_from:
- /library/library/cpp/Tree/FenwickTreeRange.hpp
- /library/library/cpp/Tree/FenwickTreeRange.hpp.html
title: library/cpp/Tree/FenwickTreeRange.hpp
---
