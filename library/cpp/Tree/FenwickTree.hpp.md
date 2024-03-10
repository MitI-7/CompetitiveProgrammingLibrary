---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Math/inversion_number.cpp
    title: library/cpp/Math/inversion_number.cpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/Tree/FenwickTreeRange.hpp
    title: library/cpp/Tree/FenwickTreeRange.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Geometry/sort_clockwise_polygon_points1.test.cpp
    title: test/cpp/Geometry/sort_clockwise_polygon_points1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Math/inversion_number1.test.cpp
    title: test/cpp/Math/inversion_number1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Tree/FenwickTree1.test.cpp
    title: test/cpp/Tree/FenwickTree1.test.cpp
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
    \  }\n        return this->sum(right) - this->sum(left);\n    }\n};\n"
  code: "#include <cassert>\n#include <vector>\n\n// \u3059\u3079\u3066 0-origin\n\
    template<class T>\nclass FenwickTree {\npublic:\n    const int n;\n    std::vector<T>\
    \ v;\n\n    // n: \u8981\u7D20\u6570\n    explicit FenwickTree(const int n) :\
    \ n(n) {\n        this->v.assign(n + 1, 0);\n    }\n\n    // v[i]\n    // O(log\
    \ n)\n    T access(const int i) const {\n        return this->sum(i, i + 1);\n\
    \    }\n\n    // v[i] += x\n    // O(log n)\n    void add(int i, T x) {\n    \
    \    assert(i < this->n);\n\n        while (i < this->n) {\n            this->v[i]\
    \ += x;\n            i |= i + 1;\n        }\n    }\n\n    // v[i] = x\n    //\
    \ O(log n)\n    void update(int i, T x) {\n        assert(i < this->n);\n\n  \
    \      const T now = this->access(i);\n        this->add(i, x - now);\n    }\n\
    \n    // sum(v[0, i))\n    // O(log n)\n    T sum(int i) const {\n        assert(0\
    \ <= i and i <= this->n);\n\n        T s = 0;\n        i -= 1;\n        while\
    \ (i >= 0) {\n            s += this->v[i];\n            i = (i & (i + 1)) - 1;\n\
    \        }\n        return s;\n    }\n\n    // sum(v[left, right))\n    // O(log\
    \ n)\n    T sum(const int left, const int right) const {\n        if (left >=\
    \ right) {\n            return 0;\n        }\n        return this->sum(right)\
    \ - this->sum(left);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Tree/FenwickTree.hpp
  requiredBy:
  - library/cpp/Math/inversion_number.cpp
  - library/cpp/Tree/FenwickTreeRange.hpp
  timestamp: '2024-01-20 16:44:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Geometry/sort_clockwise_polygon_points1.test.cpp
  - test/cpp/Math/inversion_number1.test.cpp
  - test/cpp/Tree/FenwickTreeRange1.test.cpp
  - test/cpp/Tree/FenwickTree1.test.cpp
  - test/cpp/Tree/FenwickTreeRange2.test.cpp
documentation_of: library/cpp/Tree/FenwickTree.hpp
layout: document
redirect_from:
- /library/library/cpp/Tree/FenwickTree.hpp
- /library/library/cpp/Tree/FenwickTree.hpp.html
title: library/cpp/Tree/FenwickTree.hpp
---
