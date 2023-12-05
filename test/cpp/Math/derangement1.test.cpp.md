---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/cpp/Utility/mint.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc172/tasks/abc172_e\"\n\n\
    #include \"library/cpp/Math/derangement.cpp\"\n#include \"library/cpp/Utility/mint.hpp\"\
    \n#include <iostream>\n\nusing namespace std;\n\nconst int MOD = 1000000007;\n\
    \nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n  \
    \  int N, M;\n    cin >> N >> M;\n\n    mint<MOD> ans = 1;\n    for (int i = 0;\
    \ i < N; ++i) {\n        ans *= M - i;\n    }\n    ans *= derangement<MOD>(N,\
    \ M);\n    cout << ans.x << endl;\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/cpp/Math/derangement1.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/cpp/Math/derangement1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Math/derangement1.test.cpp
- /verify/test/cpp/Math/derangement1.test.cpp.html
title: test/cpp/Math/derangement1.test.cpp
---
