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
    PROBLEM: https://atcoder.jp/contests/abc185/tasks/abc185_f
    links:
    - https://atcoder.jp/contests/abc185/tasks/abc185_f
  bundledCode: "#line 1 \"test/cpp/Tree/SegmentTree4_point_update_range_xor.test.cpp\"\
    \n#define PROBLEM \"https://atcoder.jp/contests/abc185/tasks/abc185_f\"\n\n#line\
    \ 1 \"library/cpp/Tree/SegmentTree.hpp\"\n#include <cassert>\n#include <cstdint>\n\
    #include <functional>\n#include <numeric>\n#include <tuple>\n#include <vector>\n\
    \n// \u30E2\u30CE\u30A4\u30C9\u3092\u4E57\u305B\u308B\u3053\u3068\u304C\u3067\u304D\
    \u308B\n// \u7D50\u5408\u5247: a * (b * c) = (a * b) * c\n// \u5358\u4F4D\u5143\
    : e * a = a * e = a\ntemplate<class T, T (*op)(T, T), T (*unit)()>\nclass SegmentTree\
    \ {\n    const int array_size;       // \u3082\u3068\u306E\u914D\u5217\u306E\u30B5\
    \u30A4\u30BA\n    int n;                      // \u30BB\u30B0\u6728\u3067\u4F7F\
    \u3046\u914D\u5217\u306E\u30B5\u30A4\u30BA\n    std::vector<T> data;\n\npublic:\n\
    \    SegmentTree(int array_size) : array_size(array_size) {\n        // n \u306F\
    \ array_size \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E 2 \u51AA\n        this->n =\
    \ 1;\n        while (this->n < array_size) {\n            this->n *= 2;\n    \
    \    }\n        this->data.resize(2 * this->n - 1, unit());\n    }\n\n    T access(const\
    \ int idx) const {\n        return this->data[idx + this->n - 1];\n    }\n\n \
    \   // array[idx] = x\n    // O(log N)\n    void update(int idx, const T x) {\n\
    \        assert(0 <= idx and idx < this->array_size);\n        idx += this->n\
    \ - 1;   // \u6728\u3067\u306E\u5BFE\u8C61\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\n        this->data[idx] = x;\n        while (idx > 0) {\n            idx\
    \ = (idx - 1) / 2;                                                      // \u89AA\
    \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n            this->data[idx] = op(this->data[idx\
    \ * 2 + 1], this->data[idx * 2 + 2]);   // \u5DE6\u306E\u5B50\u3068\u53F3\u306E\
    \u5B50\n        }\n    }\n\n    // op(array[left, right))\n    // O(log N)\n \
    \   T query(const int left, const int right) const {\n        assert(0 <= left\
    \ and left < right and right <= this->array_size);\n        return query(left,\
    \ right, 0, 0, this->n);\n    }\n\nprivate:\n    // [a, b)\u306E\u76EE\u7684\u5024\
    \u3092\u30CE\u30FC\u30C9k\uFF08\u533A\u9593[l, r]\uFF09\u304B\u3089\u691C\u7D22\
    \n    T query(int a, int b, int k, int l, int r) const {\n        assert(a < b\
    \ && l < r);\n        // \u7BC4\u56F2\u5916\n        if (r <= a || b <= l) {\n\
    \            return unit();\n        }\n        // \u5B8C\u5168\u306B\u542B\u3080\
    \n        if (a <= l && r <= b) {\n            return this->data[k];\n       \
    \ }\n            // \u4E00\u90E8\u542B\u3080\n        else {\n            auto\
    \ vl = query(a, b, k * 2 + 1, l, (l + r) / 2);    // \u5DE6\u306E\u5B50\n    \
    \        auto vr = query(a, b, k * 2 + 2, (l + r) / 2, r);    // \u53F3\u306E\u5B50\
    \n            return op(vl, vr);\n        }\n    }\n};\n\n\n// range minimum query\n\
    template<typename T>\nT min_op(T a, T b) {\n    return std::min(a, b);\n}\n\n\
    template<typename T>\nT min_unit() {\n    return std::numeric_limits<T>::max();\n\
    }\n\ntemplate<typename T>\nSegmentTree<T, min_op, min_unit> make_segment_tree_min(const\
    \ int n) {\n    return SegmentTree<T, min_op, min_unit>(n);\n}\n\n// range maximum\
    \ query\ntemplate<typename T>\nT max_op(T a, T b) {\n    return std::max(a, b);\n\
    }\n\ntemplate<typename T>\nT max_unit() {\n    return 0;\n}\n\ntemplate<typename\
    \ T>\nSegmentTree<T, min_op, min_unit> make_segment_tree_max(const int n) {\n\
    \    return SegmentTree<T, max_op, max_unit>(n);\n}\n\n// range summation query\n\
    template<typename T>\nT sum_op(T a, T b) {\n    return a + b;\n}\n\ntemplate<typename\
    \ T>\nT sum_unit() {\n    return 0;\n}\n\ntemplate<typename T>\nSegmentTree<T,\
    \ sum_op, sum_unit> make_segment_tree_sum(const int n) {\n    return SegmentTree<T,\
    \ sum_op, sum_unit>(n);\n}\n\n// range xor query\ntemplate<typename T>\nT xor_op(T\
    \ a, T b) {\n    return a ^ b;\n}\n\ntemplate<typename T>\nT xor_unit() {\n  \
    \  return 0;\n}\n\ntemplate<typename T>\nSegmentTree<T, xor_op, xor_unit> make_segment_tree_xor(const\
    \ int n) {\n    return SegmentTree<T, xor_op, xor_unit>(n);\n}\n\n// Rolling Hash\
    \ query\nconst int P = 998244353;\nconst long long base = 129;\n\nstd::tuple<uint_fast64_t,\
    \ long long, int>\nrh_op(std::tuple<uint_fast64_t, long long, int> a, std::tuple<uint_fast64_t,\
    \ long long, int> b) {\n    auto [h0, x0, p0] = a;\n    auto [h1, x1, p1] = b;\n\
    \    return {(h0 + h1 * x0) % p0, (x0 * x1) % p0, p0};\n}\n\nstd::tuple<uint_fast64_t,\
    \ long long, int> rh_unit() {\n    return {(uint_fast64_t) 0, 1, P};\n}\n#line\
    \ 4 \"test/cpp/Tree/SegmentTree4_point_update_range_xor.test.cpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n\n    auto st = make_segment_tree_xor<long\
    \ long>(N);\n    for (int i = 0; i < N; ++i) {\n        long long A;\n       \
    \ cin >> A;\n        st.update(i, A);\n    }\n\n    for (int i = 0; i < Q; ++i)\
    \ {\n        int T, X, Y;\n        cin >> T >> X >> Y;\n        if (T == 1) {\n\
    \            X--;\n            st.update(X, st.access(X) ^ Y);\n        } else\
    \ {\n            X--;\n            Y--;\n            cout << st.query(X, Y + 1)\
    \ << endl;\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc185/tasks/abc185_f\"\n\n\
    #include \"library/cpp/Tree/SegmentTree.hpp\"\n#include <iostream>\n\nusing namespace\
    \ std;\n\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n\n    auto st = make_segment_tree_xor<long\
    \ long>(N);\n    for (int i = 0; i < N; ++i) {\n        long long A;\n       \
    \ cin >> A;\n        st.update(i, A);\n    }\n\n    for (int i = 0; i < Q; ++i)\
    \ {\n        int T, X, Y;\n        cin >> T >> X >> Y;\n        if (T == 1) {\n\
    \            X--;\n            st.update(X, st.access(X) ^ Y);\n        } else\
    \ {\n            X--;\n            Y--;\n            cout << st.query(X, Y + 1)\
    \ << endl;\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Tree/SegmentTree.hpp
  isVerificationFile: true
  path: test/cpp/Tree/SegmentTree4_point_update_range_xor.test.cpp
  requiredBy: []
  timestamp: '2024-01-27 12:24:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Tree/SegmentTree4_point_update_range_xor.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Tree/SegmentTree4_point_update_range_xor.test.cpp
- /verify/test/cpp/Tree/SegmentTree4_point_update_range_xor.test.cpp.html
title: test/cpp/Tree/SegmentTree4_point_update_range_xor.test.cpp
---
