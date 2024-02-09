---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/cpp/Utility/is_range_overlap1.test.cpp
    title: test/cpp/Utility/is_range_overlap1.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Utility/is_range_overlap.cpp\"\n#include <cassert>\n\
    \n// \u9589\u533A\u9593[l1, r1] \u3068 [l2, r2] \u306B\u91CD\u306A\u308A\u304C\
    \u3042\u308B\u304B\u5224\u5B9A\ntemplate<typename T>\nbool is_range_overlap(T\
    \ l1, T r1, T l2, T r2) {\n    assert(l1 <= r1);\n    assert(l2 <= r2);\n    \n\
    \    // l2 in [l1, r1]\n    if (l1 <= l2 and l2 <= r1) {\n        return true;\n\
    \    }\n    // r2 in [l1, r1]\n    if (l1 <= r2 and r2 <= r1) {\n        return\
    \ true;\n    }\n    // l1 in [l2, r2]\n    if (l2 <= l1 and l1 <= r2) {\n    \
    \    return true;\n    }\n    // r1 in [l2, r2]\n    if (l2 <= r1 and r1 <= r2)\
    \ {\n        return true;\n    }\n    return false;\n}\n"
  code: "#include <cassert>\n\n// \u9589\u533A\u9593[l1, r1] \u3068 [l2, r2] \u306B\
    \u91CD\u306A\u308A\u304C\u3042\u308B\u304B\u5224\u5B9A\ntemplate<typename T>\n\
    bool is_range_overlap(T l1, T r1, T l2, T r2) {\n    assert(l1 <= r1);\n    assert(l2\
    \ <= r2);\n    \n    // l2 in [l1, r1]\n    if (l1 <= l2 and l2 <= r1) {\n   \
    \     return true;\n    }\n    // r2 in [l1, r1]\n    if (l1 <= r2 and r2 <= r1)\
    \ {\n        return true;\n    }\n    // l1 in [l2, r2]\n    if (l2 <= l1 and\
    \ l1 <= r2) {\n        return true;\n    }\n    // r1 in [l2, r2]\n    if (l2\
    \ <= r1 and r1 <= r2) {\n        return true;\n    }\n    return false;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Utility/is_range_overlap.cpp
  requiredBy: []
  timestamp: '2024-02-03 22:21:59+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/cpp/Utility/is_range_overlap1.test.cpp
documentation_of: library/cpp/Utility/is_range_overlap.cpp
layout: document
redirect_from:
- /library/library/cpp/Utility/is_range_overlap.cpp
- /library/library/cpp/Utility/is_range_overlap.cpp.html
title: library/cpp/Utility/is_range_overlap.cpp
---
