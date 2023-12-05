---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Graph/Graph.hpp
    title: library/cpp/Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/Graph/connected_components.cpp
    title: library/cpp/Graph/connected_components.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D&lang=ja
  bundledCode: "#line 1 \"test/cpp/Graph/connected_components1.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D&lang=ja\"\
    \n\n#include <iostream>\n#line 2 \"library/cpp/Graph/Graph.hpp\"\n\n#include <vector>\n\
    #line 5 \"library/cpp/Graph/Graph.hpp\"\n\ntemplate<typename T>\nclass Edge {\n\
    public:\n    int from;\n    int to;\n    T w;\n    int no;\n\n    Edge() : from(-1),\
    \ to(-1), w(-1), no(-1) {}\n\n    Edge(int from, int to, T w = 1, int no = -1)\
    \ : from(from), to(to), w(w), no(no) {\n\n    }\n};\n\ntemplate<typename T=int>\n\
    class Graph {\npublic:\n    const int num_nodes;\n    int num_edges;\n    std::vector<std::vector<Edge<T>>>\
    \ graph;\n\n    Graph(const int num_nodes) : num_nodes(num_nodes), num_edges(0)\
    \ {\n        this->graph.resize(num_nodes);\n    }\n\n    void add_directed_edge(const\
    \ int u, const int v, const T w = 1, const int no = -1) {\n        this->graph[u].emplace_back(Edge(u,\
    \ v, w, no));\n        this->num_edges++;\n    }\n\n    void add_undirected_edge(const\
    \ int u, const int v, const T w = 1, const int no = -1) {\n        this->graph[u].emplace_back(Edge(u,\
    \ v, w, no));\n        this->graph[v].emplace_back(Edge(v, u, w, no));\n     \
    \   this->num_edges += 2;\n    }\n\n    std::vector<Edge<T>> &operator[](const\
    \ int u) {\n        return this->graph[u];\n    }\n};\n\ntemplate<typename T>\n\
    Graph<T> read_unweighted_directed_graph(int num_nodes, int num_edges) {\n    Graph<T>\
    \ graph(num_nodes);\n\n    for (int i = 0; i < num_edges; ++i) {\n        int\
    \ u, v;\n        std::cin >> u >> v;\n        u--;\n        v--;\n        graph.add_directed_edge(u,\
    \ v, 1, i);\n    }\n    return graph;\n}\n\ntemplate<typename T>\nGraph<T> read_unweighted_undirected_graph(int\
    \ num_nodes, int num_edges) {\n    Graph<T> graph(num_nodes);\n\n    for (int\
    \ i = 0; i < num_edges; ++i) {\n        int u, v;\n        std::cin >> u >> v;\n\
    \        u--;\n        v--;\n        graph.add_undirected_edge(u, v, 1, i);\n\
    \    }\n    return graph;\n}\n\ntemplate<typename T>\nGraph<T> read_weighted_directed_graph(int\
    \ num_nodes, int num_edges) {\n    Graph<T> graph(num_nodes);\n\n    for (int\
    \ i = 0; i < num_edges; ++i) {\n        int u, v;\n        T w;\n        std::cin\
    \ >> u >> v >> w;\n        u--;\n        v--;\n        graph.add_directed_edge(u,\
    \ v, w, i);\n    }\n    return graph;\n}\n\ntemplate<typename T>\nGraph<T> read_weighted_undirected_graph(int\
    \ num_nodes, int num_edges) {\n    Graph<T> graph(num_nodes);\n\n    for (int\
    \ i = 0; i < num_edges; ++i) {\n        int u, v;\n        T w;\n        std::cin\
    \ >> u >> v >> w;\n        u--;\n        v--;\n        graph.add_undirected_edge(u,\
    \ v, w, i);\n    }\n    return graph;\n}\n#line 2 \"library/cpp/Graph/connected_components.cpp\"\
    \n\n// u \u304B\u3089\u5230\u9054\u3067\u304D\u308B\u30CE\u30FC\u30C9\u3092\u8272\
    \ c \u3067\u5857\u308B\ntemplate<typename T>\nvoid coloring(const int u, const\
    \ int c, std::vector<int> &color, Graph<T> &graph) {\n    color[u] = c;\n    for\
    \ (const auto &edge: graph[u]) {\n        if (color[edge.to] == -1) {\n      \
    \      coloring(edge.to, c, color, graph);\n        }\n    }\n}\n\n// \u7121\u5411\
    \u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u3054\u3068\u306B\u8272\u3092\
    \u5857\u308B\ntemplate<typename T>\nstd::vector<int> connected_components(Graph<T>\
    \ &graph) {\n    std::vector<int> color(graph.num_nodes, -1);\n    int c = 0;\n\
    \    for (int u = 0; u < graph.num_nodes; ++u) {\n        if (color[u] == -1)\
    \ {\n            coloring(u, c, color, graph);\n            c++;\n        }\n\
    \    }\n\n    return color;\n}\n#line 5 \"test/cpp/Graph/connected_components1.test.cpp\"\
    \n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, M;\n    cin >> N >> M;\n    Graph<int> graph(N);\n    for (int i\
    \ = 0; i < M; ++i) {\n        int U, V;\n        cin >> U >> V;\n        graph.add_undirected_edge(U,\
    \ V, 0, i);\n    }\n\n    auto color = connected_components(graph);\n\n    int\
    \ Q;\n    cin >> Q;\n    for (int i = 0; i < Q; ++i) {\n        int S, T;\n  \
    \      cin >> S >> T;\n        if (color[S] == color[T]) {\n            cout <<\
    \ \"yes\" << endl;\n        }\n        else {\n            cout << \"no\" << endl;\n\
    \        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D&lang=ja\"\
    \n\n#include <iostream>\n#include \"library/cpp/Graph/connected_components.cpp\"\
    \n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, M;\n    cin >> N >> M;\n    Graph<int> graph(N);\n    for (int i\
    \ = 0; i < M; ++i) {\n        int U, V;\n        cin >> U >> V;\n        graph.add_undirected_edge(U,\
    \ V, 0, i);\n    }\n\n    auto color = connected_components(graph);\n\n    int\
    \ Q;\n    cin >> Q;\n    for (int i = 0; i < Q; ++i) {\n        int S, T;\n  \
    \      cin >> S >> T;\n        if (color[S] == color[T]) {\n            cout <<\
    \ \"yes\" << endl;\n        }\n        else {\n            cout << \"no\" << endl;\n\
    \        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Graph/connected_components.cpp
  - library/cpp/Graph/Graph.hpp
  isVerificationFile: true
  path: test/cpp/Graph/connected_components1.test.cpp
  requiredBy: []
  timestamp: '2023-06-09 11:12:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Graph/connected_components1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Graph/connected_components1.test.cpp
- /verify/test/cpp/Graph/connected_components1.test.cpp.html
title: test/cpp/Graph/connected_components1.test.cpp
---
