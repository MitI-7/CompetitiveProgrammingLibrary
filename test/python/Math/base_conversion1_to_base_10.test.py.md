---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/python/Math/base_conversion.py
    title: library/python/Math/base_conversion.py
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc220/tasks/abc220_b
    links:
    - https://atcoder.jp/contests/abc220/tasks/abc220_b
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verification-helper: PROBLEM https://atcoder.jp/contests/abc220/tasks/abc220_b\n\
    \nfrom library.python.Math.base_conversion import to_base_10\n\n\ndef main():\n\
    \    K = int(input())\n    A, B = input().split()\n    print(to_base_10([int(a)\
    \ for a in A], K) * to_base_10([int(b) for b in B], K))\n\n\nif __name__ == '__main__':\n\
    \    main()\n"
  dependsOn:
  - library/python/Math/base_conversion.py
  isVerificationFile: true
  path: test/python/Math/base_conversion1_to_base_10.test.py
  requiredBy: []
  timestamp: '2024-02-14 16:25:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/python/Math/base_conversion1_to_base_10.test.py
layout: document
redirect_from:
- /verify/test/python/Math/base_conversion1_to_base_10.test.py
- /verify/test/python/Math/base_conversion1_to_base_10.test.py.html
title: test/python/Math/base_conversion1_to_base_10.test.py
---
