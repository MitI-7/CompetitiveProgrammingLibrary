---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Graph/Graph.hpp
    title: library/cpp/Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/Graph/find_cycle.cpp
    title: library/cpp/Graph/find_cycle.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection
    links:
    - https://judge.yosupo.jp/problem/cycle_detection
  bundledCode: "#line 1 \"test/cpp/Graph/find_cycle2.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/cycle_detection\"\n\n#include <iostream>\n#line\
    \ 2 \"library/cpp/Graph/Graph.hpp\"\n\n#include <vector>\n#line 5 \"library/cpp/Graph/Graph.hpp\"\
    \n\ntemplate<typename T>\nclass Edge {\npublic:\n    int from;\n    int to;\n\
    \    T w;\n    int no;\n\n    Edge() : from(-1), to(-1), w(-1), no(-1) {}\n\n\
    \    Edge(int from, int to, T w = 1, int no = -1) : from(from), to(to), w(w),\
    \ no(no) {\n\n    }\n};\n\ntemplate<typename T=int>\nclass Graph {\npublic:\n\
    \    const int num_nodes;\n    int num_edges;\n    std::vector<std::vector<Edge<T>>>\
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
    \ v, w, i);\n    }\n    return graph;\n}\n#line 2 \"library/cpp/Graph/find_cycle.cpp\"\
    \n\ntemplate<typename T>\nbool dfs(const int u, const Edge<T> &prev, std::vector<int>\
    \ &state, std::vector<Edge<T>> &edges, const Graph<T> &graph) {\n    state[u]\
    \ = 1;\n    for (auto e: graph.graph[u]) {\n        if (e.no == prev.no) {\n \
    \           continue;\n        }\n        if (state[e.to] == 2) {\n          \
    \  break;\n        }\n\n        edges.push_back(e);\n        // find cycle\n \
    \       if (state[e.to] == 1 or dfs(e.to, e, state, edges, graph)) {\n       \
    \     return true;\n        }\n        edges.pop_back();\n    }\n\n    state[u]\
    \ = 2;\n    return false;\n}\n\n// \u6709\u52B9/\u7121\u5411\u30B0\u30E9\u30D5\
    \u306E\u30B5\u30A4\u30AF\u30EB\u3092\u3072\u3068\u3064\u898B\u3064\u3051\u308B\
    \n// \u5358\u7D14\u30B0\u30E9\u30D5\u3067\u306A\u304F\u3066\u3082\u3044\u3044\n\
    // O(N + M)\n// \u8FBA\u756A\u53F7\u3092\u3044\u308C\u3066\u304A\u304F\u3053\u3068\
    \ntemplate<typename T>\nstd::vector<Edge<T>> find_cycle(const Graph<T> &graph)\
    \ {\n    std::vector<Edge<T>> edges;\n    std::vector<int> state(graph.num_nodes,\
    \ 0);   // 0: \u672A\u63A2\u7D22\uFF0C 1: \u63A2\u7D22\u4E2D\uFF0C2: \u63A2\u7D22\
    \u6E08\u307F\n\n    // u \u3092\u59CB\u70B9\u3068\u3057\uFF0C\u9589\u8DEF\u3092\
    \u63A2\u7D22\n    std::vector<Edge<T>> cycle;\n    for (int u = 0; u < graph.num_nodes;\
    \ ++u) {\n        if (state[u] != 0) {\n            continue;\n        }\n   \
    \     if (dfs(u, Edge(-1, -1, 0, -1), state, edges, graph)) {\n            auto\
    \ end = edges.back().to;\n            bool in_cycle = false;\n            for\
    \ (auto e: edges) {\n                // cycle \u306E\u958B\u59CB\u30CE\u30FC\u30C9\
    \u3092\u898B\u3064\u3051\u305F\n                if (e.from == end) {\n       \
    \             in_cycle = true;\n                }\n                if (in_cycle)\
    \ {\n                    cycle.emplace_back(e);\n                }\n         \
    \   }\n            break;\n        }\n    }\n\n    return cycle;\n}\n#line 5 \"\
    test/cpp/Graph/find_cycle2.test.cpp\"\n\nusing namespace std;\n\nint main() {\n\
    \    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    int N, M;\n  \
    \  cin >> N >> M;\n    Graph<int> graph(N);\n    for (int i = 0; i < M; ++i) {\n\
    \        int U, V;\n        cin >> U >> V;\n        graph.add_directed_edge(U,\
    \ V, 0, i);\n    }\n\n    auto cycle = find_cycle(graph);\n\n    if (cycle.empty())\
    \ {\n        cout << -1 << endl;\n        return 0;\n    }\n\n    cout << cycle.size()\
    \ << endl;\n    for (auto e: cycle) {\n        cout << e.no << endl;\n    }\n\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n\n#include\
    \ <iostream>\n#include \"library/cpp/Graph/find_cycle.cpp\"\n\nusing namespace\
    \ std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, M;\n    cin >> N >> M;\n    Graph<int> graph(N);\n    for (int i\
    \ = 0; i < M; ++i) {\n        int U, V;\n        cin >> U >> V;\n        graph.add_directed_edge(U,\
    \ V, 0, i);\n    }\n\n    auto cycle = find_cycle(graph);\n\n    if (cycle.empty())\
    \ {\n        cout << -1 << endl;\n        return 0;\n    }\n\n    cout << cycle.size()\
    \ << endl;\n    for (auto e: cycle) {\n        cout << e.no << endl;\n    }\n\n\
    \    return 0;\n}"
  dependsOn:
  - library/cpp/Graph/find_cycle.cpp
  - library/cpp/Graph/Graph.hpp
  isVerificationFile: true
  path: test/cpp/Graph/find_cycle2.test.cpp
  requiredBy: []
  timestamp: '2023-05-15 18:41:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Graph/find_cycle2.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Graph/find_cycle2.test.cpp
- /verify/test/cpp/Graph/find_cycle2.test.cpp.html
title: test/cpp/Graph/find_cycle2.test.cpp
---
