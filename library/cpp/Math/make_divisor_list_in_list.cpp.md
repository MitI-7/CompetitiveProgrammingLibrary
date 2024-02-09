---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Math/make_divisor_list_in_list1.test.cpp
    title: test/cpp/Math/make_divisor_list_in_list1.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Math/make_divisor_list_in_list.cpp\"\n#include\
    \ <vector>\n\n// \u914D\u5217 v \u306E\u8981\u7D20\u306E\u7D04\u6570\u3092\u5217\
    \u6319\n// O(maxi log maxi)\nstd::vector<int> make_divisor_list_in_list(const\
    \ std::vector<int> &v, const int maxi) {\n    if (v.empty()) {\n        return\
    \ {};\n    }\n\n    std::vector<bool> used(maxi + 1);\n    for (const auto a:\
    \ v) {\n        used[a] = true;\n    }\n\n    std::vector<int> divisor_list =\
    \ {1};\n    for (int i = 2; i <= maxi; ++i) {\n        bool is_divisor = false;\n\
    \        for (int j = i; j <= maxi; j += i) {\n            if (used[j]) {\n  \
    \              is_divisor = true;\n                break;\n            }\n   \
    \     }\n        if (is_divisor) {\n            divisor_list.emplace_back(i);\n\
    \        }\n    }\n\n    return divisor_list;\n}\n"
  code: "#include <vector>\n\n// \u914D\u5217 v \u306E\u8981\u7D20\u306E\u7D04\u6570\
    \u3092\u5217\u6319\n// O(maxi log maxi)\nstd::vector<int> make_divisor_list_in_list(const\
    \ std::vector<int> &v, const int maxi) {\n    if (v.empty()) {\n        return\
    \ {};\n    }\n\n    std::vector<bool> used(maxi + 1);\n    for (const auto a:\
    \ v) {\n        used[a] = true;\n    }\n\n    std::vector<int> divisor_list =\
    \ {1};\n    for (int i = 2; i <= maxi; ++i) {\n        bool is_divisor = false;\n\
    \        for (int j = i; j <= maxi; j += i) {\n            if (used[j]) {\n  \
    \              is_divisor = true;\n                break;\n            }\n   \
    \     }\n        if (is_divisor) {\n            divisor_list.emplace_back(i);\n\
    \        }\n    }\n\n    return divisor_list;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Math/make_divisor_list_in_list.cpp
  requiredBy: []
  timestamp: '2024-02-09 17:06:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Math/make_divisor_list_in_list1.test.cpp
documentation_of: library/cpp/Math/make_divisor_list_in_list.cpp
layout: document
redirect_from:
- /library/library/cpp/Math/make_divisor_list_in_list.cpp
- /library/library/cpp/Math/make_divisor_list_in_list.cpp.html
title: library/cpp/Math/make_divisor_list_in_list.cpp
---
