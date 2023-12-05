---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
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
  code: "#include <cassert>\n#include <cstdint>\n#include <vector>\n#include \"library/cpp/Utility/mint.hpp\"\
    \n\n// nCr\n// O(r)\ntemplate<typename T>\nT combination(long long n, long long\
    \ r) {\n    T ans = 1;\n    for (long long d = 1; d <= r; ++d) {\n        ans\
    \ *= n--;\n        ans /= d;\n    }\n    return ans;\n}\n\ntemplate<int MOD>\n\
    class Combination {\npublic:\n    std::vector<mint<MOD>> fact;\n    std::vector<mint<MOD>>\
    \ inv;\n\n    // O(n)\n    Combination(int n) {\n        assert(0 < n);\n    \
    \    this->fact.resize(n + 1, 1);\n        this->inv.resize(n + 1, 1);\n\n   \
    \     for (int i = 1; i < int(fact.size()); ++i) {\n            this->fact[i]\
    \ = this->fact[i - 1] * i;\n            this->inv[i] = this->fact[i].inv();\n\
    \        }\n    }\n\n    mint<MOD> nCr(const int n, const int r) const {\n   \
    \     assert(0 <= n and 0 <= r);\n        if (n < r) {\n            return 0;\n\
    \        }\n        return this->fact[n] * (this->inv[r] * this->inv[n - r]);\n\
    \    }\n\n    mint<MOD> nPr(const int n, const int r) const {\n        assert(0\
    \ <= n and 0 <= r);\n        if (n < r) {\n            return 0;\n        }\n\
    \        return this->fact[n] * this->inv[n - r];\n    }\n\n    // \u91CD\u8907\
    \u7D44\u5408\u305B\n    // n \u500B\u306E\u3082\u306E\u304B\u3089\u7E70\u308A\u8FD4\
    \u3057\u3092\u3086\u308B\u3057\u3066 r \u500B\u3068\u308B\u3068\u304D\u306E\u5834\
    \u5408\u306E\u6570\n    // n \u500B\u306E o \u3068 r - 1 \u500B\u306E | \u306E\
    \u4E26\u3073\u306E\u5834\u5408\u306E\u6570\n    mint<MOD> nHr(const int n, const\
    \ int r) const {\n        return nCr(n + r - 1, r);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Math/Combination.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/Math/Combination.hpp
layout: document
redirect_from:
- /library/library/cpp/Math/Combination.hpp
- /library/library/cpp/Math/Combination.hpp.html
title: library/cpp/Math/Combination.hpp
---
