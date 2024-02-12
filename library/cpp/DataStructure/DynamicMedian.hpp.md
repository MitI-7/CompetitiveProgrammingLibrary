---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/DataStructure/DynamicMedian1.test.cpp
    title: test/cpp/DataStructure/DynamicMedian1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/DataStructure/DynamicMedian.hpp\"\n#include\
    \ <cassert>\n#include <cmath>\n#include <set>\n\ntemplate<typename T=long long>\n\
    class DynamicMedian {\nprivate:\n    unsigned int num = 0;\n    std::multiset<T>\
    \ min_set;  // \u4E2D\u592E\u5024\u3088\u308A\u5C0F\u3055\u3044\u5024\u3092\u7BA1\
    \u7406\n    std::multiset<T> max_set;  // \u4E2D\u592E\u5024\u3088\u308A\u5927\
    \u304D\u3044\u5024\u3092\u7BA1\u7406\n    T total_minimum = 0;       // min_set\
    \ \u306E\u5408\u8A08\n    T total_maximum = 0;       // max_set \u306E\u5408\u8A08\
    \n\npublic:\n    DynamicMedian() = default;\n\n    [[nodiscard]] int size() const\
    \ {\n        return this->num;\n    }\n\n    // x \u3092\u633F\u5165 O(log n)\n\
    \    void insert(const T x) {\n        if (this->num % 2 == 0) {\n           \
    \ this->max_set.emplace(x);\n            this->total_maximum += x;\n         \
    \   this->num++;\n        } else {\n            this->min_set.emplace(x);\n  \
    \          this->total_minimum += x;\n            this->num++;\n        }\n  \
    \      this->balance();\n    }\n\n    // x \u3092\u524A\u9664\n    // x \u304C\
    \u5B58\u5728\u3057\u306A\u3044\u3068\u304D\u306F\u4F55\u3082\u3057\u306A\u3044\
    \n    // O(log n)\n    void erase(const T x) {\n        if (this->min_set.contains(x))\
    \ {\n            this->min_set.erase(this->min_set.find(x));\n            this->total_minimum\
    \ -= x;\n            this->num--;\n        } else if (this->max_set.contains(x))\
    \ {\n            this->max_set.erase(this->max_set.find(x));\n            this->total_maximum\
    \ -= x;\n            this->num--;\n        }\n    }\n\n    // \u4E2D\u592E\u5024\
    \u3092\u898B\u3064\u3051\u308B\n    // \u30B5\u30A4\u30BA\u304C\u5076\u6570\u306E\
    \u3068\u304D\u306E\u305F\u3081\uFF0C\u5024\u3092 2 \u3064\u8FD4\u3059\n    //\
    \ O(1)\n    std::pair<T, T> find_median() {\n        assert(this->num > 0);\n\n\
    \        if (this->num % 2 == 0) {\n            return {*this->min_set.rbegin(),\
    \ *this->max_set.begin()};\n        } else {\n            return {*this->max_set.begin(),\
    \ *this->max_set.begin()};\n        }\n    }\n\n    // \u4E2D\u592E\u5024\u3068\
    \u4ED6\u306E\u8981\u7D20\u306E\u7D76\u5BFE\u5024\u306E\u5408\u8A08\n    // sum(|a[1]\
    \ - m| + |a[2] - m| + ... + |a[n] - m|)\n    // O(1)\n    T absolute() {\n   \
    \     const auto [x, _] = this->find_median();\n        const T mini = std::abs(x\
    \ * (T) this->min_set.size() - this->total_minimum);\n        const T maxi = std::abs(x\
    \ * (T) this->max_set.size() - this->total_maximum);\n\n        return mini +\
    \ maxi;\n    }\n\nprivate:\n    void balance() {\n        // \u5076\u6570\u500B\
    \u306E\u3068\u304D\uFF0C|min set| == |max set|\n        // \u5947\u6570\u500B\u306E\
    \u3068\u304D\uFF0C|min set| + 1 == |max set|\n\n        // max set \u304C\u591A\
    \u3044\n        while (this->min_set.size() + 1 < this->max_set.size()) {\n  \
    \          auto it = this->max_set.begin();\n            this->min_set.emplace(*it);\n\
    \            this->max_set.erase(it);\n        }\n        // min set \u304C\u591A\
    \u3044\n        while (this->min_set.size() > this->max_set.size()) {\n      \
    \      auto it = this->min_set.begin();\n            this->max_set.emplace(*it);\n\
    \            this->min_set.erase(it);\n        }\n\n        if (this->num % 2\
    \ == 0) {\n            assert(this->min_set.size() == this->max_set.size());\n\
    \        } else {\n            assert(this->min_set.size() + 1 == this->max_set.size());\n\
    \        }\n\n        if (this->min_set.empty() or this->max_set.empty()) {\n\
    \            return;\n        }\n\n        // min set \u306E\u6700\u5927\u3068\
    \ max set \u306E\u6700\u5C0F\u304C\u9006\u8EE2\u3057\u3066\u3044\u305F\u3089 swap\
    \ \u3059\u308B\n        if (*this->min_set.rbegin() > *this->max_set.begin())\
    \ {\n            // max set \u304B\u3089\u51FA\u3057\u3066\uFF0Cmin set \u306B\
    \u3044\u308C\u308B\n            {\n                auto it = this->max_set.begin();\n\
    \                this->min_set.emplace(*it);\n                this->total_maximum\
    \ -= *it;\n                this->total_minimum += *it;\n                this->max_set.erase(it);\n\
    \            }\n\n            // min set \u304B\u3089\u51FA\u3057\u3066\uFF0C\
    max set \u306B\u3044\u308C\u308B\n            {\n                auto it = this->min_set.end();\n\
    \                it--;\n                this->max_set.emplace(*it);\n        \
    \        this->total_maximum += *it;\n                this->total_minimum -= *it;\n\
    \                this->min_set.erase(it);\n            }\n        }\n    }\n};\n"
  code: "#include <cassert>\n#include <cmath>\n#include <set>\n\ntemplate<typename\
    \ T=long long>\nclass DynamicMedian {\nprivate:\n    unsigned int num = 0;\n \
    \   std::multiset<T> min_set;  // \u4E2D\u592E\u5024\u3088\u308A\u5C0F\u3055\u3044\
    \u5024\u3092\u7BA1\u7406\n    std::multiset<T> max_set;  // \u4E2D\u592E\u5024\
    \u3088\u308A\u5927\u304D\u3044\u5024\u3092\u7BA1\u7406\n    T total_minimum =\
    \ 0;       // min_set \u306E\u5408\u8A08\n    T total_maximum = 0;       // max_set\
    \ \u306E\u5408\u8A08\n\npublic:\n    DynamicMedian() = default;\n\n    [[nodiscard]]\
    \ int size() const {\n        return this->num;\n    }\n\n    // x \u3092\u633F\
    \u5165 O(log n)\n    void insert(const T x) {\n        if (this->num % 2 == 0)\
    \ {\n            this->max_set.emplace(x);\n            this->total_maximum +=\
    \ x;\n            this->num++;\n        } else {\n            this->min_set.emplace(x);\n\
    \            this->total_minimum += x;\n            this->num++;\n        }\n\
    \        this->balance();\n    }\n\n    // x \u3092\u524A\u9664\n    // x \u304C\
    \u5B58\u5728\u3057\u306A\u3044\u3068\u304D\u306F\u4F55\u3082\u3057\u306A\u3044\
    \n    // O(log n)\n    void erase(const T x) {\n        if (this->min_set.contains(x))\
    \ {\n            this->min_set.erase(this->min_set.find(x));\n            this->total_minimum\
    \ -= x;\n            this->num--;\n        } else if (this->max_set.contains(x))\
    \ {\n            this->max_set.erase(this->max_set.find(x));\n            this->total_maximum\
    \ -= x;\n            this->num--;\n        }\n    }\n\n    // \u4E2D\u592E\u5024\
    \u3092\u898B\u3064\u3051\u308B\n    // \u30B5\u30A4\u30BA\u304C\u5076\u6570\u306E\
    \u3068\u304D\u306E\u305F\u3081\uFF0C\u5024\u3092 2 \u3064\u8FD4\u3059\n    //\
    \ O(1)\n    std::pair<T, T> find_median() {\n        assert(this->num > 0);\n\n\
    \        if (this->num % 2 == 0) {\n            return {*this->min_set.rbegin(),\
    \ *this->max_set.begin()};\n        } else {\n            return {*this->max_set.begin(),\
    \ *this->max_set.begin()};\n        }\n    }\n\n    // \u4E2D\u592E\u5024\u3068\
    \u4ED6\u306E\u8981\u7D20\u306E\u7D76\u5BFE\u5024\u306E\u5408\u8A08\n    // sum(|a[1]\
    \ - m| + |a[2] - m| + ... + |a[n] - m|)\n    // O(1)\n    T absolute() {\n   \
    \     const auto [x, _] = this->find_median();\n        const T mini = std::abs(x\
    \ * (T) this->min_set.size() - this->total_minimum);\n        const T maxi = std::abs(x\
    \ * (T) this->max_set.size() - this->total_maximum);\n\n        return mini +\
    \ maxi;\n    }\n\nprivate:\n    void balance() {\n        // \u5076\u6570\u500B\
    \u306E\u3068\u304D\uFF0C|min set| == |max set|\n        // \u5947\u6570\u500B\u306E\
    \u3068\u304D\uFF0C|min set| + 1 == |max set|\n\n        // max set \u304C\u591A\
    \u3044\n        while (this->min_set.size() + 1 < this->max_set.size()) {\n  \
    \          auto it = this->max_set.begin();\n            this->min_set.emplace(*it);\n\
    \            this->max_set.erase(it);\n        }\n        // min set \u304C\u591A\
    \u3044\n        while (this->min_set.size() > this->max_set.size()) {\n      \
    \      auto it = this->min_set.begin();\n            this->max_set.emplace(*it);\n\
    \            this->min_set.erase(it);\n        }\n\n        if (this->num % 2\
    \ == 0) {\n            assert(this->min_set.size() == this->max_set.size());\n\
    \        } else {\n            assert(this->min_set.size() + 1 == this->max_set.size());\n\
    \        }\n\n        if (this->min_set.empty() or this->max_set.empty()) {\n\
    \            return;\n        }\n\n        // min set \u306E\u6700\u5927\u3068\
    \ max set \u306E\u6700\u5C0F\u304C\u9006\u8EE2\u3057\u3066\u3044\u305F\u3089 swap\
    \ \u3059\u308B\n        if (*this->min_set.rbegin() > *this->max_set.begin())\
    \ {\n            // max set \u304B\u3089\u51FA\u3057\u3066\uFF0Cmin set \u306B\
    \u3044\u308C\u308B\n            {\n                auto it = this->max_set.begin();\n\
    \                this->min_set.emplace(*it);\n                this->total_maximum\
    \ -= *it;\n                this->total_minimum += *it;\n                this->max_set.erase(it);\n\
    \            }\n\n            // min set \u304B\u3089\u51FA\u3057\u3066\uFF0C\
    max set \u306B\u3044\u308C\u308B\n            {\n                auto it = this->min_set.end();\n\
    \                it--;\n                this->max_set.emplace(*it);\n        \
    \        this->total_maximum += *it;\n                this->total_minimum -= *it;\n\
    \                this->min_set.erase(it);\n            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/DataStructure/DynamicMedian.hpp
  requiredBy: []
  timestamp: '2024-01-20 16:37:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/DataStructure/DynamicMedian1.test.cpp
documentation_of: library/cpp/DataStructure/DynamicMedian.hpp
layout: document
redirect_from:
- /library/library/cpp/DataStructure/DynamicMedian.hpp
- /library/library/cpp/DataStructure/DynamicMedian.hpp.html
title: library/cpp/DataStructure/DynamicMedian.hpp
---
