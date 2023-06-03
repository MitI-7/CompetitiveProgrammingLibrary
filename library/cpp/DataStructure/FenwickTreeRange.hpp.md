---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/DataStructure/FenwickTree.hpp
    title: library/cpp/DataStructure/FenwickTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/DataStructure/FenwickTreeRange1.test.cpp
    title: test/cpp/DataStructure/FenwickTreeRange1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/DataStructure/FenwickTreeRange2.test.cpp
    title: test/cpp/DataStructure/FenwickTreeRange2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/DataStructure/FenwickTree.hpp\"\n#include <cassert>\n\
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
    library/cpp/DataStructure/FenwickTreeRange.hpp\"\n\n// \u533A\u9593\u52A0\u7B97\
    \uFF0C\u533A\u9593\u548C\u53D6\u5F97\n// \u3059\u3079\u3066 0-origin\ntemplate<typename\
    \ T>\nclass FenwickTreeRange {\n    const int n;\n    FenwickTree<T> ft0, ft1;\n\
    \npublic:\n    explicit FenwickTreeRange(const int n) : n(n), ft0(n + 1), ft1(n\
    \ + 1) {}\n\n    // v[i]\n    // O(log n)\n    T access(const int i) const {\n\
    \        assert(0 <= i and i < this->n);\n        return this->sum(i, i + 1);\n\
    \    }\n\n    // v[i] += x\n    // O(log n)\n    void add(const int i, const T\
    \ x) {\n        assert(0 <= i and i < this->n);\n        this->add(i, i + 1, x);\n\
    \    }\n\n    // v[left, right) += x\n    // O(log n)\n    void add(const int\
    \ left, const int right, const T x) {\n        assert(0 <= left and left < right\
    \ and right <= this->n);\n        this->ft0.add(left, x);\n        this->ft0.add(right,\
    \ -x);\n        this->ft1.add(left, -x * left);\n        this->ft1.add(right,\
    \ x * right);\n    }\n\n    // sum(v[0, i))\n    // O(log n)\n    T sum(const\
    \ int i) const {\n        assert(0 <= i and i <= this->n);\n        return ft0.sum(i)\
    \ * i + ft1.sum(i);\n    }\n\n    // sum(v[left, right))\n    // O(log n)\n  \
    \  T sum(const int left, const int right) const {\n        assert(0 <= left and\
    \ left < right and right <= this->n);\n        return this->sum(right) - this->sum(left);\n\
    \    }\n};\n"
  code: "#include \"library/cpp/DataStructure/FenwickTree.hpp\"\n\n// \u533A\u9593\
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
    \    }\n};"
  dependsOn:
  - library/cpp/DataStructure/FenwickTree.hpp
  isVerificationFile: false
  path: library/cpp/DataStructure/FenwickTreeRange.hpp
  requiredBy: []
  timestamp: '2023-06-03 11:57:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/DataStructure/FenwickTreeRange1.test.cpp
  - test/cpp/DataStructure/FenwickTreeRange2.test.cpp
documentation_of: library/cpp/DataStructure/FenwickTreeRange.hpp
layout: document
redirect_from:
- /library/library/cpp/DataStructure/FenwickTreeRange.hpp
- /library/library/cpp/DataStructure/FenwickTreeRange.hpp.html
title: library/cpp/DataStructure/FenwickTreeRange.hpp
---
