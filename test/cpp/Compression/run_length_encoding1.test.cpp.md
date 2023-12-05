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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/cpp/Utility/run_length_encoding.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc259/tasks/abc259_c\"\n\n\
    #include \"library/cpp/Utility/run_length_encoding.cpp\"\n#include <iostream>\n\
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
  dependsOn: []
  isVerificationFile: true
  path: test/cpp/Compression/run_length_encoding1.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/cpp/Compression/run_length_encoding1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Compression/run_length_encoding1.test.cpp
- /verify/test/cpp/Compression/run_length_encoding1.test.cpp.html
title: test/cpp/Compression/run_length_encoding1.test.cpp
---
