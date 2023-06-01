---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Math/pow_mod1.test.cpp
    title: test/cpp/Math/pow_mod1.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Math/pow_mod.cpp\"\n// a^n % mod\n// O(log n)\n\
    // mod\u304C\u3067\u304B\u3044\u3068\u304D\u306Foverflow\u306B\u6CE8\u610F\nlong\
    \ long pow_mod(long long a, long long n, long long mod) {\n    long long x = 1,\
    \ y = a % mod;\n    while (n > 0) {\n        if (n % 2 == 1) {\n            x\
    \ = (x * y) % mod;\n        }\n        y = (y * y) % mod;\n        n /= 2;\n \
    \   }\n\n    return int(x % mod);\n}\n"
  code: "// a^n % mod\n// O(log n)\n// mod\u304C\u3067\u304B\u3044\u3068\u304D\u306F\
    overflow\u306B\u6CE8\u610F\nlong long pow_mod(long long a, long long n, long long\
    \ mod) {\n    long long x = 1, y = a % mod;\n    while (n > 0) {\n        if (n\
    \ % 2 == 1) {\n            x = (x * y) % mod;\n        }\n        y = (y * y)\
    \ % mod;\n        n /= 2;\n    }\n\n    return int(x % mod);\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Math/pow_mod.cpp
  requiredBy: []
  timestamp: '2023-05-21 18:45:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Math/pow_mod1.test.cpp
documentation_of: library/cpp/Math/pow_mod.cpp
layout: document
redirect_from:
- /library/library/cpp/Math/pow_mod.cpp
- /library/library/cpp/Math/pow_mod.cpp.html
title: library/cpp/Math/pow_mod.cpp
---
