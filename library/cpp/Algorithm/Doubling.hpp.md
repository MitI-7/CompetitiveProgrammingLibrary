---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Algorithm/Doubling1.test.cpp
    title: test/cpp/Algorithm/Doubling1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Algorithm/Doubling.hpp\"\n#include <cassert>\n\
    #include <vector>\n\ntemplate<typename T>\nclass Doubling {\n    const int LOG;\n\
    \    std::vector<std::vector<T>> table;  //table[k][i] = i\u306Ek\u56DE\u9077\u79FB\
    \u5148\u306E\u5024\n    bool initialized;\n\npublic:\n    // n: function(x) \u306E\
    \ x \u306E\u6700\u5927\u5024\n    // max_k: function \u95A2\u6570\u3092\u9069\u7528\
    \u3059\u308B\u56DE\u6570 k \u306E\u6700\u5927\u5024\n    Doubling(int n, long\
    \ long max_k) : LOG(64 - __builtin_clzll(max_k)), initialized(false) {\n     \
    \   this->table.assign(LOG, std::vector<T>(n, -1));\n    }\n\n    // x\u306E\u9077\
    \u79FB\u5148\n    // function(x) = y\n    void function(const int x, const T y)\
    \ {\n        assert(not this->initialized);\n        this->table[0][x] = y;\n\
    \    }\n\n    // a \u306B function \u95A2\u6570\u3092 k \u56DE\u9069\u7528\u3057\
    \u305F\u3068\u304D\u306E\u5024\n    // O(log k)\n    T query(T a, unsigned long\
    \ long k) {\n        if (not this->initialized) {\n            this->build();\n\
    \        }\n        for (int i = this->LOG - 1; i >= 0; i--) {\n            if\
    \ ((k >> i) & 1) {\n                a = this->table[i][a];\n            }\n  \
    \      }\n\n        return a;\n    }\n\nprivate:\n    // O(N log max_k)\n    void\
    \ build() {\n        for (int k = 0; k + 1 < this->LOG; ++k) {\n            for\
    \ (int i = 0; i < int(this->table[k].size()); ++i) {\n                if (this->table[k][i]\
    \ == -1) {\n                    this->table[k + 1][i] = -1;\n                }\n\
    \                else {\n                    this->table[k + 1][i] = this->table[k][this->table[k][i]];\n\
    \                }\n            }\n        }\n        this->initialized = true;\n\
    \    }\n};\n"
  code: "#include <cassert>\n#include <vector>\n\ntemplate<typename T>\nclass Doubling\
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
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Algorithm/Doubling.hpp
  requiredBy: []
  timestamp: '2024-01-20 16:44:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Algorithm/Doubling1.test.cpp
documentation_of: library/cpp/Algorithm/Doubling.hpp
layout: document
redirect_from:
- /library/library/cpp/Algorithm/Doubling.hpp
- /library/library/cpp/Algorithm/Doubling.hpp.html
title: library/cpp/Algorithm/Doubling.hpp
---
