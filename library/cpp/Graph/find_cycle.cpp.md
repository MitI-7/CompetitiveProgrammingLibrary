---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Graph/Graph.hpp
    title: library/cpp/Graph/Graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Graph/find_cycle1.test.cpp
    title: test/cpp/Graph/find_cycle1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Graph/find_cycle2.test.cpp
    title: test/cpp/Graph/find_cycle2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/cpp/Graph/Graph.hpp\"\n\n#include <vector>\n#include\
    \ <iostream>\n\ntemplate<typename T>\nclass Edge {\npublic:\n    int from;\n \
    \   int to;\n    T w;\n    int no;\n\n    Edge() : from(-1), to(-1), w(-1), no(-1)\
    \ {}\n\n    Edge(int from, int to, T w = 1, int no = -1) : from(from), to(to),\
    \ w(w), no(no) {\n\n    }\n};\n\ntemplate<typename T=int>\nclass Graph {\npublic:\n\
    \    const int num_nodes;\n    int num_edges;\n    std::vector<std::vector<Edge<T>>>\
    \ graph;\n\n    Graph(const int num_nodes) : num_nodes(num_nodes), num_edges(0)\
    \ {\n        this->graph.resize(num_nodes);\n    }\n\n    void add_directed_edge(const\
    \ int u, const int v, const T w = 1, const int no = -1) {\n        this->graph[u].emplace_back(Edge(u,\
    \ v, w, no));\n        this->num_edges++;\n    }\n\n    void add_undirected_edge(const\
    \ int u, const int v, const T w = 1, const int no = -1) {\n        this->graph[u].emplace_back(Edge(u,\
    \ v, w, no));\n        this->graph[v].emplace_back(Edge(v, u, w, no));\n     \
    \   this->num_edges += 2;\n    }\n\n    std::vector<Edge<T>> &operator[](const\
    \ int u) {\n        return this->graph[u];\n    }\n};\n#line 2 \"library/cpp/Graph/find_cycle.cpp\"\
    \n\ntemplate<typename T>\nbool find_cycle_dfs(const int u, const Edge <T> &prev,\
    \ std::vector<int> &state, std::vector <Edge<T>> &edges, const Graph <T> &graph)\
    \ {\n    state[u] = 1;\n    for (const auto e: graph.graph[u]) {\n        if (e.no\
    \ == prev.no) {\n            continue;\n        }\n\n        // \u63A2\u7D22\u6E08\
    \u307F\n        if (state[e.to] == 2) {\n            break;\n        }\n\n   \
    \     edges.emplace_back(e);\n        // find cycle\n        if (state[e.to] ==\
    \ 1 or find_cycle_dfs(e.to, e, state, edges, graph)) {\n            return true;\n\
    \        }\n        edges.pop_back();\n    }\n\n    state[u] = 2;\n    return\
    \ false;\n}\n\n// \u6709\u52B9/\u7121\u5411\u30B0\u30E9\u30D5\u306E\u30B5\u30A4\
    \u30AF\u30EB\u3092\u3072\u3068\u3064\u898B\u3064\u3051\u308B\n// \u5358\u7D14\u30B0\
    \u30E9\u30D5\u3067\u306A\u304F\u3066\u3082\u3044\u3044\n// O(N + M)\n// \u8FBA\
    \u756A\u53F7\u3092\u3044\u308C\u3066\u304A\u304F\u3053\u3068\ntemplate<typename\
    \ T>\nstd::vector <Edge<T>> find_cycle(const Graph <T> &graph) {\n    std::vector\
    \ <Edge<T>> edges;\n    std::vector<int> state(graph.num_nodes, 0);   // 0: \u672A\
    \u63A2\u7D22\uFF0C 1: \u63A2\u7D22\u4E2D\uFF0C2: \u63A2\u7D22\u6E08\u307F\n\n\
    \    // u \u3092\u59CB\u70B9\u3068\u3057\uFF0C\u9589\u8DEF\u3092\u63A2\u7D22\n\
    \    std::vector <Edge<T>> cycle;\n    for (int u = 0; u < graph.num_nodes; ++u)\
    \ {\n        if (state[u] != 0) {\n            continue;\n        }\n        if\
    \ (find_cycle_dfs(u, Edge(-1, -1, 0, -1), state, edges, graph)) {\n          \
    \  auto cycle_start = edges.back().to;\n            bool in_cycle = false;\n \
    \           for (auto e: edges) {\n                // cycle \u306E\u958B\u59CB\
    \u30CE\u30FC\u30C9\u3092\u898B\u3064\u3051\u305F\n                if (e.from ==\
    \ cycle_start) {\n                    in_cycle = true;\n                }\n  \
    \              if (in_cycle) {\n                    cycle.emplace_back(e);\n \
    \               }\n            }\n            break;\n        }\n    }\n\n   \
    \ return cycle;\n}\n"
  code: "#include \"library/cpp/Graph/Graph.hpp\"\n\ntemplate<typename T>\nbool find_cycle_dfs(const\
    \ int u, const Edge <T> &prev, std::vector<int> &state, std::vector <Edge<T>>\
    \ &edges, const Graph <T> &graph) {\n    state[u] = 1;\n    for (const auto e:\
    \ graph.graph[u]) {\n        if (e.no == prev.no) {\n            continue;\n \
    \       }\n\n        // \u63A2\u7D22\u6E08\u307F\n        if (state[e.to] == 2)\
    \ {\n            break;\n        }\n\n        edges.emplace_back(e);\n       \
    \ // find cycle\n        if (state[e.to] == 1 or find_cycle_dfs(e.to, e, state,\
    \ edges, graph)) {\n            return true;\n        }\n        edges.pop_back();\n\
    \    }\n\n    state[u] = 2;\n    return false;\n}\n\n// \u6709\u52B9/\u7121\u5411\
    \u30B0\u30E9\u30D5\u306E\u30B5\u30A4\u30AF\u30EB\u3092\u3072\u3068\u3064\u898B\
    \u3064\u3051\u308B\n// \u5358\u7D14\u30B0\u30E9\u30D5\u3067\u306A\u304F\u3066\u3082\
    \u3044\u3044\n// O(N + M)\n// \u8FBA\u756A\u53F7\u3092\u3044\u308C\u3066\u304A\
    \u304F\u3053\u3068\ntemplate<typename T>\nstd::vector <Edge<T>> find_cycle(const\
    \ Graph <T> &graph) {\n    std::vector <Edge<T>> edges;\n    std::vector<int>\
    \ state(graph.num_nodes, 0);   // 0: \u672A\u63A2\u7D22\uFF0C 1: \u63A2\u7D22\u4E2D\
    \uFF0C2: \u63A2\u7D22\u6E08\u307F\n\n    // u \u3092\u59CB\u70B9\u3068\u3057\uFF0C\
    \u9589\u8DEF\u3092\u63A2\u7D22\n    std::vector <Edge<T>> cycle;\n    for (int\
    \ u = 0; u < graph.num_nodes; ++u) {\n        if (state[u] != 0) {\n         \
    \   continue;\n        }\n        if (find_cycle_dfs(u, Edge(-1, -1, 0, -1), state,\
    \ edges, graph)) {\n            auto cycle_start = edges.back().to;\n        \
    \    bool in_cycle = false;\n            for (auto e: edges) {\n             \
    \   // cycle \u306E\u958B\u59CB\u30CE\u30FC\u30C9\u3092\u898B\u3064\u3051\u305F\
    \n                if (e.from == cycle_start) {\n                    in_cycle =\
    \ true;\n                }\n                if (in_cycle) {\n                \
    \    cycle.emplace_back(e);\n                }\n            }\n            break;\n\
    \        }\n    }\n\n    return cycle;\n}"
  dependsOn:
  - library/cpp/Graph/Graph.hpp
  isVerificationFile: false
  path: library/cpp/Graph/find_cycle.cpp
  requiredBy: []
  timestamp: '2023-05-15 18:45:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Graph/find_cycle1.test.cpp
  - test/cpp/Graph/find_cycle2.test.cpp
documentation_of: library/cpp/Graph/find_cycle.cpp
layout: document
redirect_from:
- /library/library/cpp/Graph/find_cycle.cpp
- /library/library/cpp/Graph/find_cycle.cpp.html
title: library/cpp/Graph/find_cycle.cpp
---
