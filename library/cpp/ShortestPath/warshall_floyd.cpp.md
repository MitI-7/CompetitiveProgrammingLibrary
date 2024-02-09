---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/ShortestPath/warshall_floyd1.test.cpp
    title: test/cpp/ShortestPath/warshall_floyd1.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/ShortestPath/warshall_floyd.cpp\"\n#include\
    \ <limits>\n#include <vector>\n\n/**\n * \u5168\u30CE\u30FC\u30C9\u9593\u306E\u6700\
    \u77ED\u8DDD\u96E2\u3092\u3082\u3068\u3081\u308B\n * matrix[i][j] \u306B\u306F\
    \u8FBA (i,j) \u306E\u30B3\u30B9\u30C8(\u8FBA\u304C\u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408\u306F inf)\n * \u8CA0\u306E\u9589\u8DEF\u304C\u3042\u308B\u5834\u5408\
    \u306F\u7A7A\u3092\u8FD4\u3059\n * O(|V|^3)\n */\ntemplate<typename T>\nstd::vector<std::vector<T>>\n\
    warshall_floyd(std::vector<std::vector<T>> matrix, const T inf = std::numeric_limits<T>::max())\
    \ {\n    const int num_node = (int) matrix.size();\n\n    // \u81EA\u5206\u306E\
    \u8DDD\u96E2\u306F0\n    for (int i = 0; i < num_node; ++i) {\n        matrix[i][i]\
    \ = 0;\n    }\n\n    // m \u307E\u3067\u8003\u616E\u3057\u305F\u3068\u304D\u306E\
    \u6700\u77ED\u8DEF\u304C\u5165\u308B\n    for (int m = 0; m < num_node; ++m) {\n\
    \        for (int s = 0; s < num_node; ++s) {\n            for (int e = 0; e <\
    \ num_node; ++e) {\n                // s -> m -> e\n                if (matrix[s][m]\
    \ != inf and matrix[m][e] != inf) {\n                    if (matrix[s][e] > matrix[s][m]\
    \ + matrix[m][e]) {\n                        matrix[s][e] = matrix[s][m] + matrix[m][e];\n\
    \                    }\n                }\n            }\n        }\n    }\n\n\
    \    // \u8CA0\u9589\u8DEF\u30C1\u30A7\u30C3\u30AF\n    for (int u = 0; u < num_node;\
    \ ++u) {\n        if (matrix[u][u] < 0) {\n            return {};\n        }\n\
    \    }\n\n    return matrix;\n}\n"
  code: "#include <limits>\n#include <vector>\n\n/**\n * \u5168\u30CE\u30FC\u30C9\u9593\
    \u306E\u6700\u77ED\u8DDD\u96E2\u3092\u3082\u3068\u3081\u308B\n * matrix[i][j]\
    \ \u306B\u306F\u8FBA (i,j) \u306E\u30B3\u30B9\u30C8(\u8FBA\u304C\u5B58\u5728\u3057\
    \u306A\u3044\u5834\u5408\u306F inf)\n * \u8CA0\u306E\u9589\u8DEF\u304C\u3042\u308B\
    \u5834\u5408\u306F\u7A7A\u3092\u8FD4\u3059\n * O(|V|^3)\n */\ntemplate<typename\
    \ T>\nstd::vector<std::vector<T>>\nwarshall_floyd(std::vector<std::vector<T>>\
    \ matrix, const T inf = std::numeric_limits<T>::max()) {\n    const int num_node\
    \ = (int) matrix.size();\n\n    // \u81EA\u5206\u306E\u8DDD\u96E2\u306F0\n   \
    \ for (int i = 0; i < num_node; ++i) {\n        matrix[i][i] = 0;\n    }\n\n \
    \   // m \u307E\u3067\u8003\u616E\u3057\u305F\u3068\u304D\u306E\u6700\u77ED\u8DEF\
    \u304C\u5165\u308B\n    for (int m = 0; m < num_node; ++m) {\n        for (int\
    \ s = 0; s < num_node; ++s) {\n            for (int e = 0; e < num_node; ++e)\
    \ {\n                // s -> m -> e\n                if (matrix[s][m] != inf and\
    \ matrix[m][e] != inf) {\n                    if (matrix[s][e] > matrix[s][m]\
    \ + matrix[m][e]) {\n                        matrix[s][e] = matrix[s][m] + matrix[m][e];\n\
    \                    }\n                }\n            }\n        }\n    }\n\n\
    \    // \u8CA0\u9589\u8DEF\u30C1\u30A7\u30C3\u30AF\n    for (int u = 0; u < num_node;\
    \ ++u) {\n        if (matrix[u][u] < 0) {\n            return {};\n        }\n\
    \    }\n\n    return matrix;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/ShortestPath/warshall_floyd.cpp
  requiredBy: []
  timestamp: '2024-01-31 14:40:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/ShortestPath/warshall_floyd1.test.cpp
documentation_of: library/cpp/ShortestPath/warshall_floyd.cpp
layout: document
redirect_from:
- /library/library/cpp/ShortestPath/warshall_floyd.cpp
- /library/library/cpp/ShortestPath/warshall_floyd.cpp.html
title: library/cpp/ShortestPath/warshall_floyd.cpp
---
