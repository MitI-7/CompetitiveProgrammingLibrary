---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/cpp/Math/inversion_number1.test.cpp
    title: test/cpp/Math/inversion_number1.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Compression/CoordinateCompression.hpp\"\n#include\
    \ <set>\n#include <unordered_map>\n\ntemplate<class T=long long>\nclass CoordinateCompression\
    \ {\nprivate:\n    bool initialized;\n    std::set<T> s;\n\n    int no = 0;\n\
    \    std::unordered_map<T, int> _zip;\n    std::unordered_map<int, T> _unzip;\n\
    public:\n    CoordinateCompression() : initialized(false) {}\n\n    void add(T\
    \ x) {\n        this->s.insert(x);\n    }\n\n    int size() {\n        if (not\
    \ this->initialized) {\n            this->build();\n        }\n        return\
    \ this->no;\n    }\n\n    // \u5143\u306E\u5024 -> \u5727\u7E2E\u3057\u305F\u5024\
    \n    int zip(const T x) {\n        if (not this->initialized) {\n           \
    \ this->build();\n        }\n        return this->_zip[x];\n    }\n\n    // \u5727\
    \u7E2E\u3057\u305F\u5024 -> \u5143\u306E\u5024\n    T unzip(const int i) {\n \
    \       if (not this->initialized) {\n            this->build();\n        }\n\
    \        return this->_unzip[i];\n    }\n\nprivate:\n    void build() {\n    \
    \    this->initialized = true;\n        for (auto x: this->s) {\n            this->_zip[x]\
    \ = this->no;\n            this->_unzip[this->no] = x;\n            this->no++;\n\
    \        }\n    }\n};\n"
  code: "#include <set>\n#include <unordered_map>\n\ntemplate<class T=long long>\n\
    class CoordinateCompression {\nprivate:\n    bool initialized;\n    std::set<T>\
    \ s;\n\n    int no = 0;\n    std::unordered_map<T, int> _zip;\n    std::unordered_map<int,\
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
    \            this->no++;\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Compression/CoordinateCompression.hpp
  requiredBy: []
  timestamp: '2024-01-20 16:50:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/cpp/Math/inversion_number1.test.cpp
documentation_of: library/cpp/Compression/CoordinateCompression.hpp
layout: document
redirect_from:
- /library/library/cpp/Compression/CoordinateCompression.hpp
- /library/library/cpp/Compression/CoordinateCompression.hpp.html
title: library/cpp/Compression/CoordinateCompression.hpp
---
