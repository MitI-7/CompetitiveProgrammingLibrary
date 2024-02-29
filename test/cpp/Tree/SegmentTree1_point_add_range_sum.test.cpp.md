---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Tree/SegmentTree.hpp
    title: library/cpp/Tree/SegmentTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/cpp/Tree/SegmentTree1_point_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#line 1 \"library/cpp/Tree/SegmentTree.hpp\"\n#include <cassert>\n#include\
    \ <cstdint>\n#include <functional>\n#include <numeric>\n#include <tuple>\n#include\
    \ <vector>\n\n// \u30E2\u30CE\u30A4\u30C9\u3092\u4E57\u305B\u308B\u3053\u3068\u304C\
    \u3067\u304D\u308B\n// \u7D50\u5408\u5247: a * (b * c) = (a * b) * c\n// \u5358\
    \u4F4D\u5143: e * a = a * e = a\n// \u3059\u3079\u3066 0-origin\ntemplate<class\
    \ T, T (*op)(T, T), T (*unit)()>\nclass SegmentTree {\n    const int array_size;\
    \       // \u3082\u3068\u306E\u914D\u5217\u306E\u30B5\u30A4\u30BA\n    int n;\
    \                      // \u30BB\u30B0\u6728\u3067\u4F7F\u3046\u914D\u5217\u306E\
    \u30B5\u30A4\u30BA\n    std::vector<T> data;\n\npublic:\n    SegmentTree(int array_size)\
    \ : array_size(array_size), n(1) {\n        // n \u306F array_size \u4EE5\u4E0A\
    \u306E\u6700\u5C0F\u306E 2 \u51AA\n        while (this->n < array_size) {\n  \
    \          this->n <<= 1;\n        }\n        this->data.resize(2 * this->n -\
    \ 1, unit());\n    }\n\n    T access(const int idx) const {\n        return this->data[idx\
    \ + this->n - 1];\n    }\n\n    // array[idx] = x\n    // O(log N)\n    void update(int\
    \ idx, const T x) {\n        assert(0 <= idx and idx < this->array_size);\n  \
    \      idx += this->n - 1;   // \u6728\u3067\u306E\u5BFE\u8C61\u306E\u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\n        this->data[idx] = x;\n        while (idx > 0)\
    \ {\n            idx = (idx - 1) / 2;                                        \
    \              // \u89AA\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n         \
    \   this->data[idx] = op(this->data[idx * 2 + 1], this->data[idx * 2 + 2]);  \
    \ // \u5DE6\u306E\u5B50\u3068\u53F3\u306E\u5B50\n        }\n    }\n\n    // op(array[left,\
    \ right))\n    // O(log N)\n    T query(const int left, const int right) const\
    \ {\n        assert(0 <= left and left < right and right <= this->array_size);\n\
    \        return query(left, right, 0, 0, this->n);\n    }\n\nprivate:\n    //\
    \ \u533A\u9593 [l, r)\u306E\u5024\u3092\u30CE\u30FC\u30C9 u \u304B\u3089\u691C\
    \u7D22\n    // \u30CE\u30FC\u30C9 u \u306F[start, end) \u3092\u30AB\u30D0\u30FC\
    \u3059\u308B\n    T query(const int l, const int r, const int u, const int start,\
    \ const int end) const {\n        assert(l < r && start < end);\n        // \u7BC4\
    \u56F2\u5916\n        if (end <= l or r <= start) {\n            return unit();\n\
    \        }\n\n        // \u5B8C\u5168\u306B\u542B\u3080\n        if (l <= start\
    \ and end <= r) {\n            return this->data[u];\n        } else {\n     \
    \       const int m = (start + end) / 2;\n            auto vl = query(l, r, u\
    \ * 2 + 1, start, m);  // \u5DE6\u306E\u5B50\n            auto vr = query(l, r,\
    \ u * 2 + 2, m, end);    // \u53F3\u306E\u5B50\n            return op(vl, vr);\n\
    \        }\n    }\n};\n\n\n// range minimum query\ntemplate<typename T>\nT min_op(T\
    \ a, T b) {\n    return std::min(a, b);\n}\n\ntemplate<typename T>\nT min_unit()\
    \ {\n    return std::numeric_limits<T>::max();\n}\n\ntemplate<typename T>\nSegmentTree<T,\
    \ min_op, min_unit> make_segment_tree_min(const int n) {\n    return SegmentTree<T,\
    \ min_op, min_unit>(n);\n}\n\n// range maximum query\ntemplate<typename T>\nT\
    \ max_op(T a, T b) {\n    return std::max(a, b);\n}\n\ntemplate<typename T>\n\
    T max_unit() {\n    return 0;\n}\n\ntemplate<typename T>\nSegmentTree<T, min_op,\
    \ min_unit> make_segment_tree_max(const int n) {\n    return SegmentTree<T, max_op,\
    \ max_unit>(n);\n}\n\n// range summation query\ntemplate<typename T>\nT sum_op(T\
    \ a, T b) {\n    return a + b;\n}\n\ntemplate<typename T>\nT sum_unit() {\n  \
    \  return 0;\n}\n\ntemplate<typename T>\nSegmentTree<T, sum_op, sum_unit> make_segment_tree_sum(const\
    \ int n) {\n    return SegmentTree<T, sum_op, sum_unit>(n);\n}\n\n// range xor\
    \ query\ntemplate<typename T>\nT xor_op(T a, T b) {\n    return a ^ b;\n}\n\n\
    template<typename T>\nT xor_unit() {\n    return 0;\n}\n\ntemplate<typename T>\n\
    SegmentTree<T, xor_op, xor_unit> make_segment_tree_xor(const int n) {\n    return\
    \ SegmentTree<T, xor_op, xor_unit>(n);\n}\n\n// Rolling Hash query\nconst int\
    \ P = 998244353;\nconst long long base = 129;\n\nstd::tuple<uint_fast64_t, long\
    \ long, int>\nrh_op(std::tuple<uint_fast64_t, long long, int> a, std::tuple<uint_fast64_t,\
    \ long long, int> b) {\n    auto [h0, x0, p0] = a;\n    auto [h1, x1, p1] = b;\n\
    \    return {(h0 + h1 * x0) % p0, (x0 * x1) % p0, p0};\n}\n\nstd::tuple<uint_fast64_t,\
    \ long long, int> rh_unit() {\n    return {(uint_fast64_t) 0, 1, P};\n}\n\n\n\
    // \u30AB\u30C3\u30B3\u5217\n// \u300C(\u300D\u3092 +1\uFF0C\u300C)\u300D\u3092\
    \ -1 \u3068\u3059\u308B\n// (\u5408\u8A08\uFF0C\u533A\u9593\u6700\u5C0F)\nconst\
    \ std::pair<int, int> parenthesis_left = {1, 0};\nconst std::pair<int, int> parenthesis_right\
    \ = {-1, -1};\n\nstd::pair<int, int> parenthesis_op(std::pair<int, int> a, std::pair<int,\
    \ int> b) {\n    const auto [t0, m0] = a;\n    const auto [t1, m1] = b;\n    return\
    \ {t0 + t1, std::min(m0, t0 + m1)};\n}\n\nstd::pair<int, int> parenthesis_unit()\
    \ {\n    return {0, 0};\n}\n#line 4 \"test/cpp/Tree/SegmentTree1_point_add_range_sum.test.cpp\"\
    \n#include <iostream>\n\nusing namespace std;\n\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int N, Q;\n    cin >> N >> Q;\n\n   \
    \ auto st = make_segment_tree_sum<long long>(N);\n    for (int i = 0; i < N; ++i)\
    \ {\n        st.update(i, 0);\n    }\n\n    for (int i = 0; i < Q; ++i) {\n  \
    \      int COM, X, Y;\n        cin >> COM >> X >> Y;\n        if (COM == 0) {\n\
    \            X--;\n            st.update(X, Y + st.access(X));\n        } else\
    \ {\n            X--;\n            Y--;\n            cout << st.query(X, Y + 1)\
    \ << endl;\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include \"library/cpp/Tree/SegmentTree.hpp\"\n#include <iostream>\n\nusing\
    \ namespace std;\n\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n\n    auto st = make_segment_tree_sum<long\
    \ long>(N);\n    for (int i = 0; i < N; ++i) {\n        st.update(i, 0);\n   \
    \ }\n\n    for (int i = 0; i < Q; ++i) {\n        int COM, X, Y;\n        cin\
    \ >> COM >> X >> Y;\n        if (COM == 0) {\n            X--;\n            st.update(X,\
    \ Y + st.access(X));\n        } else {\n            X--;\n            Y--;\n \
    \           cout << st.query(X, Y + 1) << endl;\n        }\n    }\n\n    return\
    \ 0;\n}"
  dependsOn:
  - library/cpp/Tree/SegmentTree.hpp
  isVerificationFile: true
  path: test/cpp/Tree/SegmentTree1_point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-27 12:23:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Tree/SegmentTree1_point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Tree/SegmentTree1_point_add_range_sum.test.cpp
- /verify/test/cpp/Tree/SegmentTree1_point_add_range_sum.test.cpp.html
title: test/cpp/Tree/SegmentTree1_point_add_range_sum.test.cpp
---
