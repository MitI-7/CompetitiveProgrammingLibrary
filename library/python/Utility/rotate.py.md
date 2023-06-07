---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/python/Utility/rotate1.test.py
    title: test/python/Utility/rotate1.test.py
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# 2\u6B21\u5143\u884C\u5217\u3092\u53F3\u306B90\u5EA6\u56DE\u8EE2\ndef rotate(A):\n\
    \    H, W = len(A), len(A[0])\n    ans = [[None] * H for _ in range(W)]\n\n  \
    \  for y in range(H):\n        for x in range(W):\n            ans[W - 1 - x][y]\
    \ = A[y][x]\n\n    return ans\n"
  dependsOn: []
  isVerificationFile: false
  path: library/python/Utility/rotate.py
  requiredBy: []
  timestamp: '2023-06-07 17:58:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/python/Utility/rotate1.test.py
documentation_of: library/python/Utility/rotate.py
layout: document
redirect_from:
- /library/library/python/Utility/rotate.py
- /library/library/python/Utility/rotate.py.html
title: library/python/Utility/rotate.py
---
