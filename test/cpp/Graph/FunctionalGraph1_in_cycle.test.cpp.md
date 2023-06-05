---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Graph/FunctionalGraph.hpp
    title: library/cpp/Graph/FunctionalGraph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc296/tasks/abc296_e
    links:
    - https://atcoder.jp/contests/abc296/tasks/abc296_e
  bundledCode: "#line 1 \"test/cpp/Graph/FunctionalGraph1_in_cycle.test.cpp\"\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/abc296/tasks/abc296_e\"\n\n#line 1 \"\
    library/cpp/Graph/FunctionalGraph.hpp\"\n#include <cassert>\n#include <vector>\n\
    \n// \u5404\u9802\u70B9\u304C\u3061\u3087\u3046\u3069 1 \u306E\u51FA\u81EA\u6570\
    \u3092\u3082\u3064\u6709\u5411\u30B0\u30E9\u30D5\n// \u30B0\u30E9\u30D5\u306F\u9023\
    \u7D50\u3068\u306F\u9650\u3089\u306A\u3044\ntemplate<typename T>\nclass FunctionalGraph\
    \ {\npublic:\n    const int num_nodes;\n    std::vector<int> to;            //\
    \ to[u] = u \u306E\u884C\u304D\u5148\n    std::vector<bool> in_cycle;     // in_cycle[u]\
    \ = u \u304C\u30B5\u30A4\u30AF\u30EB\u306B\u542B\u307E\u308C\u308B\n    std::vector<T>\
    \ value;           // \u5404\u30CE\u30FC\u30C9\u306E\u5024\n    std::vector<int>\
    \ component_no;  // \u5404\u30CE\u30FC\u30C9\u306E\u6240\u5C5E\u30B3\u30F3\u30DD\
    \u30FC\u30CD\u30F3\u30C8\u756A\u53F7\n    int num_component = 0;          // \u30B3\
    \u30F3\u30DD\u30FC\u30CD\u30F3\u30C8\u306E\u500B\u6570\n    std::vector<int> cycle_size;\
    \    // \u30B3\u30F3\u30DD\u30FC\u30CD\u30F3\u30C8\u3054\u3068\u306E\u30B5\u30A4\
    \u30AF\u30EB\u306E\u30B5\u30A4\u30BA\n    std::vector<T> cycle_sum;       // \u30B3\
    \u30F3\u30DD\u30FC\u30CD\u30F3\u30C8\u3054\u3068\u306E\u30B5\u30A4\u30AF\u30EB\
    \u306E\u5024\u306E\u5408\u8A08\n\n    explicit FunctionalGraph(const int num_nodes)\
    \ : num_nodes(num_nodes) {\n        this->to.resize(num_nodes, -1);\n        this->in_cycle.resize(num_nodes,\
    \ false);\n        this->value.resize(num_nodes, 0);\n        this->component_no.resize(num_nodes,\
    \ -1);\n    }\n\n    // u -> v\n    void add_directed_edge(const int u, const\
    \ int v) {\n        this->to[u] = v;\n    }\n\n    void set_value(const int u,\
    \ const int x) {\n        this->value[u] = x;\n    }\n\n    void build() {\n \
    \       // \u5404\u30B5\u30A4\u30AF\u30EB\u306B\u5C5E\u3059\u308B\u30CE\u30FC\u30C9\
    \ 1 \u3064 \u3068 \u5404\u30CE\u30FC\u30C9\u306E component no \u3092\u6C42\u3081\
    \u308B\n        {\n            int no = 0;\n            std::vector<bool> seen(this->num_nodes,\
    \ false);\n            for (int u = 0; u < this->num_nodes; ++u) {\n         \
    \       if (component_no[u] == -1) {\n                    this->dfs(u, no++, seen);\n\
    \                }\n            }\n            this->num_component = no;\n   \
    \         this->cycle_size.resize(no);\n            this->cycle_sum.resize(no);\n\
    \        }\n\n        // \u5404\u30B5\u30A4\u30AF\u30EB\u306E\u30B5\u30A4\u30BA\
    \u3068\u30CE\u30FC\u30C9\u306E\u5024\u306E\u5408\u8A08\u3092\u6C42\u3081\u308B\
    \n        std::vector<bool> used(this->num_nodes, false);\n        for (int u\
    \ = 0; u < this->num_nodes; ++u) {\n            // \u30B5\u30A4\u30AF\u30EB\u3092\
    \u307F\u3064\u3051\u305F\u3089\uFF0C\u305D\u3053\u304B\u3089\u5230\u9054\u3067\
    \u304D\u308B\u30CE\u30FC\u30C9\u306B\u5370\u3092\u3064\u3051\u308B\n         \
    \   if (this->in_cycle[u] and not used[u]) {\n                used[u] = true;\n\
    \                const int no = this->component_no[u];\n\n                this->cycle_sum[no]\
    \ += this->value[u];\n                this->cycle_size[no]++;\n\n            \
    \    int v = this->to[u];\n                while (v != u) {\n                \
    \    used[v] = true;\n                    this->cycle_sum[no] += this->value[v];\n\
    \                    this->cycle_size[no]++;\n\n                    this->in_cycle[v]\
    \ = true;\n                    v = this->to[v];\n                }\n         \
    \   }\n        }\n    }\n\nprivate:\n    int dfs(const int u, const int c, std::vector<bool>\
    \ &seen) {\n\n        // \u3059\u3067\u306B\u63A2\u7D22\u6E08\u307F\n        if\
    \ (this->component_no[u] != -1) {\n            return this->component_no[u];\n\
    \        }\n\n        // \u81EA\u5DF1\u30EB\u30FC\u30D7\u3092\u307F\u3064\u3051\
    \u305F\n        if (this->to[u] == u) {\n            this->in_cycle[u] = true;\n\
    \            return this->component_no[u] = c;\n        }\n\n        // \u30EB\
    \u30FC\u30D7\u3092\u307F\u3064\u3051\u305F\n        if (seen[u]) {\n         \
    \   this->in_cycle[u] = true;\n            return this->component_no[u] = c;\n\
    \        }\n\n        seen[u] = true;\n        return this->component_no[u] =\
    \ this->dfs(this->to[u], c, seen);\n    }\n};\n#line 4 \"test/cpp/Graph/FunctionalGraph1_in_cycle.test.cpp\"\
    \n#include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int N;\n    cin >> N;\n\n    FunctionalGraph<int>\
    \ fg(N);\n    for (int i = 0; i < N; ++i) {\n        int A;\n        cin >> A;\n\
    \        fg.add_directed_edge(i, A - 1);\n    }\n    fg.build();\n\n    int ans\
    \ = 0;\n    for (int i = 0; i < N; ++i) {\n        ans += fg.in_cycle[i];\n  \
    \  }\n    cout << ans << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc296/tasks/abc296_e\"\n\n\
    #include \"library/cpp/Graph/FunctionalGraph.hpp\"\n#include <iostream>\n\nusing\
    \ namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N;\n    cin >> N;\n\n    FunctionalGraph<int> fg(N);\n    for (int i\
    \ = 0; i < N; ++i) {\n        int A;\n        cin >> A;\n        fg.add_directed_edge(i,\
    \ A - 1);\n    }\n    fg.build();\n\n    int ans = 0;\n    for (int i = 0; i <\
    \ N; ++i) {\n        ans += fg.in_cycle[i];\n    }\n    cout << ans << endl;\n\
    \n    return 0;\n}"
  dependsOn:
  - library/cpp/Graph/FunctionalGraph.hpp
  isVerificationFile: true
  path: test/cpp/Graph/FunctionalGraph1_in_cycle.test.cpp
  requiredBy: []
  timestamp: '2023-06-05 15:03:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Graph/FunctionalGraph1_in_cycle.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Graph/FunctionalGraph1_in_cycle.test.cpp
- /verify/test/cpp/Graph/FunctionalGraph1_in_cycle.test.cpp.html
title: test/cpp/Graph/FunctionalGraph1_in_cycle.test.cpp
---
