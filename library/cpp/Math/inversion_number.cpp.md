---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Tree/FenwickTree.hpp
    title: library/cpp/Tree/FenwickTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Math/inversion_number1.test.cpp
    title: test/cpp/Math/inversion_number1.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Math/inversion_number.cpp\"\n#include <algorithm>\n\
    #include <vector>\n#line 1 \"library/cpp/Tree/FenwickTree.hpp\"\n#include <cassert>\n\
    #line 3 \"library/cpp/Tree/FenwickTree.hpp\"\n\n// \u3059\u3079\u3066 0-origin\n\
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
    \ - this->sum(left);\n    }\n};\n#line 4 \"library/cpp/Math/inversion_number.cpp\"\
    \n\n// j < i \u304B\u3064 v[j] > v[i] \u306E\u7D44\u306E\u500B\u6570\u3067\u3042\
    \u308B\u8EE2\u5012\u6570\u3092\u6C42\u3081\u308B\n// v\u306E\u8981\u7D20\u304C\
    \u5927\u304D\u3044\u5834\u5408\u5EA7\u6A19\u5727\u7E2E\u3092\u3059\u308B\u3053\
    \u3068\n// O(n log n)\ntemplate<typename T>\nlong long inversion_number(const\
    \ std::vector<T> &v) {\n    int max_v = (int) *std::max_element(v.begin(), v.end());\n\
    \    FenwickTree<long long> ft(max_v + 10);\n\n    long long ans = 0;\n    for\
    \ (int i = 0; i < (int) v.size(); ++i) {\n        ans += i - ft.sum(v[i]);\n \
    \       ft.add(v[i], 1);\n    }\n    return ans;\n}\n"
  code: "#include <algorithm>\n#include <vector>\n#include \"library/cpp/Tree/FenwickTree.hpp\"\
    \n\n// j < i \u304B\u3064 v[j] > v[i] \u306E\u7D44\u306E\u500B\u6570\u3067\u3042\
    \u308B\u8EE2\u5012\u6570\u3092\u6C42\u3081\u308B\n// v\u306E\u8981\u7D20\u304C\
    \u5927\u304D\u3044\u5834\u5408\u5EA7\u6A19\u5727\u7E2E\u3092\u3059\u308B\u3053\
    \u3068\n// O(n log n)\ntemplate<typename T>\nlong long inversion_number(const\
    \ std::vector<T> &v) {\n    int max_v = (int) *std::max_element(v.begin(), v.end());\n\
    \    FenwickTree<long long> ft(max_v + 10);\n\n    long long ans = 0;\n    for\
    \ (int i = 0; i < (int) v.size(); ++i) {\n        ans += i - ft.sum(v[i]);\n \
    \       ft.add(v[i], 1);\n    }\n    return ans;\n}"
  dependsOn:
  - library/cpp/Tree/FenwickTree.hpp
  isVerificationFile: false
  path: library/cpp/Math/inversion_number.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:51:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Math/inversion_number1.test.cpp
documentation_of: library/cpp/Math/inversion_number.cpp
layout: document
redirect_from:
- /library/library/cpp/Math/inversion_number.cpp
- /library/library/cpp/Math/inversion_number.cpp.html
title: library/cpp/Math/inversion_number.cpp
---
