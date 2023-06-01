---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Algorithm/Mo1.test.cpp
    title: test/cpp/Algorithm/Mo1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Algorithm/Mo2.test.cpp
    title: test/cpp/Algorithm/Mo2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Algorithm/Mo.hpp\"\n#include <algorithm>\n#include\
    \ <cmath>\n#include <vector>\n\n// 1 \u56DE\u306E\u4F38\u7E2E\u306E\u8A08\u7B97\
    \u91CF\u304C a \u306E\u3068\u304D O(a * N * sqrt(Q))\ntemplate<class T, T (*add)(int,\
    \ T), T (*del)(int, T)>\nclass Mo {\n    struct Query {\n        int id;\n   \
    \     int left;\n        int right;\n    };\n\npublic:\n    const int num_query;\
    \             // \u30AF\u30A8\u30EA\u306E\u6570\n    std::vector<Query> queries;\
    \      // \u30AF\u30A8\u30EA\n    const int num_bucket;            // \u30D0\u30B1\
    \u30C3\u30C8\u306E\u6570\n\nprivate:\n    int now_left = 0, now_right = 0; //\
    \ \u73FE\u5728\u898B\u3066\u3044\u308B\u533A\u9593[now_left, now_right)\n\npublic:\n\
    \    // n: \u914D\u5217\u306E\u9577\u3055\n    // num_query: \u30AF\u30A8\u30EA\
    \u306E\u500B\u6570\n    // bucket = sqrt(3) * N / sqrt(2 * Q)\n    Mo(const int\
    \ n, const int num_query) : num_query(num_query), queries(num_query), num_bucket(std::max<int>(1,\
    \ (double) n / std::max<double>(1.0, sqrt(num_query * 2.0 / 3.0)))) {}\n\n   \
    \ // [l, r)\n    void add_query(const int id, const int l, const int r) {\n  \
    \      this->queries[id].id = id;\n        this->queries[id].left = l;\n     \
    \   this->queries[id].right = r;\n    }\n\n    std::vector<T> solve() {\n    \
    \    this->sort_queries();\n\n        std::vector<T> ans(this->num_query);\n\n\
    \        T now_ans = 0;\n        for (const auto [id, left, right]: this->queries)\
    \ {\n\n            // [now_left, now_right) \u3092 query\u306E [left, right) \u306B\
    \u306A\u308B\u3088\u3046\u306B\u8ABF\u6574\n            // now_left \u3092\u5DE6\
    \u306B\u305A\u3089\u3059\n            while (left < this->now_left) {\n      \
    \          now_ans = add(--this->now_left, now_ans);\n            }\n        \
    \    // now_right \u3092\u53F3\u306B\u305A\u3089\u3059\n            while (this->now_right\
    \ < right) {\n                now_ans = add(this->now_right++, now_ans);\n   \
    \         }\n            // now_left \u3092\u53F3\u306B\u305A\u3089\u3059\n  \
    \          while (this->now_left < left) {\n                now_ans = del(this->now_left++,\
    \ now_ans);\n            }\n            // now_right \u3092\u5DE6\u306B\u305A\u3089\
    \u3059\n            while (this->now_right > right) {\n                now_ans\
    \ = del(--this->now_right, now_ans);\n            }\n\n            ans[id] = now_ans;\n\
    \        }\n\n        return ans;\n    }\n\nprivate:\n    // \u30AF\u30A8\u30EA\
    \u3092\u30BD\u30FC\u30C8\u3059\u308B\n    void sort_queries() {\n        std::sort(this->queries.begin(),\
    \ this->queries.end(), [&](const Query &l, const Query &r) -> bool {\n       \
    \     const unsigned int left_bucket = l.left / this->num_bucket;     // \u30AF\
    \u30A8\u30EA l \u306E\u6240\u5C5E\u3059\u308B\u30D0\u30B1\u30C3\u30C8\n      \
    \      const unsigned int right_bucket = r.left / this->num_bucket;    // \u30AF\
    \u30A8\u30EA r \u306E\u6240\u5C5E\u3059\u308B\u30D0\u30B1\u30C3\u30C8\n\n    \
    \        // \u30AF\u30A8\u30EA [L, R) \u306E L \u306E\u6240\u5C5E\u3059\u308B\u30D0\
    \u30B1\u30C3\u30C8\u304C\u9055\u3046\u306A\u3089\uFF0CL \u306E\u6240\u5C5E\u3059\
    \u308B\u30D0\u30B1\u30C3\u30C8\u3067\u6BD4\u8F03\n            if (left_bucket\
    \ != right_bucket) {\n                return left_bucket < right_bucket;\n   \
    \         }\n            else {\n                // \u5B9A\u6570\u500D\u9AD8\u901F\
    \u5316\n                // \u5947\u6570\u756A\u76EE\u306E\u30D0\u30B1\u30C3\u30C8\
    \u3060\u3051\u53F3\u306E\u30BD\u30FC\u30C8\u9806\u3092\u9006\u306B\u3057\u3066\
    \uFF0C\u30D0\u30B1\u30C3\u30C8\u3092\u79FB\u52D5\u3057\u305F\u3068\u304D\u306E\
    \ now_right \u3092\u79FB\u52D5\u3059\u308B\u8DDD\u96E2\u3092\u77ED\u304F\u3059\
    \u308B\n                if (left_bucket & 1u) {\n                    return l.right\
    \ < r.right;\n                }\n                else {\n                    return\
    \ l.right > r.right;\n                }\n            }\n        });\n    }\n};\n\
    \n/*\n// \u554F\u984C\u7279\u6709\u306E\u30C7\u30FC\u30BF\nstd::vector<int> A;\n\
    \n// A[idx] \u304C\u8FFD\u52A0\u3055\u308C\u305F\u3068\u304D\u306E\u72B6\u614B\
    \u306E\u5909\u5316\u3068\u7B54\u3048\u3092\u8A08\u7B97\ntemplate<class T>\nT add(const\
    \ int idx, T query_ans) {\n    T diff = 0; // \u7B54\u3048\u306E\u5909\u5316\u91CF\
    \n    {\n        // \u3053\u3053\u306B\u51E6\u7406\u3092\u66F8\u304F\n    }\n\
    \    return query_ans + diff;\n}\n\n// A[idx] \u304C\u524A\u9664\u3055\u308C\u305F\
    \u3068\u304D\u306E\u72B6\u614B\u306E\u5909\u5316\u3068\u7B54\u3048\u3092\u8A08\
    \u7B97\ntemplate<class T>\nT del(const int idx, T query_ans) {\n    T diff = 0;\
    \ // \u7B54\u3048\u306E\u5909\u5316\u91CF\n    {\n        // \u3053\u3053\u306B\
    \u51E6\u7406\u3092\u66F8\u304F\n    }\n    return query_ans + diff;\n}\n*/\n\n\
    /*\n//(\u4F8B) \u533A\u9593 [l, r) \u306E\u7A2E\u985E\u6570\u3092\u30AB\u30A6\u30F3\
    \u30C8\nstd::vector<int> A;\nstd::vector<int> color;\n\n// A[idx] \u304C\u8FFD\
    \u52A0\u3055\u308C\u305F\u3068\u304D\u306E\u72B6\u614B\u306E\u5909\u5316\u3068\
    \u7B54\u3048\u3092\u8A08\u7B97\ntemplate<class T>\nT add(const int idx, T query_ans)\
    \ {\n    color[A[idx]]++;\n    query_ans += (color[A[idx]] == 1);\n    return\
    \ query_ans;\n}\n\n// A[idx] \u304C\u524A\u9664\u3055\u308C\u305F\u3068\u304D\u306E\
    \u72B6\u614B\u306E\u5909\u5316\u3068\u7B54\u3048\u3092\u8A08\u7B97\ntemplate<class\
    \ T>\nT del(const int idx, T query_ans) {\n    color[A[idx]]--;\n    query_ans\
    \ -= (color[A[idx]] == 0);\n    return query_ans;\n}\n*/\n"
  code: "#include <algorithm>\n#include <cmath>\n#include <vector>\n\n// 1 \u56DE\u306E\
    \u4F38\u7E2E\u306E\u8A08\u7B97\u91CF\u304C a \u306E\u3068\u304D O(a * N * sqrt(Q))\n\
    template<class T, T (*add)(int, T), T (*del)(int, T)>\nclass Mo {\n    struct\
    \ Query {\n        int id;\n        int left;\n        int right;\n    };\n\n\
    public:\n    const int num_query;             // \u30AF\u30A8\u30EA\u306E\u6570\
    \n    std::vector<Query> queries;      // \u30AF\u30A8\u30EA\n    const int num_bucket;\
    \            // \u30D0\u30B1\u30C3\u30C8\u306E\u6570\n\nprivate:\n    int now_left\
    \ = 0, now_right = 0; // \u73FE\u5728\u898B\u3066\u3044\u308B\u533A\u9593[now_left,\
    \ now_right)\n\npublic:\n    // n: \u914D\u5217\u306E\u9577\u3055\n    // num_query:\
    \ \u30AF\u30A8\u30EA\u306E\u500B\u6570\n    // bucket = sqrt(3) * N / sqrt(2 *\
    \ Q)\n    Mo(const int n, const int num_query) : num_query(num_query), queries(num_query),\
    \ num_bucket(std::max<int>(1, (double) n / std::max<double>(1.0, sqrt(num_query\
    \ * 2.0 / 3.0)))) {}\n\n    // [l, r)\n    void add_query(const int id, const\
    \ int l, const int r) {\n        this->queries[id].id = id;\n        this->queries[id].left\
    \ = l;\n        this->queries[id].right = r;\n    }\n\n    std::vector<T> solve()\
    \ {\n        this->sort_queries();\n\n        std::vector<T> ans(this->num_query);\n\
    \n        T now_ans = 0;\n        for (const auto [id, left, right]: this->queries)\
    \ {\n\n            // [now_left, now_right) \u3092 query\u306E [left, right) \u306B\
    \u306A\u308B\u3088\u3046\u306B\u8ABF\u6574\n            // now_left \u3092\u5DE6\
    \u306B\u305A\u3089\u3059\n            while (left < this->now_left) {\n      \
    \          now_ans = add(--this->now_left, now_ans);\n            }\n        \
    \    // now_right \u3092\u53F3\u306B\u305A\u3089\u3059\n            while (this->now_right\
    \ < right) {\n                now_ans = add(this->now_right++, now_ans);\n   \
    \         }\n            // now_left \u3092\u53F3\u306B\u305A\u3089\u3059\n  \
    \          while (this->now_left < left) {\n                now_ans = del(this->now_left++,\
    \ now_ans);\n            }\n            // now_right \u3092\u5DE6\u306B\u305A\u3089\
    \u3059\n            while (this->now_right > right) {\n                now_ans\
    \ = del(--this->now_right, now_ans);\n            }\n\n            ans[id] = now_ans;\n\
    \        }\n\n        return ans;\n    }\n\nprivate:\n    // \u30AF\u30A8\u30EA\
    \u3092\u30BD\u30FC\u30C8\u3059\u308B\n    void sort_queries() {\n        std::sort(this->queries.begin(),\
    \ this->queries.end(), [&](const Query &l, const Query &r) -> bool {\n       \
    \     const unsigned int left_bucket = l.left / this->num_bucket;     // \u30AF\
    \u30A8\u30EA l \u306E\u6240\u5C5E\u3059\u308B\u30D0\u30B1\u30C3\u30C8\n      \
    \      const unsigned int right_bucket = r.left / this->num_bucket;    // \u30AF\
    \u30A8\u30EA r \u306E\u6240\u5C5E\u3059\u308B\u30D0\u30B1\u30C3\u30C8\n\n    \
    \        // \u30AF\u30A8\u30EA [L, R) \u306E L \u306E\u6240\u5C5E\u3059\u308B\u30D0\
    \u30B1\u30C3\u30C8\u304C\u9055\u3046\u306A\u3089\uFF0CL \u306E\u6240\u5C5E\u3059\
    \u308B\u30D0\u30B1\u30C3\u30C8\u3067\u6BD4\u8F03\n            if (left_bucket\
    \ != right_bucket) {\n                return left_bucket < right_bucket;\n   \
    \         }\n            else {\n                // \u5B9A\u6570\u500D\u9AD8\u901F\
    \u5316\n                // \u5947\u6570\u756A\u76EE\u306E\u30D0\u30B1\u30C3\u30C8\
    \u3060\u3051\u53F3\u306E\u30BD\u30FC\u30C8\u9806\u3092\u9006\u306B\u3057\u3066\
    \uFF0C\u30D0\u30B1\u30C3\u30C8\u3092\u79FB\u52D5\u3057\u305F\u3068\u304D\u306E\
    \ now_right \u3092\u79FB\u52D5\u3059\u308B\u8DDD\u96E2\u3092\u77ED\u304F\u3059\
    \u308B\n                if (left_bucket & 1u) {\n                    return l.right\
    \ < r.right;\n                }\n                else {\n                    return\
    \ l.right > r.right;\n                }\n            }\n        });\n    }\n};\n\
    \n/*\n// \u554F\u984C\u7279\u6709\u306E\u30C7\u30FC\u30BF\nstd::vector<int> A;\n\
    \n// A[idx] \u304C\u8FFD\u52A0\u3055\u308C\u305F\u3068\u304D\u306E\u72B6\u614B\
    \u306E\u5909\u5316\u3068\u7B54\u3048\u3092\u8A08\u7B97\ntemplate<class T>\nT add(const\
    \ int idx, T query_ans) {\n    T diff = 0; // \u7B54\u3048\u306E\u5909\u5316\u91CF\
    \n    {\n        // \u3053\u3053\u306B\u51E6\u7406\u3092\u66F8\u304F\n    }\n\
    \    return query_ans + diff;\n}\n\n// A[idx] \u304C\u524A\u9664\u3055\u308C\u305F\
    \u3068\u304D\u306E\u72B6\u614B\u306E\u5909\u5316\u3068\u7B54\u3048\u3092\u8A08\
    \u7B97\ntemplate<class T>\nT del(const int idx, T query_ans) {\n    T diff = 0;\
    \ // \u7B54\u3048\u306E\u5909\u5316\u91CF\n    {\n        // \u3053\u3053\u306B\
    \u51E6\u7406\u3092\u66F8\u304F\n    }\n    return query_ans + diff;\n}\n*/\n\n\
    /*\n//(\u4F8B) \u533A\u9593 [l, r) \u306E\u7A2E\u985E\u6570\u3092\u30AB\u30A6\u30F3\
    \u30C8\nstd::vector<int> A;\nstd::vector<int> color;\n\n// A[idx] \u304C\u8FFD\
    \u52A0\u3055\u308C\u305F\u3068\u304D\u306E\u72B6\u614B\u306E\u5909\u5316\u3068\
    \u7B54\u3048\u3092\u8A08\u7B97\ntemplate<class T>\nT add(const int idx, T query_ans)\
    \ {\n    color[A[idx]]++;\n    query_ans += (color[A[idx]] == 1);\n    return\
    \ query_ans;\n}\n\n// A[idx] \u304C\u524A\u9664\u3055\u308C\u305F\u3068\u304D\u306E\
    \u72B6\u614B\u306E\u5909\u5316\u3068\u7B54\u3048\u3092\u8A08\u7B97\ntemplate<class\
    \ T>\nT del(const int idx, T query_ans) {\n    color[A[idx]]--;\n    query_ans\
    \ -= (color[A[idx]] == 0);\n    return query_ans;\n}\n*/"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Algorithm/Mo.hpp
  requiredBy: []
  timestamp: '2023-06-01 19:35:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Algorithm/Mo1.test.cpp
  - test/cpp/Algorithm/Mo2.test.cpp
documentation_of: library/cpp/Algorithm/Mo.hpp
layout: document
redirect_from:
- /library/library/cpp/Algorithm/Mo.hpp
- /library/library/cpp/Algorithm/Mo.hpp.html
title: library/cpp/Algorithm/Mo.hpp
---
