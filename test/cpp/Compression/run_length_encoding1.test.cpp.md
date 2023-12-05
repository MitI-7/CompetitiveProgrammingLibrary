---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Compression/run_length_encoding.cpp
    title: library/cpp/Compression/run_length_encoding.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc259/tasks/abc259_c
    links:
    - https://atcoder.jp/contests/abc259/tasks/abc259_c
  bundledCode: "#line 1 \"test/cpp/Compression/run_length_encoding1.test.cpp\"\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/abc259/tasks/abc259_c\"\n\n#line 1 \"\
    library/cpp/Compression/run_length_encoding.cpp\"\n#include <string>\n#include\
    \ <vector>\n\nstd::vector<std::pair<char, int>> run_length_encoding(const std::string\
    \ &s) {\n    std::vector<std::pair<char, int>> ans;\n\n    const int n = s.size();\n\
    \    int num = 1;\n    for (int i = 0; i < n - 1; ++i) {\n        if (s[i] ==\
    \ s[i + 1]) {\n            num++;\n        }\n        else {\n            ans.emplace_back(s[i],\
    \ num);\n            num = 1;\n        }\n    }\n    ans.emplace_back(s.back(),\
    \ num);\n\n    return ans;\n}\n#line 4 \"test/cpp/Compression/run_length_encoding1.test.cpp\"\
    \n#include <iostream>\n\nusing namespace std;\n\nbool solve(string &S, string\
    \ &T) {\n    auto s = run_length_encoding(S);\n    auto t = run_length_encoding(T);\n\
    \n    if (s.size() != t.size()) {\n        return false;\n    }\n\n    for (int\
    \ i = 0; i < (int) s.size(); ++i) {\n        if (s[i].first != t[i].first) {\n\
    \            return false;\n        }\n        if (s[i].second > t[i].second)\
    \ {\n            return false;\n        }\n        if (s[i].second < t[i].second\
    \ and s[i].second == 1) {\n            return false;\n        }\n    }\n\n   \
    \ return true;\n}\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \n    string S, T;\n    cin >> S >> T;\n\n    if (solve(S, T)) {\n        cout\
    \ << \"Yes\" << endl;\n    }\n    else {\n        cout << \"No\" << endl;\n  \
    \  }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc259/tasks/abc259_c\"\n\n\
    #include \"library/cpp/Compression/run_length_encoding.cpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\nbool solve(string &S, string &T) {\n    auto s = run_length_encoding(S);\n\
    \    auto t = run_length_encoding(T);\n\n    if (s.size() != t.size()) {\n   \
    \     return false;\n    }\n\n    for (int i = 0; i < (int) s.size(); ++i) {\n\
    \        if (s[i].first != t[i].first) {\n            return false;\n        }\n\
    \        if (s[i].second > t[i].second) {\n            return false;\n       \
    \ }\n        if (s[i].second < t[i].second and s[i].second == 1) {\n         \
    \   return false;\n        }\n    }\n\n    return true;\n}\n\nint main() {\n \
    \   cin.tie(0);\n    ios::sync_with_stdio(false);\n\n    string S, T;\n    cin\
    \ >> S >> T;\n\n    if (solve(S, T)) {\n        cout << \"Yes\" << endl;\n   \
    \ }\n    else {\n        cout << \"No\" << endl;\n    }\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Compression/run_length_encoding.cpp
  isVerificationFile: true
  path: test/cpp/Compression/run_length_encoding1.test.cpp
  requiredBy: []
  timestamp: '2023-12-05 09:37:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Compression/run_length_encoding1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Compression/run_length_encoding1.test.cpp
- /verify/test/cpp/Compression/run_length_encoding1.test.cpp.html
title: test/cpp/Compression/run_length_encoding1.test.cpp
---
