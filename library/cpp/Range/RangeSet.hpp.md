---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Range/RangeSet1.test.cpp
    title: test/cpp/Range/RangeSet1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Range/RangeSet.hpp\"\n#include <cassert>\n#include\
    \ <iostream>\n#include <numeric>\n#include <set>\n\n// \u533A\u9593\u3092 set\
    \ \u3067\u7BA1\u7406\u3059\u308B\ntemplate<class T>\nclass RangeSet {\nprivate:\n\
    \    const T INF = std::numeric_limits<T>::max() / 2;\n    T total;          \
    \                      // \u30AB\u30D0\u30FC\u3055\u308C\u3066\u3044\u308B\u533A\
    \u9593\u306E\u5408\u8A08\n    std::set<std::pair<T, T>> range_set;    // \u533A\
    \u9593 [l, r) \u306E\u96C6\u5408\n\npublic:\n    RangeSet() : total(0) {\n   \
    \     this->range_set.emplace(-INF, -INF);\n        this->range_set.emplace(INF,\
    \ INF);\n    }\n\n    // \u533A\u9593\u306E\u500B\u6570\u3092\u53D6\u5F97\u3059\
    \u308B\n    [[nodiscard]] int size() const {\n        return (int) range_set.size()\
    \ - 2;\n    }\n\n    // \u533A\u9593 [l, r) \u3092\u633F\u5165\u3059\u308B\n \
    \   void insert(T l, T r) {\n        assert(l <= r);\n\n        if (l == r) {\n\
    \            return;\n        }\n\n        // [l, r) \u304C\u3059\u3067\u306B\u30AB\
    \u30D0\u30FC\u3055\u308C\u3066\u3044\u308B\n        auto it = prev(this->range_set.upper_bound({l,\
    \ this->INF}));\n        if (it->first <= l and r <= it->second) {\n         \
    \   return;\n        }\n\n        T erased_total = 0;\n\n        // [l, r) \u304C\
    \u8FFD\u52A0\u3055\u308C\u308B\u3053\u3068\u3067\u7D71\u5408\u3055\u308C\u308B\
    \u533A\u9593\u3092\u6C42\u3081\u3066\u3044\u304F\n\n        // l \u306F it \u3067\
    \u30AB\u30D0\u30FC\u3055\u308C\u3066\u3044\u308B\n        if (it->first <= l and\
    \ l <= it->second) {\n            l = it->first;\n            // it \u3092\u524A\
    \u9664\n            erased_total += it->second - it->first;\n            it =\
    \ this->range_set.erase(it);\n        } else {\n            it = next(it);\n \
    \       }\n\n        // r \u3067\u30AB\u30D0\u30FC\u3055\u308C\u3066\u3044\u308B\
    \u3068\u3053\u308D\u3092\u524A\u9664\u3057\u3066\u3044\u304F\n        while (it->second\
    \ < r) {\n            erased_total += it->second - it->first;\n            it\
    \ = this->range_set.erase(it);\n        }\n\n        // r \u3067\u30AB\u30D0\u30FC\
    \u3055\u308C\u3066\u3044\u308B\u6700\u5F8C\n        if (it->first <= r) {\n  \
    \          erased_total += it->second - it->first;\n            r = it->second;\n\
    \            this->range_set.erase(it);\n        }\n\n        this->range_set.emplace(l,\
    \ r);\n        this->total += r - l - erased_total;\n    }\n\n    // \u533A\u9593\
    [l, r) \u304C\u5B8C\u5168\u306B\u30AB\u30D0\u30FC\u3055\u308C\u3066\u3044\u308B\
    \u304B\n    // O(lon n)\n    bool is_covered(const T l, const T r) const {\n \
    \       assert(l <= r);\n        if (l == r) {\n            return true;\n   \
    \     }\n        const auto it = prev(this->range_set.upper_bound({l, this->INF}));\n\
    \        return it->first <= l and r <= it->second;\n    }\n\n    // \u533A\u9593\
    \ [l, r) \u3092\u5B8C\u5168\u306B\u30AB\u30D0\u30FC\u3057\u3066\u3044\u308B\u533A\
    \u9593\u3092\u6C42\u3081\u308B\n    // \u30AB\u30D0\u30FC\u3055\u308C\u3066\u3044\
    \u306A\u3044\u5834\u5408\u306F {-INF, -INF} \u3092\u8FD4\u3059\n    std::pair<T,\
    \ T> covered_by(const T l, const T r) const {\n        assert(l <= r);\n     \
    \   if (l == r) {\n            return {-INF, -INF};\n        }\n        const\
    \ auto it = prev(this->range_set.upper_bound({l, this->INF}));\n\n        if (it->first\
    \ <= l and r <= it->second) {\n            return *it;\n        }\n        return\
    \ {-INF, -INF};\n    }\n\n    // \u533A\u9593 [l, r) \u3092\u524A\u9664\u3059\u308B\
    \n    void erase(const T l, const T r) {\n        assert(l <= r);\n        if\
    \ (l == r) {\n            return;\n        }\n        auto it = prev(this->range_set.upper_bound({l,\
    \ this->INF}));\n\n        // [l, r) \u3092\u5B8C\u5168\u306B\u542B\u3080\u533A\
    \u9593\u304C\u3042\u308B\n        if (it->first <= l and r <= it->second) {\n\
    \            if (it->first < l) {\n                this->range_set.emplace(it->first,\
    \ l);\n            }\n            if (r < it->second) {\n                this->range_set.emplace(r,\
    \ it->second);\n            }\n            this->range_set.erase(it);\n      \
    \      this->total -= r - l;\n            return;\n        }\n\n        T erased_total\
    \ = 0;\n        if (it->first <= l and l < it->second) {\n            erased_total\
    \ += it->second - l;\n            if (it->first < l) {\n                this->range_set.emplace(it->first,\
    \ l);\n            }\n            it = this->range_set.erase(it);\n        } else\
    \ {\n            it = next(it);\n        }\n\n        while (it->second <= r)\
    \ {\n            erased_total += it->second - it->first;\n            it = this->range_set.erase(it);\n\
    \        }\n\n        if (it->first < r) {\n            erased_total += r - it->first;\n\
    \            this->range_set.emplace(r, it->second);\n            this->range_set.erase(it);\n\
    \        }\n        this->total -= erased_total;\n    }\n\n    // mex \u3092\u6C42\
    \u3081\u308B\n    // O(log n)\n    T mex(const T x = 0) const {\n        const\
    \ auto it = prev(this->range_set.upper_bound({x, this->INF}));\n        if (it->first\
    \ <= x and x < it->second) {\n            return it->second;\n        } else {\n\
    \            return x;\n        }\n    }\n\n    // \u30AB\u30D0\u30FC\u3057\u3066\
    \u3044\u308B\u533A\u9593\u306E\u5408\u8A08\u3092\u53D6\u5F97\u3059\u308B\n   \
    \ T get_total() const {\n        return this->total;\n    }\n\n    // \u30AB\u30D0\
    \u30FC\u306E\u96C6\u5408\u3092\u53D6\u5F97\u3059\u308B\n    std::set<std::pair<T,\
    \ T>> get_covers() const {\n        std::set<std::pair<T, T>> covers;\n      \
    \  for (const auto [l, r]: this->range_set) {\n            if (l == this->INF\
    \ or l == -INF) {\n                continue;\n            }\n            covers.emplace(l,\
    \ r);\n        }\n        return covers;\n    }\n\n    void dump() const {\n \
    \       for (auto [l, r]: this->range_set) {\n            if (l == -this->INF\
    \ or l == this->INF) {\n                continue;\n            }\n           \
    \ std::cout << \"[\" << l << \",\" << r << \")\" << std::endl;\n        }\n  \
    \  }\n};\n"
  code: "#include <cassert>\n#include <iostream>\n#include <numeric>\n#include <set>\n\
    \n// \u533A\u9593\u3092 set \u3067\u7BA1\u7406\u3059\u308B\ntemplate<class T>\n\
    class RangeSet {\nprivate:\n    const T INF = std::numeric_limits<T>::max() /\
    \ 2;\n    T total;                                // \u30AB\u30D0\u30FC\u3055\u308C\
    \u3066\u3044\u308B\u533A\u9593\u306E\u5408\u8A08\n    std::set<std::pair<T, T>>\
    \ range_set;    // \u533A\u9593 [l, r) \u306E\u96C6\u5408\n\npublic:\n    RangeSet()\
    \ : total(0) {\n        this->range_set.emplace(-INF, -INF);\n        this->range_set.emplace(INF,\
    \ INF);\n    }\n\n    // \u533A\u9593\u306E\u500B\u6570\u3092\u53D6\u5F97\u3059\
    \u308B\n    [[nodiscard]] int size() const {\n        return (int) range_set.size()\
    \ - 2;\n    }\n\n    // \u533A\u9593 [l, r) \u3092\u633F\u5165\u3059\u308B\n \
    \   void insert(T l, T r) {\n        assert(l <= r);\n\n        if (l == r) {\n\
    \            return;\n        }\n\n        // [l, r) \u304C\u3059\u3067\u306B\u30AB\
    \u30D0\u30FC\u3055\u308C\u3066\u3044\u308B\n        auto it = prev(this->range_set.upper_bound({l,\
    \ this->INF}));\n        if (it->first <= l and r <= it->second) {\n         \
    \   return;\n        }\n\n        T erased_total = 0;\n\n        // [l, r) \u304C\
    \u8FFD\u52A0\u3055\u308C\u308B\u3053\u3068\u3067\u7D71\u5408\u3055\u308C\u308B\
    \u533A\u9593\u3092\u6C42\u3081\u3066\u3044\u304F\n\n        // l \u306F it \u3067\
    \u30AB\u30D0\u30FC\u3055\u308C\u3066\u3044\u308B\n        if (it->first <= l and\
    \ l <= it->second) {\n            l = it->first;\n            // it \u3092\u524A\
    \u9664\n            erased_total += it->second - it->first;\n            it =\
    \ this->range_set.erase(it);\n        } else {\n            it = next(it);\n \
    \       }\n\n        // r \u3067\u30AB\u30D0\u30FC\u3055\u308C\u3066\u3044\u308B\
    \u3068\u3053\u308D\u3092\u524A\u9664\u3057\u3066\u3044\u304F\n        while (it->second\
    \ < r) {\n            erased_total += it->second - it->first;\n            it\
    \ = this->range_set.erase(it);\n        }\n\n        // r \u3067\u30AB\u30D0\u30FC\
    \u3055\u308C\u3066\u3044\u308B\u6700\u5F8C\n        if (it->first <= r) {\n  \
    \          erased_total += it->second - it->first;\n            r = it->second;\n\
    \            this->range_set.erase(it);\n        }\n\n        this->range_set.emplace(l,\
    \ r);\n        this->total += r - l - erased_total;\n    }\n\n    // \u533A\u9593\
    [l, r) \u304C\u5B8C\u5168\u306B\u30AB\u30D0\u30FC\u3055\u308C\u3066\u3044\u308B\
    \u304B\n    // O(lon n)\n    bool is_covered(const T l, const T r) const {\n \
    \       assert(l <= r);\n        if (l == r) {\n            return true;\n   \
    \     }\n        const auto it = prev(this->range_set.upper_bound({l, this->INF}));\n\
    \        return it->first <= l and r <= it->second;\n    }\n\n    // \u533A\u9593\
    \ [l, r) \u3092\u5B8C\u5168\u306B\u30AB\u30D0\u30FC\u3057\u3066\u3044\u308B\u533A\
    \u9593\u3092\u6C42\u3081\u308B\n    // \u30AB\u30D0\u30FC\u3055\u308C\u3066\u3044\
    \u306A\u3044\u5834\u5408\u306F {-INF, -INF} \u3092\u8FD4\u3059\n    std::pair<T,\
    \ T> covered_by(const T l, const T r) const {\n        assert(l <= r);\n     \
    \   if (l == r) {\n            return {-INF, -INF};\n        }\n        const\
    \ auto it = prev(this->range_set.upper_bound({l, this->INF}));\n\n        if (it->first\
    \ <= l and r <= it->second) {\n            return *it;\n        }\n        return\
    \ {-INF, -INF};\n    }\n\n    // \u533A\u9593 [l, r) \u3092\u524A\u9664\u3059\u308B\
    \n    void erase(const T l, const T r) {\n        assert(l <= r);\n        if\
    \ (l == r) {\n            return;\n        }\n        auto it = prev(this->range_set.upper_bound({l,\
    \ this->INF}));\n\n        // [l, r) \u3092\u5B8C\u5168\u306B\u542B\u3080\u533A\
    \u9593\u304C\u3042\u308B\n        if (it->first <= l and r <= it->second) {\n\
    \            if (it->first < l) {\n                this->range_set.emplace(it->first,\
    \ l);\n            }\n            if (r < it->second) {\n                this->range_set.emplace(r,\
    \ it->second);\n            }\n            this->range_set.erase(it);\n      \
    \      this->total -= r - l;\n            return;\n        }\n\n        T erased_total\
    \ = 0;\n        if (it->first <= l and l < it->second) {\n            erased_total\
    \ += it->second - l;\n            if (it->first < l) {\n                this->range_set.emplace(it->first,\
    \ l);\n            }\n            it = this->range_set.erase(it);\n        } else\
    \ {\n            it = next(it);\n        }\n\n        while (it->second <= r)\
    \ {\n            erased_total += it->second - it->first;\n            it = this->range_set.erase(it);\n\
    \        }\n\n        if (it->first < r) {\n            erased_total += r - it->first;\n\
    \            this->range_set.emplace(r, it->second);\n            this->range_set.erase(it);\n\
    \        }\n        this->total -= erased_total;\n    }\n\n    // mex \u3092\u6C42\
    \u3081\u308B\n    // O(log n)\n    T mex(const T x = 0) const {\n        const\
    \ auto it = prev(this->range_set.upper_bound({x, this->INF}));\n        if (it->first\
    \ <= x and x < it->second) {\n            return it->second;\n        } else {\n\
    \            return x;\n        }\n    }\n\n    // \u30AB\u30D0\u30FC\u3057\u3066\
    \u3044\u308B\u533A\u9593\u306E\u5408\u8A08\u3092\u53D6\u5F97\u3059\u308B\n   \
    \ T get_total() const {\n        return this->total;\n    }\n\n    // \u30AB\u30D0\
    \u30FC\u306E\u96C6\u5408\u3092\u53D6\u5F97\u3059\u308B\n    std::set<std::pair<T,\
    \ T>> get_covers() const {\n        std::set<std::pair<T, T>> covers;\n      \
    \  for (const auto [l, r]: this->range_set) {\n            if (l == this->INF\
    \ or l == -INF) {\n                continue;\n            }\n            covers.emplace(l,\
    \ r);\n        }\n        return covers;\n    }\n\n    void dump() const {\n \
    \       for (auto [l, r]: this->range_set) {\n            if (l == -this->INF\
    \ or l == this->INF) {\n                continue;\n            }\n           \
    \ std::cout << \"[\" << l << \",\" << r << \")\" << std::endl;\n        }\n  \
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Range/RangeSet.hpp
  requiredBy: []
  timestamp: '2024-01-28 14:21:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Range/RangeSet1.test.cpp
documentation_of: library/cpp/Range/RangeSet.hpp
layout: document
redirect_from:
- /library/library/cpp/Range/RangeSet.hpp
- /library/library/cpp/Range/RangeSet.hpp.html
title: library/cpp/Range/RangeSet.hpp
---
