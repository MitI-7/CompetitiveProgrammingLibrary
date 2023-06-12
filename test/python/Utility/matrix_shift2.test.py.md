---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/python/Utility/matrix_shift.py
    title: library/python/Utility/matrix_shift.py
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc300/tasks/abc300_b
    links:
    - https://atcoder.jp/contests/abc300/tasks/abc300_b
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verification-helper: PROBLEM https://atcoder.jp/contests/abc300/tasks/abc300_b\n\
    \nfrom library.python.Utility.matrix_shift import shift_left_y, shift_up_x\n\n\
    \ndef main():\n    H, W = map(int, input().split())\n    A, B = [], []\n    for\
    \ _ in range(H):\n        A.append(list(input()))\n    for _ in range(H):\n  \
    \      B.append(list(input()))\n\n    for i in range(H):\n        for j in range(W):\n\
    \            if A == B:\n                print(\"Yes\")\n                return\n\
    \n            for y in range(H):\n                shift_left_y(y, A)\n\n     \
    \   for x in range(W):\n            shift_up_x(x, A)\n\n    print(\"No\")\n\n\n\
    if __name__ == '__main__':\n    main()\n"
  dependsOn:
  - library/python/Utility/matrix_shift.py
  isVerificationFile: true
  path: test/python/Utility/matrix_shift2.test.py
  requiredBy: []
  timestamp: '2023-06-10 11:24:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/python/Utility/matrix_shift2.test.py
layout: document
redirect_from:
- /verify/test/python/Utility/matrix_shift2.test.py
- /verify/test/python/Utility/matrix_shift2.test.py.html
title: test/python/Utility/matrix_shift2.test.py
---
