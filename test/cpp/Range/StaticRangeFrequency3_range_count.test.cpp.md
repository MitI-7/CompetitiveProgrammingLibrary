---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Range/StaticRangeFrequency.hpp
    title: library/cpp/Range/StaticRangeFrequency.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_3_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_3_C
  bundledCode: "#line 1 \"test/cpp/Range/StaticRangeFrequency3_range_count.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_3_C\"\
    \n\n#line 1 \"library/cpp/Range/StaticRangeFrequency.hpp\"\n#include <unordered_map>\n\
    #include <vector>\n\n// vec \u306E\u533A\u9593 [l, r) \u306B\u51FA\u73FE\u3059\
    \u308B\u3042\u308B\u6574\u6570\u5024 x \u306E\u500B\u6570\u3092\u30AB\u30A6\u30F3\
    \u30C8\u3059\u308B\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B\nclass StaticRangeFrequency\
    \ {\npublic:\n    int n;\nprivate:\n    std::vector<int> vec;\n    std::unordered_map<int,\
    \ std::vector<int>> idx_list;  // \u5404\u5024\u306E\u51FA\u73FE\u3059\u308B index\n\
    \npublic:\n    explicit StaticRangeFrequency(std::vector<int> &vec) : n((int)\
    \ vec.size()), vec(vec) {\n        for (int i = 0; i < int(vec.size()); ++i) {\n\
    \            this->idx_list[vec[i]].emplace_back(i);\n        }\n    }\n\n   \
    \ // vec[i]\n    int get(const int i) const {\n        return this->vec[i];\n\
    \    }\n\n    // x \u3092 vec \u306E\u672B\u5C3E\u306B\u8FFD\u52A0\n    void emplace_back(const\
    \ int x) {\n        this->vec.emplace_back(x);\n        this->idx_list[x].emplace_back(this->n);\n\
    \        this->n++;\n    }\n\n    // x \u306E\u500B\u6570\u3092\u6C42\u3081\u308B\
    \n    int count(const int x) const {\n        if (not this->idx_list.contains(x))\
    \ {\n            return 0;\n        }\n        return int(this->idx_list.at(x).size());\n\
    \    }\n\n    // vec[l, r) \u306B\u5B58\u5728\u3059\u308B x \u306E\u500B\u6570\
    \u3092\u6C42\u3081\u308B\n    int range_count(int l, int r, int x) const {\n \
    \       if (this->count(x) == 0) {\n            return 0;\n        }\n\n     \
    \   const auto begin = this->idx_list.at(x).begin();\n        const auto end =\
    \ this->idx_list.at(x).end();\n        auto it_left = std::lower_bound(begin,\
    \ end, l);\n        if (it_left == end) {\n            return 0;\n        }\n\n\
    \        auto it_right = std::lower_bound(begin, end, r);\n        return (int)\
    \ std::distance(it_left, it_right);\n    }\n};\n#line 4 \"test/cpp/Range/StaticRangeFrequency3_range_count.test.cpp\"\
    \n#include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int N;\n    cin >> N;\n\n    vector<int>\
    \ A(N);\n    for (int i = 0; i < N; ++i) {\n        cin >> A[i];\n    }\n\n  \
    \  StaticRangeFrequency srf(A);\n\n    int Q;\n    cin >> Q;\n    for (int i =\
    \ 0; i < Q; ++i) {\n        int B, E, K;\n        cin >> B >> E >> K;\n      \
    \  cout << srf.range_count(B, E, K) << endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_3_C\"\
    \n\n#include \"library/cpp/Range/StaticRangeFrequency.hpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N;\n    cin >> N;\n\n    vector<int> A(N);\n    for (int i = 0; i <\
    \ N; ++i) {\n        cin >> A[i];\n    }\n\n    StaticRangeFrequency srf(A);\n\
    \n    int Q;\n    cin >> Q;\n    for (int i = 0; i < Q; ++i) {\n        int B,\
    \ E, K;\n        cin >> B >> E >> K;\n        cout << srf.range_count(B, E, K)\
    \ << endl;\n    }\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Range/StaticRangeFrequency.hpp
  isVerificationFile: true
  path: test/cpp/Range/StaticRangeFrequency3_range_count.test.cpp
  requiredBy: []
  timestamp: '2024-02-03 19:29:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Range/StaticRangeFrequency3_range_count.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Range/StaticRangeFrequency3_range_count.test.cpp
- /verify/test/cpp/Range/StaticRangeFrequency3_range_count.test.cpp.html
title: test/cpp/Range/StaticRangeFrequency3_range_count.test.cpp
---
