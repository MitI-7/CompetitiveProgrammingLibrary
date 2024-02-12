---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Graph/Graph.hpp
    title: library/cpp/Graph/Graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Graph/connected_components1.test.cpp
    title: test/cpp/Graph/connected_components1.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/cpp/Graph/Graph.hpp\"\n\n#include <iostream>\n#include\
    \ <unordered_map>\n#include <vector>\n\ntemplate<typename T>\nclass Edge {\npublic:\n\
    \    int from;\n    int to;\n    T w;\n    int no;\n\n    Edge() : from(-1), to(-1),\
    \ w(-1), no(-1) {}\n\n    Edge(int from, int to, T w = 1, int no = -1) : from(from),\
    \ to(to), w(w), no(no) {\n\n    }\n};\n\ntemplate<typename T=int>\nclass Graph\
    \ {\npublic:\n    const int num_nodes;\n    int num_edges;\n    std::vector<std::vector<Edge<T>>>\
    \ graph;\n    std::unordered_map<int, std::pair<int, int>> no_edge;\n\n    Graph(const\
    \ int num_nodes) : num_nodes(num_nodes), num_edges(0) {\n        this->graph.resize(num_nodes);\n\
    \    }\n\n    void add_directed_edge(const int u, const int v, const T w = 1,\
    \ const int no = -1) {\n        this->no_edge[no] = {u, this->graph[u].size()};\n\
    \        this->graph[u].emplace_back(Edge(u, v, w, no));\n        this->num_edges++;\n\
    \    }\n\n    void add_undirected_edge(const int u, const int v, const T w = 1,\
    \ const int no = -1) {\n        this->graph[u].emplace_back(Edge(u, v, w, no));\n\
    \        this->graph[v].emplace_back(Edge(v, u, w, no));\n        this->num_edges\
    \ += 2;\n    }\n\n    Edge<T> &get_edge(const int no) {\n        const auto [u,\
    \ i] = this->no_edge[no];\n        return this->graph[u][i];\n    }\n\n    std::vector<Edge<T>>\
    \ &operator[](const int u) {\n        return this->graph[u];\n    }\n};\n#line\
    \ 2 \"library/cpp/Graph/connected_components.cpp\"\n\n// u \u304B\u3089\u5230\u9054\
    \u3067\u304D\u308B\u30CE\u30FC\u30C9\u3092\u8272 c \u3067\u5857\u308B\ntemplate<typename\
    \ T>\nvoid coloring(const int u, const int c, std::vector<int> &color, Graph<T>\
    \ &graph) {\n    color[u] = c;\n    for (const auto &edge: graph[u]) {\n     \
    \   if (color[edge.to] == -1) {\n            coloring(edge.to, c, color, graph);\n\
    \        }\n    }\n}\n\n// \u7121\u5411\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\
    \u5206\u3054\u3068\u306B\u8272\u3092\u5857\u308B\ntemplate<typename T>\nstd::vector<int>\
    \ connected_components(Graph<T> &graph) {\n    std::vector<int> color(graph.num_nodes,\
    \ -1);\n    int c = 0;\n    for (int u = 0; u < graph.num_nodes; ++u) {\n    \
    \    if (color[u] == -1) {\n            coloring(u, c, color, graph);\n      \
    \      c++;\n        }\n    }\n\n    return color;\n}\n"
  code: "#include \"library/cpp/Graph/Graph.hpp\"\n\n// u \u304B\u3089\u5230\u9054\
    \u3067\u304D\u308B\u30CE\u30FC\u30C9\u3092\u8272 c \u3067\u5857\u308B\ntemplate<typename\
    \ T>\nvoid coloring(const int u, const int c, std::vector<int> &color, Graph<T>\
    \ &graph) {\n    color[u] = c;\n    for (const auto &edge: graph[u]) {\n     \
    \   if (color[edge.to] == -1) {\n            coloring(edge.to, c, color, graph);\n\
    \        }\n    }\n}\n\n// \u7121\u5411\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\
    \u5206\u3054\u3068\u306B\u8272\u3092\u5857\u308B\ntemplate<typename T>\nstd::vector<int>\
    \ connected_components(Graph<T> &graph) {\n    std::vector<int> color(graph.num_nodes,\
    \ -1);\n    int c = 0;\n    for (int u = 0; u < graph.num_nodes; ++u) {\n    \
    \    if (color[u] == -1) {\n            coloring(u, c, color, graph);\n      \
    \      c++;\n        }\n    }\n\n    return color;\n}"
  dependsOn:
  - library/cpp/Graph/Graph.hpp
  isVerificationFile: false
  path: library/cpp/Graph/connected_components.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:47:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Graph/connected_components1.test.cpp
documentation_of: library/cpp/Graph/connected_components.cpp
layout: document
redirect_from:
- /library/library/cpp/Graph/connected_components.cpp
- /library/library/cpp/Graph/connected_components.cpp.html
title: library/cpp/Graph/connected_components.cpp
---
