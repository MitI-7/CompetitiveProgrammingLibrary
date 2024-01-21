---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/cpp/DataStructure/TopK.hpp
    title: library/cpp/DataStructure/TopK.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc234/tasks/abc234_d
    links:
    - https://atcoder.jp/contests/abc234/tasks/abc234_d
  bundledCode: "#line 1 \"test/cpp/DataStructure/TopK1_get_top_k.test.cpp\"\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/abc234/tasks/abc234_d\"\n\n#line 1 \"\
    library/cpp/DataStructure/TopK.hpp\"\n#include <cassert>\n#include <set>\n\ntemplate<typename\
    \ T>\nclass TopK {\nprivate:\n    T top_k_sum = 0;            // \u4E0A\u4F4D\
    \ k \u4EF6\u306E\u5408\u8A08\n    int k;\n    const bool reverse;         // \u5C0F\
    \u3055\u3044\u9806\u306B\u3059\u308B\n    std::multiset<T> top_k;     // \u4E0A\
    \u4F4D k \u4EF6\n    std::multiset<T> reserve;   // \u88DC\u6B20\n\npublic:\n\
    \    // reverse = false \u306E\u5834\u5408\uFF0C\u5927\u304D\u3044\u9806\u306B\
    \ k \u4EF6\u3092\u7BA1\u7406\uFF0Etrue\u306E\u5834\u5408\uFF0C\u5C0F\u3055\u3044\
    \u9806\u306B k \u4EF6\u3092\u7BA1\u7406\u3059\u308B\n    explicit TopK(const int\
    \ k, const bool reverse = false) : k(k), reverse(reverse) {\n        assert(k\
    \ >= 0);\n    }\n\n    // \u73FE\u5728\u306E\u8981\u7D20\u6570\u3092\u6C42\u3081\
    \u308B\n    [[nodiscard]] int size() const {\n        return this->top_k.size()\
    \ + this->reserve.size();\n    }\n\n    // k \u3092\u5909\u66F4\u3059\u308B\n\
    \    // O(abs(new_k - k))\n    void change_k(const int new_k) {\n        assert(new_k\
    \ >= 0);\n\n        if (new_k == this->k) {\n            return;\n        }\n\n\
    \        this->k = new_k;\n        this->balance();\n    }\n\n    // \u4E0A\u4F4D\
    \ k \u4EF6\u306E\u5408\u8A08\u3092\u6C42\u3081\u308B\n    // O(1)\n    [[nodiscard]]\
    \ T get_top_k_sum() {\n        if (this->reverse) {\n            return this->top_k_sum\
    \ * -1;\n        }\n        return this->top_k_sum;\n    }\n\n    // 1 \u756A\u76EE\
    \u306E\u5024\u3092\u6C42\u3081\u308B\n    [[nodiscard]] T get_top() {\n      \
    \  assert(this->size() > 0);\n        if (this->reverse) {\n            return\
    \ *this->top_k.rbegin() * -1;\n        }\n        return *this->top_k.rbegin();\n\
    \    }\n\n    // k \u756A\u76EE\u306E\u5024\u3092\u6C42\u3081\u308B\n    [[nodiscard]]\
    \ T get_top_k() {\n        assert(this->size() > 0);\n        if (this->reverse)\
    \ {\n            return *this->top_k.begin() * -1;\n        }\n        return\
    \ *this->top_k.begin();\n    }\n\n    // O(log n)\n    void insert(T x) {\n  \
    \      if (this->reverse) {\n            x *= -1;\n        }\n        this->top_k.insert(x);\n\
    \        this->top_k_sum += x;\n        this->balance();\n    }\n\n    // O(log\
    \ n)\n    void erase(T x) {\n        if (this->reverse) {\n            x *= -1;\n\
    \        }\n\n        // \u88DC\u6B20\u306B\u3044\u308B\u306A\u3089\uFF0C\u88DC\
    \u6B20\u304B\u3089\u524A\u9664\u3059\u308B\u3060\u3051\n        {\n          \
    \  const auto it = this->reserve.find(x);\n            if (it != this->reserve.end())\
    \ {\n                this->reserve.erase(it);\n                return;\n     \
    \       }\n        }\n\n        {\n            const auto it = this->top_k.find(x);\n\
    \            if (it != this->top_k.end()) {\n                this->top_k_sum -=\
    \ x;\n                this->top_k.erase(it);\n                this->balance();\n\
    \            }\n        }\n    }\n\nprivate:\n    void balance() {\n        //\
    \ top k \u304C k \u500B\u4EE5\u4E0A\u3042\u308B\u306A\u3089\u6700\u5C0F\u306E\u8981\
    \u7D20\u3092\u88DC\u6B20\u306B\u9001\u308B\n        while ((int) this->top_k.size()\
    \ > this->k) {\n            auto mini = this->top_k.begin();\n            this->top_k_sum\
    \ -= *mini;\n            this->reserve.insert(*mini);\n            this->top_k.erase(mini);\n\
    \        }\n\n        // top k \u304C k \u306B\u6E80\u305F\u306A\u3044\u306A\u3089\
    \u88DC\u6B20\u304B\u3089\u6700\u5927\u306E\u8981\u7D20\u3092\u9001\u308B\n   \
    \     while ((int) this->top_k.size() < this->k and not this->reserve.empty())\
    \ {\n            auto maxi = this->reserve.rbegin();\n            this->top_k_sum\
    \ += *maxi;\n            this->top_k.insert(*maxi);\n            this->reserve.erase((++maxi).base());\n\
    \        }\n    }\n};\n#line 4 \"test/cpp/DataStructure/TopK1_get_top_k.test.cpp\"\
    \n#include <iostream>\n#include <vector>\n\nusing namespace std;\n\nint main()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    int N, K;\n\
    \    cin >> N >> K;\n    vector<int> P(N);\n    for (int i = 0; i < N; ++i) {\n\
    \        cin >> P[i];\n    }\n\n    TopK<int> top_k(K);\n\n    for (int i = 0;\
    \ i < N; ++i) {\n        top_k.insert(P[i]);\n        if (i >= K - 1) {\n    \
    \        cout << top_k.get_top_k() << endl;\n        }\n    }\n\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc234/tasks/abc234_d\"\n\n\
    #include \"library/cpp/DataStructure/TopK.hpp\"\n#include <iostream>\n#include\
    \ <vector>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n  \
    \  ios::sync_with_stdio(false);\n\n    int N, K;\n    cin >> N >> K;\n    vector<int>\
    \ P(N);\n    for (int i = 0; i < N; ++i) {\n        cin >> P[i];\n    }\n\n  \
    \  TopK<int> top_k(K);\n\n    for (int i = 0; i < N; ++i) {\n        top_k.insert(P[i]);\n\
    \        if (i >= K - 1) {\n            cout << top_k.get_top_k() << endl;\n \
    \       }\n    }\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/DataStructure/TopK.hpp
  isVerificationFile: true
  path: test/cpp/DataStructure/TopK1_get_top_k.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 16:50:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/DataStructure/TopK1_get_top_k.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/DataStructure/TopK1_get_top_k.test.cpp
- /verify/test/cpp/DataStructure/TopK1_get_top_k.test.cpp.html
title: test/cpp/DataStructure/TopK1_get_top_k.test.cpp
---
