---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Compression/run_length_encoding1.test.cpp
    title: test/cpp/Compression/run_length_encoding1.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Compression/run_length_encoding.cpp\"\n#include\
    \ <string>\n#include <vector>\n\nstd::vector<std::pair<char, int>> run_length_encoding(const\
    \ std::string &s) {\n    std::vector<std::pair<char, int>> ans;\n\n    const int\
    \ n = s.size();\n    int num = 1;\n    for (int i = 0; i < n - 1; ++i) {\n   \
    \     if (s[i] == s[i + 1]) {\n            num++;\n        }\n        else {\n\
    \            ans.emplace_back(s[i], num);\n            num = 1;\n        }\n \
    \   }\n    ans.emplace_back(s.back(), num);\n\n    return ans;\n}\n"
  code: "#include <string>\n#include <vector>\n\nstd::vector<std::pair<char, int>>\
    \ run_length_encoding(const std::string &s) {\n    std::vector<std::pair<char,\
    \ int>> ans;\n\n    const int n = s.size();\n    int num = 1;\n    for (int i\
    \ = 0; i < n - 1; ++i) {\n        if (s[i] == s[i + 1]) {\n            num++;\n\
    \        }\n        else {\n            ans.emplace_back(s[i], num);\n       \
    \     num = 1;\n        }\n    }\n    ans.emplace_back(s.back(), num);\n\n   \
    \ return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Compression/run_length_encoding.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:51:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Compression/run_length_encoding1.test.cpp
documentation_of: library/cpp/Compression/run_length_encoding.cpp
layout: document
redirect_from:
- /library/library/cpp/Compression/run_length_encoding.cpp
- /library/library/cpp/Compression/run_length_encoding.cpp.html
title: library/cpp/Compression/run_length_encoding.cpp
---
