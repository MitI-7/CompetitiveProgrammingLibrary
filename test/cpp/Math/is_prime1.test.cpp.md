---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Math/is_prime.cpp
    title: library/cpp/Math/is_prime.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C
  bundledCode: "#line 1 \"test/cpp/Math/is_prime1.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C\"\
    \n\n#line 1 \"library/cpp/Math/is_prime.cpp\"\n// \u7D20\u6570\u5224\u5B9A\n//\
    \ O(sqrt(x))\nbool is_prime(int x) {\n    if (x == 2) {\n        return true;\n\
    \    }\n    if (x < 2 || x % 2 == 0) {\n        return false;\n    }\n\n    for\
    \ (int i = 3; i * i <= x; i += 2) {\n        if (x % i == 0) {\n            return\
    \ false;\n        }\n    }\n    return true;\n}\n#line 4 \"test/cpp/Math/is_prime1.test.cpp\"\
    \n#include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int N;\n    cin >> N;\n    int ans =\
    \ 0;\n    for (int i = 0; i < N; ++i) {\n        int X;\n        cin >> X;\n \
    \       ans += is_prime(X);\n    }\n    cout << ans << endl;\n\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C\"\
    \n\n#include \"library/cpp/Math/is_prime.cpp\"\n#include <iostream>\n\nusing namespace\
    \ std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N;\n    cin >> N;\n    int ans = 0;\n    for (int i = 0; i < N; ++i)\
    \ {\n        int X;\n        cin >> X;\n        ans += is_prime(X);\n    }\n \
    \   cout << ans << endl;\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Math/is_prime.cpp
  isVerificationFile: true
  path: test/cpp/Math/is_prime1.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:48:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Math/is_prime1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Math/is_prime1.test.cpp
- /verify/test/cpp/Math/is_prime1.test.cpp.html
title: test/cpp/Math/is_prime1.test.cpp
---
