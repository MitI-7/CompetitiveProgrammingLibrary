---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Tree/WeightedUnionFind1.test.cpp
    title: test/cpp/Tree/WeightedUnionFind1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Tree/WeightedUnionFind2.test.cpp
    title: test/cpp/Tree/WeightedUnionFind2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Tree/WeightedUnionFind3.test.cpp
    title: test/cpp/Tree/WeightedUnionFind3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Tree/WeightedUnionFind.hpp\"\n#include <cassert>\n\
    #include <vector>\n\ntemplate<class T>\nclass WeightedUnionFind {\npublic:\n \
    \   std::vector<int> parent;\n    std::vector<T> diff_weight;\n\n    explicit\
    \ WeightedUnionFind(const int num_nodes) {\n        this->parent.resize(num_nodes,\
    \ -1);\n        this->diff_weight.resize(num_nodes);\n    }\n\n    // u \u3068\
    \ v \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\u3059\
    \u308B\n    bool is_same_set(const int u, const int v) {\n        return this->find_root(u)\
    \ == this->find_root(v);\n    }\n\n    // u \u3068 v \u306E\u5C5E\u3059\u308B\u96C6\
    \u5408\u3092\u4F75\u5408\u3059\u308B\n    // weight(u) + w = weight(v) \u3068\u306A\
    \u308B\u3088\u3046\u306B\u3059\u308B\n    // u \u3068 v \u304C\u540C\u3058\u96C6\
    \u5408\u3067\uFF0C\u6574\u5408\u6027\u304C\u4FDD\u305F\u308C\u308B\u3068\u304D\
    \ true \u3092\u8FD4\u3059\n    bool unite(int u, int v, const T w) {\n       \
    \ T new_w = this->weight(u) + w - this->weight(v);\n        u = this->find_root(u);\n\
    \        v = this->find_root(v);\n\n        if (u == v) {\n            return\
    \ new_w == 0;\n        }\n\n        // \u96C6\u5408\u306E\u30B5\u30A4\u30BA\u304C\
    \u5C0F\u3055\u3044\u65B9\u3092 u \u3068\u3059\u308B\n        if (this->parent[u]\
    \ > this->parent[v]) {\n            std::swap(u, v);\n            new_w = -new_w;\n\
    \        }\n\n        // u \u306E\u4E0B\u306B v \u3092\u3064\u3051\u308B\n   \
    \     this->parent[u] += this->parent[v];\n        this->parent[v] = u;\n    \
    \    this->diff_weight[v] = new_w;\n\n        return true;\n    }\n\n    T weight(const\
    \ int u) {\n        this->find_root(u);\n        return this->diff_weight[u];\n\
    \    }\n\n    // u \u3068 v \u3068\u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\
    \u3044\u308B\u3068\u304D\u3001weight(v) - weight(u)\n    T diff(const int u, const\
    \ int v) {\n        assert(this->is_same_set(u, v));\n        return this->weight(v)\
    \ - this->weight(u);\n    }\n\nprivate:\n    // \u6728\u306E\u6839\u3092\u6C42\
    \u3081\u308B\n    int find_root(const int u) {\n        if (this->parent[u] <\
    \ 0) {\n            return u;\n        }\n\n        const int root = this->find_root(this->parent[u]);\n\
    \        // u \u306F root \u306E\u76F4\u4E0B\u306B\u3064\u304F\u306E\u3067\uFF0C\
    u \u306E weight \u306F u \u304B\u3089 root \u307E\u3067\u306E\u7D2F\u7A4D\u548C\
    \u3068\u306A\u308B\n        this->diff_weight[u] += this->diff_weight[this->parent[u]];\n\
    \        // \u7D4C\u8DEF\u5727\u7E2E\n        return this->parent[u] = root;\n\
    \    }\n};\n"
  code: "#include <cassert>\n#include <vector>\n\ntemplate<class T>\nclass WeightedUnionFind\
    \ {\npublic:\n    std::vector<int> parent;\n    std::vector<T> diff_weight;\n\n\
    \    explicit WeightedUnionFind(const int num_nodes) {\n        this->parent.resize(num_nodes,\
    \ -1);\n        this->diff_weight.resize(num_nodes);\n    }\n\n    // u \u3068\
    \ v \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\u3059\
    \u308B\n    bool is_same_set(const int u, const int v) {\n        return this->find_root(u)\
    \ == this->find_root(v);\n    }\n\n    // u \u3068 v \u306E\u5C5E\u3059\u308B\u96C6\
    \u5408\u3092\u4F75\u5408\u3059\u308B\n    // weight(u) + w = weight(v) \u3068\u306A\
    \u308B\u3088\u3046\u306B\u3059\u308B\n    // u \u3068 v \u304C\u540C\u3058\u96C6\
    \u5408\u3067\uFF0C\u6574\u5408\u6027\u304C\u4FDD\u305F\u308C\u308B\u3068\u304D\
    \ true \u3092\u8FD4\u3059\n    bool unite(int u, int v, const T w) {\n       \
    \ T new_w = this->weight(u) + w - this->weight(v);\n        u = this->find_root(u);\n\
    \        v = this->find_root(v);\n\n        if (u == v) {\n            return\
    \ new_w == 0;\n        }\n\n        // \u96C6\u5408\u306E\u30B5\u30A4\u30BA\u304C\
    \u5C0F\u3055\u3044\u65B9\u3092 u \u3068\u3059\u308B\n        if (this->parent[u]\
    \ > this->parent[v]) {\n            std::swap(u, v);\n            new_w = -new_w;\n\
    \        }\n\n        // u \u306E\u4E0B\u306B v \u3092\u3064\u3051\u308B\n   \
    \     this->parent[u] += this->parent[v];\n        this->parent[v] = u;\n    \
    \    this->diff_weight[v] = new_w;\n\n        return true;\n    }\n\n    T weight(const\
    \ int u) {\n        this->find_root(u);\n        return this->diff_weight[u];\n\
    \    }\n\n    // u \u3068 v \u3068\u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\
    \u3044\u308B\u3068\u304D\u3001weight(v) - weight(u)\n    T diff(const int u, const\
    \ int v) {\n        assert(this->is_same_set(u, v));\n        return this->weight(v)\
    \ - this->weight(u);\n    }\n\nprivate:\n    // \u6728\u306E\u6839\u3092\u6C42\
    \u3081\u308B\n    int find_root(const int u) {\n        if (this->parent[u] <\
    \ 0) {\n            return u;\n        }\n\n        const int root = this->find_root(this->parent[u]);\n\
    \        // u \u306F root \u306E\u76F4\u4E0B\u306B\u3064\u304F\u306E\u3067\uFF0C\
    u \u306E weight \u306F u \u304B\u3089 root \u307E\u3067\u306E\u7D2F\u7A4D\u548C\
    \u3068\u306A\u308B\n        this->diff_weight[u] += this->diff_weight[this->parent[u]];\n\
    \        // \u7D4C\u8DEF\u5727\u7E2E\n        return this->parent[u] = root;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Tree/WeightedUnionFind.hpp
  requiredBy: []
  timestamp: '2024-01-27 12:52:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Tree/WeightedUnionFind3.test.cpp
  - test/cpp/Tree/WeightedUnionFind2.test.cpp
  - test/cpp/Tree/WeightedUnionFind1.test.cpp
documentation_of: library/cpp/Tree/WeightedUnionFind.hpp
layout: document
redirect_from:
- /library/library/cpp/Tree/WeightedUnionFind.hpp
- /library/library/cpp/Tree/WeightedUnionFind.hpp.html
title: library/cpp/Tree/WeightedUnionFind.hpp
---
