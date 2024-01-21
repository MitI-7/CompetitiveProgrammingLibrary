---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/DataStructure/CumulativeSum1.test.cpp
    title: test/cpp/DataStructure/CumulativeSum1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/DataStructure/CumulativeSum.hpp\"\n#include\
    \ <cassert>\n#include <vector>\n\ntemplate<typename T>\nclass CumulativeSum {\n\
    private:\n    std::vector<T> memo;\n\npublic:\n    CumulativeSum() {\n    }\n\n\
    \    CumulativeSum(const std::vector<T> &line) {\n        this->build(line);\n\
    \    }\n\n    void build(const std::vector<T> &line) {\n        this->memo = std::vector<T>(line.size()\
    \ + 1, 0);\n        for (int i = 0; i < int(line.size()); ++i) {\n           \
    \ this->memo[i + 1] = this->memo[i] + line[i];\n        }\n    }\n\n    // sum[left,\
    \ right)\n    T sum(const int left, const int right) const {\n        assert(right\
    \ >= left);\n        return this->memo[right] - this->memo[left];\n    }\n};\n"
  code: "#include <cassert>\n#include <vector>\n\ntemplate<typename T>\nclass CumulativeSum\
    \ {\nprivate:\n    std::vector<T> memo;\n\npublic:\n    CumulativeSum() {\n  \
    \  }\n\n    CumulativeSum(const std::vector<T> &line) {\n        this->build(line);\n\
    \    }\n\n    void build(const std::vector<T> &line) {\n        this->memo = std::vector<T>(line.size()\
    \ + 1, 0);\n        for (int i = 0; i < int(line.size()); ++i) {\n           \
    \ this->memo[i + 1] = this->memo[i] + line[i];\n        }\n    }\n\n    // sum[left,\
    \ right)\n    T sum(const int left, const int right) const {\n        assert(right\
    \ >= left);\n        return this->memo[right] - this->memo[left];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/DataStructure/CumulativeSum.hpp
  requiredBy: []
  timestamp: '2024-01-20 16:45:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/DataStructure/CumulativeSum1.test.cpp
documentation_of: library/cpp/DataStructure/CumulativeSum.hpp
layout: document
redirect_from:
- /library/library/cpp/DataStructure/CumulativeSum.hpp
- /library/library/cpp/DataStructure/CumulativeSum.hpp.html
title: library/cpp/DataStructure/CumulativeSum.hpp
---
