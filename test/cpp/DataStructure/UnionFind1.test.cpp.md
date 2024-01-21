---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/DataStructure/UnionFind.hpp
    title: library/cpp/DataStructure/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/cpp/DataStructure/UnionFind1.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 1 \"library/cpp/DataStructure/UnionFind.hpp\"\
    \n#include <vector>\n\nclass UnionFind {\npublic:\n    const int num_nodes;  \
    \  // \u8981\u7D20\u306E\u500B\u6570\n    int set_size;           // \u96C6\u5408\
    \u306E\u500B\u6570\n\nprivate:\n    std::vector<int> parent;    // \u89AA\u306E\
    \u756A\u53F7(\u89AA\u3060\u3063\u305F\u5834\u5408\u306F-(\u305D\u306E\u96C6\u5408\
    \u306E\u30B5\u30A4\u30BA))\n\npublic:\n    explicit UnionFind(int num_nodes) :\
    \ num_nodes(num_nodes), set_size(num_nodes), parent(num_nodes, -1) {\n    }\n\n\
    \    // u \u3068 v \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\
    \u5224\u5B9A\u3059\u308B\n    bool is_same_set(const int u, const int v) {\n \
    \       return this->find_root(u) == this->find_root(v);\n    }\n\n    // u \u3068\
    \ v \u306E\u5C5E\u3059\u308B\u96C6\u5408\u3092\u4F75\u5408\u3059\u308B\n    void\
    \ unite(int u, int v) {\n        u = this->find_root(u);\n        v = this->find_root(v);\n\
    \        if (u == v) {\n            return;\n        }\n\n        // \u96C6\u5408\
    \u306E\u30B5\u30A4\u30BA\u304C\u5927\u304D\u3044\u3044\u65B9\u3092 u \u3068\u306A\
    \u308B\u3088\u3046\u306B\u3059\u308B\n        if (this->parent[u] > this->parent[v])\
    \ {\n            std::swap(u, v);\n        }\n\n        // u \u306E\u4E0B\u306B\
    \ v \u3092\u3064\u3051\u308B\n        this->parent[u] += this->parent[v];\n  \
    \      this->parent[v] = u;\n        this->set_size--;\n    }\n\n    // u \u306E\
    \u5C5E\u3059\u308B\u96C6\u5408\u306E\u8981\u7D20\u6570\u3092\u6C42\u3081\u308B\
    \n    int size(const int u) {\n        return (-this->parent[this->find_root(u)]);\n\
    \    }\n\n    int leader(const int u) {\n        return this->find_root(u);\n\
    \    }\n\nprivate:\n    // \u6728\u306E\u6839\u3092\u6C42\u3081\u308B\n    int\
    \ find_root(const int u) {\n        if (this->parent[u] < 0) {\n            return\
    \ u;\n        }\n        else {\n            return this->parent[u] = this->find_root(this->parent[u]);\n\
    \        }\n    }\n};\n#line 4 \"test/cpp/DataStructure/UnionFind1.test.cpp\"\n\
    #include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int N, Q;\n    cin >> N >> Q;\n\n   \
    \ UnionFind uf(N);\n    for (int i = 0; i < Q; ++i) {\n        int T, U, V;\n\
    \        cin >> T >> U >> V;\n        if (T == 0) {\n            uf.unite(U, V);\n\
    \        }\n        else {\n            cout << uf.is_same_set(U, V) << endl;\n\
    \        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"library/cpp/DataStructure/UnionFind.hpp\"\n#include <iostream>\n\nusing namespace\
    \ std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n\n    UnionFind uf(N);\n    for (int i =\
    \ 0; i < Q; ++i) {\n        int T, U, V;\n        cin >> T >> U >> V;\n      \
    \  if (T == 0) {\n            uf.unite(U, V);\n        }\n        else {\n   \
    \         cout << uf.is_same_set(U, V) << endl;\n        }\n    }\n\n    return\
    \ 0;\n}"
  dependsOn:
  - library/cpp/DataStructure/UnionFind.hpp
  isVerificationFile: true
  path: test/cpp/DataStructure/UnionFind1.test.cpp
  requiredBy: []
  timestamp: '2023-05-15 18:22:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/DataStructure/UnionFind1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/DataStructure/UnionFind1.test.cpp
- /verify/test/cpp/DataStructure/UnionFind1.test.cpp.html
title: test/cpp/DataStructure/UnionFind1.test.cpp
---
