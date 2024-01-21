---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/DataStructure/CumulativeSum.hpp
    title: library/cpp/DataStructure/CumulativeSum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/cpp/DataStructure/CumulativeSum1.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#line 1 \"library/cpp/DataStructure/CumulativeSum.hpp\"\
    \n#include <cassert>\n#include <vector>\n\ntemplate<typename T>\nclass CumulativeSum\
    \ {\nprivate:\n    std::vector<T> memo;\n\npublic:\n    CumulativeSum() {\n  \
    \  }\n\n    CumulativeSum(const std::vector<T> &line) {\n        this->build(line);\n\
    \    }\n\n    void build(const std::vector<T> &line) {\n        this->memo = std::vector<T>(line.size()\
    \ + 1, 0);\n        for (int i = 0; i < int(line.size()); ++i) {\n           \
    \ this->memo[i + 1] = this->memo[i] + line[i];\n        }\n    }\n\n    // sum[left,\
    \ right)\n    T sum(const int left, const int right) const {\n        assert(right\
    \ >= left);\n        return this->memo[right] - this->memo[left];\n    }\n};\n\
    #line 4 \"test/cpp/DataStructure/CumulativeSum1.test.cpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n    vector<long long> A(N);\n    for (int\
    \ i = 0; i < N; ++i) {\n        cin >> A[i];\n    }\n\n    CumulativeSum<long\
    \ long> cs(A);\n\n    for (int i = 0; i < Q; ++i) {\n        int L, R;\n     \
    \   cin >> L >> R;\n        cout << cs.sum(L, R) << endl;\n    }\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"library/cpp/DataStructure/CumulativeSum.hpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n    vector<long long> A(N);\n    for (int\
    \ i = 0; i < N; ++i) {\n        cin >> A[i];\n    }\n\n    CumulativeSum<long\
    \ long> cs(A);\n\n    for (int i = 0; i < Q; ++i) {\n        int L, R;\n     \
    \   cin >> L >> R;\n        cout << cs.sum(L, R) << endl;\n    }\n\n    return\
    \ 0;\n}"
  dependsOn:
  - library/cpp/DataStructure/CumulativeSum.hpp
  isVerificationFile: true
  path: test/cpp/DataStructure/CumulativeSum1.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:45:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/DataStructure/CumulativeSum1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/DataStructure/CumulativeSum1.test.cpp
- /verify/test/cpp/DataStructure/CumulativeSum1.test.cpp.html
title: test/cpp/DataStructure/CumulativeSum1.test.cpp
---
