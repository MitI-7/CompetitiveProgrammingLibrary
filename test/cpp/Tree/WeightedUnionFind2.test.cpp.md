---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Tree/WeightedUnionFind.hpp
    title: library/cpp/Tree/WeightedUnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B&lang=ja
  bundledCode: "#line 1 \"test/cpp/Tree/WeightedUnionFind2.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B&lang=ja\"\
    \n\n#line 1 \"library/cpp/Tree/WeightedUnionFind.hpp\"\n#include <cassert>\n#include\
    \ <vector>\n\ntemplate<class T>\nclass WeightedUnionFind {\npublic:\n    std::vector<int>\
    \ parent;\n    std::vector<T> diff_weight;\n\n    explicit WeightedUnionFind(const\
    \ int num_nodes) {\n        this->parent.resize(num_nodes, -1);\n        this->diff_weight.resize(num_nodes);\n\
    \    }\n\n    // u \u3068 v \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\
    \u304B\u5224\u5B9A\u3059\u308B\n    bool is_same_set(const int u, const int v)\
    \ {\n        return this->find_root(u) == this->find_root(v);\n    }\n\n    //\
    \ u \u3068 v \u306E\u5C5E\u3059\u308B\u96C6\u5408\u3092\u4F75\u5408\u3059\u308B\
    \n    // weight(u) + w = weight(v) \u3068\u306A\u308B\u3088\u3046\u306B\u3059\u308B\
    \n    // u \u3068 v \u304C\u540C\u3058\u96C6\u5408\u3067\uFF0C\u6574\u5408\u6027\
    \u304C\u4FDD\u305F\u308C\u308B\u3068\u304D true \u3092\u8FD4\u3059\n    bool unite(int\
    \ u, int v, const T w) {\n        T new_w = this->weight(u) + w - this->weight(v);\n\
    \        u = this->find_root(u);\n        v = this->find_root(v);\n\n        if\
    \ (u == v) {\n            return new_w == 0;\n        }\n\n        // \u96C6\u5408\
    \u306E\u30B5\u30A4\u30BA\u304C\u5C0F\u3055\u3044\u65B9\u3092 u \u3068\u3059\u308B\
    \n        if (this->parent[u] > this->parent[v]) {\n            std::swap(u, v);\n\
    \            new_w = -new_w;\n        }\n\n        // u \u306E\u4E0B\u306B v \u3092\
    \u3064\u3051\u308B\n        this->parent[u] += this->parent[v];\n        this->parent[v]\
    \ = u;\n        this->diff_weight[v] = new_w;\n\n        return true;\n    }\n\
    \n    T weight(const int u) {\n        this->find_root(u);\n        return this->diff_weight[u];\n\
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
    \    }\n};\n#line 4 \"test/cpp/Tree/WeightedUnionFind2.test.cpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n\n    WeightedUnionFind<long long> wuf(N);\n\
    \n    vector<int> ans;\n    for (int i = 0; i < Q; ++i) {\n        int T;\n  \
    \      cin >> T;\n        if (T == 0) {\n            int X, Y, Z;\n          \
    \  cin >> X >> Y >> Z;\n            wuf.unite(X, Y, Z);\n        } else {\n  \
    \          int X, Y;\n            cin >> X >> Y;\n            if (wuf.is_same_set(X,\
    \ Y)) {\n                cout << wuf.diff(X, Y) << endl;\n            } else {\n\
    \                cout << \"?\" << endl;\n            }\n        }\n    }\n\n \
    \   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B&lang=ja\"\
    \n\n#include \"library/cpp/Tree/WeightedUnionFind.hpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n\n    WeightedUnionFind<long long> wuf(N);\n\
    \n    vector<int> ans;\n    for (int i = 0; i < Q; ++i) {\n        int T;\n  \
    \      cin >> T;\n        if (T == 0) {\n            int X, Y, Z;\n          \
    \  cin >> X >> Y >> Z;\n            wuf.unite(X, Y, Z);\n        } else {\n  \
    \          int X, Y;\n            cin >> X >> Y;\n            if (wuf.is_same_set(X,\
    \ Y)) {\n                cout << wuf.diff(X, Y) << endl;\n            } else {\n\
    \                cout << \"?\" << endl;\n            }\n        }\n    }\n\n \
    \   return 0;\n}"
  dependsOn:
  - library/cpp/Tree/WeightedUnionFind.hpp
  isVerificationFile: true
  path: test/cpp/Tree/WeightedUnionFind2.test.cpp
  requiredBy: []
  timestamp: '2024-01-27 12:52:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Tree/WeightedUnionFind2.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Tree/WeightedUnionFind2.test.cpp
- /verify/test/cpp/Tree/WeightedUnionFind2.test.cpp.html
title: test/cpp/Tree/WeightedUnionFind2.test.cpp
---
