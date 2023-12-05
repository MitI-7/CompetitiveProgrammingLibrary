---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Math/make_divisor_list.cpp
    title: library/cpp/Math/make_divisor_list.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D
  bundledCode: "#line 1 \"test/cpp/Math/make_divisor_list1.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D\"\n\n#line\
    \ 1 \"library/cpp/Math/make_divisor_list.cpp\"\n#include <vector>\n#include <algorithm>\n\
    \n// n \u306E\u7D04\u6570\u3092\u5217\u6319\u3059\u308B\n// O(sqrt(n))\n// n <=\
    \ 10^9 \u3067\u6700\u5927 1344 \u500B\uFF0Cn <= 10^18 \u3067\u6700\u5927 103680\
    \ \u500B\u306E\u7D04\u6570\u304C\u3042\u308B\nstd::vector<long long> make_divisor_list(long\
    \ long n) {\n    std::vector<long long> ret;\n    for (long long i = 1; i * i\
    \ <= n; ++i) {\n        if (n % i == 0) {\n            ret.emplace_back(i);\n\
    \            if (i * i != n) {\n                ret.emplace_back(n / i);\n   \
    \         }\n        }\n    }\n    std::sort(ret.begin(), ret.end());\n    return\
    \ ret;\n}\n#line 4 \"test/cpp/Math/make_divisor_list1.test.cpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    long long A, B, C;\n    cin >> A >> B >> C;\n\n    auto divisor_list = make_divisor_list(C);\n\
    \    int ans = 0;\n    for (const auto d: divisor_list) {\n        ans += (A <=\
    \ d and d <= B);\n    }\n    cout << ans << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D\"\
    \n\n#include \"library/cpp/Math/make_divisor_list.cpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    long long A, B, C;\n    cin >> A >> B >> C;\n\n    auto divisor_list = make_divisor_list(C);\n\
    \    int ans = 0;\n    for (const auto d: divisor_list) {\n        ans += (A <=\
    \ d and d <= B);\n    }\n    cout << ans << endl;\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Math/make_divisor_list.cpp
  isVerificationFile: true
  path: test/cpp/Math/make_divisor_list1.test.cpp
  requiredBy: []
  timestamp: '2023-05-20 15:21:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Math/make_divisor_list1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Math/make_divisor_list1.test.cpp
- /verify/test/cpp/Math/make_divisor_list1.test.cpp.html
title: test/cpp/Math/make_divisor_list1.test.cpp
---
