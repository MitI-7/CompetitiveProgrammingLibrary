---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/ShortestPath/warshall_floyd.cpp
    title: library/cpp/ShortestPath/warshall_floyd.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"test/cpp/ShortestPath/warshall_floyd1.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include <iostream>\n#line 1 \"library/cpp/ShortestPath/warshall_floyd.cpp\"\
    \n#include <limits>\n#include <vector>\n\n/**\n * \u5168\u30CE\u30FC\u30C9\u9593\
    \u306E\u6700\u77ED\u8DDD\u96E2\u3092\u3082\u3068\u3081\u308B\n * matrix[i][j]\u306B\
    \u306F\u8FBAe=(i,j)\u306E\u30B3\u30B9\u30C8(\u8FBA\u304C\u5B58\u5728\u3057\u306A\
    \u3044\u5834\u5408\u306FLINF)\n * \u8CA0\u306E\u9589\u8DEF\u304C\u3042\u308B\u5834\
    \u5408\u306F\u7A7A\u3092\u8FD4\u3059\n * O(|V|^3)\n */\ntemplate<typename T>\n\
    std::vector<std::vector<T>> warshall_floyd(std::vector<std::vector<T>> matrix)\
    \ {\n    const auto infinity = std::numeric_limits<T>::max();\n    const int num_node\
    \ = matrix.size();\n\n    // \u81EA\u5206\u306E\u8DDD\u96E2\u306F0\n    for (int\
    \ i = 0; i < num_node; ++i) {\n        matrix[i][i] = 0;\n    }\n\n    // m \u307E\
    \u3067\u8003\u616E\u3057\u305F\u3068\u304D\u306E\u6700\u77ED\u8DEF\u304C\u5165\
    \u308B\n    for (int m = 0; m < num_node; ++m) {\n        for (int s = 0; s <\
    \ num_node; ++s) {\n            for (int e = 0; e < num_node; ++e) {\n       \
    \         // s \u304B\u3089 e \u3078 m \u3092\u7D4C\u7531\u3057\u3066\u5230\u9054\
    \u53EF\u80FD\n                if (matrix[s][m] != infinity and matrix[m][e] !=\
    \ infinity) {\n                    if (matrix[s][e] > matrix[s][m] + matrix[m][e])\
    \ {\n                        matrix[s][e] = matrix[s][m] + matrix[m][e];\n   \
    \                 }\n                }\n            }\n        }\n    }\n\n  \
    \  // \u8CA0\u9589\u8DEF\u30C1\u30A7\u30C3\u30AF\n    for (int u = 0; u < num_node;\
    \ ++u) {\n        if (matrix[u][u] < 0) {\n            return {};\n        }\n\
    \    }\n\n    return matrix;\n}\n#line 5 \"test/cpp/ShortestPath/warshall_floyd1.test.cpp\"\
    \n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int V, E;\n    cin >> V >> E;\n\n    const auto inf = std::numeric_limits<long\
    \ long>::max();\n\n    vector<vector<long long>> matrix(V, vector<long long>(V,\
    \ inf));\n    for (int i = 0; i < E; ++i) {\n        int S, T, D;\n        cin\
    \ >> S >> T >> D;\n        matrix[S][T] = D;\n    }\n\n    auto ans = warshall_floyd(matrix);\n\
    \n    if (ans.empty()) {\n        cout << \"NEGATIVE CYCLE\" << endl;\n    } else\
    \ {\n        for (int i = 0; i < V; ++i) {\n            for (int j = 0; j < V;\
    \ ++j) {\n                if (j != 0) {\n                    cout << \" \";\n\
    \                }\n\n                if (ans[i][j] == inf) {\n              \
    \      cout << \"INF\";\n                } else {\n                    cout <<\
    \ ans[i][j];\n                }\n            }\n            cout << endl;\n  \
    \      }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include <iostream>\n#include \"library/cpp/ShortestPath/warshall_floyd.cpp\"\
    \n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int V, E;\n    cin >> V >> E;\n\n    const auto inf = std::numeric_limits<long\
    \ long>::max();\n\n    vector<vector<long long>> matrix(V, vector<long long>(V,\
    \ inf));\n    for (int i = 0; i < E; ++i) {\n        int S, T, D;\n        cin\
    \ >> S >> T >> D;\n        matrix[S][T] = D;\n    }\n\n    auto ans = warshall_floyd(matrix);\n\
    \n    if (ans.empty()) {\n        cout << \"NEGATIVE CYCLE\" << endl;\n    } else\
    \ {\n        for (int i = 0; i < V; ++i) {\n            for (int j = 0; j < V;\
    \ ++j) {\n                if (j != 0) {\n                    cout << \" \";\n\
    \                }\n\n                if (ans[i][j] == inf) {\n              \
    \      cout << \"INF\";\n                } else {\n                    cout <<\
    \ ans[i][j];\n                }\n            }\n            cout << endl;\n  \
    \      }\n    }\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/ShortestPath/warshall_floyd.cpp
  isVerificationFile: true
  path: test/cpp/ShortestPath/warshall_floyd1.test.cpp
  requiredBy: []
  timestamp: '2024-01-28 11:55:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/ShortestPath/warshall_floyd1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/ShortestPath/warshall_floyd1.test.cpp
- /verify/test/cpp/ShortestPath/warshall_floyd1.test.cpp.html
title: test/cpp/ShortestPath/warshall_floyd1.test.cpp
---
