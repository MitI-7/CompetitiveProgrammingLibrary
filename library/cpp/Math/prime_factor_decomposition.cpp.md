---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/cpp/Math/prime_factor_decomposition1.test.cpp
    title: test/cpp/Math/prime_factor_decomposition1.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Math/prime_factor_decomposition.cpp\"\n#include\
    \ <map>\n\n// n\u3092\u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\n// O(n^(1/2))\n\
    // prime_factor_decomposition(12) : {2:2, 3:1}\nstd::map<long long, long long>\
    \ prime_factor_decomposition(long long n) {\n    std::map<long long, long long>\
    \ m;\n    while (n > 1) {\n        bool findFactor = false;\n        for (long\
    \ long i = 2; i * i <= n; ++i) {\n            if (n % i == 0) {\n            \
    \    m[i]++;\n                n /= i;\n                findFactor = true;\n  \
    \              break;\n            }\n        }\n        if (not findFactor) {\n\
    \            m[n]++;\n            break;\n        }\n    }\n    return m;\n}\n"
  code: "#include <map>\n\n// n\u3092\u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\n\
    // O(n^(1/2))\n// prime_factor_decomposition(12) : {2:2, 3:1}\nstd::map<long long,\
    \ long long> prime_factor_decomposition(long long n) {\n    std::map<long long,\
    \ long long> m;\n    while (n > 1) {\n        bool findFactor = false;\n     \
    \   for (long long i = 2; i * i <= n; ++i) {\n            if (n % i == 0) {\n\
    \                m[i]++;\n                n /= i;\n                findFactor\
    \ = true;\n                break;\n            }\n        }\n        if (not findFactor)\
    \ {\n            m[n]++;\n            break;\n        }\n    }\n    return m;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Math/prime_factor_decomposition.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:43:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/cpp/Math/prime_factor_decomposition1.test.cpp
documentation_of: library/cpp/Math/prime_factor_decomposition.cpp
layout: document
redirect_from:
- /library/library/cpp/Math/prime_factor_decomposition.cpp
- /library/library/cpp/Math/prime_factor_decomposition.cpp.html
title: library/cpp/Math/prime_factor_decomposition.cpp
---
