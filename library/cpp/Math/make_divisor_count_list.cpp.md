---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Math/make_divisor_count_list1.test.cpp
    title: test/cpp/Math/make_divisor_count_list1.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Math/make_divisor_count_list.cpp\"\n#include\
    \ <vector>\n\n// [1, n]\u306E\u5404\u5024\u306B\u3064\u3044\u3066\u7D04\u6570\u306E\
    \u500B\u6570\u3092\u683C\u7D0D\u3057\u305F\u914D\u5217\u3092\u4F5C\u6210\n// O(n\
    \ log n)\nstd::vector<int> make_divisor_count_list(const int n) {\n    std::vector<int>\
    \ divisor_count_list(n + 1);\n    for (int d = 1; d <= n; ++d) {\n        for\
    \ (long long i = d; i <= n; i += d) {\n            divisor_count_list[i]++;\n\
    \        }\n    }\n    return divisor_count_list;\n}\n"
  code: "#include <vector>\n\n// [1, n]\u306E\u5404\u5024\u306B\u3064\u3044\u3066\u7D04\
    \u6570\u306E\u500B\u6570\u3092\u683C\u7D0D\u3057\u305F\u914D\u5217\u3092\u4F5C\
    \u6210\n// O(n log n)\nstd::vector<int> make_divisor_count_list(const int n) {\n\
    \    std::vector<int> divisor_count_list(n + 1);\n    for (int d = 1; d <= n;\
    \ ++d) {\n        for (long long i = d; i <= n; i += d) {\n            divisor_count_list[i]++;\n\
    \        }\n    }\n    return divisor_count_list;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Math/make_divisor_count_list.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:49:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Math/make_divisor_count_list1.test.cpp
documentation_of: library/cpp/Math/make_divisor_count_list.cpp
layout: document
redirect_from:
- /library/library/cpp/Math/make_divisor_count_list.cpp
- /library/library/cpp/Math/make_divisor_count_list.cpp.html
title: library/cpp/Math/make_divisor_count_list.cpp
---
