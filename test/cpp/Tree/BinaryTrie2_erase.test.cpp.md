---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/Tree/BinaryTrie.hpp
    title: library/cpp/Tree/BinaryTrie.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_7_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_7_B
  bundledCode: "#line 1 \"test/cpp/Tree/BinaryTrie2_erase.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_7_B\"\n\n#line\
    \ 1 \"library/cpp/Tree/BinaryTrie.hpp\"\n#include <array>\n#include <cassert>\n\
    #include <limits>\n#include <memory>\n#include <vector>\n\nclass Node {\npublic:\n\
    \    std::array<std::unique_ptr<Node>, 2> children;\n    int freq;   // \u51FA\
    \u73FE\u983B\u5EA6\n    int count;  // \u3053\u306E\u30CE\u30FC\u30C9\u3092\u901A\
    \u308B\u56DE\u6570\n\n    Node() : freq(0), count(0) {}\n\n    Node(int count)\
    \ : freq(0), count(count) {};\n};\n\ntemplate<typename T=uint64_t, int bit_size\
    \ = 64>\nclass BinaryTrie {\nprivate:\n    std::unique_ptr<Node> root;\n\npublic:\n\
    \    const T NOTFOUND = std::numeric_limits<T>::max();\n\n    BinaryTrie() {\n\
    \        this->root = std::make_unique<Node>(0);\n    }\n\n    // \u96C6\u5408\
    \u306E\u8981\u7D20\u6570\n    [[nodiscard]] int size() const {\n        return\
    \ this->root->count;\n    }\n\n    [[nodiscard]] bool empty() const {\n      \
    \  return this->root->count == 0;\n    }\n\n    // x \u3092 num \u500B\u633F\u5165\
    \u3059\u308B\n    void insert(const T x, int num = 1) {\n        assert(x >= 0);\n\
    \        auto node = this->root.get();\n        node->count++;\n\n        for\
    \ (int i = bit_size - 1; i >= 0; --i) {\n            const auto b = this->get_ith_bit(x,\
    \ i);\n            if (node->children[b] == nullptr) {\n                node->children[b]\
    \ = std::make_unique<Node>(0);\n            }\n            node = node->children[b].get();\n\
    \            node->count++;\n        }\n        node->freq += num;\n    }\n\n\
    \    // x \u3092 num \u500B\u524A\u9664\u3059\u308B\n    // num \u672A\u6E80\u3057\
    \u304B\u306A\u3044\u5834\u5408\u306F\u3059\u3079\u3066\u524A\u9664\u3059\u308B\
    \n    void erase(const T x, int num = 1) {\n        assert(x >= 0);\n        num\
    \ = std::min(num, this->count(x));\n        if (num == 0) {\n            return;\n\
    \        }\n\n        auto node = this->root.get();\n        node->count -= num;\n\
    \n        for (int i = bit_size - 1; i >= 0; --i) {\n            const auto b\
    \ = this->get_ith_bit(x, i);\n\n            if (node->children[b].get()->count\
    \ - num <= 0) {\n                node->children[b].release();\n              \
    \  return;\n            }\n\n            node = node->children[b].get();\n   \
    \         node->count -= num;\n        }\n        node->freq -= num;\n    }\n\n\
    \    std::pair<T, T> find_median() {\n        const int m = this->size();\n  \
    \      assert(m > 0);\n        if (m % 2 == 0) {\n            return {this->find_kth_min_element(m\
    \ / 2 - 1), this->find_kth_min_element(m / 2)};\n        } else {\n          \
    \  return {this->find_kth_min_element(m / 2), this->find_kth_min_element(m / 2)};\n\
    \        }\n    }\n\n    // x \u306E\u51FA\u73FE\u56DE\u6570\n    int count(const\
    \ T x) const {\n        assert(x >= 0);\n        auto node = this->root.get();\n\
    \        for (int i = bit_size - 1; i >= 0; --i) {\n            const auto b =\
    \ this->get_ith_bit(x, i);\n            if (node->children[b] == nullptr) {\n\
    \                return 0;\n            }\n            node = node->children[b].get();\n\
    \        }\n        return node->freq;\n    }\n\n    // x \u3088\u308A\u5C0F\u3055\
    \u3044\u5024\u306E\u51FA\u73FE\u56DE\u6570\n    long long count_less_than(const\
    \ T x) const {\n        assert(x >= 0);\n        long long count = 0;\n      \
    \  auto node = this->root.get();\n\n        for (int i = bit_size - 1; i >= 0;\
    \ --i) {\n            const auto b = this->get_ith_bit(x, i);\n            //\
    \ bit \u304C 0 \u306E\u65B9\u306B\u3042\u308B\u51FA\u73FE\u56DE\u6570\u3092\u3059\
    \u3079\u3066\u8DB3\u3059\n            if (b == 1 and node->children[0] != nullptr)\
    \ {\n                count += node->children[0]->count;\n            }\n     \
    \       if (node->children[b] == nullptr) {\n                break;\n        \
    \    }\n            node = node->children[b].get();\n        }\n\n        return\
    \ count;\n    }\n\n    // x \u3088\u308A\u5927\u304D\u3044\u5024\u306E\u51FA\u73FE\
    \u56DE\u6570\n    int count_more_than(const T x) const {\n        assert(x >=\
    \ 0);\n        return this->size() - this->count_less_than(x) - this->count(x);\n\
    \    }\n\n    // v\u304C\u3042\u308B\u304B\n    bool exist(const T x) const {\n\
    \        assert(x >= 0);\n        return this->count(x) > 0;\n    }\n\n    //\
    \ \u96C6\u5408\u5185\u3067\u6700\u5927\u306E\u5024\n    T find_max_element() const\
    \ {\n        return this->find_kth_max_element(0);\n    }\n\n    // \u96C6\u5408\
    \u5185\u3067\u6700\u5C0F\u306E\u5024\n    T find_min_element() const {\n     \
    \   return this->find_kth_min_element(0);\n    }\n\n    // \u96C6\u5408\u5185\u3067\
    \u5C0F\u3055\u3044\u9806\u306B\u6570\u3048\u3066 k \u756A\u76EE\u306E\u5024(0-origin)\n\
    \    // k = 0 \u3067\u6700\u5C0F\u5024\n    T find_kth_min_element(int k) const\
    \ {\n        if (k < 0 or k >= this->size()) {\n            return this->NOTFOUND;\n\
    \        }\n\n        T ans = 0;\n        auto node = this->root.get();\n    \
    \    for (int i = bit_size - 1; i >= 0; --i) {\n\n            const bool exist0\
    \ = node->children[0] != nullptr;\n            const bool exist1 = node->children[1]\
    \ != nullptr;\n            assert(exist0 or exist1);\n\n            bool go_node0;\n\
    \            if (exist0 and exist1) {\n                if (k < node->children[0]->count)\
    \ {\n                    go_node0 = true;\n                } else {\n        \
    \            go_node0 = false;\n                    k -= node->children[0]->count;\n\
    \                }\n            } else {\n                go_node0 = exist0;\n\
    \            }\n\n            if (go_node0) {\n                node = node->children[0].get();\n\
    \            } else {\n                ans |= ((T) 1 << i);\n                node\
    \ = node->children[1].get();\n            }\n        }\n\n        return ans;\n\
    \    }\n\n    // k \u756A\u76EE\u306B\u5927\u304D\u3044\u5024(0-based)\n    //\
    \ k = 0 \u3067\u6700\u5927\u5024\n    T find_kth_max_element(const int k) const\
    \ {\n        if (k < 0 or k >= this->size()) {\n            return this->NOTFOUND;\n\
    \        }\n        return this->find_kth_min_element(this->size() - 1 - k);\n\
    \    }\n\n    // x \u4EE5\u4E0B\u3067\u6700\u5927\u306E\u5024\n    T predecessor(const\
    \ T x) const {\n        assert(x >= 0);\n        const auto num_less_than_x =\
    \ this->count_less_than(x + 1);\n        return this->find_kth_min_element(num_less_than_x\
    \ - 1);\n    }\n\n    // x \u4EE5\u4E0A\u3067\u6700\u5C0F\u306E\u5024\n    T successor(const\
    \ T x) const {\n        assert(x >= 0);\n        const auto num_less_than_x =\
    \ this->count_less_than(x);\n        return this->find_kth_min_element(num_less_than_x);\n\
    \    }\n\n    // v^x \u3092\u6700\u5C0F\u306B\u3059\u308B\u3088\u3046\u306A x\
    \ \u3092\u307F\u3064\u3051\u308B\n    T find_xor_min_element(T v) const {\n  \
    \      assert(v >= 0);\n        assert(not this->empty());\n\n        auto node\
    \ = this->root.get();\n        T ans = 0;\n        for (int i = bit_size - 1;\
    \ i >= 0; --i) {\n            auto b = (v >> (T) i) & 1u;\n\n            const\
    \ bool exist0 = node->children[0] != nullptr;\n            const bool exist1 =\
    \ node->children[1] != nullptr;\n            assert(exist0 or exist1);\n\n   \
    \         bool go_node0;\n            if (exist0 and exist1) {\n             \
    \   go_node0 = (b == 0);\n            } else {\n                go_node0 = exist0;\n\
    \            }\n\n            if (go_node0) {\n                node = node->children[0].get();\n\
    \            } else {\n                ans |= (1u << (unsigned) i);\n        \
    \        node = node->children[1].get();\n            }\n        }\n\n       \
    \ return ans;\n    }\n\n    // v\u4EE5\u5916\u3067v^x\u3092\u6700\u5C0F\u306B\u3059\
    \u308B\u3088\u3046\u306Ax\n    T min_element_xor_without_v(T v) const {\n    \
    \    assert(false);\n        return 0;\n    }\n\n    // v^x\u3092\u6700\u5927\u306B\
    \u3059\u308B\u3088\u3046\u306Ax\n    T max_element_xor(const T v) const {\n  \
    \      assert(v >= 0);\n        assert(not this->empty());\n\n        auto node\
    \ = this->root.get();\n        T ans = 0;\n        for (int i = bit_size - 1;\
    \ i >= 0; --i) {\n            auto b = (v >> (T) i) & 1u;\n\n            const\
    \ bool exist0 = node->children[0] != nullptr;\n            const bool exist1 =\
    \ node->children[1] != nullptr;\n            assert(exist0 or exist1);\n\n   \
    \         bool go_node0;\n            if (exist0 and exist1) {\n             \
    \   go_node0 = (b == 1);\n            } else {\n                go_node0 = exist0;\n\
    \            }\n\n            if (go_node0) {\n                node = node->children[0].get();\n\
    \            } else {\n                ans |= (1u << (unsigned) i);\n        \
    \        node = node->children[1].get();\n            }\n        }\n\n       \
    \ return ans;\n    }\n\n    // xor\u3057\u305F\u3068\u304D\u306B\uFF0C\u5C0F\u3055\
    \u3044\u65B9\u304B\u3089\u898B\u3066k\u756A\u76EE\u306E\u6570(0-based)\n    T\
    \ kth_element_xor(const T v, int k) const {\n        assert(v >= 0);\n       \
    \ assert(this->root->count != 0);\n        assert(k < this->root->count);\n  \
    \      assert(false);\n        return 0;\n\n    }\n\n    // \u3059\u3079\u3066\
    \u306E\u8981\u7D20\u306B\u3064\u3044\u3066\uFF0Cv\u3092xor\u3057\u305F\u5024\u306B\
    \u5909\u66F4\u3059\u308B\n    void xor_all(T v) const {\n        assert(v >= 0);\n\
    \        assert(false);\n    }\n\nprivate:\n    // x \u306E i \u756A\u76EE\u306E\
    \ bit \u3092\u53D6\u5F97\n    int get_ith_bit(const T x, const int i) const {\n\
    \        return (x >> i) & 1u;\n    }\n};\n#line 4 \"test/cpp/Tree/BinaryTrie2_erase.test.cpp\"\
    \n#include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int Q;\n    cin >> Q;\n\n    BinaryTrie\
    \ bt;\n    for (int i = 0; i < Q; ++i) {\n        int QUERY, X;\n        cin >>\
    \ QUERY >> X;\n        if (QUERY == 0) {\n            if (not bt.exist(X)) {\n\
    \                bt.insert(X);\n            }\n            cout << bt.size() <<\
    \ endl;\n        } else if (QUERY == 1) {\n            cout << bt.exist(X) <<\
    \ endl;\n        } else if (QUERY == 2) {\n            bt.erase(X);\n        }\n\
    \    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_7_B\"\
    \n\n#include \"library/cpp/Tree/BinaryTrie.hpp\"\n#include <iostream>\n\nusing\
    \ namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int Q;\n    cin >> Q;\n\n    BinaryTrie bt;\n    for (int i = 0; i < Q;\
    \ ++i) {\n        int QUERY, X;\n        cin >> QUERY >> X;\n        if (QUERY\
    \ == 0) {\n            if (not bt.exist(X)) {\n                bt.insert(X);\n\
    \            }\n            cout << bt.size() << endl;\n        } else if (QUERY\
    \ == 1) {\n            cout << bt.exist(X) << endl;\n        } else if (QUERY\
    \ == 2) {\n            bt.erase(X);\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Tree/BinaryTrie.hpp
  isVerificationFile: true
  path: test/cpp/Tree/BinaryTrie2_erase.test.cpp
  requiredBy: []
  timestamp: '2024-02-12 19:57:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Tree/BinaryTrie2_erase.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Tree/BinaryTrie2_erase.test.cpp
- /verify/test/cpp/Tree/BinaryTrie2_erase.test.cpp.html
title: test/cpp/Tree/BinaryTrie2_erase.test.cpp
---
