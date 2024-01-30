---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Tree/RollbackUnionFind.hpp
    title: library/cpp/Tree/RollbackUnionFind.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/Utility/mint.hpp
    title: library/cpp/Utility/mint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc334/tasks/abc334_e
    links:
    - https://atcoder.jp/contests/abc334/tasks/abc334_e
  bundledCode: "#line 1 \"test/cpp/Tree/RollbackUnionFind1.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc334/tasks/abc334_e\"\n\n#line 1 \"library/cpp/Tree/RollbackUnionFind.hpp\"\
    \n#include <cassert>\n#include <stack>\n#include <tuple>\n#include <vector>\n\n\
    class RollbackUnionFind {\npublic:\n    int set_size;   // \u96C6\u5408\u306E\u500B\
    \u6570\n\nprivate:\n    std::vector<int> parent;\n    std::stack<std::tuple<int,\
    \ int, int, int, int>> history;\n    int snap_no;\n\npublic:\n    explicit RollbackUnionFind(const\
    \ int num_nodes) : set_size(num_nodes), parent(num_nodes, -1), snap_no(0) {\n\
    \    }\n\n    // u \u3068 v \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\
    \u304B\u5224\u5B9A\u3059\u308B\n    // O(log n)\n    int is_same_set(const int\
    \ u, const int v) {\n        return this->find_root(u) == this->find_root(v);\n\
    \    }\n\n    // u \u3068 v \u306E\u5C5E\u3059\u308B\u96C6\u5408\u3092\u4F75\u5408\
    \u3059\u308B\n    // O(log n)\n    bool unite(int u, int v) {\n        u = this->find_root(u);\n\
    \        v = this->find_root(v);\n\n        // u \u3068 v \u306E\u73FE\u5728\u306E\
    \u89AA\u3092\u8A18\u9332\n        this->history.emplace(u, this->parent[u], v,\
    \ this->parent[v], this->set_size);\n\n        if (u == v) {\n            return\
    \ false;\n        }\n\n        // \u96C6\u5408\u306E\u30B5\u30A4\u30BA\u304C\u5927\
    \u304D\u3044\u65B9\u3092 u \u3068\u3059\u308B\n        if (this->parent[u] > this->parent[v])\
    \ {\n            std::swap(u, v);\n        }\n\n        // u \u306E\u4E0B\u306B\
    \ v \u3092\u3064\u3051\u308B\n        this->parent[u] += this->parent[v];\n  \
    \      this->parent[v] = u;\n        this->set_size--;\n\n        return true;\n\
    \    }\n\n    // u \u306E\u5C5E\u3059\u308B\u96C6\u5408\u306E\u8981\u7D20\u6570\
    \u3092\u6C42\u3081\u308B\n    // O(log n)\n    int size(const int u) {\n     \
    \   return (-this->parent[this->find_root(u)]);\n    }\n\n    // u \u306E\u5C5E\
    \u3059\u308B\u96C6\u5408\u306E leader \u3092\u53D6\u5F97\n    // O(log n)\n  \
    \  int leader(const int u) {\n        return this->find_root(u);\n    }\n\n  \
    \  // \u76F4\u524D\u306B\u884C\u3063\u305F unite \u64CD\u4F5C\u3092\u53D6\u308A\
    \u6D88\u3059\n    // \u53D6\u308A\u6D88\u3057\u305F (u, v) \u3092\u8FD4\u3059\n\
    \    // O(1)\n    std::pair<int, int> undo() {\n        assert(not this->history.empty());\n\
    \n        const auto [u, u_p, v, v_p, s] = history.top();\n        this->history.pop();\n\
    \        this->parent[u] = u_p;\n        this->parent[v] = v_p;\n        this->set_size\
    \ = s;\n\n        return {u, v};\n    }\n\n    // \u73FE\u5728\u306E\u72B6\u614B\
    \u3092\u4FDD\u5B58\n    // undo \u3092\u3088\u3093\u3067\uFF0Csnapshot \u3092\u547C\
    \u3073\u51FA\u3057\u305F\u72B6\u614B\u3088\u308A\u524D\u306B\u623B\u3063\u305F\
    \u3068\u304D\uFF0C\u610F\u5473\u306E\u306A\u3044\u72B6\u614B\u306B\u306A\u308B\
    \u3053\u3068\u306B\u6CE8\u610F\n    // O(1)\n    void snapshot() {\n        this->snap_no\
    \ = this->get_snap_no();\n    }\n\n    int get_snap_no() {\n        return int(history.size());\n\
    \    }\n\n    // snapshot \u3092\u64AE\u3063\u305F\u72B6\u614B\u306B\u623B\u3059\
    \n    // num \u3092\u6307\u5B9A\u3057\u305F\u5834\u5408\uFF0Cunite \u95A2\u6570\
    \u3092 num \u56DE\u547C\u3073\u51FA\u3057\u305F\u6642\u306E\u72B6\u614B\u306B\u623B\
    \u3059\n    // O(\u623B\u3059\u56DE\u6570)\n    void rollback(int num = -1) {\n\
    \        if (num == -1) {\n            num = this->snap_no;\n        }\n     \
    \   while (num < int(this->history.size())) {\n            this->undo();\n   \
    \     }\n    }\n\nprivate:\n    // u \u306E\u6839\u3092\u6C42\u3081\u308B\n  \
    \  // O(log n)\n    int find_root(int u) {\n        if (this->parent[u] < 0) {\n\
    \            return u;\n        }\n        // \u7D4C\u8DEF\u5727\u7E2E\u306F\u3057\
    \u306A\u3044\n        return this->find_root(this->parent[u]);\n    }\n};\n#line\
    \ 2 \"library/cpp/Utility/mint.hpp\"\n\n#include <iostream>\n\ntemplate<int mod>\n\
    struct mint {\n    long long x;\n\n    mint(long long x = 0) : x((x % mod + mod)\
    \ % mod) {\n    }\n\n    mint &operator+=(const mint a) {\n        if ((x += a.x)\
    \ >= mod) {\n            x -= mod;\n        }\n        return *this;\n    }\n\n\
    \    mint &operator-=(const mint a) {\n        if ((x += mod - a.x) >= mod) {\n\
    \            x -= mod;\n        }\n        return *this;\n    }\n\n    mint &operator*=(const\
    \ mint a) {\n        (x *= a.x) %= mod;\n        return *this;\n    }\n\n    mint\
    \ operator+(const mint a) const {\n        mint res(*this);\n        return res\
    \ += a;\n    }\n\n    mint operator-(const mint a) const {\n        mint res(*this);\n\
    \        return res -= a;\n    }\n\n    mint operator*(const mint a) const {\n\
    \        mint res(*this);\n        return res *= a;\n    }\n\n    mint pow(long\
    \ long t) const {\n        if (!t) {\n            return 1;\n        }\n     \
    \   mint a = pow(t >> 1);\n        a *= a;\n        if (t & 1) {\n           \
    \ a *= *this;\n        }\n        return a;\n    }\n\n    // mod \u304C\u7D20\u6570\
    \u306E\u3068\u304D\u306E\u307F\u5229\u7528\u53EF\u80FD\n    mint inv() const {\n\
    \        return pow(mod - 2);\n    }\n\n    mint &operator/=(const mint a) {\n\
    \        return (*this) *= a.inv();\n    }\n\n    mint operator/(const mint a)\
    \ const {\n        mint res(*this);\n        return res /= a;\n    }\n\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const mint &obj) {\n        os <<\
    \ obj.x;\n        return os;\n    }\n};\n\n\n//const int MOD = 1000000000 + 7;\
    \ // 10^9 + 7\n//const int MOD = 998244353;\n#line 6 \"test/cpp/Tree/RollbackUnionFind1.test.cpp\"\
    \n\nusing namespace std;\nconst int MOD = 998244353;\n\ninline bool inside(long\
    \ long y, long long x, long long H, long long W) { return 0 <= y and y < H and\
    \ 0 <= x and x < W; }\n\nconst std::vector<int> dy8 = {0, 1, 0, -1, -1, 1, 1,\
    \ -1};\nconst std::vector<int> dx8 = {1, 0, -1, 0, 1, 1, -1, -1};\n\nint main()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    int H, W;\n\
    \    cin >> H >> W;\n    vector<string> grid(H);\n    for (int y = 0; y < H; ++y)\
    \ {\n        cin >> grid[y];\n    }\n\n    RollbackUnionFind ruf(H * W);\n   \
    \ int num_red = 0;\n    for (int y = 0; y < H; ++y) {\n        for (int x = 0;\
    \ x < W; ++x) {\n\n            if (grid[y][x] == '.') {\n                num_red++;\n\
    \                continue;\n            }\n\n            for (int i = 0; i < 4;\
    \ ++i) {\n                int ny = dy8[i] + y;\n                int nx = dx8[i]\
    \ + x;\n\n                if (inside(ny, nx, H, W) and grid[ny][nx] == '#') {\n\
    \                    ruf.unite(y * W + x, ny * W + nx);\n                }\n \
    \           }\n        }\n    }\n    ruf.snapshot();\n\n    mint<MOD> ans;\n \
    \   for (int y = 0; y < H; ++y) {\n        for (int x = 0; x < W; ++x) {\n   \
    \         if (grid[y][x] == '#') {\n                continue;\n            }\n\
    \n            for (int i = 0; i < 4; ++i) {\n                int ny = dy8[i] +\
    \ y;\n                int nx = dx8[i] + x;\n\n                if (inside(ny, nx,\
    \ H, W) and grid[ny][nx] == '#') {\n                    ruf.unite(y * W + x, ny\
    \ * W + nx);\n                }\n            }\n\n            ans += ruf.set_size\
    \ - (num_red - 1);\n\n            ruf.rollback();\n        }\n    }\n    cout\
    \ << ans / num_red << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc334/tasks/abc334_e\"\n\n\
    #include \"library/cpp/Tree/RollbackUnionFind.hpp\"\n#include \"library/cpp/Utility/mint.hpp\"\
    \n#include <iostream>\n\nusing namespace std;\nconst int MOD = 998244353;\n\n\
    inline bool inside(long long y, long long x, long long H, long long W) { return\
    \ 0 <= y and y < H and 0 <= x and x < W; }\n\nconst std::vector<int> dy8 = {0,\
    \ 1, 0, -1, -1, 1, 1, -1};\nconst std::vector<int> dx8 = {1, 0, -1, 0, 1, 1, -1,\
    \ -1};\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int H, W;\n    cin >> H >> W;\n    vector<string> grid(H);\n    for (int\
    \ y = 0; y < H; ++y) {\n        cin >> grid[y];\n    }\n\n    RollbackUnionFind\
    \ ruf(H * W);\n    int num_red = 0;\n    for (int y = 0; y < H; ++y) {\n     \
    \   for (int x = 0; x < W; ++x) {\n\n            if (grid[y][x] == '.') {\n  \
    \              num_red++;\n                continue;\n            }\n\n      \
    \      for (int i = 0; i < 4; ++i) {\n                int ny = dy8[i] + y;\n \
    \               int nx = dx8[i] + x;\n\n                if (inside(ny, nx, H,\
    \ W) and grid[ny][nx] == '#') {\n                    ruf.unite(y * W + x, ny *\
    \ W + nx);\n                }\n            }\n        }\n    }\n    ruf.snapshot();\n\
    \n    mint<MOD> ans;\n    for (int y = 0; y < H; ++y) {\n        for (int x =\
    \ 0; x < W; ++x) {\n            if (grid[y][x] == '#') {\n                continue;\n\
    \            }\n\n            for (int i = 0; i < 4; ++i) {\n                int\
    \ ny = dy8[i] + y;\n                int nx = dx8[i] + x;\n\n                if\
    \ (inside(ny, nx, H, W) and grid[ny][nx] == '#') {\n                    ruf.unite(y\
    \ * W + x, ny * W + nx);\n                }\n            }\n\n            ans\
    \ += ruf.set_size - (num_red - 1);\n\n            ruf.rollback();\n        }\n\
    \    }\n    cout << ans / num_red << endl;\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Tree/RollbackUnionFind.hpp
  - library/cpp/Utility/mint.hpp
  isVerificationFile: true
  path: test/cpp/Tree/RollbackUnionFind1.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:52:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Tree/RollbackUnionFind1.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Tree/RollbackUnionFind1.test.cpp
- /verify/test/cpp/Tree/RollbackUnionFind1.test.cpp.html
title: test/cpp/Tree/RollbackUnionFind1.test.cpp
---
