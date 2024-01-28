---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Math/is_odd_permutation.cpp
    title: library/cpp/Math/is_odd_permutation.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc296/tasks/abc296_f
    links:
    - https://atcoder.jp/contests/abc296/tasks/abc296_f
  bundledCode: "#line 1 \"test/cpp/Math/is_odd_permutation1.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc296/tasks/abc296_f\"\n\n#line 1 \"library/cpp/Math/is_odd_permutation.cpp\"\
    \n#include <vector>\n\n// \u5076\u7F6E\u63DB\u304B\u5947\u7F6E\u63DB\u304B\u5224\
    \u5B9A\u3059\u308B\n// A \u306F 0 \u304B\u3089 N - 1 \u306E\u9806\u5217\u3067\u3042\
    \u308B\u3053\u3068\n// O(N)\ntemplate<typename T>\nbool is_odd_permutation(std::vector<T>\
    \ &A) {\n    const int N = A.size();\n    int num_cycle = 0;\n    std::vector<bool>\
    \ used(N);\n    for (int u = 0; u < N; ++u) {\n        if (used[u]) {\n      \
    \      continue;\n        }\n        int v = u;\n        while (not used[v]) {\n\
    \            used[v] = true;\n            v = A[v];\n        }\n        num_cycle++;\n\
    \    }\n\n    return num_cycle % 2;\n}\n#line 4 \"test/cpp/Math/is_odd_permutation1.test.cpp\"\
    \n#include <algorithm>\n#include <iostream>\n#include <set>\n\nusing namespace\
    \ std;\n\nbool solve(vector<int> &A, vector<int> &B) {\n    {\n        auto C\
    \ = A;\n        auto D = B;\n        std::sort(C.begin(), C.end());\n        std::sort(D.begin(),\
    \ D.end());\n        if (C != D) {\n            return false;\n        }\n   \
    \ }\n\n    {\n        set<int> s(A.begin(), A.end());\n        if (s.size() !=\
    \ A.size()) {\n            return true;\n        }\n    }\n\n    return is_odd_permutation(A)\
    \ == is_odd_permutation(B);\n}\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N;\n    cin >> N;\n    vector<int> A(N), B(N);\n    for (int i = 0;\
    \ i < N; ++i) {\n        cin >> A[i];\n        A[i]--;\n    }\n    for (int i\
    \ = 0; i < N; ++i) {\n        cin >> B[i];\n        B[i]--;\n    }\n\n    if (solve(A,\
    \ B)) {\n        cout << \"Yes\" << endl;\n    }\n    else {\n        cout <<\
    \ \"No\" << endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc296/tasks/abc296_f\"\n\n\
    #include \"library/cpp/Math/is_odd_permutation.cpp\"\n#include <algorithm>\n#include\
    \ <iostream>\n#include <set>\n\nusing namespace std;\n\nbool solve(vector<int>\
    \ &A, vector<int> &B) {\n    {\n        auto C = A;\n        auto D = B;\n   \
    \     std::sort(C.begin(), C.end());\n        std::sort(D.begin(), D.end());\n\
    \        if (C != D) {\n            return false;\n        }\n    }\n\n    {\n\
    \        set<int> s(A.begin(), A.end());\n        if (s.size() != A.size()) {\n\
    \            return true;\n        }\n    }\n\n    return is_odd_permutation(A)\
    \ == is_odd_permutation(B);\n}\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N;\n    cin >> N;\n    vector<int> A(N), B(N);\n    for (int i = 0;\
    \ i < N; ++i) {\n        cin >> A[i];\n        A[i]--;\n    }\n    for (int i\
    \ = 0; i < N; ++i) {\n        cin >> B[i];\n        B[i]--;\n    }\n\n    if (solve(A,\
    \ B)) {\n        cout << \"Yes\" << endl;\n    }\n    else {\n        cout <<\
    \ \"No\" << endl;\n    }\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Math/is_odd_permutation.cpp
  isVerificationFile: true
  path: test/cpp/Math/is_odd_permutation1.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:47:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Math/is_odd_permutation1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Math/is_odd_permutation1.test.cpp
- /verify/test/cpp/Math/is_odd_permutation1.test.cpp.html
title: test/cpp/Math/is_odd_permutation1.test.cpp
---
