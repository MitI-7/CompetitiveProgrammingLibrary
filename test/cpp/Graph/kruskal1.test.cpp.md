---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/DataStructure/UnionFind.hpp
    title: library/cpp/DataStructure/UnionFind.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/Graph/kruskal.cpp
    title: library/cpp/Graph/kruskal.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"test/cpp/Graph/kruskal1.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#line 1 \"library/cpp/Graph/kruskal.cpp\"\n#include <algorithm>\n#include\
    \ <vector>\n#line 2 \"library/cpp/DataStructure/UnionFind.hpp\"\n\nclass UnionFind\
    \ {\npublic:\n    const int num_nodes;    // \u8981\u7D20\u306E\u500B\u6570\n\
    \    int set_size;           // \u96C6\u5408\u306E\u500B\u6570\n\nprivate:\n \
    \   std::vector<int> parent;    // \u89AA\u306E\u756A\u53F7(\u89AA\u3060\u3063\
    \u305F\u5834\u5408\u306F-(\u305D\u306E\u96C6\u5408\u306E\u30B5\u30A4\u30BA))\n\
    \npublic:\n    explicit UnionFind(int num_nodes) : num_nodes(num_nodes), set_size(num_nodes),\
    \ parent(num_nodes, -1) {\n    }\n\n    // u \u3068 v \u304C\u540C\u3058\u96C6\
    \u5408\u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\u3059\u308B\n    bool is_same_set(const\
    \ int u, const int v) {\n        return this->find_root(u) == this->find_root(v);\n\
    \    }\n\n    // u \u3068 v \u306E\u5C5E\u3059\u308B\u96C6\u5408\u3092\u4F75\u5408\
    \u3059\u308B\n    void unite(int u, int v) {\n        u = this->find_root(u);\n\
    \        v = this->find_root(v);\n        if (u == v) {\n            return;\n\
    \        }\n\n        // \u96C6\u5408\u306E\u30B5\u30A4\u30BA\u304C\u5C0F\u3055\
    \u3044\u65B9\u3092 u \u3068\u3059\u308B\n        if (this->parent[u] > this->parent[v])\
    \ {\n            std::swap(u, v);\n        }\n\n        // \u5C0F\u3055\u3044\u65B9\
    (u) \u306B\u5927\u304D\u3044\u65B9(v) \u3092\u304F\u3063\u3064\u3051\u308B\n \
    \       // \u4E21\u65B9\u3068\u3082root\u306A\u306E\u3067-(\u96C6\u5408\u306E\u30B5\
    \u30A4\u30BA)\u304C\u5165\u3063\u3066\u3044\u308B\n        this->parent[u] +=\
    \ this->parent[v];\n        // v \u306E\u89AA\u3092 u \u306B\u3059\u308B\n   \
    \     this->parent[v] = u;\n        this->set_size--;\n    }\n\n    // x\u306E\
    \u5C5E\u3059\u308B\u96C6\u5408\u306E\u8981\u7D20\u6570\u3092\u6C42\u3081\u308B\
    \n    int size(const int u) {\n        return (-this->parent[find_root(u)]);\n\
    \    }\n\n    int leader(const int u) {\n        return this->find_root(u);\n\
    \    }\n\nprivate:\n    // \u6728\u306E\u6839\u3092\u6C42\u3081\u308B\n    int\
    \ find_root(const int u) {\n        if (this->parent[u] < 0) {\n            return\
    \ u;\n        }\n        else {\n            return this->parent[u] = this->find_root(this->parent[u]);\n\
    \        }\n    }\n};\n#line 4 \"library/cpp/Graph/kruskal.cpp\"\n\n\nstruct Edge\
    \ {\n    int from;\n    int to;\n    long long cost;\n    int no;\n\n    Edge()\
    \ {}\n\n    Edge(int from, int to, long long cost, int no = 0) : from(from), to(to),\
    \ cost(cost), no(no) {}\n\n    bool operator<(const Edge &edge) const {\n    \
    \    return this->cost < edge.cost;\n    }\n\n    bool operator>(const Edge &edge)\
    \ const {\n        return this->cost > edge.cost;\n    }\n};\n\n// \u30B0\u30E9\
    \u30D5\u306E\u6700\u5C0F\u5168\u57DF\u6728\u3092\u6C42\u3081\u308B\u3002O(|E|\
    \ log|V|)\nlong long kruskal(int num_of_node, std::vector<Edge> &edges) {\n  \
    \  // \u30B3\u30B9\u30C8\u306E\u5C0F\u3055\u3044\u9806\u306B\u30BD\u30FC\u30C8\
    \n    sort(edges.begin(), edges.end());\n\n    UnionFind uf(num_of_node);\n  \
    \  long long ans = 0;\n    for (const auto e: edges) {\n        if (!uf.is_same_set(e.from,\
    \ e.to)) {\n            uf.unite(e.from, e.to);\n            ans += e.cost;\n\
    \        }\n    }\n\n    return ans;\n}\n#line 4 \"test/cpp/Graph/kruskal1.test.cpp\"\
    \n\n#include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int V, E;\n    cin >> V >> E;\n\n   \
    \ vector<Edge> edges;\n    for (int i = 0; i < E; ++i) {\n        int s, t, w;\n\
    \        cin >> s >> t >> w;\n        edges.emplace_back(s, t, w);\n    }\n\n\
    \    cout << kruskal(V, edges) << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include \"library/cpp/Graph/kruskal.cpp\"\n\n#include <iostream>\n\nusing\
    \ namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int V, E;\n    cin >> V >> E;\n\n    vector<Edge> edges;\n    for (int i\
    \ = 0; i < E; ++i) {\n        int s, t, w;\n        cin >> s >> t >> w;\n    \
    \    edges.emplace_back(s, t, w);\n    }\n\n    cout << kruskal(V, edges) << endl;\n\
    \n    return 0;\n}"
  dependsOn:
  - library/cpp/Graph/kruskal.cpp
  - library/cpp/DataStructure/UnionFind.hpp
  isVerificationFile: true
  path: test/cpp/Graph/kruskal1.test.cpp
  requiredBy: []
  timestamp: '2023-05-18 13:20:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Graph/kruskal1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Graph/kruskal1.test.cpp
- /verify/test/cpp/Graph/kruskal1.test.cpp.html
title: test/cpp/Graph/kruskal1.test.cpp
---
