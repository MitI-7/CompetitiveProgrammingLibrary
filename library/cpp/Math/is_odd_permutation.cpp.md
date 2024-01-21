---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/cpp/Math/is_odd_permutation1.test.cpp
    title: test/cpp/Math/is_odd_permutation1.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Math/is_odd_permutation.cpp\"\n#include <vector>\n\
    \n// \u5076\u7F6E\u63DB\u304B\u5947\u7F6E\u63DB\u304B\u5224\u5B9A\u3059\u308B\n\
    // A \u306F 0 \u304B\u3089 N - 1 \u306E\u9806\u5217\u3067\u3042\u308B\u3053\u3068\
    \n// O(N)\ntemplate<typename T>\nbool is_odd_permutation(std::vector<T> &A) {\n\
    \    const int N = A.size();\n    int num_cycle = 0;\n    std::vector<bool> used(N);\n\
    \    for (int u = 0; u < N; ++u) {\n        if (used[u]) {\n            continue;\n\
    \        }\n        int v = u;\n        while (not used[v]) {\n            used[v]\
    \ = true;\n            v = A[v];\n        }\n        num_cycle++;\n    }\n\n \
    \   return num_cycle % 2;\n}\n"
  code: "#include <vector>\n\n// \u5076\u7F6E\u63DB\u304B\u5947\u7F6E\u63DB\u304B\u5224\
    \u5B9A\u3059\u308B\n// A \u306F 0 \u304B\u3089 N - 1 \u306E\u9806\u5217\u3067\u3042\
    \u308B\u3053\u3068\n// O(N)\ntemplate<typename T>\nbool is_odd_permutation(std::vector<T>\
    \ &A) {\n    const int N = A.size();\n    int num_cycle = 0;\n    std::vector<bool>\
    \ used(N);\n    for (int u = 0; u < N; ++u) {\n        if (used[u]) {\n      \
    \      continue;\n        }\n        int v = u;\n        while (not used[v]) {\n\
    \            used[v] = true;\n            v = A[v];\n        }\n        num_cycle++;\n\
    \    }\n\n    return num_cycle % 2;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Math/is_odd_permutation.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:47:19+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/cpp/Math/is_odd_permutation1.test.cpp
documentation_of: library/cpp/Math/is_odd_permutation.cpp
layout: document
redirect_from:
- /library/library/cpp/Math/is_odd_permutation.cpp
- /library/library/cpp/Math/is_odd_permutation.cpp.html
title: library/cpp/Math/is_odd_permutation.cpp
---
