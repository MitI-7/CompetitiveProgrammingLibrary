---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/python/String/find_kth_string_permutation.py
    title: library/python/String/find_kth_string_permutation.py
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc202/tasks/abc202_d
    links:
    - https://atcoder.jp/contests/abc202/tasks/abc202_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verification-helper: PROBLEM https://atcoder.jp/contests/abc202/tasks/abc202_d\n\
    \nfrom library.python.String.find_kth_string_permutation import find_kth_string_permutation\n\
    \n\ndef main():\n    A, B, K = map(int, input().split())\n\n    s = \"a\" * A\
    \ + \"b\" * B\n    ans = find_kth_string_permutation(K - 1, s)\n    print(*ans,\
    \ sep=\"\")\n\n\nif __name__ == '__main__':\n    main()\n"
  dependsOn:
  - library/python/String/find_kth_string_permutation.py
  isVerificationFile: true
  path: test/python/String/find_kth_string_permutation1.test.py
  requiredBy: []
  timestamp: '2024-01-28 14:26:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/python/String/find_kth_string_permutation1.test.py
layout: document
redirect_from:
- /verify/test/python/String/find_kth_string_permutation1.test.py
- /verify/test/python/String/find_kth_string_permutation1.test.py.html
title: test/python/String/find_kth_string_permutation1.test.py
---
