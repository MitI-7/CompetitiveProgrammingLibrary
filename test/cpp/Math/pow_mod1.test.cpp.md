---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Math/pow_mod.cpp
    title: library/cpp/Math/pow_mod.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
  bundledCode: "#line 1 \"test/cpp/Math/pow_mod1.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n\n#line 1 \"library/cpp/Math/pow_mod.cpp\"\n// a^n % mod\n// O(log n)\n// mod\u304C\
    \u3067\u304B\u3044\u3068\u304D\u306Foverflow\u306B\u6CE8\u610F\nlong long pow_mod(long\
    \ long a, long long n, long long mod) {\n    long long x = 1, y = a % mod;\n \
    \   while (n > 0) {\n        if (n % 2 == 1) {\n            x = (x * y) % mod;\n\
    \        }\n        y = (y * y) % mod;\n        n /= 2;\n    }\n\n    return int(x\
    \ % mod);\n}\n#line 4 \"test/cpp/Math/pow_mod1.test.cpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    long long M, N;\n    cin >> M >> N;\n\n    cout << pow_mod(M, N, 1000000007)\
    \ << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n\n#include \"library/cpp/Math/pow_mod.cpp\"\n#include <iostream>\n\nusing namespace\
    \ std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    long long M, N;\n    cin >> M >> N;\n\n    cout << pow_mod(M, N, 1000000007)\
    \ << endl;\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Math/pow_mod.cpp
  isVerificationFile: true
  path: test/cpp/Math/pow_mod1.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:43:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Math/pow_mod1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Math/pow_mod1.test.cpp
- /verify/test/cpp/Math/pow_mod1.test.cpp.html
title: test/cpp/Math/pow_mod1.test.cpp
---
