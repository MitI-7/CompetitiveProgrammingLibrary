---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/DataStructure/FenwickTree.hpp
    title: library/cpp/DataStructure/FenwickTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=ja
  bundledCode: "#line 1 \"test/cpp/DataStructure/FenwickTree1.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=ja\"\
    \n\n#line 1 \"library/cpp/DataStructure/FenwickTree.hpp\"\n#include <cassert>\n\
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
    \  }\n        return this->sum(right) - this->sum(left);\n    }\n};\n#line 4 \"\
    test/cpp/DataStructure/FenwickTree1.test.cpp\"\n#include <iostream>\n\nusing namespace\
    \ std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n\n    FenwickTree<int> ft(N);\n    for (int\
    \ i = 0; i < Q; ++i) {\n        int COM, X, Y;\n        cin >> COM >> X >> Y;\n\
    \        if (COM == 0) {\n            X--;\n            ft.add(X, Y);\n      \
    \  }\n        else {\n            X--;\n            Y--;\n            cout <<\
    \ ft.sum(X, Y + 1) << endl;\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=ja\"\
    \n\n#include \"library/cpp/DataStructure/FenwickTree.hpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n\n    FenwickTree<int> ft(N);\n    for (int\
    \ i = 0; i < Q; ++i) {\n        int COM, X, Y;\n        cin >> COM >> X >> Y;\n\
    \        if (COM == 0) {\n            X--;\n            ft.add(X, Y);\n      \
    \  }\n        else {\n            X--;\n            Y--;\n            cout <<\
    \ ft.sum(X, Y + 1) << endl;\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/DataStructure/FenwickTree.hpp
  isVerificationFile: true
  path: test/cpp/DataStructure/FenwickTree1.test.cpp
  requiredBy: []
  timestamp: '2023-05-21 19:05:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/DataStructure/FenwickTree1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/DataStructure/FenwickTree1.test.cpp
- /verify/test/cpp/DataStructure/FenwickTree1.test.cpp.html
title: test/cpp/DataStructure/FenwickTree1.test.cpp
---
