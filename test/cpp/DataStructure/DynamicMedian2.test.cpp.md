---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/cpp/Tree/Tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc218/tasks/abc218_g\"\n\n\
    #include \"library/cpp/DataStructure/DynamicMedian.hpp\"\n#include \"library/cpp/Tree/Tree.hpp\"\
    \n#include <iostream>\n\nusing namespace std;\n\nvector<int> A;\n\nint dfs(int\
    \ u, int no, int p, DynamicMedian<int> &dm, Tree<int> &tree) {\n\n    int ans\
    \ = no % 2 == 0 ? 0 : 1000000100;\n    dm.insert(A[u]);\n\n    for (auto e: tree[u])\
    \ {\n        if (e.to != p) {\n            auto m = dfs(e.to, no + 1, u, dm, tree);\n\
    \            ans = (no % 2 == 0) ? max(ans, m) : min(ans, m);\n        }\n   \
    \ }\n\n    // \u8449\n    if (ans == 0 or ans == 1000000100) {\n        auto [a,\
    \ b] = dm.find_median();\n        ans = (a + b) / 2;\n    }\n    dm.erase(A[u]);\n\
    \n    return ans;\n}\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N;\n    cin >> N;\n    A.resize(N);\n    for (int i = 0; i < N; ++i)\
    \ {\n        cin >> A[i];\n    }\n\n    Tree<int> tree(N);\n    for (int i = 0;\
    \ i < N - 1; ++i) {\n        int U, V;\n        cin >> U >> V;\n        U--;\n\
    \        V--;\n        tree.add_undirected_edge(U, V);\n    }\n\n    DynamicMedian<int>\
    \ dm;\n    cout << dfs(0, 0, -1, dm, tree) << endl;\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/cpp/DataStructure/DynamicMedian2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/cpp/DataStructure/DynamicMedian2.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/DataStructure/DynamicMedian2.test.cpp
- /verify/test/cpp/DataStructure/DynamicMedian2.test.cpp.html
title: test/cpp/DataStructure/DynamicMedian2.test.cpp
---
