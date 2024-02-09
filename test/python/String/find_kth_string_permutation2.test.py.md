---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/python/String/find_kth_string_permutation.py
    title: library/python/String/find_kth_string_permutation.py
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: py
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc215/tasks/abc215_c
    links:
    - https://atcoder.jp/contests/abc215/tasks/abc215_c
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verification-helper: PROBLEM https://atcoder.jp/contests/abc215/tasks/abc215_c\n\
    \nfrom library.python.String.find_kth_string_permutation import find_kth_string_permutation\n\
    \n\ndef main():\n    S, K = input().split()\n    print(*find_kth_string_permutation(int(K)\
    \ - 1, S), sep=\"\")\n\n\nif __name__ == '__main__':\n    main()\n"
  dependsOn:
  - library/python/String/find_kth_string_permutation.py
  isVerificationFile: true
  path: test/python/String/find_kth_string_permutation2.test.py
  requiredBy: []
  timestamp: '2024-02-09 16:09:21+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/python/String/find_kth_string_permutation2.test.py
layout: document
redirect_from:
- /verify/test/python/String/find_kth_string_permutation2.test.py
- /verify/test/python/String/find_kth_string_permutation2.test.py.html
title: test/python/String/find_kth_string_permutation2.test.py
---
