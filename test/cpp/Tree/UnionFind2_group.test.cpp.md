---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Tree/UnionFind.hpp
    title: library/cpp/Tree/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc256/tasks/abc256_e
    links:
    - https://atcoder.jp/contests/abc256/tasks/abc256_e
  bundledCode: "#line 1 \"test/cpp/Tree/UnionFind2_group.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc256/tasks/abc256_e\"\n\n#line 1 \"library/cpp/Tree/UnionFind.hpp\"\
    \n#include <numeric>\n#include <vector>\n\nclass UnionFind {\npublic:\n    const\
    \ int num_nodes;    // \u8981\u7D20\u306E\u500B\u6570\n    int set_size;     \
    \      // \u96C6\u5408\u306E\u500B\u6570\n\nprivate:\n    std::vector<int> parent;\
    \    // \u89AA\u306E\u756A\u53F7(\u89AA\u3060\u3063\u305F\u5834\u5408\u306F-(\u305D\
    \u306E\u96C6\u5408\u306E\u30B5\u30A4\u30BA))\n    std::vector<int> next;\n\npublic:\n\
    \    explicit UnionFind(int num_nodes) : num_nodes(num_nodes), set_size(num_nodes),\
    \ parent(num_nodes, -1) {\n        this->next.resize(num_nodes);\n        std::iota(this->next.begin(),\
    \ this->next.end(), 0);\n    }\n\n    // u \u3068 v \u304C\u540C\u3058\u96C6\u5408\
    \u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\u3059\u308B\n    bool is_same_set(const\
    \ int u, const int v) {\n        return this->find_root(u) == this->find_root(v);\n\
    \    }\n\n    // u \u3068 v \u306E\u5C5E\u3059\u308B\u96C6\u5408\u3092\u4F75\u5408\
    \u3059\u308B\n    bool unite(int u, int v) {\n        u = this->find_root(u);\n\
    \        v = this->find_root(v);\n        if (u == v) {\n            return false;\n\
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
    \        }\n    }\n};\n#line 4 \"test/cpp/Tree/UnionFind2_group.test.cpp\"\n#include\
    \ <iostream>\n#include <tuple>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int N;\n    cin >> N;\n    vector<int>\
    \ X(N), C(N);\n    for (int i = 0; i < N; ++i) {\n        cin >> X[i];\n     \
    \   X[i]--;\n    }\n    for (int i = 0; i < N; ++i) {\n        cin >> C[i];\n\
    \    }\n\n    vector<tuple<int, int, int>> c_u_v;\n    for (int i = 0; i < N;\
    \ ++i) {\n        c_u_v.emplace_back(C[i], i, X[i]);\n    }\n    sort(c_u_v.rbegin(),\
    \ c_u_v.rend());\n\n    long long ans = 0;\n    UnionFind uf(N);\n    for (auto\
    \ [c, u, v]: c_u_v) {\n        if (not uf.unite(u, v)) {\n            ans += c;\n\
    \        }\n    }\n    cout << ans << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc256/tasks/abc256_e\"\n\n\
    #include \"library/cpp/Tree/UnionFind.hpp\"\n#include <iostream>\n#include <tuple>\n\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N;\n    cin >> N;\n    vector<int> X(N), C(N);\n    for (int i = 0;\
    \ i < N; ++i) {\n        cin >> X[i];\n        X[i]--;\n    }\n    for (int i\
    \ = 0; i < N; ++i) {\n        cin >> C[i];\n    }\n\n    vector<tuple<int, int,\
    \ int>> c_u_v;\n    for (int i = 0; i < N; ++i) {\n        c_u_v.emplace_back(C[i],\
    \ i, X[i]);\n    }\n    sort(c_u_v.rbegin(), c_u_v.rend());\n\n    long long ans\
    \ = 0;\n    UnionFind uf(N);\n    for (auto [c, u, v]: c_u_v) {\n        if (not\
    \ uf.unite(u, v)) {\n            ans += c;\n        }\n    }\n    cout << ans\
    \ << endl;\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Tree/UnionFind.hpp
  isVerificationFile: true
  path: test/cpp/Tree/UnionFind2_group.test.cpp
  requiredBy: []
  timestamp: '2024-01-22 20:11:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Tree/UnionFind2_group.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Tree/UnionFind2_group.test.cpp
- /verify/test/cpp/Tree/UnionFind2_group.test.cpp.html
title: test/cpp/Tree/UnionFind2_group.test.cpp
---
