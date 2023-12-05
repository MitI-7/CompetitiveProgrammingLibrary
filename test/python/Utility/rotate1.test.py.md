---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/python/Utility/rotate.py
    title: library/python/Utility/rotate.py
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc298/tasks/abc298_b
    links:
    - https://atcoder.jp/contests/abc298/tasks/abc298_b
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verification-helper: PROBLEM https://atcoder.jp/contests/abc298/tasks/abc298_b\n\
    \nfrom library.python.Utility.rotate import rotate\n\n\ndef main():\n    N = int(input())\n\
    \    A, B = [], []\n    for _ in range(N):\n        A.append(list(map(int, input().split())))\n\
    \    for _ in range(N):\n        B.append(list(map(int, input().split())))\n\n\
    \    for i in range(4):\n        ok = True\n        for y in range(N):\n     \
    \       for x in range(N):\n                if A[y][x] == 1:\n               \
    \     ok &= B[y][x] == 1\n        if ok:\n            print(\"Yes\")\n       \
    \     return\n        A = rotate(A)\n\n    print(\"No\")\n\n\nif __name__ == '__main__':\n\
    \    main()\n"
  dependsOn:
  - library/python/Utility/rotate.py
  isVerificationFile: true
  path: test/python/Utility/rotate1.test.py
  requiredBy: []
  timestamp: '2023-06-07 17:58:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/python/Utility/rotate1.test.py
layout: document
redirect_from:
- /verify/test/python/Utility/rotate1.test.py
- /verify/test/python/Utility/rotate1.test.py.html
title: test/python/Utility/rotate1.test.py
---
