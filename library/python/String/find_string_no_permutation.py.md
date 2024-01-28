---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/python/String/find_string_no_permutation1.test.py
    title: test/python/String/find_string_no_permutation1.test.py
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
  code: "# s \u3092\u4E26\u3073\u66FF\u3048\u3066\u3067\u304D\u308B\u6587\u5B57\u5217\
    \u306E\u3046\u3061\uFF0Cs \u304C\u8F9E\u66F8\u9806\u3067\u4F55\u756A\u76EE\u304B\
    (0-indexed)\u3092\u6C42\u3081\u308B\ndef find_string_no_permutation_no(s):\n \
    \   n = len(s)\n\n    fact = [1] * (n + 1)\n    for i in range(1, n + 1):\n  \
    \      fact[i] = fact[i - 1] * i\n\n    freq = dict()\n    for c in s:\n     \
    \   if c not in freq:\n            freq[c] = 0\n        freq[c] += 1\n    chars\
    \ = list(sorted(list(set(s))))\n\n    ans = 0\n    for i in range(n):\n      \
    \  for c in chars:\n            if freq[c] == 0:\n                continue\n\n\
    \            if c >= s[i]:\n                break\n\n            freq[c] -= 1\n\
    \n            num = fact[n - i - 1]\n            for v in freq.values():\n   \
    \             if v != 0:\n                    num //= fact[v]\n\n            ans\
    \ += num\n            freq[c] += 1\n\n        freq[s[i]] -= 1\n\n    return ans\n"
  dependsOn: []
  isVerificationFile: false
  path: library/python/String/find_string_no_permutation.py
  requiredBy: []
  timestamp: '2024-01-28 14:26:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/python/String/find_string_no_permutation1.test.py
documentation_of: library/python/String/find_string_no_permutation.py
layout: document
redirect_from:
- /library/library/python/String/find_string_no_permutation.py
- /library/library/python/String/find_string_no_permutation.py.html
title: library/python/String/find_string_no_permutation.py
---
