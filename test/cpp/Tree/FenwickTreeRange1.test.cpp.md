---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/Tree/FenwickTree.hpp
    title: library/cpp/Tree/FenwickTree.hpp
  - icon: ':x:'
    path: library/cpp/Tree/FenwickTreeRange.hpp
    title: library/cpp/Tree/FenwickTreeRange.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=ja
  bundledCode: "#line 1 \"test/cpp/Tree/FenwickTreeRange1.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=ja\"\
    \n\n#line 1 \"library/cpp/Tree/FenwickTree.hpp\"\n#include <cassert>\n#include\
    \ <vector>\n\n// \u3059\u3079\u3066 0-origin\ntemplate<class T>\nclass FenwickTree\
    \ {\npublic:\n    const int n;\n    std::vector<T> v;\n\n    // n: \u8981\u7D20\
    \u6570\n    explicit FenwickTree(const int n) : n(n) {\n        this->v.assign(n\
    \ + 1, 0);\n    }\n\n    // v[i]\n    // O(log n)\n    T access(const int i) const\
    \ {\n        return this->sum(i, i + 1);\n    }\n\n    // v[i] += x\n    // O(log\
    \ n)\n    void add(int i, T x) {\n        assert(i < this->n);\n\n        while\
    \ (i < this->n) {\n            this->v[i] += x;\n            i |= i + 1;\n   \
    \     }\n    }\n\n    // v[i] = x\n    // O(log n)\n    void update(int i, T x)\
    \ {\n        assert(i < this->n);\n\n        const T now = this->access(i);\n\
    \        this->add(i, x - now);\n    }\n\n    // sum(v[0, i))\n    // O(log n)\n\
    \    T sum(int i) const {\n        assert(0 <= i and i <= this->n);\n\n      \
    \  T s = 0;\n        i -= 1;\n        while (i >= 0) {\n            s += this->v[i];\n\
    \            i = (i & (i + 1)) - 1;\n        }\n        return s;\n    }\n\n \
    \   // sum(v[left, right))\n    // O(log n)\n    T sum(const int left, const int\
    \ right) const {\n        if (left >= right) {\n            return 0;\n      \
    \  }\n        return this->sum(right) - this->sum(left);\n    }\n};\n#line 2 \"\
    library/cpp/Tree/FenwickTreeRange.hpp\"\n\n// \u533A\u9593\u52A0\u7B97\uFF0C\u533A\
    \u9593\u548C\u53D6\u5F97\n// \u3059\u3079\u3066 0-origin\ntemplate<typename T>\n\
    class FenwickTreeRange {\n    const int n;\n    FenwickTree<T> ft0, ft1;\n\npublic:\n\
    \    explicit FenwickTreeRange(const int n) : n(n), ft0(n + 1), ft1(n + 1) {}\n\
    \n    // v[i]\n    // O(log n)\n    T access(const int i) const {\n        assert(0\
    \ <= i and i < this->n);\n        return this->sum(i, i + 1);\n    }\n\n    //\
    \ v[i] += x\n    // O(log n)\n    void add(const int i, const T x) {\n       \
    \ assert(0 <= i and i < this->n);\n        this->add(i, i + 1, x);\n    }\n\n\
    \    // v[left, right) += x\n    // O(log n)\n    void add(const int left, const\
    \ int right, const T x) {\n        assert(0 <= left and left < right and right\
    \ <= this->n);\n        this->ft0.add(left, x);\n        this->ft0.add(right,\
    \ -x);\n        this->ft1.add(left, -x * left);\n        this->ft1.add(right,\
    \ x * right);\n    }\n\n    // sum(v[0, i))\n    // O(log n)\n    T sum(const\
    \ int i) const {\n        assert(0 <= i and i <= this->n);\n        return ft0.sum(i)\
    \ * i + ft1.sum(i);\n    }\n\n    // sum(v[left, right))\n    // O(log n)\n  \
    \  T sum(const int left, const int right) const {\n        assert(0 <= left and\
    \ left < right and right <= this->n);\n        return this->sum(right) - this->sum(left);\n\
    \    }\n};\n#line 4 \"test/cpp/Tree/FenwickTreeRange1.test.cpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n\n    FenwickTreeRange<int> ftr(N);\n   \
    \ for (int _ = 0; _ < Q; ++_) {\n        int QUERY, S, T, X, I;\n        cin >>\
    \ QUERY;\n        if (QUERY == 0) {\n            cin >> S >> T >> X;\n       \
    \     S--;\n            T--;\n            ftr.add(S, T + 1, X);\n        } else\
    \ {\n            cin >> I;\n            I--;\n            cout << ftr.access(I)\
    \ << endl;\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=ja\"\
    \n\n#include \"library/cpp/Tree/FenwickTreeRange.hpp\"\n#include <iostream>\n\n\
    using namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n\n    FenwickTreeRange<int> ftr(N);\n   \
    \ for (int _ = 0; _ < Q; ++_) {\n        int QUERY, S, T, X, I;\n        cin >>\
    \ QUERY;\n        if (QUERY == 0) {\n            cin >> S >> T >> X;\n       \
    \     S--;\n            T--;\n            ftr.add(S, T + 1, X);\n        } else\
    \ {\n            cin >> I;\n            I--;\n            cout << ftr.access(I)\
    \ << endl;\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Tree/FenwickTreeRange.hpp
  - library/cpp/Tree/FenwickTree.hpp
  isVerificationFile: true
  path: test/cpp/Tree/FenwickTreeRange1.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:46:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/cpp/Tree/FenwickTreeRange1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Tree/FenwickTreeRange1.test.cpp
- /verify/test/cpp/Tree/FenwickTreeRange1.test.cpp.html
title: test/cpp/Tree/FenwickTreeRange1.test.cpp
---
