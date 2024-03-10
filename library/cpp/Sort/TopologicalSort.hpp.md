---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Sort/TopologicalSort1.test.cpp
    title: test/cpp/Sort/TopologicalSort1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Sort/TopologicalSort2.test.cpp
    title: test/cpp/Sort/TopologicalSort2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Sort/TopologicalSort.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n#include <queue>\n\n\nclass TopologicalSort\
    \ {\n    const int num_nodes;                   // \u30CE\u30FC\u30C9\u6570\n\
    \    std::vector<std::vector<int>> graph;   // \u30B0\u30E9\u30D5\n\npublic:\n\
    \    std::vector<int> result; // \u30BD\u30FC\u30C8\u7D50\u679C\uFF08\u7D50\u679C\
    \u304C\u8907\u6570\u3042\u308B\u5834\u5408\u306F\u8F9E\u66F8\u9806\u3067\u6700\
    \u5C0F\u306E\u3082\u306E\uFF09\n\npublic:\n    TopologicalSort(int num_nodes)\
    \ : num_nodes(num_nodes) {\n        this->graph.resize(num_nodes);\n    }\n\n\
    \    // u -> v\u306Edirect edge\u3092\u8FFD\u52A0\n    void add_directed_edge(int\
    \ u, int v) {\n        assert(u != v);\n        this->graph[u].emplace_back(v);\n\
    \    }\n\n    // O(E + V log V)\n    // sort\u304C\u3067\u304D\u305F\u3089true\u3092\
    \u8FD4\u3059\n    bool sort() {\n        // \u3059\u3079\u3066\u306E\u30CE\u30FC\
    \u30C9\u306E\u5165\u6B21\u6570\u3092\u7B97\u51FA\n        std::vector<int> indegree(this->num_nodes);\n\
    \        for (int u = 0; u < this->num_nodes; ++u) {\n            for (int v:\
    \ this->graph[u]) {\n                indegree[v]++;\n            }\n        }\n\
    \n        std::priority_queue<int, std::vector<int>, std::greater<>> que;\n  \
    \      std::vector<bool> used(this->num_nodes);\n        for (int u = 0; u < this->num_nodes;\
    \ ++u) {\n            if (indegree[u] == 0) {\n                que.push(u);\n\
    \                used[u] = true;\n            }\n        }\n\n        while (not\
    \ que.empty()) {\n            const int u = que.top();\n            que.pop();\n\
    \            this->result.emplace_back(u);\n\n            for (int v: this->graph[u])\
    \ {\n                indegree[v]--;\n                if (indegree[v] == 0 and\
    \ not used[v]) {\n                    used[v] = true;\n                    que.push(v);\n\
    \                }\n            }\n        }\n\n        return (int) this->result.size()\
    \ == this->num_nodes;\n    }\n\n    // \u30B0\u30E9\u30D5\u306E\u6709\u5411\u30D1\
    \u30B9\u306E\u3046\u3061\u6700\u9577\u306E\u3082\u306E\u306E\u9577\u3055\n   \
    \ // \u30BD\u30FC\u30C8\u7D50\u679C\u304C\u4E00\u610F\u306A\u3089\u8FD4\u308A\u5024\
    \u306FN - 1\u306B\u306A\u308A\uFF0C\u5143\u306E\u30B0\u30E9\u30D5\u306F\u30CF\u30DF\
    \u30EB\u30C8\u30F3\u8DEF\u3092\u542B\u3080\u30B0\u30E9\u30D5\u3067\u3042\u308B\
    \n    int longest_distance() {\n        int ans = 0;\n        std::vector<int>\
    \ distance(this->num_nodes, 0);\n        for (int u: this->result) {\n       \
    \     for (int v: this->graph[u]) {\n                distance[v] = std::max(distance[v],\
    \ distance[u] + 1);\n                ans = std::max(ans, distance[v]);\n     \
    \       }\n        }\n\n        return ans;\n    }\n};\n"
  code: "#include <algorithm>\n#include <cassert>\n#include <vector>\n#include <queue>\n\
    \n\nclass TopologicalSort {\n    const int num_nodes;                   // \u30CE\
    \u30FC\u30C9\u6570\n    std::vector<std::vector<int>> graph;   // \u30B0\u30E9\
    \u30D5\n\npublic:\n    std::vector<int> result; // \u30BD\u30FC\u30C8\u7D50\u679C\
    \uFF08\u7D50\u679C\u304C\u8907\u6570\u3042\u308B\u5834\u5408\u306F\u8F9E\u66F8\
    \u9806\u3067\u6700\u5C0F\u306E\u3082\u306E\uFF09\n\npublic:\n    TopologicalSort(int\
    \ num_nodes) : num_nodes(num_nodes) {\n        this->graph.resize(num_nodes);\n\
    \    }\n\n    // u -> v\u306Edirect edge\u3092\u8FFD\u52A0\n    void add_directed_edge(int\
    \ u, int v) {\n        assert(u != v);\n        this->graph[u].emplace_back(v);\n\
    \    }\n\n    // O(E + V log V)\n    // sort\u304C\u3067\u304D\u305F\u3089true\u3092\
    \u8FD4\u3059\n    bool sort() {\n        // \u3059\u3079\u3066\u306E\u30CE\u30FC\
    \u30C9\u306E\u5165\u6B21\u6570\u3092\u7B97\u51FA\n        std::vector<int> indegree(this->num_nodes);\n\
    \        for (int u = 0; u < this->num_nodes; ++u) {\n            for (int v:\
    \ this->graph[u]) {\n                indegree[v]++;\n            }\n        }\n\
    \n        std::priority_queue<int, std::vector<int>, std::greater<>> que;\n  \
    \      std::vector<bool> used(this->num_nodes);\n        for (int u = 0; u < this->num_nodes;\
    \ ++u) {\n            if (indegree[u] == 0) {\n                que.push(u);\n\
    \                used[u] = true;\n            }\n        }\n\n        while (not\
    \ que.empty()) {\n            const int u = que.top();\n            que.pop();\n\
    \            this->result.emplace_back(u);\n\n            for (int v: this->graph[u])\
    \ {\n                indegree[v]--;\n                if (indegree[v] == 0 and\
    \ not used[v]) {\n                    used[v] = true;\n                    que.push(v);\n\
    \                }\n            }\n        }\n\n        return (int) this->result.size()\
    \ == this->num_nodes;\n    }\n\n    // \u30B0\u30E9\u30D5\u306E\u6709\u5411\u30D1\
    \u30B9\u306E\u3046\u3061\u6700\u9577\u306E\u3082\u306E\u306E\u9577\u3055\n   \
    \ // \u30BD\u30FC\u30C8\u7D50\u679C\u304C\u4E00\u610F\u306A\u3089\u8FD4\u308A\u5024\
    \u306FN - 1\u306B\u306A\u308A\uFF0C\u5143\u306E\u30B0\u30E9\u30D5\u306F\u30CF\u30DF\
    \u30EB\u30C8\u30F3\u8DEF\u3092\u542B\u3080\u30B0\u30E9\u30D5\u3067\u3042\u308B\
    \n    int longest_distance() {\n        int ans = 0;\n        std::vector<int>\
    \ distance(this->num_nodes, 0);\n        for (int u: this->result) {\n       \
    \     for (int v: this->graph[u]) {\n                distance[v] = std::max(distance[v],\
    \ distance[u] + 1);\n                ans = std::max(ans, distance[v]);\n     \
    \       }\n        }\n\n        return ans;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Sort/TopologicalSort.hpp
  requiredBy: []
  timestamp: '2024-01-20 16:49:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Sort/TopologicalSort1.test.cpp
  - test/cpp/Sort/TopologicalSort2.test.cpp
documentation_of: library/cpp/Sort/TopologicalSort.hpp
layout: document
redirect_from:
- /library/library/cpp/Sort/TopologicalSort.hpp
- /library/library/cpp/Sort/TopologicalSort.hpp.html
title: library/cpp/Sort/TopologicalSort.hpp
---
