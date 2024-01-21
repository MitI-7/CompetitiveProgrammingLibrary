---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/cpp/Math/make_divisor_list1.test.cpp
    title: test/cpp/Math/make_divisor_list1.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Math/make_divisor_list.cpp\"\n#include <vector>\n\
    #include <algorithm>\n\n// n \u306E\u7D04\u6570\u3092\u5217\u6319\u3059\u308B\n\
    // O(sqrt(n))\n// n <= 10^9 \u3067\u6700\u5927 1344 \u500B\uFF0Cn <= 10^18 \u3067\
    \u6700\u5927 103680 \u500B\u306E\u7D04\u6570\u304C\u3042\u308B\nstd::vector<long\
    \ long> make_divisor_list(long long n) {\n    std::vector<long long> ret;\n  \
    \  for (long long i = 1; i * i <= n; ++i) {\n        if (n % i == 0) {\n     \
    \       ret.emplace_back(i);\n            if (i * i != n) {\n                ret.emplace_back(n\
    \ / i);\n            }\n        }\n    }\n    std::sort(ret.begin(), ret.end());\n\
    \    return ret;\n}\n"
  code: "#include <vector>\n#include <algorithm>\n\n// n \u306E\u7D04\u6570\u3092\u5217\
    \u6319\u3059\u308B\n// O(sqrt(n))\n// n <= 10^9 \u3067\u6700\u5927 1344 \u500B\
    \uFF0Cn <= 10^18 \u3067\u6700\u5927 103680 \u500B\u306E\u7D04\u6570\u304C\u3042\
    \u308B\nstd::vector<long long> make_divisor_list(long long n) {\n    std::vector<long\
    \ long> ret;\n    for (long long i = 1; i * i <= n; ++i) {\n        if (n % i\
    \ == 0) {\n            ret.emplace_back(i);\n            if (i * i != n) {\n \
    \               ret.emplace_back(n / i);\n            }\n        }\n    }\n  \
    \  std::sort(ret.begin(), ret.end());\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Math/make_divisor_list.cpp
  requiredBy: []
  timestamp: '2024-01-21 16:46:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/cpp/Math/make_divisor_list1.test.cpp
documentation_of: library/cpp/Math/make_divisor_list.cpp
layout: document
redirect_from:
- /library/library/cpp/Math/make_divisor_list.cpp
- /library/library/cpp/Math/make_divisor_list.cpp.html
title: library/cpp/Math/make_divisor_list.cpp
---
