---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Compression/CoordinateCompression.hpp
    title: library/cpp/Compression/CoordinateCompression.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc213/tasks/abc213_c
    links:
    - https://atcoder.jp/contests/abc213/tasks/abc213_c
  bundledCode: "#line 1 \"test/cpp/Compression/CoordinateCompression1.test.cpp\"\n\
    #define PROBLEM \"https://atcoder.jp/contests/abc213/tasks/abc213_c\"\n\n#line\
    \ 1 \"library/cpp/Compression/CoordinateCompression.hpp\"\n#include <cassert>\n\
    #include <set>\n#include <unordered_map>\n\ntemplate<class T=long long>\nclass\
    \ CoordinateCompression {\nprivate:\n    bool initialized;\n    std::set<T> s;\n\
    \n    int no = 0;\n    std::unordered_map<T, int> _zip;\n    std::unordered_map<int,\
    \ T> _unzip;\npublic:\n    CoordinateCompression() : initialized(false) {}\n\n\
    \    void add(T x) {\n        this->s.insert(x);\n    }\n\n    int size() {\n\
    \        if (not this->initialized) {\n            this->build();\n        }\n\
    \        return this->no;\n    }\n\n    // \u5143\u306E\u5024 -> \u5727\u7E2E\u3057\
    \u305F\u5024\n    int zip(const T x) {\n        if (not this->initialized) {\n\
    \            this->build();\n        }\n        return this->_zip[x];\n    }\n\
    \n    // \u5727\u7E2E\u3057\u305F\u5024 -> \u5143\u306E\u5024\n    T unzip(const\
    \ int i) {\n        if (not this->initialized) {\n            this->build();\n\
    \        }\n        assert(this->_unzip.contains(i));\n        return this->_unzip[i];\n\
    \    }\n\nprivate:\n    void build() {\n        this->initialized = true;\n  \
    \      for (auto x: this->s) {\n            this->_zip[x] = this->no;\n      \
    \      this->_unzip[this->no] = x;\n            this->no++;\n        }\n    }\n\
    };\n#line 4 \"test/cpp/Compression/CoordinateCompression1.test.cpp\"\n#include\
    \ <vector>\n#include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int H, W, N;\n    cin >> H >> W >> N;\n\
    \n    vector<pair<int, int>> cards(N);\n    CoordinateCompression<int> cy, cx;\n\
    \    for (int i = 0; i < N; ++i) {\n        int A, B;\n        cin >> A >> B;\n\
    \        cards[i] = {A, B};\n        cy.add(A);\n        cx.add(B);\n    }\n\n\
    \    for (auto [a, b]: cards) {\n        cout << cy.zip(a) + 1 << \" \" << cx.zip(b)\
    \ + 1 << endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc213/tasks/abc213_c\"\n\n\
    #include \"library/cpp/Compression/CoordinateCompression.hpp\"\n#include <vector>\n\
    #include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int H, W, N;\n    cin >> H >> W >> N;\n\
    \n    vector<pair<int, int>> cards(N);\n    CoordinateCompression<int> cy, cx;\n\
    \    for (int i = 0; i < N; ++i) {\n        int A, B;\n        cin >> A >> B;\n\
    \        cards[i] = {A, B};\n        cy.add(A);\n        cx.add(B);\n    }\n\n\
    \    for (auto [a, b]: cards) {\n        cout << cy.zip(a) + 1 << \" \" << cx.zip(b)\
    \ + 1 << endl;\n    }\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Compression/CoordinateCompression.hpp
  isVerificationFile: true
  path: test/cpp/Compression/CoordinateCompression1.test.cpp
  requiredBy: []
  timestamp: '2024-02-07 17:22:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Compression/CoordinateCompression1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Compression/CoordinateCompression1.test.cpp
- /verify/test/cpp/Compression/CoordinateCompression1.test.cpp.html
title: test/cpp/Compression/CoordinateCompression1.test.cpp
---
