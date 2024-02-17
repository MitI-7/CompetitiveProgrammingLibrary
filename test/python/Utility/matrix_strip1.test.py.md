---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/python/Utility/matrix_strip.py
    title: library/python/Utility/matrix_strip.py
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc307/tasks/abc307_c
    links:
    - https://atcoder.jp/contests/abc307/tasks/abc307_c
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verification-helper: PROBLEM https://atcoder.jp/contests/abc307/tasks/abc307_c\n\
    \nfrom library.python.Utility.matrix_strip import matrix_strip\n\n\ndef main():\n\
    \    HA, WA = map(int, input().split())\n    A = [input() for _ in range(HA)]\n\
    \n    HB, WB = map(int, input().split())\n    B = [input() for _ in range(HB)]\n\
    \n    HX, WX = map(int, input().split())\n    X = [input() for _ in range(HX)]\n\
    \n    A, B, X = matrix_strip(A, '#'), matrix_strip(B, '#'), matrix_strip(X, '#')\n\
    \n    HA, WA = len(A), len(A[0])\n    HB, WB = len(B), len(B[0])\n    HX, WX =\
    \ len(X), len(X[0])\n    for sy_a in range(HX - HA + 1):\n        for sx_a in\
    \ range(WX - WA + 1):\n            for sy_b in range(HX - HB + 1):\n         \
    \       for sx_b in range(WX - WB + 1):\n\n                    ans = [[\".\"]\
    \ * WX for _ in range(HX)]\n                    for y in range(HA):\n        \
    \                for x in range(WA):\n                            if A[y][x] ==\
    \ '#':\n                                ans[sy_a + y][sx_a + x] = A[y][x]\n  \
    \                  for y in range(HB):\n                        for x in range(WB):\n\
    \                            if B[y][x] == '#':\n                            \
    \    ans[sy_b + y][sx_b + x] = B[y][x]\n\n                    if ans == X:\n \
    \                       print(\"Yes\")\n                        return\n    print(\"\
    No\")\n\n\nif __name__ == '__main__':\n    main()\n"
  dependsOn:
  - library/python/Utility/matrix_strip.py
  isVerificationFile: true
  path: test/python/Utility/matrix_strip1.test.py
  requiredBy: []
  timestamp: '2024-01-28 13:43:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/python/Utility/matrix_strip1.test.py
layout: document
redirect_from:
- /verify/test/python/Utility/matrix_strip1.test.py
- /verify/test/python/Utility/matrix_strip1.test.py.html
title: test/python/Utility/matrix_strip1.test.py
---
