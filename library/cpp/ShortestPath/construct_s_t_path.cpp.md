---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Graph/Graph.hpp
    title: library/cpp/Graph/Graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/ShortestPath/construct_s_t_path1.test.cpp
    title: test/cpp/ShortestPath/construct_s_t_path1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/ShortestPath/construct_s_t_path2.test.cpp
    title: test/cpp/ShortestPath/construct_s_t_path2.test.cpp
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
    \ 2 \"library/cpp/ShortestPath/construct_s_t_path.cpp\"\n\n// \u7D4C\u8DEF\u5FA9\
    \u5143\n// s-t \u7D4C\u8DEF\u304C\u306A\u3044\u5834\u5408\u306F\u7A7A\u3092\u8FD4\
    \u3059\n// prev: prev[u] = u \u3078\u305F\u3069\u308B\u8FBA\n// O(M)\ntemplate<typename\
    \ T>\nstd::vector<Edge<T>> construct_s_t_path(const int s, const int t, const\
    \ std::vector<Edge<T>> &prev) {\n    std::vector<Edge<T>> path;\n    int now =\
    \ t;\n    while (now != s) {\n        path.emplace_back(prev[now]);\n        now\
    \ = prev[now].from;\n        if (now == -1) {\n            return {};\n      \
    \  }\n    }\n    std::reverse(path.begin(), path.end());\n\n    return path;\n\
    }\n"
  code: "#include \"library/cpp/Graph/Graph.hpp\"\n\n// \u7D4C\u8DEF\u5FA9\u5143\n\
    // s-t \u7D4C\u8DEF\u304C\u306A\u3044\u5834\u5408\u306F\u7A7A\u3092\u8FD4\u3059\
    \n// prev: prev[u] = u \u3078\u305F\u3069\u308B\u8FBA\n// O(M)\ntemplate<typename\
    \ T>\nstd::vector<Edge<T>> construct_s_t_path(const int s, const int t, const\
    \ std::vector<Edge<T>> &prev) {\n    std::vector<Edge<T>> path;\n    int now =\
    \ t;\n    while (now != s) {\n        path.emplace_back(prev[now]);\n        now\
    \ = prev[now].from;\n        if (now == -1) {\n            return {};\n      \
    \  }\n    }\n    std::reverse(path.begin(), path.end());\n\n    return path;\n\
    }"
  dependsOn:
  - library/cpp/Graph/Graph.hpp
  isVerificationFile: false
  path: library/cpp/ShortestPath/construct_s_t_path.cpp
  requiredBy: []
  timestamp: '2024-02-12 19:55:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/ShortestPath/construct_s_t_path1.test.cpp
  - test/cpp/ShortestPath/construct_s_t_path2.test.cpp
documentation_of: library/cpp/ShortestPath/construct_s_t_path.cpp
layout: document
redirect_from:
- /library/library/cpp/ShortestPath/construct_s_t_path.cpp
- /library/library/cpp/ShortestPath/construct_s_t_path.cpp.html
title: library/cpp/ShortestPath/construct_s_t_path.cpp
---
