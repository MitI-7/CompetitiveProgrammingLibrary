---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/python/Utility/matrix_strip1.test.py
    title: test/python/Utility/matrix_strip1.test.py
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
  code: "# target \u304C\u542B\u307E\u308C\u308B\u6700\u5C0F\u306E\u9577\u65B9\u5F62\
    \u306B\u306A\u308B\u3088\u3046\u306B matrix \u306E\u5468\u56F2\u3092\u524A\u9664\
    \u3059\u308B\ndef matrix_strip(matrix, target=\"#\"):\n    h, w = len(matrix),\
    \ len(matrix[0])\n    min_y, max_y = h, -1\n    min_x, max_x = w, -1\n    for\
    \ y in range(h):\n        for x in range(w):\n            if matrix[y][x] == target:\n\
    \                min_x = min(min_x, x)\n                max_x = max(max_x, x)\n\
    \                min_y = min(min_y, y)\n                max_y = max(max_y, y)\n\
    \n    ans = []\n    for y in range(h):\n        b = []\n        for x in range(w):\n\
    \            if min_y <= y <= max_y and min_x <= x <= max_x:\n               \
    \ b.append(matrix[y][x])\n        if b:\n            ans.append(b)\n    return\
    \ ans\n"
  dependsOn: []
  isVerificationFile: false
  path: library/python/Utility/matrix_strip.py
  requiredBy: []
  timestamp: '2024-01-28 13:42:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/python/Utility/matrix_strip1.test.py
documentation_of: library/python/Utility/matrix_strip.py
layout: document
redirect_from:
- /library/library/python/Utility/matrix_strip.py
- /library/library/python/Utility/matrix_strip.py.html
title: library/python/Utility/matrix_strip.py
---
