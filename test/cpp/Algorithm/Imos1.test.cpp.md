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
    \ \"library/cpp/Algorithm/Imos.hpp\"\n#include <cassert>\n#include <iostream>\n\
    #include <vector>\n\ntemplate<typename T>\nclass Imos {\npublic:\n    const int\
    \ n;\n    std::vector<T> line;\n\n    Imos(int n) : n(n) {\n        this->line.resize(n\
    \ + 1, 0);\n    }\n\n    // [left, right) \u306B +x\n    void add(const int left,\
    \ const int right, const T x) {\n        if (left == right) {\n            return;\n\
    \        }\n        assert(left < right);\n        this->line[left] += x;\n  \
    \      this->line[right] -= x;\n    }\n\n    // [left, right) += x\n    // \u52A0\
    \u7B97\u4F4D\u7F6E\u304C n \u4EE5\u4E0A\u306E\u5834\u5408\u306F 0 \u306B\u623B\
    \u3063\u3066\u52A0\u7B97\u3055\u308C\u308B\n    // O(log n)\n    void add_circle(long\
    \ long left, long long right, const T x) {\n        assert(left < right);\n\n\
    \        const long long num_loop = (right - left) / this->n;\n        this->add(0,\
    \ this->n, x * num_loop);\n\n        // \u30EB\u30FC\u30D7\u3067\u7D42\u308F\u308A\
    \n        if ((right - left) % this->n == 0) {\n            return;\n        }\n\
    \n        left %= this->n;\n        right %= this->n;\n\n        if (left < right)\
    \ {\n            this->add(left, right, x);\n        } else {\n            this->add(left,\
    \ this->n, x);\n            this->add(0, right, x);\n        }\n    }\n\n    void\
    \ build() {\n        for (int i = 1; i < (int) line.size(); ++i) {\n         \
    \   this->line[i] += this->line[i - 1];\n        }\n    }\n\n    T access(const\
    \ int i) const {\n        return this->line[i];\n    }\n\n    void dump() const\
    \ {\n        for (int i = 0; i < this->n; ++i) {\n            if (i != 0) {\n\
    \                std::cout << \" \";\n            }\n            std::cout <<\
    \ this->access(i);\n        }\n        std::cout << std::endl;\n    }\n};\n#line\
    \ 5 \"test/cpp/Algorithm/Imos1.test.cpp\"\n\nusing namespace std;\n\nint main()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    int N, T;\n\
    \    cin >> N >> T;\n\n    Imos<int> imos(T + 100);\n    for (int i = 0; i < N;\
    \ ++i) {\n        int L, R;\n        cin >> L >> R;\n        imos.add(L, R, 1);\n\
    \    }\n    imos.build();\n\n    int ans = 0;\n    for (int i = 0; i <= T; ++i)\
    \ {\n        ans = max(ans, imos.access(i));\n    }\n    cout << ans << endl;\n\
    \n    return 0;\n}\n"
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
