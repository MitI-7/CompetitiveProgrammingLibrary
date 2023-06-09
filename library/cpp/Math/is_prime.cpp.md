---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Math/is_prime1.test.cpp
    title: test/cpp/Math/is_prime1.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Math/is_prime.cpp\"\n// \u7D20\u6570\u5224\u5B9A\
    \n// O(sqrt(x))\nbool is_prime(int x) {\n    if (x == 2) {\n        return true;\n\
    \    }\n    if (x < 2 || x % 2 == 0) {\n        return false;\n    }\n\n    for\
    \ (int i = 3; i * i <= x; i += 2) {\n        if (x % i == 0) {\n            return\
    \ false;\n        }\n    }\n    return true;\n}\n"
  code: "// \u7D20\u6570\u5224\u5B9A\n// O(sqrt(x))\nbool is_prime(int x) {\n    if\
    \ (x == 2) {\n        return true;\n    }\n    if (x < 2 || x % 2 == 0) {\n  \
    \      return false;\n    }\n\n    for (int i = 3; i * i <= x; i += 2) {\n   \
    \     if (x % i == 0) {\n            return false;\n        }\n    }\n    return\
    \ true;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Math/is_prime.cpp
  requiredBy: []
  timestamp: '2023-06-09 15:07:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Math/is_prime1.test.cpp
documentation_of: library/cpp/Math/is_prime.cpp
layout: document
redirect_from:
- /library/library/cpp/Math/is_prime.cpp
- /library/library/cpp/Math/is_prime.cpp.html
title: library/cpp/Math/is_prime.cpp
---
