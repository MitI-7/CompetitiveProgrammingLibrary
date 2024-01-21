---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Algorithm/Imos.hpp
    title: library/cpp/Algorithm/Imos.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A
  bundledCode: "#line 1 \"test/cpp/Algorithm/Imos1.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A\"\n\n#line 1\
    \ \"library/cpp/Algorithm/Imos.hpp\"\n#include <vector>\n#include <iostream>\n\
    #include <cassert>\n\ntemplate<typename T>\nclass Imos {\npublic:\n    const int\
    \ n;\n    std::vector<T> line;\n\n    Imos(int n) : n(n) {\n        this->line.resize(n\
    \ + 1, 0);\n    }\n\n    // [left, right) \u306B +num\n    void add(const int\
    \ left, const int right, const T num) {\n        assert(left < right);\n     \
    \   this->line[left] += num;\n        this->line[right] -= num;\n    }\n\n   \
    \ void build() {\n        for (int i = 1; i < (int) line.size(); ++i) {\n    \
    \        this->line[i] += this->line[i - 1];\n        }\n    }\n\n    T access(const\
    \ int i) {\n        return this->line[i];\n    }\n};\n#line 5 \"test/cpp/Algorithm/Imos1.test.cpp\"\
    \n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, T;\n    cin >> N >> T;\n\n    Imos<int> imos(T + 100);\n    for (int\
    \ i = 0; i < N; ++i) {\n        int L, R;\n        cin >> L >> R;\n        imos.add(L,\
    \ R, 1);\n    }\n    imos.build();\n\n    int ans = 0;\n    for (int i = 0; i\
    \ <= T; ++i) {\n        ans = max(ans, imos.access(i));\n    }\n    cout << ans\
    \ << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A\"\
    \n\n#include \"library/cpp/Algorithm/Imos.hpp\"\n#include <iostream>\n\nusing\
    \ namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, T;\n    cin >> N >> T;\n\n    Imos<int> imos(T + 100);\n    for (int\
    \ i = 0; i < N; ++i) {\n        int L, R;\n        cin >> L >> R;\n        imos.add(L,\
    \ R, 1);\n    }\n    imos.build();\n\n    int ans = 0;\n    for (int i = 0; i\
    \ <= T; ++i) {\n        ans = max(ans, imos.access(i));\n    }\n    cout << ans\
    \ << endl;\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Algorithm/Imos.hpp
  isVerificationFile: true
  path: test/cpp/Algorithm/Imos1.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:44:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Algorithm/Imos1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Algorithm/Imos1.test.cpp
- /verify/test/cpp/Algorithm/Imos1.test.cpp.html
title: test/cpp/Algorithm/Imos1.test.cpp
---
