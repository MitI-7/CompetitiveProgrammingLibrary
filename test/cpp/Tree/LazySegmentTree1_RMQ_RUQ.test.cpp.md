---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Tree/LazySegmentTree.hpp
    title: library/cpp/Tree/LazySegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/Tree/LazySegmentTree_template.hpp
    title: library/cpp/Tree/LazySegmentTree_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
  bundledCode: "#line 1 \"test/cpp/Tree/LazySegmentTree1_RMQ_RUQ.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n#line 1 \"library/cpp/Tree/LazySegmentTree.hpp\"\n#include <cassert>\n#include\
    \ <functional>\n#include <numeric>\n#include <vector>\n\ntemplate<typename T>\n\
    T op(const T left_value, const T right_value) {\n    return std::min(left_value,\
    \ right_value);\n}\n\ntemplate<typename T>\nT mapping(const T value, const T lazy_value,\
    \ const int len) {\n    return value + lazy_value;\n}\n\ntemplate<typename T>\n\
    T composition(const T old_lazy_value, const T new_lazy_value) {\n    return old_lazy_value\
    \ + new_lazy_value;\n}\n\ntemplate<typename T>\nT unit() {\n    return std::numeric_limits<T>::max()\
    \ / 3;\n}\n\ntemplate<typename T>\nT lazy_unit() {\n    return 0;\n}\n\ntemplate<typename\
    \ T, T (*op)(T, T), T (*mapping)(T, T, int), T (*composition)(T, T), T (*unit)(),\
    \ T (*lazy_unit)()>\nclass LazySegmentTree {\nprivate:\n    int n;\n    std::vector<T>\
    \ data, lazy;\npublic:\n    LazySegmentTree(const int array_size, const T initial_value)\
    \ : n(1) {\n        while (this->n < array_size) {\n            this->n <<= 1;\n\
    \        }\n        this->data.resize(2 * this->n - 1);\n        this->lazy.resize(2\
    \ * this->n - 1, lazy_unit());\n\n        for (int u = 0; u < array_size; ++u)\
    \ {\n            this->data[this->n - 1 + u] = initial_value;\n        }\n   \
    \     for (int u = this->n - 2; u >= 0; --u) {\n            this->data[u] = op(this->data[u\
    \ * 2 + 1], this->data[u * 2 + 2]);\n        }\n    }\n\n    LazySegmentTree(const\
    \ std::vector<T> &v) : n(1) {\n        while (this->n < (int) v.size()) {\n  \
    \          this->n <<= 1;\n        }\n        this->data.resize(2 * this->n -\
    \ 1);\n        this->lazy.resize(2 * this->n - 1, lazy_unit());\n\n        for\
    \ (int u = 0; u < (int) v.size(); ++u) {\n            this->data[this->n - 1 +\
    \ u] = v[u];\n        }\n        for (int u = this->n - 2; u >= 0; --u) {\n  \
    \          this->data[u] = op(this->data[u * 2 + 1], this->data[u * 2 + 2]);\n\
    \        }\n    }\n\n    // array[idx]\n    // log(N)\n    T access(const int\
    \ idx) {\n        return this->query(idx, idx + 1);\n    }\n\n    // idx \u306B\
    \ x \u3092\u9069\u7528\u3059\u308B\n    // log(N)\n    void operation(const int\
    \ idx, const T x) {\n        this->operation(idx, idx + 1, x);\n    }\n\n    //\
    \ \u533A\u9593 [left, right) \u306B x \u3092\u9069\u7528\u3059\u308B\n    // log(N)\n\
    \    void operation(const int left, const int right, const T x) {\n        if\
    \ (left >= right) {\n            return;\n        }\n        this->operation(left,\
    \ right, x, 0, 0, this->n);\n    }\n\n    // \u533A\u9593 [left, right) \u304B\
    \u3089\u5024\u3092\u6C42\u3081\u308B\n    // log(N)\n    T query(const int left,\
    \ const int right) {\n        return this->query(left, right, 0, 0, this->n);\n\
    \    }\n\nprivate:\n    // \u533A\u9593 [l, r) \u306B x \u3092\u9069\u7528\u3059\
    \u308B\n    // \u30CE\u30FC\u30C9 u \u306F[start, end) \u3092\u30AB\u30D0\u30FC\
    \u3059\u308B\n    T operation(const int l, const int r, const T x, const int u,\
    \ const int start, const int end) {\n        this->propagate(u, end - start);\n\
    \n        // \u7BC4\u56F2\u5916\n        if (r <= start or end <= l) {\n     \
    \       // \u30AF\u30A8\u30EA\u3067\u306F\u306A\u304F\u66F4\u65B0\u306A\u306E\u3067\
    \ unit() \u3067\u306F\u306A\u304F\uFF0Cdata[u] \u3092\u8FD4\u3059\n          \
    \  return this->data[u];\n        }\n\n        // \u5B8C\u5168\u306B\u542B\u3080\
    \n        if (l <= start and end <= r) {\n            this->lazy[u] = composition(this->lazy[u],\
    \ x);\n            this->propagate(u, end - start);\n            return this->data[u]\
    \ = mapping(this->data[u], this->lazy[u], end - start);\n        }\n\n       \
    \ // \u90E8\u5206\u7684\u306B\u542B\u3080\n        const auto m = (start + end)\
    \ / 2;\n        const auto lv = this->operation(l, r, x, 2 * u + 1, start, m);\
    \  // \u5DE6\u306E\u5B50\n        const auto rv = this->operation(l, r, x, 2 *\
    \ u + 2, m, end);    // \u53F3\u306E\u5B50\n        return this->data[u] = op(lv,\
    \ rv);\n    }\n\n    // \u533A\u9593 [l, r) \u304B\u3089\u5024\u3092\u691C\u7D22\
    \u3059\u308B\n    // \u30CE\u30FC\u30C9 u \u306F[start, end) \u3092\u30AB\u30D0\
    \u30FC\u3059\u308B\n    T query(const int l, const int r, const int u, const int\
    \ start, const int end) {\n        this->propagate(u, end - start);\n\n      \
    \  // \u7BC4\u56F2\u5916\n        if (r <= start or end <= l) {\n            return\
    \ unit();\n        }\n\n        // \u5B8C\u5168\u306B\u542B\u3080\n        if\
    \ (l <= start and end <= r) {\n            return this->data[u];\n        }\n\n\
    \        // \u4E00\u90E8\u542B\u3080\n        const auto m = (start + end) / 2;\n\
    \        const auto vl = this->query(l, r, u * 2 + 1, start, m);  // \u5DE6\u306E\
    \u5B50\n        const auto vr = this->query(l, r, u * 2 + 2, m, end);    // \u53F3\
    \u306E\u5B50\n        return op(vl, vr);\n    }\n\n    // u \u306E\u5024\u3092\
    \u66F4\u65B0\u3057\uFF0Cu \u306E\u5B50\u4F9B\u306B\u9045\u5EF6\u60C5\u5831\u3092\
    \u4F1D\u3048\u308B\n    void propagate(const int u, const int len) {\n       \
    \ // \u4F1D\u64AD\u6E08\u307F\n        if (this->lazy[u] == lazy_unit()) {\n \
    \           return;\n        }\n\n        if (len > 1) {\n            this->lazy[u\
    \ * 2 + 1] = composition(this->lazy[u * 2 + 1], this->lazy[u]);\n            this->lazy[u\
    \ * 2 + 2] = composition(this->lazy[u * 2 + 2], this->lazy[u]);\n        }\n \
    \       this->data[u] = mapping(this->data[u], this->lazy[u], len);\n        this->lazy[u]\
    \ = lazy_unit();\n    }\n};\n#line 2 \"library/cpp/Tree/LazySegmentTree_template.hpp\"\
    \n\n// \u533A\u9593\u6700\u5C0F\u5024\uFF0C\u533A\u9593\u52A0\u7B97\ntemplate<typename\
    \ T>\nT range_minimum_query_range_add_operation_op(const T left_value, const T\
    \ right_value) {\n    return std::min(left_value, right_value);\n}\n\ntemplate<typename\
    \ T>\nT range_minimum_query_range_add_operation_mapping(const T value, const T\
    \ lazy_value, const int len) {\n    return value + lazy_value;\n}\n\ntemplate<typename\
    \ T>\nT range_minimum_query_range_add_operation_composition(const T old_lazy_value,\
    \ const T new_lazy_value) {\n    return old_lazy_value + new_lazy_value;\n}\n\n\
    template<typename T>\nT range_minimum_query_range_add_operation_unit() {\n   \
    \ return std::numeric_limits<T>::max() / 3;\n}\n\ntemplate<typename T>\nT range_minimum_query_range_add_operation_lazy_unit()\
    \ {\n    return 0;\n}\n\ntemplate<typename T>\nauto make_range_minimum_query_range_add_operation(const\
    \ int n, const T initial_value) {\n    return LazySegmentTree<T,\n           \
    \ range_minimum_query_range_add_operation_op,\n            range_minimum_query_range_add_operation_mapping,\n\
    \            range_minimum_query_range_add_operation_composition,\n          \
    \  range_minimum_query_range_add_operation_unit,\n            range_minimum_query_range_add_operation_lazy_unit>(n,\
    \ initial_value);\n}\n\n// \u533A\u9593\u6700\u5C0F\u5024\uFF0C\u533A\u9593\u66F4\
    \u65B0\ntemplate<typename T>\nT range_minimum_query_range_update_operation_unit()\
    \ {\n    return std::numeric_limits<T>::max() / 3;\n}\n\ntemplate<typename T>\n\
    T range_minimum_query_range_update_operation_lazy_unit() {\n    return -1;\n}\n\
    \ntemplate<typename T>\nT range_minimum_query_range_update_operation_op(const\
    \ T left_value, const T right_value) {\n    return std::min(left_value, right_value);\n\
    }\n\ntemplate<typename T>\nT range_minimum_query_range_update_operation_mapping(const\
    \ T value, const T lazy_value, const int len) {\n    if (lazy_value == range_minimum_query_range_update_operation_lazy_unit<T>())\
    \ {\n        return value;\n    }\n    return lazy_value;\n}\n\ntemplate<typename\
    \ T>\nT range_minimum_query_range_update_operation_composition(const T old_lazy_value,\
    \ const T new_lazy_value) {\n    if (new_lazy_value == range_minimum_query_range_update_operation_lazy_unit<T>())\
    \ {\n        return old_lazy_value;\n    }\n    return new_lazy_value;\n}\n\n\
    template<typename T>\nauto make_range_minimum_query_range_update_operation(const\
    \ int n, const T initial_value) {\n    return LazySegmentTree<T,\n           \
    \ range_minimum_query_range_update_operation_op,\n            range_minimum_query_range_update_operation_mapping,\n\
    \            range_minimum_query_range_update_operation_composition,\n       \
    \     range_minimum_query_range_update_operation_unit,\n            range_minimum_query_range_update_operation_lazy_unit>(n,\
    \ initial_value);\n}\n\n\n// \u533A\u9593\u5408\u8A08\uFF0C\u533A\u9593\u52A0\u7B97\
    \ntemplate<typename T>\nT range_sum_query_range_add_operation_op(const T left_value,\
    \ const T right_value) {\n    return left_value + right_value;\n}\n\ntemplate<typename\
    \ T>\nT range_sum_query_range_add_operation_mapping(const T value, const T lazy_value,\
    \ const int len) {\n    return value + lazy_value * len;\n}\n\ntemplate<typename\
    \ T>\nT range_sum_query_range_add_operation_composition(const T old_lazy_value,\
    \ const T new_lazy_value) {\n    return old_lazy_value + new_lazy_value;\n}\n\n\
    template<typename T>\nT range_sum_query_range_add_operation_unit() {\n    return\
    \ 0;\n}\n\ntemplate<typename T>\nT range_sum_query_range_add_operation_lazy_unit()\
    \ {\n    return 0;\n}\n\ntemplate<typename T>\nauto make_range_sum_query_range_add_operation(const\
    \ int n, const T initial_value) {\n    return LazySegmentTree<T,\n           \
    \ range_sum_query_range_add_operation_op,\n            range_sum_query_range_add_operation_mapping,\n\
    \            range_sum_query_range_add_operation_composition,\n            range_sum_query_range_add_operation_unit,\n\
    \            range_sum_query_range_add_operation_lazy_unit>(n, initial_value);\n\
    }\n\n\n// \u533A\u9593\u5408\u8A08\uFF0C\u533A\u9593\u66F4\u65B0\ntemplate<typename\
    \ T>\nT range_sum_query_range_update_operation_unit() {\n    return 0;\n}\n\n\
    template<typename T>\nT range_sum_query_range_update_operation_lazy_unit() {\n\
    \    return std::numeric_limits<T>::max() / 3;\n}\n\ntemplate<typename T>\nT range_sum_query_range_update_operation_op(const\
    \ T left_value, const T right_value) {\n    return left_value + right_value;\n\
    }\n\ntemplate<typename T>\nT range_sum_query_range_update_operation_mapping(const\
    \ T value, const T lazy_value, const int len) {\n    if (lazy_value == range_sum_query_range_update_operation_lazy_unit<T>())\
    \ {\n        return value;\n    }\n    return lazy_value * len;\n}\n\ntemplate<typename\
    \ T>\nT range_sum_query_range_update_operation_composition(const T old_lazy_value,\
    \ const T new_lazy_value) {\n    if (new_lazy_value == range_sum_query_range_update_operation_lazy_unit<T>())\
    \ {\n        return old_lazy_value;\n    }\n    return new_lazy_value;\n}\n\n\
    template<typename T>\nauto make_range_sum_query_range_update_operation(const int\
    \ n, const T initial_value) {\n    return LazySegmentTree<T,\n            range_sum_query_range_update_operation_op,\n\
    \            range_sum_query_range_update_operation_mapping,\n            range_sum_query_range_update_operation_composition,\n\
    \            range_sum_query_range_update_operation_unit,\n            range_sum_query_range_update_operation_lazy_unit>(n,\
    \ initial_value);\n}\n\ntemplate<typename T>\nauto make_range_sum_query_range_update_operation(const\
    \ std::vector<T> &v) {\n    return LazySegmentTree<T,\n            range_sum_query_range_update_operation_op,\n\
    \            range_sum_query_range_update_operation_mapping,\n            range_sum_query_range_update_operation_composition,\n\
    \            range_sum_query_range_update_operation_unit,\n            range_sum_query_range_update_operation_lazy_unit>(v);\n\
    }\n\n\n\n/*\ntemplate<typename T>\nMode <T> range_minimum_query_update() {\n \
    \   const T lazy_unit = -1;\n    return Mode < T > {\n            [](T a, T b)\
    \ { return std::min(a, b); },\n            [=](T a, T b) { return b == lazy_unit\
    \ ? a : b; },\n            [=](T a, T b) { return b == lazy_unit ? a : b; },\n\
    \            [=](T a, int len) { return a; },\n            std::numeric_limits<T>::max()\
    \ / 3,\n            lazy_unit,\n    };\n}\n\ntemplate<typename T>\nMode <T> range_minimum_query_add()\
    \ {\n    return Mode < T > {\n            [](T a, T b) { return std::min(a, b);\
    \ },\n            [](T a, T b) { return a + b; },\n            [](T a, T b) {\
    \ return a + b; },\n            [](T a, int len) { return a; },\n            std::numeric_limits<T>::max()\
    \ / 3,\n            0,\n    };\n}\n\ntemplate<typename T>\nMode <T> range_maximum_query_update()\
    \ {\n    const T lazy_unit = -1;\n    return Mode < T > {\n            [](T a,\
    \ T b) { return std::max(a, b); },\n            [=](T a, T b) { return b == lazy_unit\
    \ ? a : b; },\n            [=](T a, T b) { return b == lazy_unit ? a : b; },\n\
    \            [](T a, int len) { return a; },\n            std::numeric_limits<T>::min()\
    \ / 3,\n            lazy_unit,\n    };\n}\n\ntemplate<typename T>\nMode <T> range_maximum_query_add()\
    \ {\n    return Mode < T > {\n            [](T a, T b) { return std::max(a, b);\
    \ },\n            [](T a, T b) { return a + b; },\n            [](T a, T b) {\
    \ return a + b; },\n            [](T a, int len) { return a; },\n            std::numeric_limits<T>::min()\
    \ / 3,\n            0,\n    };\n}\n\ntemplate<typename T>\nMode <T> range_summation_query_update()\
    \ {\n    const T lazy_unit = std::numeric_limits<T>::max() / 3;\n    return Mode\
    \ < T > {\n            [](T a, T b) { return a + b; },\n            [=](T a, T\
    \ b) { return b == lazy_unit ? a : b; },\n            [=](T a, T b) { return b\
    \ == lazy_unit ? a : b; },\n            [=](T a, int len) { return a == lazy_unit\
    \ ? a : a * len; },\n            0,\n            lazy_unit,\n    };\n}\n\ntemplate<typename\
    \ T>\nMode <T> range_summation_query_add() {\n    return Mode < T > {\n      \
    \      [](T a, T b) { return a + b; },\n            [](T a, T b) { return a +\
    \ b; },\n            [](T a, T b) { return a + b; },\n            [](T a, int\
    \ len) { return a * len; },\n            0,\n            0,\n    };\n}\n\n// \u533A\
    \u9593min\u66F4\u65B0\ntemplate<typename T>\nT &chmin(T &a, const T &b) { return\
    \ a = std::min(a, b); }\n\ntemplate<typename T>\nMode <T> range_minimum_query_min()\
    \ {\n    return Mode < T > {\n            [](T a, T b) { return std::min(a, b);\
    \ },\n            [](T a, T b) { return chmin(a, b); },\n            [](T a, T\
    \ b) { return chmin(a, b); },\n            [](T a, int len) { return a; },\n \
    \           std::numeric_limits<T>::max() / 3,\n            std::numeric_limits<T>::max()\
    \ / 3,\n    };\n}\n*/\n#line 4 \"test/cpp/Tree/LazySegmentTree1_RMQ_RUQ.test.cpp\"\
    \n#include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int N, Q;\n    cin >> N >> Q;\n\n   \
    \ auto lst = make_range_minimum_query_range_update_operation(N, (1ull << 31u)\
    \ - 1);\n    for (int i = 0; i < Q; ++i) {\n        int TYPE;\n        cin >>\
    \ TYPE;\n        if (TYPE == 0) {\n            int S, T, X;\n            cin >>\
    \ S >> T >> X;\n            lst.operation(S, T + 1, X);\n        } else {\n  \
    \          int S, T;\n            cin >> S >> T;\n            cout << lst.query(S,\
    \ T + 1) << endl;\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n#include \"library/cpp/Tree/LazySegmentTree_template.hpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n\n    auto lst = make_range_minimum_query_range_update_operation(N,\
    \ (1ull << 31u) - 1);\n    for (int i = 0; i < Q; ++i) {\n        int TYPE;\n\
    \        cin >> TYPE;\n        if (TYPE == 0) {\n            int S, T, X;\n  \
    \          cin >> S >> T >> X;\n            lst.operation(S, T + 1, X);\n    \
    \    } else {\n            int S, T;\n            cin >> S >> T;\n           \
    \ cout << lst.query(S, T + 1) << endl;\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Tree/LazySegmentTree_template.hpp
  - library/cpp/Tree/LazySegmentTree.hpp
  isVerificationFile: true
  path: test/cpp/Tree/LazySegmentTree1_RMQ_RUQ.test.cpp
  requiredBy: []
  timestamp: '2024-03-09 23:46:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Tree/LazySegmentTree1_RMQ_RUQ.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Tree/LazySegmentTree1_RMQ_RUQ.test.cpp
- /verify/test/cpp/Tree/LazySegmentTree1_RMQ_RUQ.test.cpp.html
title: test/cpp/Tree/LazySegmentTree1_RMQ_RUQ.test.cpp
---
