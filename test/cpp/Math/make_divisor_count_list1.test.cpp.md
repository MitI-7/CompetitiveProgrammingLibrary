---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Math/make_divisor_count_list.cpp
    title: library/cpp/Math/make_divisor_count_list.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc172/tasks/abc172_d
    links:
    - https://atcoder.jp/contests/abc172/tasks/abc172_d
  bundledCode: "#line 1 \"test/cpp/Math/make_divisor_count_list1.test.cpp\"\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/abc172/tasks/abc172_d\"\n\n#line 1 \"\
    library/cpp/Math/make_divisor_count_list.cpp\"\n#include <vector>\n\n// [1, n]\u306E\
    \u5404\u5024\u306B\u3064\u3044\u3066\u7D04\u6570\u306E\u500B\u6570\u3092\u683C\
    \u7D0D\u3057\u305F\u914D\u5217\u3092\u4F5C\u6210\n// O(n log n)\nstd::vector<int>\
    \ make_divisor_count_list(const int n) {\n    std::vector<int> divisor_count_list(n\
    \ + 1);\n    for (int d = 1; d <= n; ++d) {\n        for (long long i = d; i <=\
    \ n; i += d) {\n            divisor_count_list[i]++;\n        }\n    }\n    return\
    \ divisor_count_list;\n}\n#line 4 \"test/cpp/Math/make_divisor_count_list1.test.cpp\"\
    \n#include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int N;\n    cin >> N;\n\n    auto divisor_count_list\
    \ = make_divisor_count_list(N);\n    long long ans = 0;\n    for (long long k\
    \ = 1; k <= N; ++k) {\n        ans += k * divisor_count_list[k];\n    }\n    cout\
    \ << ans << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc172/tasks/abc172_d\"\n\n\
    #include \"library/cpp/Math/make_divisor_count_list.cpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N;\n    cin >> N;\n\n    auto divisor_count_list = make_divisor_count_list(N);\n\
    \    long long ans = 0;\n    for (long long k = 1; k <= N; ++k) {\n        ans\
    \ += k * divisor_count_list[k];\n    }\n    cout << ans << endl;\n\n    return\
    \ 0;\n}"
  dependsOn:
  - library/cpp/Math/make_divisor_count_list.cpp
  isVerificationFile: true
  path: test/cpp/Math/make_divisor_count_list1.test.cpp
  requiredBy: []
  timestamp: '2023-11-12 11:34:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Math/make_divisor_count_list1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Math/make_divisor_count_list1.test.cpp
- /verify/test/cpp/Math/make_divisor_count_list1.test.cpp.html
title: test/cpp/Math/make_divisor_count_list1.test.cpp
---
