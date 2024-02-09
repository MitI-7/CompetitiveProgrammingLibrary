---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Math/make_divisor_list_in_list.cpp
    title: library/cpp/Math/make_divisor_list_in_list.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc215/tasks/abc215_d
    links:
    - https://atcoder.jp/contests/abc215/tasks/abc215_d
  bundledCode: "#line 1 \"test/cpp/Math/make_divisor_list_in_list1.test.cpp\"\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/abc215/tasks/abc215_d\"\n\n#line 1 \"\
    library/cpp/Math/make_divisor_list_in_list.cpp\"\n#include <vector>\n\n// \u914D\
    \u5217 v \u306E\u8981\u7D20\u306E\u7D04\u6570\u3092\u5217\u6319\n// O(maxi log\
    \ maxi)\nstd::vector<int> make_divisor_list_in_list(const std::vector<int> &v,\
    \ const int maxi) {\n    if (v.empty()) {\n        return {};\n    }\n\n    std::vector<bool>\
    \ used(maxi + 1);\n    for (const auto a: v) {\n        used[a] = true;\n    }\n\
    \n    std::vector<int> divisor_list = {1};\n    for (int i = 2; i <= maxi; ++i)\
    \ {\n        bool is_divisor = false;\n        for (int j = i; j <= maxi; j +=\
    \ i) {\n            if (used[j]) {\n                is_divisor = true;\n     \
    \           break;\n            }\n        }\n        if (is_divisor) {\n    \
    \        divisor_list.emplace_back(i);\n        }\n    }\n\n    return divisor_list;\n\
    }\n#line 4 \"test/cpp/Math/make_divisor_list_in_list1.test.cpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, M;\n    cin >> N >> M;\n    vector<int> A(N);\n    for (int i = 0;\
    \ i < N; ++i) {\n        cin >> A[i];\n    }\n\n    const auto divisor_list =\
    \ make_divisor_list_in_list(A, 100001);\n\n    vector<bool> ok(100001, true);\n\
    \    for (const auto d: divisor_list) {\n        if (d == 1) {\n            continue;\n\
    \        }\n        for (int i = d; i <= M; i += d) {\n            ok[i] = false;\n\
    \        }\n    }\n\n    vector<int> ans;\n    for (int i = 1; i <= M; ++i) {\n\
    \        if (ok[i]) {\n            ans.emplace_back(i);\n        }\n    }\n\n\
    \    cout << ans.size() << endl;\n    for (const auto a: ans) {\n        cout\
    \ << a << endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc215/tasks/abc215_d\"\n\n\
    #include \"library/cpp/Math/make_divisor_list_in_list.cpp\"\n#include <iostream>\n\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, M;\n    cin >> N >> M;\n    vector<int> A(N);\n    for (int i = 0;\
    \ i < N; ++i) {\n        cin >> A[i];\n    }\n\n    const auto divisor_list =\
    \ make_divisor_list_in_list(A, 100001);\n\n    vector<bool> ok(100001, true);\n\
    \    for (const auto d: divisor_list) {\n        if (d == 1) {\n            continue;\n\
    \        }\n        for (int i = d; i <= M; i += d) {\n            ok[i] = false;\n\
    \        }\n    }\n\n    vector<int> ans;\n    for (int i = 1; i <= M; ++i) {\n\
    \        if (ok[i]) {\n            ans.emplace_back(i);\n        }\n    }\n\n\
    \    cout << ans.size() << endl;\n    for (const auto a: ans) {\n        cout\
    \ << a << endl;\n    }\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Math/make_divisor_list_in_list.cpp
  isVerificationFile: true
  path: test/cpp/Math/make_divisor_list_in_list1.test.cpp
  requiredBy: []
  timestamp: '2024-02-09 18:17:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Math/make_divisor_list_in_list1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Math/make_divisor_list_in_list1.test.cpp
- /verify/test/cpp/Math/make_divisor_list_in_list1.test.cpp.html
title: test/cpp/Math/make_divisor_list_in_list1.test.cpp
---
