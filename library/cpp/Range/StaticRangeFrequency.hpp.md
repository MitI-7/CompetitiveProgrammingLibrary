---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Range/StaticRangeFrequency1_range_count.test.cpp
    title: test/cpp/Range/StaticRangeFrequency1_range_count.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Range/StaticRangeFrequency2_range_count.test.cpp
    title: test/cpp/Range/StaticRangeFrequency2_range_count.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cpp/Range/StaticRangeFrequency3_range_count.test.cpp
    title: test/cpp/Range/StaticRangeFrequency3_range_count.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Range/StaticRangeFrequency.hpp\"\n#include <unordered_map>\n\
    #include <vector>\n\n// vec \u306E\u533A\u9593 [l, r) \u306B\u51FA\u73FE\u3059\
    \u308B\u3042\u308B\u6574\u6570\u5024 x \u306E\u500B\u6570\u3092\u30AB\u30A6\u30F3\
    \u30C8\u3059\u308B\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B\nclass StaticRangeFrequency\
    \ {\npublic:\n    int n;\nprivate:\n    std::vector<int> vec;\n    std::unordered_map<int,\
    \ std::vector<int>> idx_list;  // \u5404\u5024\u306E\u51FA\u73FE\u3059\u308B index\n\
    \npublic:\n    explicit StaticRangeFrequency(std::vector<int> &vec) : n((int)\
    \ vec.size()), vec(vec) {\n        for (int i = 0; i < int(vec.size()); ++i) {\n\
    \            this->idx_list[vec[i]].emplace_back(i);\n        }\n    }\n\n   \
    \ // vec[i]\n    int get(const int i) const {\n        return this->vec[i];\n\
    \    }\n\n    // x \u3092 vec \u306E\u672B\u5C3E\u306B\u8FFD\u52A0\n    void emplace_back(const\
    \ int x) {\n        this->vec.emplace_back(x);\n        this->idx_list[x].emplace_back(this->n);\n\
    \        this->n++;\n    }\n\n    // x \u306E\u500B\u6570\u3092\u6C42\u3081\u308B\
    \n    int count(const int x) const {\n        if (not this->idx_list.contains(x))\
    \ {\n            return 0;\n        }\n        return int(this->idx_list.at(x).size());\n\
    \    }\n\n    // vec[l, r) \u306B\u5B58\u5728\u3059\u308B x \u306E\u500B\u6570\
    \u3092\u6C42\u3081\u308B\n    int range_count(int l, int r, int x) const {\n \
    \       if (this->count(x) == 0) {\n            return 0;\n        }\n\n     \
    \   const auto begin = this->idx_list.at(x).begin();\n        const auto end =\
    \ this->idx_list.at(x).end();\n        auto it_left = std::lower_bound(begin,\
    \ end, l);\n        if (it_left == end) {\n            return 0;\n        }\n\n\
    \        auto it_right = std::lower_bound(begin, end, r);\n        return (int)\
    \ std::distance(it_left, it_right);\n    }\n};\n"
  code: "#include <unordered_map>\n#include <vector>\n\n// vec \u306E\u533A\u9593\
    \ [l, r) \u306B\u51FA\u73FE\u3059\u308B\u3042\u308B\u6574\u6570\u5024 x \u306E\
    \u500B\u6570\u3092\u30AB\u30A6\u30F3\u30C8\u3059\u308B\u30AF\u30A8\u30EA\u306B\
    \u7B54\u3048\u308B\nclass StaticRangeFrequency {\npublic:\n    int n;\nprivate:\n\
    \    std::vector<int> vec;\n    std::unordered_map<int, std::vector<int>> idx_list;\
    \  // \u5404\u5024\u306E\u51FA\u73FE\u3059\u308B index\n\npublic:\n    explicit\
    \ StaticRangeFrequency(std::vector<int> &vec) : n((int) vec.size()), vec(vec)\
    \ {\n        for (int i = 0; i < int(vec.size()); ++i) {\n            this->idx_list[vec[i]].emplace_back(i);\n\
    \        }\n    }\n\n    // vec[i]\n    int get(const int i) const {\n       \
    \ return this->vec[i];\n    }\n\n    // x \u3092 vec \u306E\u672B\u5C3E\u306B\u8FFD\
    \u52A0\n    void emplace_back(const int x) {\n        this->vec.emplace_back(x);\n\
    \        this->idx_list[x].emplace_back(this->n);\n        this->n++;\n    }\n\
    \n    // x \u306E\u500B\u6570\u3092\u6C42\u3081\u308B\n    int count(const int\
    \ x) const {\n        if (not this->idx_list.contains(x)) {\n            return\
    \ 0;\n        }\n        return int(this->idx_list.at(x).size());\n    }\n\n \
    \   // vec[l, r) \u306B\u5B58\u5728\u3059\u308B x \u306E\u500B\u6570\u3092\u6C42\
    \u3081\u308B\n    int range_count(int l, int r, int x) const {\n        if (this->count(x)\
    \ == 0) {\n            return 0;\n        }\n\n        const auto begin = this->idx_list.at(x).begin();\n\
    \        const auto end = this->idx_list.at(x).end();\n        auto it_left =\
    \ std::lower_bound(begin, end, l);\n        if (it_left == end) {\n          \
    \  return 0;\n        }\n\n        auto it_right = std::lower_bound(begin, end,\
    \ r);\n        return (int) std::distance(it_left, it_right);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Range/StaticRangeFrequency.hpp
  requiredBy: []
  timestamp: '2024-01-28 14:22:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Range/StaticRangeFrequency2_range_count.test.cpp
  - test/cpp/Range/StaticRangeFrequency3_range_count.test.cpp
  - test/cpp/Range/StaticRangeFrequency1_range_count.test.cpp
documentation_of: library/cpp/Range/StaticRangeFrequency.hpp
layout: document
redirect_from:
- /library/library/cpp/Range/StaticRangeFrequency.hpp
- /library/library/cpp/Range/StaticRangeFrequency.hpp.html
title: library/cpp/Range/StaticRangeFrequency.hpp
---
