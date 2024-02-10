---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/python/String/find_kth_string_permutation1.test.py
    title: test/python/String/find_kth_string_permutation1.test.py
  - icon: ':heavy_check_mark:'
    path: test/python/String/find_kth_string_permutation2.test.py
    title: test/python/String/find_kth_string_permutation2.test.py
  - icon: ':heavy_check_mark:'
    path: test/python/String/find_string_no_permutation1.test.py
    title: test/python/String/find_string_no_permutation1.test.py
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# s \u3092\u4E26\u3073\u66FF\u3048\u3066\u3067\u304D\u308B\u6587\u5B57\u5217\
    \u306E\u3046\u3061\uFF0C\u8F9E\u66F8\u9806\u3067 k \u756A\u76EE(0-indexed)\u306E\
    \u6587\u5B57\u5217\u3092\u6C42\u3081\u308B\n# \u5B58\u5728\u3057\u306A\u3044\u5834\
    \u5408\u306F\u7A7A\u6587\u5B57\u5217\u3092\u8FD4\u3059\ndef find_kth_string_permutation(k,\
    \ s):\n    n = len(s)\n\n    fact = [1] * (n + 1)\n    for i in range(1, n + 1):\n\
    \        fact[i] = fact[i - 1] * i\n\n    freq = dict()\n    for c in s:\n   \
    \     if c not in freq:\n            freq[c] = 0\n        freq[c] += 1\n    chars\
    \ = list(sorted(list(set(s))))\n\n    # k \u304C\u4F5C\u308C\u308B\u304B\u30C1\
    \u30A7\u30C3\u30AF\n    max_k = fact[n]\n    for v in freq.values():\n       \
    \ max_k //= fact[v]\n\n    if k >= max_k:\n        return []\n\n    ans = []\n\
    \    for i in range(n):\n        # i \u6587\u5B57\u76EE\u3092 c \u306B\u3067\u304D\
    \u308B\u304B\n        for c in chars:\n            if freq[c] <= 0:\n        \
    \        continue\n\n            freq[c] -= 1\n\n            # i \u6587\u5B57\u76EE\
    \u3092 c \u306B\u3057\u305F\u3068\u304D\uFF0C\u4F5C\u6210\u3067\u304D\u308B\u6587\
    \u5B57\u5217\u306E\u500B\u6570\n            count = fact[n - i - 1]\n        \
    \    for v in freq.values():\n                count //= fact[v]\n\n          \
    \  if k < count:\n                ans.append(c)\n                break\n\n   \
    \         freq[c] += 1\n            k -= count\n\n    return ans\n"
  dependsOn: []
  isVerificationFile: false
  path: library/python/String/find_kth_string_permutation.py
  requiredBy: []
  timestamp: '2024-01-28 14:26:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/python/String/find_kth_string_permutation2.test.py
  - test/python/String/find_string_no_permutation1.test.py
  - test/python/String/find_kth_string_permutation1.test.py
documentation_of: library/python/String/find_kth_string_permutation.py
layout: document
redirect_from:
- /library/library/python/String/find_kth_string_permutation.py
- /library/library/python/String/find_kth_string_permutation.py.html
title: library/python/String/find_kth_string_permutation.py
---
