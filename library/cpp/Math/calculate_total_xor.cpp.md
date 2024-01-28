---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Math/calculate_total_xor1.test.cpp
    title: test/cpp/Math/calculate_total_xor1.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Math/calculate_total_xor.cpp\"\n// [0, n] \u306E\
    \u7DCF xor \u3092\u6C42\u3081\u308B\nlong long calculate_total_xor(long long n)\
    \ {\n    if (n < 0) {\n        return 0;\n    }\n\n    switch (n % 4) {\n    \
    \    case 0:\n            return n;\n        case 1:\n            return 1;\n\
    \        case 2:\n            return n + 1;\n        case 3:\n            return\
    \ 0;\n    }\n\n    // \u3053\u3053\u306B\u306F\u3053\u306A\u3044\n    return -1;\n\
    }\n"
  code: "// [0, n] \u306E\u7DCF xor \u3092\u6C42\u3081\u308B\nlong long calculate_total_xor(long\
    \ long n) {\n    if (n < 0) {\n        return 0;\n    }\n\n    switch (n % 4)\
    \ {\n        case 0:\n            return n;\n        case 1:\n            return\
    \ 1;\n        case 2:\n            return n + 1;\n        case 3:\n          \
    \  return 0;\n    }\n\n    // \u3053\u3053\u306B\u306F\u3053\u306A\u3044\n   \
    \ return -1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Math/calculate_total_xor.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:45:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Math/calculate_total_xor1.test.cpp
documentation_of: library/cpp/Math/calculate_total_xor.cpp
layout: document
redirect_from:
- /library/library/cpp/Math/calculate_total_xor.cpp
- /library/library/cpp/Math/calculate_total_xor.cpp.html
title: library/cpp/Math/calculate_total_xor.cpp
---
