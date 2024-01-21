---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Algorithm/Doubling.hpp
    title: library/cpp/Algorithm/Doubling.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc167/tasks/abc167_d
    links:
    - https://atcoder.jp/contests/abc167/tasks/abc167_d
  bundledCode: "#line 1 \"test/cpp/Algorithm/Doubling1.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc167/tasks/abc167_d\"\n\n#line 1 \"library/cpp/Algorithm/Doubling.hpp\"\
    \n#include <cassert>\n#include <vector>\n\ntemplate<typename T>\nclass Doubling\
    \ {\n    const int LOG;\n    std::vector<std::vector<T>> table;  //table[k][i]\
    \ = i\u306Ek\u56DE\u9077\u79FB\u5148\u306E\u5024\n    bool initialized;\n\npublic:\n\
    \    // n: function(x) \u306E x \u306E\u6700\u5927\u5024\n    // max_k: function\
    \ \u95A2\u6570\u3092\u9069\u7528\u3059\u308B\u56DE\u6570 k \u306E\u6700\u5927\u5024\
    \n    Doubling(int n, long long max_k) : LOG(64 - __builtin_clzll(max_k)), initialized(false)\
    \ {\n        this->table.assign(LOG, std::vector<T>(n, -1));\n    }\n\n    //\
    \ x\u306E\u9077\u79FB\u5148\n    // function(x) = y\n    void function(const int\
    \ x, const T y) {\n        assert(not this->initialized);\n        this->table[0][x]\
    \ = y;\n    }\n\n    // a \u306B function \u95A2\u6570\u3092 k \u56DE\u9069\u7528\
    \u3057\u305F\u3068\u304D\u306E\u5024\n    // O(log k)\n    T query(T a, unsigned\
    \ long long k) {\n        if (not this->initialized) {\n            this->build();\n\
    \        }\n        for (int i = this->LOG - 1; i >= 0; i--) {\n            if\
    \ ((k >> i) & 1) {\n                a = this->table[i][a];\n            }\n  \
    \      }\n\n        return a;\n    }\n\nprivate:\n    // O(N log max_k)\n    void\
    \ build() {\n        for (int k = 0; k + 1 < this->LOG; ++k) {\n            for\
    \ (int i = 0; i < int(this->table[k].size()); ++i) {\n                if (this->table[k][i]\
    \ == -1) {\n                    this->table[k + 1][i] = -1;\n                }\n\
    \                else {\n                    this->table[k + 1][i] = this->table[k][this->table[k][i]];\n\
    \                }\n            }\n        }\n        this->initialized = true;\n\
    \    }\n};\n#line 4 \"test/cpp/Algorithm/Doubling1.test.cpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N;\n    long long K;\n    cin >> N >> K;\n    vector<int> A(N);\n  \
    \  for (int i = 0; i < N; ++i) {\n        cin >> A[i];\n        A[i]--;\n    }\n\
    \n    Doubling<int> doubling(N, (long long) 1000000000000000100);\n    for (int\
    \ i = 0; i < N; ++i) {\n        doubling.function(i, A[i]);\n    }\n\n    cout\
    \ << doubling.query(0, K) + 1 << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc167/tasks/abc167_d\"\n\n\
    #include \"library/cpp/Algorithm/Doubling.hpp\"\n#include <iostream>\n\nusing\
    \ namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N;\n    long long K;\n    cin >> N >> K;\n    vector<int> A(N);\n  \
    \  for (int i = 0; i < N; ++i) {\n        cin >> A[i];\n        A[i]--;\n    }\n\
    \n    Doubling<int> doubling(N, (long long) 1000000000000000100);\n    for (int\
    \ i = 0; i < N; ++i) {\n        doubling.function(i, A[i]);\n    }\n\n    cout\
    \ << doubling.query(0, K) + 1 << endl;\n\n    return 0;\n}\n"
  dependsOn:
  - library/cpp/Algorithm/Doubling.hpp
  isVerificationFile: true
  path: test/cpp/Algorithm/Doubling1.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:45:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Algorithm/Doubling1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Algorithm/Doubling1.test.cpp
- /verify/test/cpp/Algorithm/Doubling1.test.cpp.html
title: test/cpp/Algorithm/Doubling1.test.cpp
---
