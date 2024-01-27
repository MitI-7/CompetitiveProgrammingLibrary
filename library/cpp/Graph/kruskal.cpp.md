---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/DataStructure/UnionFind.hpp
    title: library/cpp/DataStructure/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/cpp/Graph/kruskal1.test.cpp
    title: test/cpp/Graph/kruskal1.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Graph/kruskal.cpp\"\n#include <algorithm>\n\
    #include <vector>\n#line 1 \"library/cpp/DataStructure/UnionFind.hpp\"\n#include\
    \ <numeric>\n#line 3 \"library/cpp/DataStructure/UnionFind.hpp\"\n\nclass UnionFind\
    \ {\npublic:\n    const int num_nodes;    // \u8981\u7D20\u306E\u500B\u6570\n\
    \    int set_size;           // \u96C6\u5408\u306E\u500B\u6570\n\nprivate:\n \
    \   std::vector<int> parent;    // \u89AA\u306E\u756A\u53F7(\u89AA\u3060\u3063\
    \u305F\u5834\u5408\u306F-(\u305D\u306E\u96C6\u5408\u306E\u30B5\u30A4\u30BA))\n\
    \    std::vector<int> next;\n\npublic:\n    explicit UnionFind(int num_nodes)\
    \ : num_nodes(num_nodes), set_size(num_nodes), parent(num_nodes, -1) {\n     \
    \   this->next.resize(num_nodes);\n        std::iota(this->next.begin(), this->next.end(),\
    \ 0);\n    }\n\n    // u \u3068 v \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\
    \u308B\u304B\u5224\u5B9A\u3059\u308B\n    bool is_same_set(const int u, const\
    \ int v) {\n        return this->find_root(u) == this->find_root(v);\n    }\n\n\
    \    // u \u3068 v \u306E\u5C5E\u3059\u308B\u96C6\u5408\u3092\u4F75\u5408\u3059\
    \u308B\n    bool unite(int u, int v) {\n        u = this->find_root(u);\n    \
    \    v = this->find_root(v);\n        if (u == v) {\n            return false;\n\
    \        }\n\n        // \u96C6\u5408\u306E\u30B5\u30A4\u30BA\u304C\u5927\u304D\
    \u3044\u3044\u65B9\u3092 u \u3068\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n\
    \        if (this->parent[u] > this->parent[v]) {\n            std::swap(u, v);\n\
    \        }\n\n        // u \u306E\u4E0B\u306B v \u3092\u3064\u3051\u308B\n   \
    \     this->parent[u] += this->parent[v];\n        this->parent[v] = u;\n    \
    \    std::swap(this->next[v], this->next[u]);\n        this->set_size--;\n\n \
    \       return true;\n    }\n\n    // u \u306E\u5C5E\u3059\u308B\u96C6\u5408\u306E\
    \u8981\u7D20\u6570\u3092\u6C42\u3081\u308B\n    int size(const int u) {\n    \
    \    return (-this->parent[this->find_root(u)]);\n    }\n\n    int leader(const\
    \ int u) {\n        return this->find_root(u);\n    }\n\n    // u \u306E\u6240\
    \u5C5E\u3059\u308B\u96C6\u5408\u306E\u30E1\u30F3\u30D0\u30FC\u3092\u6C42\u3081\
    \u308B\n    // O(\u30E1\u30F3\u30D0\u30FC\u306E\u4EBA\u6570)\n    std::vector<int>\
    \ group(const int u) {\n        std::vector<int> group(this->size(u));\n     \
    \   int now = this->find_root(u);\n        for (int i = 0; i < (int) group.size();\
    \ ++i) {\n            group[i] = now = this->next[now];;\n        }\n        return\
    \ group;\n    }\n\nprivate:\n    // \u6728\u306E\u6839\u3092\u6C42\u3081\u308B\
    \n    int find_root(const int u) {\n        if (this->parent[u] < 0) {\n     \
    \       return u;\n        } else {\n            return this->parent[u] = this->find_root(this->parent[u]);\n\
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
    \        }\n    }\n\n    return ans;\n}\n"
  code: "#include <algorithm>\n#include <vector>\n#include \"library/cpp/DataStructure/UnionFind.hpp\"\
    \n\n\nstruct Edge {\n    int from;\n    int to;\n    long long cost;\n    int\
    \ no;\n\n    Edge() {}\n\n    Edge(int from, int to, long long cost, int no =\
    \ 0) : from(from), to(to), cost(cost), no(no) {}\n\n    bool operator<(const Edge\
    \ &edge) const {\n        return this->cost < edge.cost;\n    }\n\n    bool operator>(const\
    \ Edge &edge) const {\n        return this->cost > edge.cost;\n    }\n};\n\n//\
    \ \u30B0\u30E9\u30D5\u306E\u6700\u5C0F\u5168\u57DF\u6728\u3092\u6C42\u3081\u308B\
    \u3002O(|E| log|V|)\nlong long kruskal(int num_of_node, std::vector<Edge> &edges)\
    \ {\n    // \u30B3\u30B9\u30C8\u306E\u5C0F\u3055\u3044\u9806\u306B\u30BD\u30FC\
    \u30C8\n    sort(edges.begin(), edges.end());\n\n    UnionFind uf(num_of_node);\n\
    \    long long ans = 0;\n    for (const auto e: edges) {\n        if (!uf.is_same_set(e.from,\
    \ e.to)) {\n            uf.unite(e.from, e.to);\n            ans += e.cost;\n\
    \        }\n    }\n\n    return ans;\n}"
  dependsOn:
  - library/cpp/DataStructure/UnionFind.hpp
  isVerificationFile: false
  path: library/cpp/Graph/kruskal.cpp
  requiredBy: []
  timestamp: '2024-01-22 20:10:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/cpp/Graph/kruskal1.test.cpp
documentation_of: library/cpp/Graph/kruskal.cpp
layout: document
redirect_from:
- /library/library/cpp/Graph/kruskal.cpp
- /library/library/cpp/Graph/kruskal.cpp.html
title: library/cpp/Graph/kruskal.cpp
---
