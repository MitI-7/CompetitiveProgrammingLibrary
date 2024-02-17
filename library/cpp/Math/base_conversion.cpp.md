---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Math/base_conversion1_to_base_10.test.cpp
    title: test/cpp/Math/base_conversion1_to_base_10.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Math/base_conversion.cpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n#include <limits>\n\n// base \u9032\u6570\
    \u304B\u308910\u9032\u6570\u306B\u5909\u3048\u308B\n// v[0]\u304C\u6700\u4E0A\u4F4D\
    \u306E\u6841\u3092\u8868\u3059\n// 6 = 110 \u306A\u3089 {0, 1, 1}\nlong long to_base_10(const\
    \ std::vector<int> &v, const long long base) {\n    auto inf = std::numeric_limits<long\
    \ long>::max();\n    long long ans = 0;\n    for (int x: v) {\n        assert(x\
    \ >= 0);\n        assert(x < base);\n\n        // overflow \u304C\u8D77\u304D\u305F\
    \u3068\u304D\u306E\u51E6\u7406\n        if (ans > inf / base) {\n            return\
    \ inf;\n        }\n\n        ans = ans * base + x;\n    }\n    return ans;\n}\n\
    \n// 10 \u9032\u6570\u304B\u3089 base \u9032\u6570\u306B\u5909\u3048\u308B\nstd::vector<int>\
    \ to_base_n(long long x, const int base) {\n    if (x == 0) {\n        return\
    \ {0};\n    }\n\n    std::vector<int> ans;\n    while (x > 0) {\n        auto\
    \ t = x % base;\n        ans.emplace_back(t);\n        x /= base;\n    }\n   \
    \ reverse(ans.begin(), ans.end());\n    return ans;\n}\n"
  code: "#include <algorithm>\n#include <cassert>\n#include <vector>\n#include <limits>\n\
    \n// base \u9032\u6570\u304B\u308910\u9032\u6570\u306B\u5909\u3048\u308B\n// v[0]\u304C\
    \u6700\u4E0A\u4F4D\u306E\u6841\u3092\u8868\u3059\n// 6 = 110 \u306A\u3089 {0,\
    \ 1, 1}\nlong long to_base_10(const std::vector<int> &v, const long long base)\
    \ {\n    auto inf = std::numeric_limits<long long>::max();\n    long long ans\
    \ = 0;\n    for (int x: v) {\n        assert(x >= 0);\n        assert(x < base);\n\
    \n        // overflow \u304C\u8D77\u304D\u305F\u3068\u304D\u306E\u51E6\u7406\n\
    \        if (ans > inf / base) {\n            return inf;\n        }\n\n     \
    \   ans = ans * base + x;\n    }\n    return ans;\n}\n\n// 10 \u9032\u6570\u304B\
    \u3089 base \u9032\u6570\u306B\u5909\u3048\u308B\nstd::vector<int> to_base_n(long\
    \ long x, const int base) {\n    if (x == 0) {\n        return {0};\n    }\n\n\
    \    std::vector<int> ans;\n    while (x > 0) {\n        auto t = x % base;\n\
    \        ans.emplace_back(t);\n        x /= base;\n    }\n    reverse(ans.begin(),\
    \ ans.end());\n    return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Math/base_conversion.cpp
  requiredBy: []
  timestamp: '2024-02-14 16:29:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Math/base_conversion1_to_base_10.test.cpp
documentation_of: library/cpp/Math/base_conversion.cpp
layout: document
redirect_from:
- /library/library/cpp/Math/base_conversion.cpp
- /library/library/cpp/Math/base_conversion.cpp.html
title: library/cpp/Math/base_conversion.cpp
---
