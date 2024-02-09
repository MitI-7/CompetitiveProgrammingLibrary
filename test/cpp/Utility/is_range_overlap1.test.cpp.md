---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/cpp/Utility/is_range_overlap.cpp
    title: library/cpp/Utility/is_range_overlap.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc207/tasks/abc207_c
    links:
    - https://atcoder.jp/contests/abc207/tasks/abc207_c
  bundledCode: "#line 1 \"test/cpp/Utility/is_range_overlap1.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc207/tasks/abc207_c\"\n\n#line 1 \"library/cpp/Utility/is_range_overlap.cpp\"\
    \n#include <cassert>\n\n// \u9589\u533A\u9593[l1, r1] \u3068 [l2, r2] \u306B\u91CD\
    \u306A\u308A\u304C\u3042\u308B\u304B\u5224\u5B9A\ntemplate<typename T>\nbool is_range_overlap(T\
    \ l1, T r1, T l2, T r2) {\n    assert(l1 <= r1);\n    assert(l2 <= r2);\n    \n\
    \    // l2 in [l1, r1]\n    if (l1 <= l2 and l2 <= r1) {\n        return true;\n\
    \    }\n    // r2 in [l1, r1]\n    if (l1 <= r2 and r2 <= r1) {\n        return\
    \ true;\n    }\n    // l1 in [l2, r2]\n    if (l2 <= l1 and l1 <= r2) {\n    \
    \    return true;\n    }\n    // r1 in [l2, r2]\n    if (l2 <= r1 and r1 <= r2)\
    \ {\n        return true;\n    }\n    return false;\n}\n#line 4 \"test/cpp/Utility/is_range_overlap1.test.cpp\"\
    \n#include <iostream>\n#include <vector>\n\nusing namespace std;\n\nint main()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    int N;\n \
    \   cin >> N;\n\n    vector<pair<int, int>> v(N);\n    for (int i = 0; i < N;\
    \ ++i) {\n        int T, L, R;\n        cin >> T >> L >> R;\n        L *= 2;\n\
    \        R *= 2;\n        if (T == 2) {\n            R--;\n        } else if (T\
    \ == 3) {\n            L++;\n        } else if (T == 4) {\n            L++;\n\
    \            R--;\n        }\n        v[i] = {L, R};\n    }\n\n    int ans = 0;\n\
    \    for (int i = 0; i < N; ++i) {\n        for (int j = i + 1; j < N; ++j) {\n\
    \            const auto [l1, r1] = v[i];\n            const auto [l2, r2] = v[j];\n\
    \            ans += is_range_overlap(l1, r1, l2, r2);\n        }\n    }\n    cout\
    \ << ans << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc207/tasks/abc207_c\"\n\n\
    #include \"library/cpp/Utility/is_range_overlap.cpp\"\n#include <iostream>\n#include\
    \ <vector>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n  \
    \  ios::sync_with_stdio(false);\n\n    int N;\n    cin >> N;\n\n    vector<pair<int,\
    \ int>> v(N);\n    for (int i = 0; i < N; ++i) {\n        int T, L, R;\n     \
    \   cin >> T >> L >> R;\n        L *= 2;\n        R *= 2;\n        if (T == 2)\
    \ {\n            R--;\n        } else if (T == 3) {\n            L++;\n      \
    \  } else if (T == 4) {\n            L++;\n            R--;\n        }\n     \
    \   v[i] = {L, R};\n    }\n\n    int ans = 0;\n    for (int i = 0; i < N; ++i)\
    \ {\n        for (int j = i + 1; j < N; ++j) {\n            const auto [l1, r1]\
    \ = v[i];\n            const auto [l2, r2] = v[j];\n            ans += is_range_overlap(l1,\
    \ r1, l2, r2);\n        }\n    }\n    cout << ans << endl;\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Utility/is_range_overlap.cpp
  isVerificationFile: true
  path: test/cpp/Utility/is_range_overlap1.test.cpp
  requiredBy: []
  timestamp: '2024-02-03 22:22:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/cpp/Utility/is_range_overlap1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Utility/is_range_overlap1.test.cpp
- /verify/test/cpp/Utility/is_range_overlap1.test.cpp.html
title: test/cpp/Utility/is_range_overlap1.test.cpp
---
