---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/python/Utility/matrix_rotate.py
    title: library/python/Utility/matrix_rotate.py
  - icon: ':heavy_check_mark:'
    path: library/python/Utility/matrix_strip.py
    title: library/python/Utility/matrix_strip.py
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc218/tasks/abc218_c
    links:
    - https://atcoder.jp/contests/abc218/tasks/abc218_c
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verification-helper: PROBLEM https://atcoder.jp/contests/abc218/tasks/abc218_c\n\
    \nfrom library.python.Utility.matrix_rotate import matrix_rotate\nfrom library.python.Utility.matrix_strip\
    \ import matrix_strip\n\n\ndef main():\n    N = int(input())\n    S, T = [], []\n\
    \    for y in range(N):\n        S.append(input())\n    for y in range(N):\n \
    \       T.append(input())\n\n    S, T = matrix_strip(S, \"#\"), matrix_strip(T,\
    \ \"#\")\n\n    for i in range(4):\n        if S == T:\n            print(\"Yes\"\
    )\n            return\n        S = matrix_rotate(S)\n\n    print(\"No\")\n\n\n\
    if __name__ == '__main__':\n    main()\n"
  dependsOn:
  - library/python/Utility/matrix_rotate.py
  - library/python/Utility/matrix_strip.py
  isVerificationFile: true
  path: test/python/Utility/matrix_rotate2.test.py
  requiredBy: []
  timestamp: '2024-01-28 13:42:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/python/Utility/matrix_rotate2.test.py
layout: document
redirect_from:
- /verify/test/python/Utility/matrix_rotate2.test.py
- /verify/test/python/Utility/matrix_rotate2.test.py.html
title: test/python/Utility/matrix_rotate2.test.py
---
