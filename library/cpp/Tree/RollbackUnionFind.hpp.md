---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Tree/RollbackUnionFind1.test.cpp
    title: test/cpp/Tree/RollbackUnionFind1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Tree/RollbackUnionFind2.test.cpp
    title: test/cpp/Tree/RollbackUnionFind2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Tree/RollbackUnionFind3.test.cpp
    title: test/cpp/Tree/RollbackUnionFind3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Tree/RollbackUnionFind.hpp\"\n#include <cassert>\n\
    #include <stack>\n#include <tuple>\n#include <vector>\n\nclass RollbackUnionFind\
    \ {\npublic:\n    int set_size;   // \u96C6\u5408\u306E\u500B\u6570\n\nprivate:\n\
    \    std::vector<int> parent;\n    std::stack<std::tuple<int, int, int, int, int>>\
    \ history;\n    int snap_no;\n\npublic:\n    explicit RollbackUnionFind(const\
    \ int num_nodes) : set_size(num_nodes), parent(num_nodes, -1), snap_no(0) {\n\
    \    }\n\n    // u \u3068 v \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\
    \u304B\u5224\u5B9A\u3059\u308B\n    // O(log n)\n    int is_same_set(const int\
    \ u, const int v) {\n        return this->find_root(u) == this->find_root(v);\n\
    \    }\n\n    // u \u3068 v \u306E\u5C5E\u3059\u308B\u96C6\u5408\u3092\u4F75\u5408\
    \u3059\u308B\n    // O(log n)\n    bool unite(int u, int v) {\n        u = this->find_root(u);\n\
    \        v = this->find_root(v);\n\n        // u \u3068 v \u306E\u73FE\u5728\u306E\
    \u89AA\u3092\u8A18\u9332\n        this->history.emplace(u, this->parent[u], v,\
    \ this->parent[v], this->set_size);\n\n        if (u == v) {\n            return\
    \ false;\n        }\n\n        // \u96C6\u5408\u306E\u30B5\u30A4\u30BA\u304C\u5927\
    \u304D\u3044\u65B9\u3092 u \u3068\u3059\u308B\n        if (this->parent[u] > this->parent[v])\
    \ {\n            std::swap(u, v);\n        }\n\n        // u \u306E\u4E0B\u306B\
    \ v \u3092\u3064\u3051\u308B\n        this->parent[u] += this->parent[v];\n  \
    \      this->parent[v] = u;\n        this->set_size--;\n\n        return true;\n\
    \    }\n\n    // u \u306E\u5C5E\u3059\u308B\u96C6\u5408\u306E\u8981\u7D20\u6570\
    \u3092\u6C42\u3081\u308B\n    // O(log n)\n    int size(const int u) {\n     \
    \   return (-this->parent[this->find_root(u)]);\n    }\n\n    // u \u306E\u5C5E\
    \u3059\u308B\u96C6\u5408\u306E leader \u3092\u53D6\u5F97\n    // O(log n)\n  \
    \  int leader(const int u) {\n        return this->find_root(u);\n    }\n\n  \
    \  // \u76F4\u524D\u306B\u884C\u3063\u305F unite \u64CD\u4F5C\u3092\u53D6\u308A\
    \u6D88\u3059\n    // \u53D6\u308A\u6D88\u3057\u305F (u, v) \u3092\u8FD4\u3059\n\
    \    // O(1)\n    std::pair<int, int> undo() {\n        assert(not this->history.empty());\n\
    \n        const auto [u, u_p, v, v_p, s] = history.top();\n        this->history.pop();\n\
    \        this->parent[u] = u_p;\n        this->parent[v] = v_p;\n        this->set_size\
    \ = s;\n\n        return {u, v};\n    }\n\n    // \u73FE\u5728\u306E\u72B6\u614B\
    \u3092\u4FDD\u5B58\n    // undo \u3092\u3088\u3093\u3067\uFF0Csnapshot \u3092\u547C\
    \u3073\u51FA\u3057\u305F\u72B6\u614B\u3088\u308A\u524D\u306B\u623B\u3063\u305F\
    \u3068\u304D\uFF0C\u610F\u5473\u306E\u306A\u3044\u72B6\u614B\u306B\u306A\u308B\
    \u3053\u3068\u306B\u6CE8\u610F\n    // O(1)\n    void snapshot() {\n        this->snap_no\
    \ = this->get_snap_no();\n    }\n\n    int get_snap_no() {\n        return int(history.size());\n\
    \    }\n\n    // snapshot \u3092\u64AE\u3063\u305F\u72B6\u614B\u306B\u623B\u3059\
    \n    // num \u3092\u6307\u5B9A\u3057\u305F\u5834\u5408\uFF0Cunite \u95A2\u6570\
    \u3092 num \u56DE\u547C\u3073\u51FA\u3057\u305F\u6642\u306E\u72B6\u614B\u306B\u623B\
    \u3059\n    // O(\u623B\u3059\u56DE\u6570)\n    void rollback(int num = -1) {\n\
    \        if (num == -1) {\n            num = this->snap_no;\n        }\n     \
    \   while (num < int(this->history.size())) {\n            this->undo();\n   \
    \     }\n    }\n\nprivate:\n    // u \u306E\u6839\u3092\u6C42\u3081\u308B\n  \
    \  // O(log n)\n    int find_root(int u) {\n        if (this->parent[u] < 0) {\n\
    \            return u;\n        }\n        // \u7D4C\u8DEF\u5727\u7E2E\u306F\u3057\
    \u306A\u3044\n        return this->find_root(this->parent[u]);\n    }\n};\n"
  code: "#include <cassert>\n#include <stack>\n#include <tuple>\n#include <vector>\n\
    \nclass RollbackUnionFind {\npublic:\n    int set_size;   // \u96C6\u5408\u306E\
    \u500B\u6570\n\nprivate:\n    std::vector<int> parent;\n    std::stack<std::tuple<int,\
    \ int, int, int, int>> history;\n    int snap_no;\n\npublic:\n    explicit RollbackUnionFind(const\
    \ int num_nodes) : set_size(num_nodes), parent(num_nodes, -1), snap_no(0) {\n\
    \    }\n\n    // u \u3068 v \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\
    \u304B\u5224\u5B9A\u3059\u308B\n    // O(log n)\n    int is_same_set(const int\
    \ u, const int v) {\n        return this->find_root(u) == this->find_root(v);\n\
    \    }\n\n    // u \u3068 v \u306E\u5C5E\u3059\u308B\u96C6\u5408\u3092\u4F75\u5408\
    \u3059\u308B\n    // O(log n)\n    bool unite(int u, int v) {\n        u = this->find_root(u);\n\
    \        v = this->find_root(v);\n\n        // u \u3068 v \u306E\u73FE\u5728\u306E\
    \u89AA\u3092\u8A18\u9332\n        this->history.emplace(u, this->parent[u], v,\
    \ this->parent[v], this->set_size);\n\n        if (u == v) {\n            return\
    \ false;\n        }\n\n        // \u96C6\u5408\u306E\u30B5\u30A4\u30BA\u304C\u5927\
    \u304D\u3044\u65B9\u3092 u \u3068\u3059\u308B\n        if (this->parent[u] > this->parent[v])\
    \ {\n            std::swap(u, v);\n        }\n\n        // u \u306E\u4E0B\u306B\
    \ v \u3092\u3064\u3051\u308B\n        this->parent[u] += this->parent[v];\n  \
    \      this->parent[v] = u;\n        this->set_size--;\n\n        return true;\n\
    \    }\n\n    // u \u306E\u5C5E\u3059\u308B\u96C6\u5408\u306E\u8981\u7D20\u6570\
    \u3092\u6C42\u3081\u308B\n    // O(log n)\n    int size(const int u) {\n     \
    \   return (-this->parent[this->find_root(u)]);\n    }\n\n    // u \u306E\u5C5E\
    \u3059\u308B\u96C6\u5408\u306E leader \u3092\u53D6\u5F97\n    // O(log n)\n  \
    \  int leader(const int u) {\n        return this->find_root(u);\n    }\n\n  \
    \  // \u76F4\u524D\u306B\u884C\u3063\u305F unite \u64CD\u4F5C\u3092\u53D6\u308A\
    \u6D88\u3059\n    // \u53D6\u308A\u6D88\u3057\u305F (u, v) \u3092\u8FD4\u3059\n\
    \    // O(1)\n    std::pair<int, int> undo() {\n        assert(not this->history.empty());\n\
    \n        const auto [u, u_p, v, v_p, s] = history.top();\n        this->history.pop();\n\
    \        this->parent[u] = u_p;\n        this->parent[v] = v_p;\n        this->set_size\
    \ = s;\n\n        return {u, v};\n    }\n\n    // \u73FE\u5728\u306E\u72B6\u614B\
    \u3092\u4FDD\u5B58\n    // undo \u3092\u3088\u3093\u3067\uFF0Csnapshot \u3092\u547C\
    \u3073\u51FA\u3057\u305F\u72B6\u614B\u3088\u308A\u524D\u306B\u623B\u3063\u305F\
    \u3068\u304D\uFF0C\u610F\u5473\u306E\u306A\u3044\u72B6\u614B\u306B\u306A\u308B\
    \u3053\u3068\u306B\u6CE8\u610F\n    // O(1)\n    void snapshot() {\n        this->snap_no\
    \ = this->get_snap_no();\n    }\n\n    int get_snap_no() {\n        return int(history.size());\n\
    \    }\n\n    // snapshot \u3092\u64AE\u3063\u305F\u72B6\u614B\u306B\u623B\u3059\
    \n    // num \u3092\u6307\u5B9A\u3057\u305F\u5834\u5408\uFF0Cunite \u95A2\u6570\
    \u3092 num \u56DE\u547C\u3073\u51FA\u3057\u305F\u6642\u306E\u72B6\u614B\u306B\u623B\
    \u3059\n    // O(\u623B\u3059\u56DE\u6570)\n    void rollback(int num = -1) {\n\
    \        if (num == -1) {\n            num = this->snap_no;\n        }\n     \
    \   while (num < int(this->history.size())) {\n            this->undo();\n   \
    \     }\n    }\n\nprivate:\n    // u \u306E\u6839\u3092\u6C42\u3081\u308B\n  \
    \  // O(log n)\n    int find_root(int u) {\n        if (this->parent[u] < 0) {\n\
    \            return u;\n        }\n        // \u7D4C\u8DEF\u5727\u7E2E\u306F\u3057\
    \u306A\u3044\n        return this->find_root(this->parent[u]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Tree/RollbackUnionFind.hpp
  requiredBy: []
  timestamp: '2024-01-20 16:38:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Tree/RollbackUnionFind3.test.cpp
  - test/cpp/Tree/RollbackUnionFind1.test.cpp
  - test/cpp/Tree/RollbackUnionFind2.test.cpp
documentation_of: library/cpp/Tree/RollbackUnionFind.hpp
layout: document
redirect_from:
- /library/library/cpp/Tree/RollbackUnionFind.hpp
- /library/library/cpp/Tree/RollbackUnionFind.hpp.html
title: library/cpp/Tree/RollbackUnionFind.hpp
---
