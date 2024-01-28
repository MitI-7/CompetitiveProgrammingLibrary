---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Math/prime_factor_decomposition.cpp
    title: library/cpp/Math/prime_factor_decomposition.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
  bundledCode: "#line 1 \"test/cpp/Math/prime_factor_decomposition1.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n\n#line 1 \"library/cpp/Math/prime_factor_decomposition.cpp\"\n#include <map>\n\
    \n// n\u3092\u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\n// O(n^(1/2))\n// prime_factor_decomposition(12)\
    \ : {2:2, 3:1}\nstd::map<long long, long long> prime_factor_decomposition(long\
    \ long n) {\n    std::map<long long, long long> m;\n    while (n > 1) {\n    \
    \    bool findFactor = false;\n        for (long long i = 2; i * i <= n; ++i)\
    \ {\n            if (n % i == 0) {\n                m[i]++;\n                n\
    \ /= i;\n                findFactor = true;\n                break;\n        \
    \    }\n        }\n        if (not findFactor) {\n            m[n]++;\n      \
    \      break;\n        }\n    }\n    return m;\n}\n#line 4 \"test/cpp/Math/prime_factor_decomposition1.test.cpp\"\
    \n#include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int N;\n    cin >> N;\n\n    auto pfd\
    \ = prime_factor_decomposition(N);\n    cout << N << \":\";\n    for (const auto\
    \ [p, n]: pfd) {\n        for (int _ = 0; _ < n; ++_) {\n            cout << \"\
    \ \" << p;\n        }\n    }\n    cout << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n\n#include \"library/cpp/Math/prime_factor_decomposition.cpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N;\n    cin >> N;\n\n    auto pfd = prime_factor_decomposition(N);\n\
    \    cout << N << \":\";\n    for (const auto [p, n]: pfd) {\n        for (int\
    \ _ = 0; _ < n; ++_) {\n            cout << \" \" << p;\n        }\n    }\n  \
    \  cout << endl;\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Math/prime_factor_decomposition.cpp
  isVerificationFile: true
  path: test/cpp/Math/prime_factor_decomposition1.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:43:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Math/prime_factor_decomposition1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Math/prime_factor_decomposition1.test.cpp
- /verify/test/cpp/Math/prime_factor_decomposition1.test.cpp.html
title: test/cpp/Math/prime_factor_decomposition1.test.cpp
---
