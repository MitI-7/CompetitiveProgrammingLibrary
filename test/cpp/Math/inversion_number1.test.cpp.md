---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/cpp/Compression/CoordinateCompression.hpp
    title: library/cpp/Compression/CoordinateCompression.hpp
  - icon: ':question:'
    path: library/cpp/DataStructure/FenwickTree.hpp
    title: library/cpp/DataStructure/FenwickTree.hpp
  - icon: ':x:'
    path: library/cpp/Math/inversion_number.cpp
    title: library/cpp/Math/inversion_number.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
  bundledCode: "#line 1 \"test/cpp/Math/inversion_number1.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\n\n\
    #line 1 \"library/cpp/Math/inversion_number.cpp\"\n#include <algorithm>\n#include\
    \ <vector>\n#line 1 \"library/cpp/DataStructure/FenwickTree.hpp\"\n#include <cassert>\n\
    #line 3 \"library/cpp/DataStructure/FenwickTree.hpp\"\n\n// \u3059\u3079\u3066\
    \ 0-origin\ntemplate<class T>\nclass FenwickTree {\npublic:\n    const int n;\n\
    \    std::vector<T> v;\n\n    // n: \u8981\u7D20\u6570\n    explicit FenwickTree(const\
    \ int n) : n(n) {\n        this->v.assign(n + 1, 0);\n    }\n\n    // v[i]\n \
    \   // O(log n)\n    T access(const int i) const {\n        return this->sum(i,\
    \ i + 1);\n    }\n\n    // v[i] += x\n    // O(log n)\n    void add(int i, T x)\
    \ {\n        assert(i < this->n);\n\n        while (i < this->n) {\n         \
    \   this->v[i] += x;\n            i |= i + 1;\n        }\n    }\n\n    // v[i]\
    \ = x\n    // O(log n)\n    void update(int i, T x) {\n        assert(i < this->n);\n\
    \n        const T now = this->access(i);\n        this->add(i, x - now);\n   \
    \ }\n\n    // sum(v[0, i))\n    // O(log n)\n    T sum(int i) const {\n      \
    \  assert(0 <= i and i <= this->n);\n\n        T s = 0;\n        i -= 1;\n   \
    \     while (i >= 0) {\n            s += this->v[i];\n            i = (i & (i\
    \ + 1)) - 1;\n        }\n        return s;\n    }\n\n    // sum(v[left, right))\n\
    \    // O(log n)\n    T sum(const int left, const int right) const {\n       \
    \ if (left >= right) {\n            return 0;\n        }\n        return this->sum(right)\
    \ - this->sum(left);\n    }\n};\n#line 4 \"library/cpp/Math/inversion_number.cpp\"\
    \n\n// j < i \u304B\u3064 v[j] > v[i] \u306E\u7D44\u306E\u500B\u6570\u3067\u3042\
    \u308B\u8EE2\u5012\u6570\u3092\u6C42\u3081\u308B\n// v\u306E\u8981\u7D20\u304C\
    \u5927\u304D\u3044\u5834\u5408\u5EA7\u6A19\u5727\u7E2E\u3092\u3059\u308B\u3053\
    \u3068\n// O(n log n)\ntemplate<typename T>\nlong long inversion_number(const\
    \ std::vector<T> &v) {\n    int max_v = (int) *std::max_element(v.begin(), v.end());\n\
    \    FenwickTree<long long> ft(max_v + 10);\n\n    long long ans = 0;\n    for\
    \ (int i = 0; i < (int) v.size(); ++i) {\n        ans += i - ft.sum(v[i]);\n \
    \       ft.add(v[i], 1);\n    }\n    return ans;\n}\n#line 1 \"library/cpp/Compression/CoordinateCompression.hpp\"\
    \n#include <set>\n#include <unordered_map>\n\ntemplate<class T=long long>\nclass\
    \ CoordinateCompression {\nprivate:\n    bool initialized;\n    std::set<T> s;\n\
    \n    int no = 0;\n    std::unordered_map<T, int> _zip;\n    std::unordered_map<int,\
    \ T> _unzip;\npublic:\n    CoordinateCompression() : initialized(false) {}\n\n\
    \    void add(T x) {\n        this->s.insert(x);\n    }\n\n    int size() {\n\
    \        if (not this->initialized) {\n            this->build();\n        }\n\
    \        return this->no;\n    }\n\n    // \u5143\u306E\u5024 -> \u5727\u7E2E\u3057\
    \u305F\u5024\n    int zip(const T x) {\n        if (not this->initialized) {\n\
    \            this->build();\n        }\n        return this->_zip[x];\n    }\n\
    \n    // \u5727\u7E2E\u3057\u305F\u5024 -> \u5143\u306E\u5024\n    T unzip(const\
    \ int i) {\n        if (not this->initialized) {\n            this->build();\n\
    \        }\n        return this->_unzip[i];\n    }\n\nprivate:\n    void build()\
    \ {\n        this->initialized = true;\n        for (auto x: this->s) {\n    \
    \        this->_zip[x] = this->no;\n            this->_unzip[this->no] = x;\n\
    \            this->no++;\n        }\n    }\n};\n#line 5 \"test/cpp/Math/inversion_number1.test.cpp\"\
    \n#include <iostream>\n#line 7 \"test/cpp/Math/inversion_number1.test.cpp\"\n\n\
    using namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N;\n    cin >> N;\n    vector<int> A(N);\n    CoordinateCompression\
    \ cc;\n    for (int i = 0; i < N; ++i) {\n        cin >> A[i];\n        cc.add(A[i]);\n\
    \    }\n\n    for (int i = 0; i < N; ++i) {\n        A[i] = cc.zip(A[i]);\n  \
    \  }\n\n    cout << inversion_number(A) << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n\n#include \"library/cpp/Math/inversion_number.cpp\"\n#include \"library/cpp/Compression/CoordinateCompression.hpp\"\
    \n#include <iostream>\n#include <vector>\n\nusing namespace std;\n\nint main()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    int N;\n \
    \   cin >> N;\n    vector<int> A(N);\n    CoordinateCompression cc;\n    for (int\
    \ i = 0; i < N; ++i) {\n        cin >> A[i];\n        cc.add(A[i]);\n    }\n\n\
    \    for (int i = 0; i < N; ++i) {\n        A[i] = cc.zip(A[i]);\n    }\n\n  \
    \  cout << inversion_number(A) << endl;\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Math/inversion_number.cpp
  - library/cpp/DataStructure/FenwickTree.hpp
  - library/cpp/Compression/CoordinateCompression.hpp
  isVerificationFile: true
  path: test/cpp/Math/inversion_number1.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:51:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/cpp/Math/inversion_number1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Math/inversion_number1.test.cpp
- /verify/test/cpp/Math/inversion_number1.test.cpp.html
title: test/cpp/Math/inversion_number1.test.cpp
---
