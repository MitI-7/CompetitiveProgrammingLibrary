---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Graph/Graph.hpp
    title: library/cpp/Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/ShortestPath/dijkstra.cpp
    title: library/cpp/ShortestPath/dijkstra.cpp
  - icon: ':warning:'
    path: library/cpp/ShortestPath/make_shortest_path_tree.cpp
    title: library/cpp/ShortestPath/make_shortest_path_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc252/tasks/abc252_e
  bundledCode: "#line 1 \"test/cpp/ShortestPath/make_shortest_path_tree1.dummy.cpp\"\
    \n#define PROBLEM \"https://atcoder.jp/contests/abc252/tasks/abc252_e\"\n\n#include\
    \ <iostream>\n#line 2 \"library/cpp/Graph/Graph.hpp\"\n\n#line 4 \"library/cpp/Graph/Graph.hpp\"\
    \n#include <unordered_map>\n#include <vector>\n\ntemplate<typename T>\nclass Edge\
    \ {\npublic:\n    int from;\n    int to;\n    T w;\n    int no;\n\n    Edge()\
    \ : from(-1), to(-1), w(-1), no(-1) {}\n\n    Edge(int from, int to, T w = 1,\
    \ int no = -1) : from(from), to(to), w(w), no(no) {\n\n    }\n};\n\ntemplate<typename\
    \ T=int>\nclass Graph {\npublic:\n    const int num_nodes;\n    int num_edges;\n\
    \    std::vector<std::vector<Edge<T>>> graph;\n    std::unordered_map<int, std::pair<int,\
    \ int>> no_edge;\n\n    Graph(const int num_nodes) : num_nodes(num_nodes), num_edges(0)\
    \ {\n        this->graph.resize(num_nodes);\n    }\n\n    void add_directed_edge(const\
    \ int u, const int v, const T w = 1, const int no = -1) {\n        this->no_edge[no]\
    \ = {u, this->graph[u].size()};\n        this->graph[u].emplace_back(Edge(u, v,\
    \ w, no));\n        this->num_edges++;\n    }\n\n    void add_undirected_edge(const\
    \ int u, const int v, const T w = 1, const int no = -1) {\n        this->graph[u].emplace_back(Edge(u,\
    \ v, w, no));\n        this->graph[v].emplace_back(Edge(v, u, w, no));\n     \
    \   this->num_edges += 2;\n    }\n\n    Edge<T> &get_edge(const int no) {\n  \
    \      const auto [u, i] = this->no_edge[no];\n        return this->graph[u][i];\n\
    \    }\n\n    std::vector<Edge<T>> &operator[](const int u) {\n        return\
    \ this->graph[u];\n    }\n};\n#line 1 \"library/cpp/ShortestPath/dijkstra.cpp\"\
    \n#include <functional>\n#include <limits>\n#include <queue>\n#line 6 \"library/cpp/ShortestPath/dijkstra.cpp\"\
    \n\n/**\n * s \u304B\u3089\u3059\u3079\u3066\u306E\u9802\u70B9\u3078\u306E\u6700\
    \u77ED\u8DDD\u96E2\u3068\uFF0C\u5404\u9802\u70B9\u306B\u63A5\u7D9A\u3059\u308B\
    \u6700\u77ED\u8DDD\u96E2\u3068\u306A\u308B\u8FBA\u3092\u6C42\u3081\u308B\n * O(|E|\
    \ log |V|)\n * \u5230\u9054\u3067\u304D\u306A\u3044\u5834\u5408\u306F infinity\
    \ \u3092\u683C\u7D0D\u3059\u308B\n * \u8CA0\u8FBA\u306F\u306A\u3044\u3082\u306E\
    \u3068\u3059\u308B\n */\ntemplate<typename T>\nstd::pair<std::vector<T>, std::vector<Edge<T>>>\
    \ dijkstra(const int s, const Graph<T> &graph, const T infinity = std::numeric_limits<T>::max()\
    \ / 3) {\n\n    // [(\u6700\u77ED\u8DDD\u96E2, node\u756A\u53F7)]\u306Eque (\u8DDD\
    \u96E2\u304C\u8FD1\u3044\u9806\u306B\u3068\u308A\u3060\u3059)\n    std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>, std::greater<>> que;\n    que.push({0,\
    \ s});\n\n    std::vector<Edge<T>> prev_edge(graph.num_nodes);       // \u7D4C\
    \u8DEF\u5FA9\u5143\u7528\n    std::vector<bool> seen(graph.num_nodes);\n    std::vector<T>\
    \ distance(graph.num_nodes, infinity);   // start\u304B\u3089\u306E\u8DDD\u96E2\
    \n    distance[s] = 0;\n\n    while (not que.empty()) {\n        const auto [now_dist,\
    \ u] = que.top();\n        que.pop();\n        if (seen[u]) {\n            continue;\n\
    \        }\n        seen[u] = true;\n\n        for (auto edge: graph.graph[u])\
    \ {\n            const auto new_dist = now_dist + edge.w;\n            if (new_dist\
    \ < distance[edge.to]) {\n                prev_edge[edge.to] = edge;\n       \
    \         distance[edge.to] = new_dist;\n                que.push({new_dist, edge.to});\n\
    \            }\n        }\n    }\n\n    return {distance, prev_edge};\n}\n#line\
    \ 3 \"library/cpp/ShortestPath/make_shortest_path_tree.cpp\"\n\n// start\u3092\
    \u6839\u3068\u3059\u308B\u6700\u77ED\u8DEF\u6728\u3092\u3064\u304F\u308B\n// \u6700\
    \u77ED\u8DEF\u6728\u306F\u6709\u5411\u6728\u306B\u306A\u308B\u3053\u3068\u306B\
    \u6CE8\u610F\ntemplate<typename T>\nGraph<T> make_shortest_path_tree(const int\
    \ start, Graph<T> &graph) {\n\n    const auto [_, prev] = dijkstra(start, graph);\n\
    \n    Graph<T> shortest_path_tree(graph.num_nodes);\n    for (auto e: prev) {\n\
    \        if (e.no != -1) {\n            shortest_path_tree.add_directed_edge(e.from,\
    \ e.to, e.w, e.no);\n        }\n    }\n\n    return shortest_path_tree;\n}\n#line\
    \ 5 \"test/cpp/ShortestPath/make_shortest_path_tree1.dummy.cpp\"\n\nusing namespace\
    \ std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, M;\n    cin >> N >> M;\n    Graph<long long> graph(N);\n    for (int\
    \ i = 0; i < M; ++i) {\n        int A, B, C;\n        cin >> A >> B >> C;\n  \
    \      A--;\n        B--;\n        graph.add_undirected_edge(A, B, C, i + 1);\n\
    \    }\n\n    auto spt = make_shortest_path_tree(0, graph);\n\n    for (int u\
    \ = 0; u < N; ++u) {\n        for (auto e: spt[u]) {\n            cout << e.no\
    \ << \" \";\n        }\n    }\n    cout << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc252/tasks/abc252_e\"\n\n\
    #include <iostream>\n#include \"library/cpp/ShortestPath/make_shortest_path_tree.cpp\"\
    \n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, M;\n    cin >> N >> M;\n    Graph<long long> graph(N);\n    for (int\
    \ i = 0; i < M; ++i) {\n        int A, B, C;\n        cin >> A >> B >> C;\n  \
    \      A--;\n        B--;\n        graph.add_undirected_edge(A, B, C, i + 1);\n\
    \    }\n\n    auto spt = make_shortest_path_tree(0, graph);\n\n    for (int u\
    \ = 0; u < N; ++u) {\n        for (auto e: spt[u]) {\n            cout << e.no\
    \ << \" \";\n        }\n    }\n    cout << endl;\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/ShortestPath/make_shortest_path_tree.cpp
  - library/cpp/Graph/Graph.hpp
  - library/cpp/ShortestPath/dijkstra.cpp
  isVerificationFile: false
  path: test/cpp/ShortestPath/make_shortest_path_tree1.dummy.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:49:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/cpp/ShortestPath/make_shortest_path_tree1.dummy.cpp
layout: document
redirect_from:
- /library/test/cpp/ShortestPath/make_shortest_path_tree1.dummy.cpp
- /library/test/cpp/ShortestPath/make_shortest_path_tree1.dummy.cpp.html
title: test/cpp/ShortestPath/make_shortest_path_tree1.dummy.cpp
---
