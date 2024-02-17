---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/python/Math/base_conversion1_to_base_10.test.py
    title: test/python/Math/base_conversion1_to_base_10.test.py
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# base \u9032\u6570\u304B\u308910\u9032\u6570\u306B\u5909\u3048\u308B\n#\
    \ v[0]\u304C\u6700\u4E0A\u4F4D\u306E\u6841\u3092\u8868\u3059\n# 6 = 110 \u306A\
    \u3089 v = {0, 1, 1}\ndef to_base_10(v, base):\n    ans = 0\n    for x in v:\n\
    \        assert x >= 0\n        assert x < base\n        ans = ans * base + x\n\
    \    return ans\n\n\n# 10 \u9032\u6570\u304B\u3089 base \u9032\u6570\u306B\u5909\
    \u3048\u308B\ndef to_base_n(x, base):\n    if x == 0:\n        return [0]\n\n\
    \    ans = []\n    while x > 0:\n        t = x % base\n        ans.append(t)\n\
    \        x //= base\n\n    return ans[::-1]\n"
  dependsOn: []
  isVerificationFile: false
  path: library/python/Math/base_conversion.py
  requiredBy: []
  timestamp: '2024-02-14 16:25:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/python/Math/base_conversion1_to_base_10.test.py
documentation_of: library/python/Math/base_conversion.py
layout: document
redirect_from:
- /library/library/python/Math/base_conversion.py
- /library/library/python/Math/base_conversion.py.html
title: library/python/Math/base_conversion.py
---
