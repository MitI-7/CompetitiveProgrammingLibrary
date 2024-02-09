---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Tree/ReRooting1.test.cpp
    title: test/cpp/Tree/ReRooting1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Tree/ReRooting2.test.cpp
    title: test/cpp/Tree/ReRooting2.test.cpp
  - icon: ':x:'
    path: test/cpp/Tree/ReRooting3.test.cpp
    title: test/cpp/Tree/ReRooting3.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Tree/ReRooting.hpp\"\n#include <cassert>\n#include\
    \ <functional>\n#include <stack>\n#include <vector>\n\ntemplate<typename W>\n\
    class Edge {\npublic:\n    int to;\n    W w;\n    int rev;\n    int no;\n\n  \
    \  Edge() : to(-1), w(-1), rev(-1), no(-1) {}\n\n    Edge(int to, W w, int rev,\
    \ int no = -1) : to(to), w(w), rev(rev), no(no) {\n    }\n};\n\n// \u30E2\u30CE\
    \u30A4\u30C9\u3092\u4E57\u305B\u308B\u3053\u3068\u304C\u3067\u304D\u308B\n// \u7D50\
    \u5408\u5247: a * (b * c) = (a * b) * c\n// \u5358\u4F4D\u5143: e * a = a * e\
    \ = a\ntemplate<class T, typename W, T (*marge)(T, T), T (*add_node)(T, int),\
    \ T (*add_edge)(T, Edge<W>), T (*unit)()>\nclass ReRooting {\npublic:\n    const\
    \ int num_nodes;\n\nprivate:\n    std::vector<std::vector<Edge<W>>> graph;\n\n\
    \    std::vector<std::vector<T>> dp; // dp[u][i] = \u9802\u70B9 u \u306E i \u756A\
    \u76EE\u306E\u5B50\u4F9B\u3092\u90E8\u5206\u6728\u306E\u6839\u3068\u3057\u305F\
    \u7B54\u3048\n    std::vector<T> ans;\n\n    bool initialized;\npublic:\n    explicit\
    \ ReRooting(const int num_nodes) : num_nodes(num_nodes), graph(num_nodes), dp(num_nodes),\
    \ ans(num_nodes), initialized(false) {\n\n    }\n\n    void add_undirected_edge(const\
    \ int u, const int v, const W w = 1) {\n        assert(not this->initialized);\n\
    \        assert(u != v);\n        const int rev_u = this->graph[v].size();\n \
    \       const int rev_v = this->graph[u].size();\n        this->graph[u].emplace_back(Edge(v,\
    \ w, rev_u));\n        this->graph[v].emplace_back(Edge(u, w, rev_v));\n    }\n\
    \n    T query(const int u) const {\n        assert(this->initialized);\n     \
    \   assert(0 <= u and u < this->num_nodes);\n        return this->ans[u];\n  \
    \  }\n\n    void build() {\n        this->initialized = true;\n\n        for (int\
    \ i = 0; i < (int) this->graph.size(); i++) {\n            this->dp[i].resize(this->graph[i].size());\n\
    \        }\n\n        // \u9802\u70B9\u304C 1 \u500B\u3057\u306A\u304B\u306A\u3044\
    \n        if (this->num_nodes == 1) {\n            this->ans[0] = add_node(unit(),\
    \ 0);\n            return;\n        }\n\n        std::vector<int> parents(num_nodes);\n\
    \        std::vector<int> order;\n\n        // \u9802\u70B9 0 \u3092\u6839\u3068\
    \u3057\u305F dfs \u9806\u3068\u5404\u30CE\u30FC\u30C9\u306E\u89AA\u3092\u6C42\u3081\
    \u308B\n        {\n            std::stack<int> stack;\n            stack.push(0);\n\
    \            parents[0] = -1;\n            while (not stack.empty()) {\n     \
    \           const auto u = stack.top();\n                stack.pop();\n      \
    \          order.emplace_back(u);\n                for (const auto e: this->graph[u])\
    \ {\n                    if (e.to == parents[u]) {\n                        continue;\n\
    \                    }\n                    stack.push(e.to);\n              \
    \      parents[e.to] = u;\n                }\n            }\n        }\n\n   \
    \     // \u8449\u304B\u3089\u6839\u3078\u90E8\u5206\u6728\u306E\u5024\u3092\u6C42\
    \u3081\u3066\u3044\u304F\n        for (int i = (int) order.size() - 1; i >= 1;\
    \ --i) {\n            const auto u = order[i];\n            const auto parent\
    \ = parents[u];\n\n            // u \u306E\u5B50\u4F9B\u9054\u306E\u7D50\u679C\
    \u3092\u307E\u3068\u3081\u308B\n            T accum = unit();\n            int\
    \ rev = -1;\n            for (int j = 0; j < (int) this->graph[u].size(); ++j)\
    \ {\n                const auto &edge = this->graph[u][j];\n                if\
    \ (edge.to == parent) {\n                    rev = edge.rev;\n               \
    \     continue;\n                }\n                accum = marge(accum, add_edge(this->dp[u][j],\
    \ edge));\n            }\n            assert(rev != -1);\n\n            // u \u3092\
    \u90E8\u5206\u6728\u306E\u6839\u3068\u3057\u305F\u3068\u304D\u306E\u7B54\u3048\
    \u3092\u6C42\u3081\u308B\n            this->dp[parent][rev] = add_node(accum,\
    \ u);\n            assert(this->graph[parent][rev].to == u);\n        }\n\n  \
    \      // u \u3092\u6728\u306E\u6839\u3068\u3057\u305F\u3068\u304D\u306E\u5024\
    \u3092\u6C42\u3081\u308B\n        for (const auto u: order) {\n\n            //\
    \ \u53F3\u308D\u304B\u3089\u306E\u7D2F\u7A4D\u548C\u3092\u6C42\u3081\u308B(dp[u]\
    \ \u306E\u5148\u982D\u306F\u5165\u3063\u3066\u3044\u306A\u3044)\n            std::vector<T>\
    \ accums_left(this->graph[u].size());\n            accums_left[accums_left.size()\
    \ - 1] = unit();\n            for (int j = (int) accums_left.size() - 1; j >=\
    \ 1; --j) {\n                const auto &edge = this->graph[u][j];\n         \
    \       auto val = add_edge(this->dp[u][j], edge);\n                accums_left[j\
    \ - 1] = marge(val, accums_left[j]);\n            }\n\n            // \u5DE6\u304B\
    \u3089\u306E\u7D2F\u7A4D\u548C\u3092\u6C42\u3081\u308B\n            T accum =\
    \ unit();\n            for (int j = 0; j < (int) accums_left.size(); j++) {\n\
    \                const auto &edge = graph[u][j];\n                // j \u304C\u5165\
    \u3063\u3066\u3044\u306A\u3044\n                this->dp[edge.to][edge.rev] =\
    \ add_node(marge(accum, accums_left[j]), u);\n                const auto val =\
    \ add_edge(this->dp[u][j], edge);\n                accum = marge(accum, val);\n\
    \            }\n\n            this->ans[u] = add_node(accum, u);\n        }\n\
    \    }\n};\n\n/*\n// \u7D2F\u7A4D accum \u3068 t \u3092\u7D50\u5408\u3059\u308B\
    \u95A2\u6570\n// \uFF08\u5B50\u4F9B\u9054\u306E\u7D50\u5408\u306E\u307F\u8003\u616E\
    \u3057\uFF0C\u89AA\u306B\u7D50\u5408\u3059\u308B\u3068\u304D\u306E\u3053\u3068\
    \u306F\u8003\u3048\u306A\u3044\u3053\u3068\u306B\u6CE8\u610F\uFF09\ntemplate<typename\
    \ T>\nT merge(const T accum, const T t) {\n    return max(accum, t);\n}\n\n//\
    \ \u5B50\u4F9B\u9054\u306E\u7D50\u679C\u3068\u9802\u70B9 u \u3092\u7D50\u5408\u3059\
    \u308B\u95A2\u6570\ntemplate<typename T>\nT add_node(const T accum, const int\
    \ u) {\n    return accum;\n}\n\n// \u7D50\u679C t \u306B \u8FBA e \u3092\u5F71\
    \u97FF\u3055\u305B\u308B\ntemplate<typename T, typename W>\nT add_edge(const T\
    \ t, Edge<W> e) {\n    return t + e.w;\n}\n\n// \u5358\u4F4D\u5143\ntemplate<typename\
    \ T>\nT unit() {\n    return 0;\n}\n\nReRooting<int, int, merge, add_node, add_edge,\
    \ unit> rr(N);\n */\n"
  code: "#include <cassert>\n#include <functional>\n#include <stack>\n#include <vector>\n\
    \ntemplate<typename W>\nclass Edge {\npublic:\n    int to;\n    W w;\n    int\
    \ rev;\n    int no;\n\n    Edge() : to(-1), w(-1), rev(-1), no(-1) {}\n\n    Edge(int\
    \ to, W w, int rev, int no = -1) : to(to), w(w), rev(rev), no(no) {\n    }\n};\n\
    \n// \u30E2\u30CE\u30A4\u30C9\u3092\u4E57\u305B\u308B\u3053\u3068\u304C\u3067\u304D\
    \u308B\n// \u7D50\u5408\u5247: a * (b * c) = (a * b) * c\n// \u5358\u4F4D\u5143\
    : e * a = a * e = a\ntemplate<class T, typename W, T (*marge)(T, T), T (*add_node)(T,\
    \ int), T (*add_edge)(T, Edge<W>), T (*unit)()>\nclass ReRooting {\npublic:\n\
    \    const int num_nodes;\n\nprivate:\n    std::vector<std::vector<Edge<W>>> graph;\n\
    \n    std::vector<std::vector<T>> dp; // dp[u][i] = \u9802\u70B9 u \u306E i \u756A\
    \u76EE\u306E\u5B50\u4F9B\u3092\u90E8\u5206\u6728\u306E\u6839\u3068\u3057\u305F\
    \u7B54\u3048\n    std::vector<T> ans;\n\n    bool initialized;\npublic:\n    explicit\
    \ ReRooting(const int num_nodes) : num_nodes(num_nodes), graph(num_nodes), dp(num_nodes),\
    \ ans(num_nodes), initialized(false) {\n\n    }\n\n    void add_undirected_edge(const\
    \ int u, const int v, const W w = 1) {\n        assert(not this->initialized);\n\
    \        assert(u != v);\n        const int rev_u = this->graph[v].size();\n \
    \       const int rev_v = this->graph[u].size();\n        this->graph[u].emplace_back(Edge(v,\
    \ w, rev_u));\n        this->graph[v].emplace_back(Edge(u, w, rev_v));\n    }\n\
    \n    T query(const int u) const {\n        assert(this->initialized);\n     \
    \   assert(0 <= u and u < this->num_nodes);\n        return this->ans[u];\n  \
    \  }\n\n    void build() {\n        this->initialized = true;\n\n        for (int\
    \ i = 0; i < (int) this->graph.size(); i++) {\n            this->dp[i].resize(this->graph[i].size());\n\
    \        }\n\n        // \u9802\u70B9\u304C 1 \u500B\u3057\u306A\u304B\u306A\u3044\
    \n        if (this->num_nodes == 1) {\n            this->ans[0] = add_node(unit(),\
    \ 0);\n            return;\n        }\n\n        std::vector<int> parents(num_nodes);\n\
    \        std::vector<int> order;\n\n        // \u9802\u70B9 0 \u3092\u6839\u3068\
    \u3057\u305F dfs \u9806\u3068\u5404\u30CE\u30FC\u30C9\u306E\u89AA\u3092\u6C42\u3081\
    \u308B\n        {\n            std::stack<int> stack;\n            stack.push(0);\n\
    \            parents[0] = -1;\n            while (not stack.empty()) {\n     \
    \           const auto u = stack.top();\n                stack.pop();\n      \
    \          order.emplace_back(u);\n                for (const auto e: this->graph[u])\
    \ {\n                    if (e.to == parents[u]) {\n                        continue;\n\
    \                    }\n                    stack.push(e.to);\n              \
    \      parents[e.to] = u;\n                }\n            }\n        }\n\n   \
    \     // \u8449\u304B\u3089\u6839\u3078\u90E8\u5206\u6728\u306E\u5024\u3092\u6C42\
    \u3081\u3066\u3044\u304F\n        for (int i = (int) order.size() - 1; i >= 1;\
    \ --i) {\n            const auto u = order[i];\n            const auto parent\
    \ = parents[u];\n\n            // u \u306E\u5B50\u4F9B\u9054\u306E\u7D50\u679C\
    \u3092\u307E\u3068\u3081\u308B\n            T accum = unit();\n            int\
    \ rev = -1;\n            for (int j = 0; j < (int) this->graph[u].size(); ++j)\
    \ {\n                const auto &edge = this->graph[u][j];\n                if\
    \ (edge.to == parent) {\n                    rev = edge.rev;\n               \
    \     continue;\n                }\n                accum = marge(accum, add_edge(this->dp[u][j],\
    \ edge));\n            }\n            assert(rev != -1);\n\n            // u \u3092\
    \u90E8\u5206\u6728\u306E\u6839\u3068\u3057\u305F\u3068\u304D\u306E\u7B54\u3048\
    \u3092\u6C42\u3081\u308B\n            this->dp[parent][rev] = add_node(accum,\
    \ u);\n            assert(this->graph[parent][rev].to == u);\n        }\n\n  \
    \      // u \u3092\u6728\u306E\u6839\u3068\u3057\u305F\u3068\u304D\u306E\u5024\
    \u3092\u6C42\u3081\u308B\n        for (const auto u: order) {\n\n            //\
    \ \u53F3\u308D\u304B\u3089\u306E\u7D2F\u7A4D\u548C\u3092\u6C42\u3081\u308B(dp[u]\
    \ \u306E\u5148\u982D\u306F\u5165\u3063\u3066\u3044\u306A\u3044)\n            std::vector<T>\
    \ accums_left(this->graph[u].size());\n            accums_left[accums_left.size()\
    \ - 1] = unit();\n            for (int j = (int) accums_left.size() - 1; j >=\
    \ 1; --j) {\n                const auto &edge = this->graph[u][j];\n         \
    \       auto val = add_edge(this->dp[u][j], edge);\n                accums_left[j\
    \ - 1] = marge(val, accums_left[j]);\n            }\n\n            // \u5DE6\u304B\
    \u3089\u306E\u7D2F\u7A4D\u548C\u3092\u6C42\u3081\u308B\n            T accum =\
    \ unit();\n            for (int j = 0; j < (int) accums_left.size(); j++) {\n\
    \                const auto &edge = graph[u][j];\n                // j \u304C\u5165\
    \u3063\u3066\u3044\u306A\u3044\n                this->dp[edge.to][edge.rev] =\
    \ add_node(marge(accum, accums_left[j]), u);\n                const auto val =\
    \ add_edge(this->dp[u][j], edge);\n                accum = marge(accum, val);\n\
    \            }\n\n            this->ans[u] = add_node(accum, u);\n        }\n\
    \    }\n};\n\n/*\n// \u7D2F\u7A4D accum \u3068 t \u3092\u7D50\u5408\u3059\u308B\
    \u95A2\u6570\n// \uFF08\u5B50\u4F9B\u9054\u306E\u7D50\u5408\u306E\u307F\u8003\u616E\
    \u3057\uFF0C\u89AA\u306B\u7D50\u5408\u3059\u308B\u3068\u304D\u306E\u3053\u3068\
    \u306F\u8003\u3048\u306A\u3044\u3053\u3068\u306B\u6CE8\u610F\uFF09\ntemplate<typename\
    \ T>\nT merge(const T accum, const T t) {\n    return max(accum, t);\n}\n\n//\
    \ \u5B50\u4F9B\u9054\u306E\u7D50\u679C\u3068\u9802\u70B9 u \u3092\u7D50\u5408\u3059\
    \u308B\u95A2\u6570\ntemplate<typename T>\nT add_node(const T accum, const int\
    \ u) {\n    return accum;\n}\n\n// \u7D50\u679C t \u306B \u8FBA e \u3092\u5F71\
    \u97FF\u3055\u305B\u308B\ntemplate<typename T, typename W>\nT add_edge(const T\
    \ t, Edge<W> e) {\n    return t + e.w;\n}\n\n// \u5358\u4F4D\u5143\ntemplate<typename\
    \ T>\nT unit() {\n    return 0;\n}\n\nReRooting<int, int, merge, add_node, add_edge,\
    \ unit> rr(N);\n */"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Tree/ReRooting.hpp
  requiredBy: []
  timestamp: '2024-02-05 18:56:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/cpp/Tree/ReRooting1.test.cpp
  - test/cpp/Tree/ReRooting3.test.cpp
  - test/cpp/Tree/ReRooting2.test.cpp
documentation_of: library/cpp/Tree/ReRooting.hpp
layout: document
redirect_from:
- /library/library/cpp/Tree/ReRooting.hpp
- /library/library/cpp/Tree/ReRooting.hpp.html
title: library/cpp/Tree/ReRooting.hpp
---
