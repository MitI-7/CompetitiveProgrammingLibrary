---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/DataStructure/DynamicMedian.hpp
    title: library/cpp/DataStructure/DynamicMedian.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc127/tasks/abc127_f
    links:
    - https://atcoder.jp/contests/abc127/tasks/abc127_f
  bundledCode: "#line 1 \"test/cpp/DataStructure/DynamicMedian1.test.cpp\"\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/abc127/tasks/abc127_f\"\n\n#line 1 \"\
    library/cpp/DataStructure/DynamicMedian.hpp\"\n#include <cassert>\n#include <queue>\n\
    \ntemplate<typename T=long long>\nclass DynamicMedian {\n    \nprivate:\n    unsigned\
    \ int num = 0;\n    std::priority_queue<T> min_heap;                         \
    \          // \u4E2D\u592E\u5024\u3088\u308A\u5C0F\u3055\u3044\u5024\u3092\u7BA1\
    \u7406\n    std::priority_queue<T, std::vector<T>, std::greater<T>> max_heap;\
    \  // \u4E2D\u592E\u5024\u3088\u308A\u5927\u304D\u3044\u5024\u3092\u7BA1\u7406\
    \n    T total_minimum = 0;\n    T total_maximum = 0;\n\npublic:\n    DynamicMedian()\
    \ = default;\n\n    // x\u3092\u633F\u5165O(log n)\n    void insert(T x) {\n \
    \       if (num % 2 == 0) {\n            this->max_heap.push(x);\n           \
    \ this->total_maximum += x;\n        }\n        else {\n            this->min_heap.push(x);\n\
    \            this->total_minimum += x;\n        }\n        this->balance();\n\
    \        this->num++;\n    }\n\n    // \u4E2D\u592E\u5024\u3092\u898B\u3064\u3051\
    \u308B\n    // \u30B5\u30A4\u30BA\u304C\u5076\u6570\u306E\u3068\u304D\u306F\uFF0C\
    \u5C0F\u3055\u3044\u65B9\u3092\u4E2D\u592E\u5024\u3068\u3057\u3066\u3044\u308B\
    \n    // O(1)\n    T find_median() {\n        assert(this->num > 0);\n\n     \
    \   if (this->num % 2 == 0) {\n            return this->min_heap.top();\n    \
    \    }\n        else {\n            return this->max_heap.top();\n        }\n\
    \    }\n\n    // \u4E2D\u592E\u5024\u3068\u4ED6\u306E\u8981\u7D20\u306E\u7D76\u5BFE\
    \u5024\u306E\u5408\u8A08\n    // sum(|a[1] - m| + |a[2] - m| + ... + |a[n] - m|)\n\
    \    // O(1)\n    T absolute() {\n        T x = this->find_median();\n       \
    \ T mini = std::abs(x * (T) this->min_heap.size() - this->total_minimum);\n  \
    \      T maxi = std::abs(x * (T) this->max_heap.size() - this->total_maximum);\n\
    \n        return mini + maxi;\n    }\n\nprivate:\n    void balance() {\n     \
    \   if (this->min_heap.empty() or this->max_heap.empty()) {\n            return;\n\
    \        }\n\n        // min heap \u306E\u6700\u5927\u3068 max heap \u306E\u6700\
    \u5C0F\u304C\u9006\u8EE2\u3057\u3066\u3044\u305F\u3089 swap \u3059\u308B\n   \
    \     if (this->min_heap.top() > this->max_heap.top()) {\n            T tmp;\n\
    \n            // max heap \u304B\u3089\u51FA\u3057\u3066\uFF0Cmin heap \u306B\u3044\
    \u308C\u308B\n            tmp = this->max_heap.top();\n            this->max_heap.pop();\n\
    \            this->min_heap.push(tmp);\n            this->total_maximum -= tmp;\n\
    \            this->total_minimum += tmp;\n\n            // min heap \u304B\u3089\
    \u51FA\u3057\u3066\uFF0Cmax heap \u306B\u3044\u308C\u308B\n            tmp = this->min_heap.top();\n\
    \            this->min_heap.pop();\n            this->max_heap.push(tmp);\n  \
    \          this->total_maximum += tmp;\n            this->total_minimum -= tmp;\n\
    \        }\n    }\n};\n#line 4 \"test/cpp/DataStructure/DynamicMedian1.test.cpp\"\
    \n#include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int Q;\n    cin >> Q;\n\n    DynamicMedian\
    \ dm;\n\n    long long total_b = 0;\n    for (int i = 0; i < Q; ++i) {\n     \
    \   int T;\n        cin >> T;\n        if (T == 1) {\n            long long A,\
    \ B;\n            cin >> A >> B;\n            dm.insert(A);\n            total_b\
    \ += B;\n        }\n        else {\n            auto x = dm.find_median();\n \
    \           auto a = dm.absolute();\n            cout << x << \" \" << a + total_b\
    \ << endl;\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc127/tasks/abc127_f\"\n\n\
    #include \"library/cpp/DataStructure/DynamicMedian.hpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int Q;\n    cin >> Q;\n\n    DynamicMedian dm;\n\n    long long total_b\
    \ = 0;\n    for (int i = 0; i < Q; ++i) {\n        int T;\n        cin >> T;\n\
    \        if (T == 1) {\n            long long A, B;\n            cin >> A >> B;\n\
    \            dm.insert(A);\n            total_b += B;\n        }\n        else\
    \ {\n            auto x = dm.find_median();\n            auto a = dm.absolute();\n\
    \            cout << x << \" \" << a + total_b << endl;\n        }\n    }\n\n\
    \    return 0;\n}"
  dependsOn:
  - library/cpp/DataStructure/DynamicMedian.hpp
  isVerificationFile: true
  path: test/cpp/DataStructure/DynamicMedian1.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:38:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/DataStructure/DynamicMedian1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/DataStructure/DynamicMedian1.test.cpp
- /verify/test/cpp/DataStructure/DynamicMedian1.test.cpp.html
title: test/cpp/DataStructure/DynamicMedian1.test.cpp
---
