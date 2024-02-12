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
  bundledCode: "#line 1 \"library/cpp/Algorithm/Imos.hpp\"\n#include <cassert>\n#include\
    \ <iostream>\n#include <vector>\n\ntemplate<typename T>\nclass Imos {\npublic:\n\
    \    const int n;\n    std::vector<T> line;\n\n    Imos(int n) : n(n) {\n    \
    \    this->line.resize(n + 1, 0);\n    }\n\n    // [left, right) \u306B +x\n \
    \   void add(const int left, const int right, const T x) {\n        if (left ==\
    \ right) {\n            return;\n        }\n        assert(left < right);\n  \
    \      this->line[left] += x;\n        this->line[right] -= x;\n    }\n\n    //\
    \ [left, right) += x\n    // \u52A0\u7B97\u4F4D\u7F6E\u304C n \u4EE5\u4E0A\u306E\
    \u5834\u5408\u306F 0 \u306B\u623B\u3063\u3066\u52A0\u7B97\u3055\u308C\u308B\n\
    \    // O(log n)\n    void add_circle(long long left, long long right, const T\
    \ x) {\n        assert(left < right);\n\n        const long long num_loop = (right\
    \ - left) / this->n;\n        this->add(0, this->n, x * num_loop);\n\n       \
    \ // \u30EB\u30FC\u30D7\u3067\u7D42\u308F\u308A\n        if ((right - left) %\
    \ this->n == 0) {\n            return;\n        }\n\n        left %= this->n;\n\
    \        right %= this->n;\n\n        if (left < right) {\n            this->add(left,\
    \ right, x);\n        } else {\n            this->add(left, this->n, x);\n   \
    \         this->add(0, right, x);\n        }\n    }\n\n    void build() {\n  \
    \      for (int i = 1; i < (int) line.size(); ++i) {\n            this->line[i]\
    \ += this->line[i - 1];\n        }\n    }\n\n    T access(const int i) const {\n\
    \        return this->line[i];\n    }\n\n    void dump() const {\n        for\
    \ (int i = 0; i < this->n; ++i) {\n            if (i != 0) {\n               \
    \ std::cout << \" \";\n            }\n            std::cout << this->access(i);\n\
    \        }\n        std::cout << std::endl;\n    }\n};\n"
  code: "#include <cassert>\n#include <iostream>\n#include <vector>\n\ntemplate<typename\
    \ T>\nclass Imos {\npublic:\n    const int n;\n    std::vector<T> line;\n\n  \
    \  Imos(int n) : n(n) {\n        this->line.resize(n + 1, 0);\n    }\n\n    //\
    \ [left, right) \u306B +x\n    void add(const int left, const int right, const\
    \ T x) {\n        if (left == right) {\n            return;\n        }\n     \
    \   assert(left < right);\n        this->line[left] += x;\n        this->line[right]\
    \ -= x;\n    }\n\n    // [left, right) += x\n    // \u52A0\u7B97\u4F4D\u7F6E\u304C\
    \ n \u4EE5\u4E0A\u306E\u5834\u5408\u306F 0 \u306B\u623B\u3063\u3066\u52A0\u7B97\
    \u3055\u308C\u308B\n    // O(log n)\n    void add_circle(long long left, long\
    \ long right, const T x) {\n        assert(left < right);\n\n        const long\
    \ long num_loop = (right - left) / this->n;\n        this->add(0, this->n, x *\
    \ num_loop);\n\n        // \u30EB\u30FC\u30D7\u3067\u7D42\u308F\u308A\n      \
    \  if ((right - left) % this->n == 0) {\n            return;\n        }\n\n  \
    \      left %= this->n;\n        right %= this->n;\n\n        if (left < right)\
    \ {\n            this->add(left, right, x);\n        } else {\n            this->add(left,\
    \ this->n, x);\n            this->add(0, right, x);\n        }\n    }\n\n    void\
    \ build() {\n        for (int i = 1; i < (int) line.size(); ++i) {\n         \
    \   this->line[i] += this->line[i - 1];\n        }\n    }\n\n    T access(const\
    \ int i) const {\n        return this->line[i];\n    }\n\n    void dump() const\
    \ {\n        for (int i = 0; i < this->n; ++i) {\n            if (i != 0) {\n\
    \                std::cout << \" \";\n            }\n            std::cout <<\
    \ this->access(i);\n        }\n        std::cout << std::endl;\n    }\n};"
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
