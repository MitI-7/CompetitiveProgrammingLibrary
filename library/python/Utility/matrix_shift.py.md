---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/python/Utility/matrix_shift1.test.py
    title: test/python/Utility/matrix_shift1.test.py
  - icon: ':x:'
    path: test/python/Utility/matrix_shift2.test.py
    title: test/python/Utility/matrix_shift2.test.py
  _isVerificationFailed: true
  _pathExtension: py
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# 2 \u6B21\u5143\u884C\u5217 A \u306E y \u884C\u3092\u53F3\u306B\u30B7\u30D5\
    \u30C8\ndef shift_right_y(y, A):\n    back = A[y][-1]\n    for x in range(len(A[0])\
    \ - 1, 0, -1):\n        A[y][x] = A[y][x - 1]\n    A[y][0] = back\n\n\n# 2 \u6B21\
    \u5143\u884C\u5217 A \u306E y \u884C\u3092\u5DE6\u306B\u30B7\u30D5\u30C8\ndef\
    \ shift_left_y(y, A):\n    back = A[y][0]\n    for x in range(1, len(A[0])):\n\
    \        A[y][x - 1] = A[y][x]\n    A[y][-1] = back\n\n\n# 2 \u6B21\u5143\u884C\
    \u5217 A \u306E x \u5217\u3092\u4E0A\u306B\u30B7\u30D5\u30C8\ndef shift_up_x(x,\
    \ A):\n    back = A[0][x]\n    for y in range(1, len(A)):\n        A[y - 1][x]\
    \ = A[y][x]\n    A[-1][x] = back\n\n\n# 2 \u6B21\u5143\u884C\u5217 A \u306E x\
    \ \u5217\u3092\u4E0B\u306B\u30B7\u30D5\u30C8\ndef shift_down_x(x, A):\n    back\
    \ = A[-1][x]\n    for y in range(len(A) - 1, 0, -1):\n        A[y][x] = A[y -\
    \ 1][x]\n    A[0][x] = back\n"
  dependsOn: []
  isVerificationFile: false
  path: library/python/Utility/matrix_shift.py
  requiredBy: []
  timestamp: '2024-01-20 16:48:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/python/Utility/matrix_shift2.test.py
  - test/python/Utility/matrix_shift1.test.py
documentation_of: library/python/Utility/matrix_shift.py
layout: document
redirect_from:
- /library/library/python/Utility/matrix_shift.py
- /library/library/python/Utility/matrix_shift.py.html
title: library/python/Utility/matrix_shift.py
---
