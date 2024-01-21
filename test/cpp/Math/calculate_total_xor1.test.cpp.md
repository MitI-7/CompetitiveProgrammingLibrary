---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/cpp/Math/calculate_total_xor.cpp
    title: library/cpp/Math/calculate_total_xor.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc121/tasks/abc121_d
    links:
    - https://atcoder.jp/contests/abc121/tasks/abc121_d
  bundledCode: "#line 1 \"test/cpp/Math/calculate_total_xor1.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc121/tasks/abc121_d\"\n\n#line 1 \"library/cpp/Math/calculate_total_xor.cpp\"\
    \n// [0, n] \u306E\u7DCF xor \u3092\u6C42\u3081\u308B\nlong long calculate_total_xor(long\
    \ long n) {\n    if (n < 0) {\n        return 0;\n    }\n\n    switch (n % 4)\
    \ {\n        case 0:\n            return n;\n        case 1:\n            return\
    \ 1;\n        case 2:\n            return n + 1;\n        case 3:\n          \
    \  return 0;\n    }\n\n    // \u3053\u3053\u306B\u306F\u3053\u306A\u3044\n   \
    \ return -1;\n}\n#line 4 \"test/cpp/Math/calculate_total_xor1.test.cpp\"\n#include\
    \ <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    long long A, B;\n    cin >> A >> B;\n\
    \n    cout << (calculate_total_xor(B) ^ calculate_total_xor(A) ^ A) << endl;\n\
    \n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc121/tasks/abc121_d\"\n\n\
    #include \"library/cpp/Math/calculate_total_xor.cpp\"\n#include <iostream>\n\n\
    using namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    long long A, B;\n    cin >> A >> B;\n\n    cout << (calculate_total_xor(B)\
    \ ^ calculate_total_xor(A) ^ A) << endl;\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Math/calculate_total_xor.cpp
  isVerificationFile: true
  path: test/cpp/Math/calculate_total_xor1.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:45:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/cpp/Math/calculate_total_xor1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Math/calculate_total_xor1.test.cpp
- /verify/test/cpp/Math/calculate_total_xor1.test.cpp.html
title: test/cpp/Math/calculate_total_xor1.test.cpp
---
