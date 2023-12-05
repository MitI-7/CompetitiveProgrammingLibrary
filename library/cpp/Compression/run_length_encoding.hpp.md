---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Compression/run_length_encoding.hpp\"\n#include\
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
  path: library/cpp/Compression/run_length_encoding.hpp
  requiredBy: []
  timestamp: '2023-12-05 09:36:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/Compression/run_length_encoding.hpp
layout: document
redirect_from:
- /library/library/cpp/Compression/run_length_encoding.hpp
- /library/library/cpp/Compression/run_length_encoding.hpp.html
title: library/cpp/Compression/run_length_encoding.hpp
---
