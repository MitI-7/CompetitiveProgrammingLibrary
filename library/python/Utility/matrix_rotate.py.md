---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# 2\u6B21\u5143\u884C\u5217\u3092\u53F3\u306B90\u5EA6\u56DE\u8EE2\ndef matrix_rotate(A):\n\
    \    H, W = len(A), len(A[0])\n    ans = [[None] * H for _ in range(W)]\n\n  \
    \  for y in range(H):\n        for x in range(W):\n            ans[W - 1 - x][y]\
    \ = A[y][x]\n\n    return ans\n"
  dependsOn: []
  isVerificationFile: false
  path: library/python/Utility/matrix_rotate.py
  requiredBy: []
  timestamp: '2024-01-28 11:56:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/python/Utility/matrix_rotate.py
layout: document
redirect_from:
- /library/library/python/Utility/matrix_rotate.py
- /library/library/python/Utility/matrix_rotate.py.html
title: library/python/Utility/matrix_rotate.py
---
