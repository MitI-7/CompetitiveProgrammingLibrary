---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/Graph/Graph.hpp
    title: library/cpp/Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/ShortestPath/bellman_ford.cpp
    title: library/cpp/ShortestPath/bellman_ford.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"test/cpp/ShortestPath/bellman_ford1.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include <iostream>\n#line 1 \"library/cpp/ShortestPath/bellman_ford.cpp\"\
    \n#include <vector>\n#include <functional>\n#include <limits>\n#line 2 \"library/cpp/Graph/Graph.hpp\"\
    \n\n#line 5 \"library/cpp/Graph/Graph.hpp\"\n\ntemplate<typename T>\nclass Edge\
    \ {\npublic:\n    int from;\n    int to;\n    T w;\n    int no;\n\n    Edge()\
    \ : from(-1), to(-1), w(-1), no(-1) {}\n\n    Edge(int from, int to, T w = 1,\
    \ int no = -1) : from(from), to(to), w(w), no(no) {\n\n    }\n};\n\ntemplate<typename\
    \ T=int>\nclass Graph {\npublic:\n    const int num_nodes;\n    int num_edges;\n\
    \    std::vector<std::vector<Edge<T>>> graph;\n\n    Graph(const int num_nodes)\
    \ : num_nodes(num_nodes), num_edges(0) {\n        this->graph.resize(num_nodes);\n\
    \    }\n\n    void add_directed_edge(const int u, const int v, const T w = 1,\
    \ const int no = -1) {\n        this->graph[u].emplace_back(Edge(u, v, w, no));\n\
    \        this->num_edges++;\n    }\n\n    void add_undirected_edge(const int u,\
    \ const int v, const T w = 1, const int no = -1) {\n        this->graph[u].emplace_back(Edge(u,\
    \ v, w, no));\n        this->graph[v].emplace_back(Edge(v, u, w, no));\n     \
    \   this->num_edges += 2;\n    }\n\n    std::vector<Edge<T>> &operator[](const\
    \ int u) {\n        return this->graph[u];\n    }\n};\n#line 5 \"library/cpp/ShortestPath/bellman_ford.cpp\"\
    \n\n/**\n * start\u304B\u3089\u4ED6\u306E\u3059\u3079\u3066\u306Enode\u3078\u306E\
    \u6700\u77ED\u8DDD\u96E2(\u5230\u9054\u3067\u304D\u306A\u3044node\u306Finf)\u3092\
    \u3082\u3068\u3081\u308B\n * \u8CA0\u306E\u9589\u8DEF\u304C\u3042\u308B\u5834\u5408\
    \u306F\u7A7A\u3092\u8FD4\u3059\n * start\u304B\u3089\u5230\u9054\u3067\u304D\u306A\
    \u3044\u3088\u3046\u306A\u8CA0\u306E\u9589\u8DEF\u306F\u7121\u8996\u3055\u308C\
    \u308B\u304C\u3001\u76EE\u7684\u5730\u306B\u5230\u9054\u3067\u304D\u306A\u3044\
    \u8CA0\u306E\u9589\u8DEF\u304C\u3042\u308B\u5834\u5408\u3082\u7A7A\u306B\u306A\
    \u308B\u3053\u3068\u306B\u6CE8\u610F\n * \u76EE\u7684\u5730\u306B\u5230\u9054\u3067\
    \u304D\u306A\u3044\u8CA0\u306E\u9589\u8DEF\u3092\u7121\u8996\u3057\u305F\u3044\
    \u5834\u5408\u306F\uFF0C\u76EE\u7684\u5730\u306B\u5230\u9054\u3067\u304D\u306A\
    \u3044\u3088\u3046\u306A\u30CE\u30FC\u30C9\u306B\u5165\u308B\u8FBA\u3092\u9664\
    \u53BB\u3057\u3066\u304A\u3051\u3070\u3044\u3044\n * O(|V||E|)\n */\ntemplate<typename\
    \ T>\nstd::pair<std::vector<T>, std::vector<Edge<T>>> bellman_ford(const int start,\
    \ Graph<T> &graph) {\n    const int num_nodes = graph.num_nodes;\n    const auto\
    \ infinity = std::numeric_limits<T>::max();\n    std::vector<T> distance(num_nodes,\
    \ infinity);\n    distance[start] = 0;\n    std::vector<Edge<T>> prev_edge(graph.num_nodes);\
    \       // \u7D4C\u8DEF\u5FA9\u5143\u7528\n\n    int i;\n    for (i = 0; i < num_nodes;\
    \ ++i) {\n        bool update = false;\n        for (int u = 0; u < num_nodes;\
    \ ++u) {\n            for (const auto &edge: graph[u]) {\n                if (distance[u]\
    \ != infinity and distance[edge.to] > distance[u] + edge.w) {\n              \
    \      distance[edge.to] = distance[u] + edge.w;\n                    prev_edge[edge.to]\
    \ = edge;\n                    update = true;\n                }\n           \
    \ }\n        }\n        if (not update) {\n            break;\n        }\n   \
    \ }\n\n    if (i == num_nodes) {\n        return {{}, {}};\n    } else {\n   \
    \     return {distance, prev_edge};\n    }\n}\n#line 5 \"test/cpp/ShortestPath/bellman_ford1.test.cpp\"\
    \n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int V, E, R;\n    cin >> V >> E >> R;\n\n    Graph<long long> graph(V);\n\
    \    for (int i = 0; i < E; ++i) {\n        int S, T, D;\n        cin >> S >>\
    \ T >> D;\n        graph.add_directed_edge(S, T, D);\n    }\n\n    const auto\
    \ [distance, _] = bellman_ford(R, graph);\n\n    if (distance.empty()) {\n   \
    \     cout << \"NEGATIVE CYCLE\" << endl;\n    } else {\n        for (auto a:\
    \ distance) {\n            if (a == std::numeric_limits<long long>::max()) {\n\
    \                cout << \"INF\" << endl;\n            } else {\n            \
    \    cout << a << endl;\n            }\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include <iostream>\n#include \"library/cpp/ShortestPath/bellman_ford.cpp\"\
    \n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int V, E, R;\n    cin >> V >> E >> R;\n\n    Graph<long long> graph(V);\n\
    \    for (int i = 0; i < E; ++i) {\n        int S, T, D;\n        cin >> S >>\
    \ T >> D;\n        graph.add_directed_edge(S, T, D);\n    }\n\n    const auto\
    \ [distance, _] = bellman_ford(R, graph);\n\n    if (distance.empty()) {\n   \
    \     cout << \"NEGATIVE CYCLE\" << endl;\n    } else {\n        for (auto a:\
    \ distance) {\n            if (a == std::numeric_limits<long long>::max()) {\n\
    \                cout << \"INF\" << endl;\n            } else {\n            \
    \    cout << a << endl;\n            }\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/ShortestPath/bellman_ford.cpp
  - library/cpp/Graph/Graph.hpp
  isVerificationFile: true
  path: test/cpp/ShortestPath/bellman_ford1.test.cpp
  requiredBy: []
  timestamp: '2023-05-15 19:51:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/ShortestPath/bellman_ford1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/ShortestPath/bellman_ford1.test.cpp
- /verify/test/cpp/ShortestPath/bellman_ford1.test.cpp.html
title: test/cpp/ShortestPath/bellman_ford1.test.cpp
---
