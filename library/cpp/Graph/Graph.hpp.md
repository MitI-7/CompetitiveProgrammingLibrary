---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Graph/connected_components.cpp
    title: library/cpp/Graph/connected_components.cpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/Graph/find_cycle.cpp
    title: library/cpp/Graph/find_cycle.cpp
  - icon: ':x:'
    path: library/cpp/ShortestPath/bellman_ford.cpp
    title: library/cpp/ShortestPath/bellman_ford.cpp
  - icon: ':x:'
    path: library/cpp/ShortestPath/dijkstra.cpp
    title: library/cpp/ShortestPath/dijkstra.cpp
  - icon: ':warning:'
    path: library/cpp/ShortestPath/make_shortest_path_tree.cpp
    title: library/cpp/ShortestPath/make_shortest_path_tree.cpp
  - icon: ':warning:'
    path: test/cpp/ShortestPath/make_shortest_path_tree1.dummy.cpp
    title: test/cpp/ShortestPath/make_shortest_path_tree1.dummy.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Graph/connected_components1.test.cpp
    title: test/cpp/Graph/connected_components1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Graph/find_cycle1.test.cpp
    title: test/cpp/Graph/find_cycle1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Graph/find_cycle2.test.cpp
    title: test/cpp/Graph/find_cycle2.test.cpp
  - icon: ':x:'
    path: test/cpp/ShortestPath/bellman_ford1.test.cpp
    title: test/cpp/ShortestPath/bellman_ford1.test.cpp
  - icon: ':x:'
    path: test/cpp/ShortestPath/dijkstra1.test.cpp
    title: test/cpp/ShortestPath/dijkstra1.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ int u) {\n        return this->graph[u];\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <iostream>\n\ntemplate<typename\
    \ T>\nclass Edge {\npublic:\n    int from;\n    int to;\n    T w;\n    int no;\n\
    \n    Edge() : from(-1), to(-1), w(-1), no(-1) {}\n\n    Edge(int from, int to,\
    \ T w = 1, int no = -1) : from(from), to(to), w(w), no(no) {\n\n    }\n};\n\n\
    template<typename T=int>\nclass Graph {\npublic:\n    const int num_nodes;\n \
    \   int num_edges;\n    std::vector<std::vector<Edge<T>>> graph;\n\n    Graph(const\
    \ int num_nodes) : num_nodes(num_nodes), num_edges(0) {\n        this->graph.resize(num_nodes);\n\
    \    }\n\n    void add_directed_edge(const int u, const int v, const T w = 1,\
    \ const int no = -1) {\n        this->graph[u].emplace_back(Edge(u, v, w, no));\n\
    \        this->num_edges++;\n    }\n\n    void add_undirected_edge(const int u,\
    \ const int v, const T w = 1, const int no = -1) {\n        this->graph[u].emplace_back(Edge(u,\
    \ v, w, no));\n        this->graph[v].emplace_back(Edge(v, u, w, no));\n     \
    \   this->num_edges += 2;\n    }\n\n    std::vector<Edge<T>> &operator[](const\
    \ int u) {\n        return this->graph[u];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Graph/Graph.hpp
  requiredBy:
  - test/cpp/ShortestPath/make_shortest_path_tree1.dummy.cpp
  - library/cpp/ShortestPath/make_shortest_path_tree.cpp
  - library/cpp/ShortestPath/bellman_ford.cpp
  - library/cpp/ShortestPath/dijkstra.cpp
  - library/cpp/Graph/connected_components.cpp
  - library/cpp/Graph/find_cycle.cpp
  timestamp: '2023-05-15 18:41:16+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/cpp/ShortestPath/bellman_ford1.test.cpp
  - test/cpp/ShortestPath/dijkstra1.test.cpp
  - test/cpp/Graph/find_cycle1.test.cpp
  - test/cpp/Graph/connected_components1.test.cpp
  - test/cpp/Graph/find_cycle2.test.cpp
documentation_of: library/cpp/Graph/Graph.hpp
layout: document
redirect_from:
- /library/library/cpp/Graph/Graph.hpp
- /library/library/cpp/Graph/Graph.hpp.html
title: library/cpp/Graph/Graph.hpp
---
