---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Graph/Graph.hpp
    title: library/cpp/Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/Graph/dijkstra.cpp
    title: library/cpp/Graph/dijkstra.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/cpp/Graph/dijkstra1.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/shortest_path\"\n\n#include <iostream>\n#line\
    \ 1 \"library/cpp/Graph/dijkstra.cpp\"\n#include <functional>\n#include <vector>\n\
    #include <queue>\n#include <limits>\n#line 2 \"library/cpp/Graph/Graph.hpp\"\n\
    \ntemplate<typename T>\nclass Edge {\npublic:\n    int from;\n    int to;\n  \
    \  T w;\n    int no;\n\n    Edge() : from(-1), to(-1), w(-1), no(-1) {}\n\n  \
    \  Edge(int from, int to, T w = 1, int no = -1) : from(from), to(to), w(w), no(no)\
    \ {\n\n    }\n};\n\ntemplate<typename T=int>\nclass Graph {\npublic:\n    const\
    \ int num_nodes;\n    int num_edges;\n    std::vector<std::vector<Edge<T>>> graph;\n\
    \n    Graph(const int num_nodes) : num_nodes(num_nodes), num_edges(0) {\n    \
    \    this->graph.resize(num_nodes);\n    }\n\n    void add_directed_edge(const\
    \ int u, const int v, const T w = 1, const int no = -1) {\n        this->graph[u].emplace_back(Edge(u,\
    \ v, w, no));\n        this->num_edges++;\n    }\n\n    void add_undirected_edge(const\
    \ int u, const int v, const T w = 1, const int no = -1) {\n        this->graph[u].emplace_back(Edge(u,\
    \ v, w, no));\n        this->graph[v].emplace_back(Edge(v, u, w, no));\n     \
    \   this->num_edges += 2;\n    }\n\n    std::vector<Edge<T>> &operator[](const\
    \ int u) {\n        return this->graph[u];\n    }\n};\n#line 6 \"library/cpp/Graph/dijkstra.cpp\"\
    \n\n/**\n * s \u304B\u3089\u3059\u3079\u3066\u306E\u9802\u70B9\u3078\u306E\u6700\
    \u77ED\u8DDD\u96E2\u3068\uFF0C\u5404\u9802\u70B9\u306B\u63A5\u7D9A\u3059\u308B\
    \u6700\u77ED\u8DDD\u96E2\u3068\u306A\u308B\u8FBA\u3092\u6C42\u3081\u308B\n * O(|E|\
    \ log |V|)\n * \u5230\u9054\u3067\u304D\u306A\u3044\u5834\u5408\u306F T \u306E\
    \u6700\u5927\u5024\u3092\u683C\u7D0D\u3059\u308B\n * \u8CA0\u8FBA\u306F\u306A\u3044\
    \u3082\u306E\u3068\u3059\u308B\n */\ntemplate<typename T>\nstd::pair<std::vector<T>,\
    \ std::vector<Edge<T>>> dijkstra(const int s, const Graph<T> &graph) {\n\n   \
    \ //[(\u6700\u77ED\u8DDD\u96E2, node\u756A\u53F7)]\u306Eque(\u8DDD\u96E2\u304C\
    \u8FD1\u3044\u9806\u306B\u3068\u308A\u3060\u3059)\n    std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>, std::greater<>> que;\n    que.push({0,\
    \ s});\n\n    std::vector<Edge<T>> prev_edge(graph.num_nodes);       // \u7D4C\
    \u8DEF\u5FA9\u5143\u7528\n    std::vector<bool> seen(graph.num_nodes);\n\n   \
    \ std::vector<T> distance(graph.num_nodes, std::numeric_limits<T>::max());   //\
    \ start\u304B\u3089\u306E\u8DDD\u96E2\n    distance[s] = 0;\n\n    while (not\
    \ que.empty()) {\n        const auto [now_dist, u] = que.top();\n        que.pop();\n\
    \        if (seen[u]) {\n            continue;\n        }\n        seen[u] = true;\n\
    \n        for (auto edge: graph.graph[u]) {\n            const auto new_dist =\
    \ now_dist + edge.w;\n            if (new_dist < distance[edge.to]) {\n      \
    \          prev_edge[edge.to] = edge;\n                distance[edge.to] = new_dist;\n\
    \                que.push({new_dist, edge.to});\n            }\n        }\n  \
    \  }\n\n    return {distance, prev_edge};\n}\n\n// \u7D4C\u8DEF\u5FA9\u5143\n\
    // O(M)\ntemplate<typename T>\nstd::vector<Edge<T>> get_path(const int s, const\
    \ int t, const std::vector<Edge<T>> &prev) {\n    int now = t;\n    std::vector<Edge<long\
    \ long>> path;\n    while (now != s) {\n        path.emplace_back(prev[now]);\n\
    \        now = prev[now].from;\n    }\n    std::reverse(path.begin(), path.end());\n\
    \n    return path;\n}\n#line 5 \"test/cpp/Graph/dijkstra1.test.cpp\"\n\nusing\
    \ namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, M, S, T;\n    cin >> N >> M >> S >> T;\n\n    Graph<long long> graph(N);\n\
    \    for (int i = 0; i < M; ++i) {\n        int A, B;\n        long long C;\n\
    \        cin >> A >> B >> C;\n        graph.add_directed_edge(A, B, C, i);\n \
    \   }\n\n    auto [distance, prev] = dijkstra(S, graph);\n\n    if (distance[T]\
    \ == std::numeric_limits<long long>::max()) {\n        cout << -1 << endl;\n \
    \       return 0;\n    }\n\n    auto path = get_path(S, T, prev);\n\n    cout\
    \ << distance[T] << \" \" << path.size() << endl;\n    for (const auto e: path)\
    \ {\n        cout << e.from << \" \" << e.to << endl;\n    }\n\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ <iostream>\n#include \"library/cpp/Graph/dijkstra.cpp\"\n\nusing namespace std;\n\
    \nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n  \
    \  int N, M, S, T;\n    cin >> N >> M >> S >> T;\n\n    Graph<long long> graph(N);\n\
    \    for (int i = 0; i < M; ++i) {\n        int A, B;\n        long long C;\n\
    \        cin >> A >> B >> C;\n        graph.add_directed_edge(A, B, C, i);\n \
    \   }\n\n    auto [distance, prev] = dijkstra(S, graph);\n\n    if (distance[T]\
    \ == std::numeric_limits<long long>::max()) {\n        cout << -1 << endl;\n \
    \       return 0;\n    }\n\n    auto path = get_path(S, T, prev);\n\n    cout\
    \ << distance[T] << \" \" << path.size() << endl;\n    for (const auto e: path)\
    \ {\n        cout << e.from << \" \" << e.to << endl;\n    }\n\n    return 0;\n\
    }"
  dependsOn:
  - library/cpp/Graph/dijkstra.cpp
  - library/cpp/Graph/Graph.hpp
  isVerificationFile: true
  path: test/cpp/Graph/dijkstra1.test.cpp
  requiredBy: []
  timestamp: '2023-05-15 18:47:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Graph/dijkstra1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Graph/dijkstra1.test.cpp
- /verify/test/cpp/Graph/dijkstra1.test.cpp.html
title: test/cpp/Graph/dijkstra1.test.cpp
---
