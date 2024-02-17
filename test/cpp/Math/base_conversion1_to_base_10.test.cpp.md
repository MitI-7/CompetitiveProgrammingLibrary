---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Math/base_conversion.cpp
    title: library/cpp/Math/base_conversion.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc220/tasks/abc220_b
    links:
    - https://atcoder.jp/contests/abc220/tasks/abc220_b
  bundledCode: "#line 1 \"test/cpp/Math/base_conversion1_to_base_10.test.cpp\"\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/abc220/tasks/abc220_b\"\n\n#line 1 \"\
    library/cpp/Math/base_conversion.cpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n#include <limits>\n\n// base \u9032\u6570\u304B\u308910\u9032\
    \u6570\u306B\u5909\u3048\u308B\n// v[0]\u304C\u6700\u4E0A\u4F4D\u306E\u6841\u3092\
    \u8868\u3059\n// 6 = 110 \u306A\u3089 {0, 1, 1}\nlong long to_base_10(const std::vector<int>\
    \ &v, const long long base) {\n    auto inf = std::numeric_limits<long long>::max();\n\
    \    long long ans = 0;\n    for (int x: v) {\n        assert(x >= 0);\n     \
    \   assert(x < base);\n\n        // overflow \u304C\u8D77\u304D\u305F\u3068\u304D\
    \u306E\u51E6\u7406\n        if (ans > inf / base) {\n            return inf;\n\
    \        }\n\n        ans = ans * base + x;\n    }\n    return ans;\n}\n\n// 10\
    \ \u9032\u6570\u304B\u3089 base \u9032\u6570\u306B\u5909\u3048\u308B\nstd::vector<int>\
    \ to_base_n(long long x, const int base) {\n    if (x == 0) {\n        return\
    \ {0};\n    }\n\n    std::vector<int> ans;\n    while (x > 0) {\n        auto\
    \ t = x % base;\n        ans.emplace_back(t);\n        x /= base;\n    }\n   \
    \ reverse(ans.begin(), ans.end());\n    return ans;\n}\n#line 4 \"test/cpp/Math/base_conversion1_to_base_10.test.cpp\"\
    \n#include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int K;\n    string A, B;\n    cin >>\
    \ K >> A >> B;\n\n    vector<int> a, b;\n    for (int x: A) {\n        a.emplace_back(x\
    \ - '0');\n    }\n    for (int x: B) {\n        b.emplace_back(x - '0');\n   \
    \ }\n    cout << to_base_10(a, K) * to_base_10(b, K) << endl;\n\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc220/tasks/abc220_b\"\n\n\
    #include \"library/cpp/Math/base_conversion.cpp\"\n#include <iostream>\n\nusing\
    \ namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int K;\n    string A, B;\n    cin >> K >> A >> B;\n\n    vector<int> a,\
    \ b;\n    for (int x: A) {\n        a.emplace_back(x - '0');\n    }\n    for (int\
    \ x: B) {\n        b.emplace_back(x - '0');\n    }\n    cout << to_base_10(a,\
    \ K) * to_base_10(b, K) << endl;\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Math/base_conversion.cpp
  isVerificationFile: true
  path: test/cpp/Math/base_conversion1_to_base_10.test.cpp
  requiredBy: []
  timestamp: '2024-02-14 16:29:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Math/base_conversion1_to_base_10.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Math/base_conversion1_to_base_10.test.cpp
- /verify/test/cpp/Math/base_conversion1_to_base_10.test.cpp.html
title: test/cpp/Math/base_conversion1_to_base_10.test.cpp
---
