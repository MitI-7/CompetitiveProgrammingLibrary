---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Math/row_reduction_xor.cpp
    title: library/cpp/Math/row_reduction_xor.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc141/tasks/abc141_f
    links:
    - https://atcoder.jp/contests/abc141/tasks/abc141_f
  bundledCode: "#line 1 \"test/cpp/Math/row_reduction_xor.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc141/tasks/abc141_f\"\n\n#line 1 \"library/cpp/Math/row_reduction_xor.cpp\"\
    \n#include <vector>\n#include <bitset>\n\n// xor \u306E\u6383\u304D\u51FA\u3057\
    \u6CD5\n// O(nm)\nint row_reduction_xor(std::vector<std::bitset<60>> &matrix)\
    \ {\n    const int n = int(matrix.size());\n    const int m = int(matrix[0].size());\n\
    \n    int pos = 0;    // \u6700\u5F8C\u306E\u672A\u5B9A\u306E\u884C\n    // \u5217\
    (bit)\u3054\u3068\u306B\u6C7A\u3081\u3066\u3044\u304F\n    for (int b = m - 1;\
    \ b >= 0; --b) {\n        bool found = false;\n\n        // b bit \u76EE\u304C\
    \ 1 \u3068\u306A\u3063\u3066\u3044\u308B\u884C\u3092\u63A2\u3059\n        for\
    \ (int y = pos; y < n; ++y) {\n            if (matrix[y][b]) {\n             \
    \   if (y != pos) {\n                    swap(matrix[y], matrix[pos]);\n     \
    \           }\n                found = true;\n                break;\n       \
    \     }\n        }\n        if (found) {\n            // pos \u3068\u305D\u308C\
    \u4EE5\u5916\u306E\u3059\u3079\u3066\u306E\u884C\u3068\u3067 xor \u3092\u3068\u308A\
    \uFF0Cb bit \u76EE\u306F pos \u306E\u307F\u304C 1 \u306B\u306A\u308B\u3088\u3046\
    \u306B\u3059\u308B\n            for (int y = 0; y < n; ++y) {\n              \
    \  if (y != pos and matrix[y][b] == 1) {\n                    matrix[y] ^= matrix[pos];\n\
    \                }\n            }\n            ++pos;\n        }\n    }\n\n  \
    \  return pos;\n}\n#line 4 \"test/cpp/Math/row_reduction_xor.test.cpp\"\n#include\
    \ <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int N;\n    cin >> N;\n\n    bitset<60>\
    \ S = 0;\n    vector<bitset<60>> A(N);\n    for (int i = 0; i < N; ++i) {\n  \
    \      unsigned long long a;\n        cin >> a;\n        A[i] = a;\n        S\
    \ ^= A[i];\n    }\n\n    for (int i = 0; i < N; ++i) {\n        A[i] &= ~S;\n\
    \    }\n\n    row_reduction_xor(A);\n\n    bitset<60> a_and_b = 0;\n    for (int\
    \ i = 0; i < N; ++i) {\n        a_and_b ^= A[i];\n    }\n    cout << S.to_ullong()\
    \ + 2 * a_and_b.to_ullong() << endl;\n    \n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc141/tasks/abc141_f\"\n\n\
    #include \"library/cpp/Math/row_reduction_xor.cpp\"\n#include <iostream>\n\nusing\
    \ namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N;\n    cin >> N;\n\n    bitset<60> S = 0;\n    vector<bitset<60>> A(N);\n\
    \    for (int i = 0; i < N; ++i) {\n        unsigned long long a;\n        cin\
    \ >> a;\n        A[i] = a;\n        S ^= A[i];\n    }\n\n    for (int i = 0; i\
    \ < N; ++i) {\n        A[i] &= ~S;\n    }\n\n    row_reduction_xor(A);\n\n   \
    \ bitset<60> a_and_b = 0;\n    for (int i = 0; i < N; ++i) {\n        a_and_b\
    \ ^= A[i];\n    }\n    cout << S.to_ullong() + 2 * a_and_b.to_ullong() << endl;\n\
    \    \n    return 0;\n}"
  dependsOn:
  - library/cpp/Math/row_reduction_xor.cpp
  isVerificationFile: true
  path: test/cpp/Math/row_reduction_xor.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:49:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Math/row_reduction_xor.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Math/row_reduction_xor.test.cpp
- /verify/test/cpp/Math/row_reduction_xor.test.cpp.html
title: test/cpp/Math/row_reduction_xor.test.cpp
---
