---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/cpp/Utility/mint.hpp:\
    \ line -1: no such header\n"
  code: "#include <algorithm>\n#include \"library/cpp/Utility/mint.hpp\"\n#include\
    \ \"library/cpp/Math/Combination.hpp\"\n\n// \u5B8C\u5168\u9806\u5217\u306E m\
    \ \u8272\u7248\u306E\u5834\u5408\u306E\u6570\n// \u5024\u3068\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\u304C\u3069\u3053\u3082\u4E00\u81F4\u3057\u3066\u3044\u306A\
    \u3044\u3088\u3046\u306A\u9806\u5217\u306E\u5834\u5408\u306E\u6570\n// \u5024\u306F\
    [0, m)\u306E\u7BC4\u56F2\u3092\u3068\u308B\uFF0En == m \u306E\u3068\u304D\uFF0C\
    \u5B8C\u5168\u9806\u5217\n// O(n)\ntemplate<int MOD>\nmint<MOD> derangement(const\
    \ int n, const int m) {\n\n    Combination<MOD> comb(std::max(n, m) + 100);\n\n\
    \    mint<MOD> ans = 0;\n    for (int i = 0; i <= n; ++i) {\n        // i\u500B\
    \u4EE5\u4E0A\u306E\u7B87\u6240\u304C\u6307\u5B9A\u306E\u8272\u3068\u4E00\u81F4\
    \u3057\u3066\u3057\u307E\u3063\u3066\u3044\u308B\n        auto now = comb.nCr(n,\
    \ i);\n        // n - i\u500B\u306E\u7B87\u6240\u306F\u6307\u5B9A\u306E\u8272\u3068\
    \u4E00\u81F4\u3057\u3066\u3082\u3057\u306A\u304F\u3066\u3082\u3044\u3044\n   \
    \     now *= comb.nPr(m - i, n - i);\n\n        if (i % 2 == 0) {\n          \
    \  ans += now;\n        }\n        else {\n            ans -= now;\n        }\n\
    \    }\n\n    return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Math/derangement.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/Math/derangement.cpp
layout: document
redirect_from:
- /library/library/cpp/Math/derangement.cpp
- /library/library/cpp/Math/derangement.cpp.html
title: library/cpp/Math/derangement.cpp
---
