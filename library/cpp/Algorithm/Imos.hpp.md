---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Algorithm/Imos1.test.cpp
    title: test/cpp/Algorithm/Imos1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Algorithm/Imos.hpp\"\n#include <vector>\n#include\
    \ <iostream>\n#include <cassert>\n\ntemplate<typename T>\nclass Imos {\npublic:\n\
    \    const int n;\n    std::vector<T> line;\n\n    Imos(int n) : n(n) {\n    \
    \    this->line.resize(n + 1, 0);\n    }\n\n    // [left, right) \u306B +num\n\
    \    void add(const int left, const int right, const T num) {\n        assert(left\
    \ < right);\n        this->line[left] += num;\n        this->line[right] -= num;\n\
    \    }\n\n    void build() {\n        for (int i = 1; i < (int) line.size(); ++i)\
    \ {\n            this->line[i] += this->line[i - 1];\n        }\n    }\n\n   \
    \ T access(const int i) {\n        return this->line[i];\n    }\n};\n"
  code: "#include <vector>\n#include <iostream>\n#include <cassert>\n\ntemplate<typename\
    \ T>\nclass Imos {\npublic:\n    const int n;\n    std::vector<T> line;\n\n  \
    \  Imos(int n) : n(n) {\n        this->line.resize(n + 1, 0);\n    }\n\n    //\
    \ [left, right) \u306B +num\n    void add(const int left, const int right, const\
    \ T num) {\n        assert(left < right);\n        this->line[left] += num;\n\
    \        this->line[right] -= num;\n    }\n\n    void build() {\n        for (int\
    \ i = 1; i < (int) line.size(); ++i) {\n            this->line[i] += this->line[i\
    \ - 1];\n        }\n    }\n\n    T access(const int i) {\n        return this->line[i];\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Algorithm/Imos.hpp
  requiredBy: []
  timestamp: '2024-01-20 16:44:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Algorithm/Imos1.test.cpp
documentation_of: library/cpp/Algorithm/Imos.hpp
layout: document
redirect_from:
- /library/library/cpp/Algorithm/Imos.hpp
- /library/library/cpp/Algorithm/Imos.hpp.html
title: library/cpp/Algorithm/Imos.hpp
---
