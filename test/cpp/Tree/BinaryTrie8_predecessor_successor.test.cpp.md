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
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"test/cpp/Tree/BinaryTrie8_predecessor_successor.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\n\
    #line 1 \"library/cpp/Tree/BinaryTrie.hpp\"\n#include <array>\n#include <cassert>\n\
    #include <limits>\n#include <memory>\n#include <vector>\n\ntemplate<typename T>\n\
    class Node {\npublic:\n    T x;                 // \u8449\u306E\u5024\n    int\
    \ count;           // \u3053\u306E\u30CE\u30FC\u30C9\u3092\u901A\u308B\u56DE\u6570\
    \n    int count_distinct;  // \u3053\u306E\u30CE\u30FC\u30C9\u3092\u9802\u70B9\
    \u3068\u3059\u308B\u8449\u306E\u500B\u6570(=\u7A2E\u985E\u6570)\n\n    // \u5DE6\
    \u306E\u5B50\u3068\u53F3\u306E\u5B50\n    std::array<std::unique_ptr<Node>, 2>\
    \ child = {nullptr, nullptr};\n\n    // \u8449\u306E\u3068\u304D\uFF0C\u5DE6\u306E\
    \u8449\u3068\u53F3\u306E\u8449\u3092\u6307\u3059\uFF08\u5B58\u5728\u3057\u306A\
    \u3044\u5834\u5408\u306F DUMMY\u3092\u6307\u3059\uFF09\n    Node *prev;\n    Node\
    \ *next;\n\n    Node *parent;\n\n    // \u5DE6\u306E\u5B50\u3092\u6301\u305F\u306A\
    \u3044\u3068\u304D\u306F\u3001\u3053\u306E node \u3092\u6839\u3068\u3059\u308B\
    \u90E8\u5206\u6728\u306B\u304A\u3051\u308B\u6700\u5C0F\u306E\u8449\u3092\u6307\
    \u3059\n    // \u53F3\u306E\u5B50\u3092\u6301\u305F\u306A\u3044\u3068\u304D\u306F\
    \u3001\u3053\u306E node \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306B\
    \u304A\u3051\u308B\u6700\u5927\u306E\u8449\u3092\u6307\u3059\n    // Trie \u304C\
    \u7A7A\u306E\u3068\u304D\u306F DUMMY \u3092\u6307\u3059\n    Node *jump;\n\n \
    \   Node() : x(0), count(0), count_distinct(0), prev(nullptr), next(nullptr),\
    \ parent(nullptr), jump(nullptr) {}\n\n    Node(const T x, int count) : x(x),\
    \ count(count), count_distinct(0), prev(nullptr), next(nullptr), parent(nullptr),\
    \ jump(nullptr) {};\n};\n\ntemplate<typename T=uint64_t, int bit_size = 64>\n\
    class BinaryTrie {\nprivate:\npublic:\n    std::unique_ptr<Node<T>> root;\n  \
    \  const T NOTFOUND = std::numeric_limits<T>::max();\n    Node<T> DUMMY;\n\n \
    \   BinaryTrie() {\n        this->root = std::make_unique<Node<T>>();\n      \
    \  root->jump = &DUMMY;\n        DUMMY.jump = &DUMMY;\n        DUMMY.x = NOTFOUND;\n\
    \        DUMMY.prev = DUMMY.next = &DUMMY;\n    }\n\n    // \u96C6\u5408\u306E\
    \u8981\u7D20\u6570\n    [[nodiscard]] int size() const {\n        return this->root->count;\n\
    \    }\n\n    // \u96C6\u5408\u306E\u7A2E\u985E\u6570(= \u8449\u306E\u500B\u6570\
    )\n    [[nodiscard]] int distinct() const {\n        return this->root->count_distinct;\n\
    \    }\n\n    [[nodiscard]] bool empty() const {\n        return this->root->count\
    \ == 0;\n    }\n\n    // x \u3092 num \u500B\u633F\u5165\u3059\u308B\n    void\
    \ insert(const T x, const int num = 1) {\n        assert(x >= 0);\n        auto\
    \ node = this->root.get();\n        node->count += num;\n\n        const bool\
    \ exist = this->exist(x);\n\n        int i = bit_size - 1;\n        // \u6728\u306E\
    \u7D42\u7AEF\u30CE\u30FC\u30C9\u306B\u305F\u3069\u308A\u7740\u304F\u307E\u3067\
    \u4E0B\u308B\n        for (; i >= 0; --i) {\n            const int b = this->get_ith_bit(x,\
    \ i);\n            if (node->child[b] == nullptr) {\n                break;\n\
    \            }\n            node = node->child[b].get();\n            assert(node->count\
    \ >= 1);\n            node->count += num;\n            node->count_distinct +=\
    \ not exist;\n        }\n        // \u3059\u3067\u306B\u8449\u304C\u3042\u308B\
    \n        if (i == -1) {\n            assert(node->x == x);\n            return;\n\
    \        }\n\n        // \u65B0\u3057\u3044\u7A2E\u985E\u306E\u6570\u5024\u304C\
    \u8FFD\u52A0\u3055\u308C\u305F\n        this->root.get()->count_distinct++;\n\n\
    \        // x \u306E\u5DE6\u306E\u8449\u3068\u53F3\u306E\u8449\u3092\u53D6\u5F97\
    \n        assert(node->jump != nullptr);\n        const int b = this->get_ith_bit(x,\
    \ i);\n        auto *left_leaf = (b == 1) ? node->jump : node->jump->prev;\n \
    \       auto *right_leaf = left_leaf->next;\n        node->jump = nullptr;\n \
    \       assert(left_leaf != nullptr);\n\n        // \u8449\u307E\u3067\u306E\u7D4C\
    \u8DEF\u3092\u4F5C\u308B\n        for (; i >= 0; --i) {\n            const int\
    \ b = this->get_ith_bit(x, i);\n            assert(node->child[b] == nullptr);\n\
    \            node->child[b] = std::make_unique<Node<T>>();\n            node->child[b]->parent\
    \ = node;\n            node = node->child[b].get();\n            node->count +=\
    \ num;\n            node->count_distinct++;\n        }\n        node->x = x;\n\
    \n        // x \u3092\u9023\u7D50\u30EA\u30B9\u30C8\u306B\u8FFD\u52A0\n      \
    \  node->prev = left_leaf;\n        node->next = right_leaf;\n        left_leaf->next\
    \ = node;\n        right_leaf->prev = node;\n\n        // \u6839\u306B\u623B\u308A\
    \u306A\u304C\u3089\uFF0Cjump \u3092\u66F4\u65B0\u3059\u308B\n        auto u =\
    \ node->parent;\n        while (u != nullptr) {\n            if ((u->child[0]\
    \ == nullptr and (u->jump == nullptr or u->jump->x > x)) or\n                (u->child[1]\
    \ == nullptr and (u->jump == nullptr or u->jump->x < x))) {\n                u->jump\
    \ = node;\n            }\n            u = u->parent;\n        }\n    }\n\n   \
    \ // x \u3092 num \u500B\u524A\u9664\u3059\u308B\n    // x \u304C num \u500B\u672A\
    \u6E80\u3057\u304B\u306A\u3044\u5834\u5408\u306F\u3059\u3079\u3066\u524A\u9664\
    \u3059\u308B\n    void erase(const T x, int num = 1) {\n        assert(x >= 0);\n\
    \        int num_x = this->count(x);\n        if (num_x == 0) {\n            return;\n\
    \        }\n\n        num = std::min(num, num_x);\n\n        auto node = this->root.get();\n\
    \        node->count -= num;\n\n        int i = bit_size - 1;\n\n        // x\
    \ \u3092\u542B\u3080\u8449 u \u3092\u898B\u3064\u3051\u308B\n        for (; i\
    \ >= 0; --i) {\n            int b = this->get_ith_bit(x, i);\n            assert(node->child[b]\
    \ != nullptr);\n            node = node->child[b].get();\n            assert(node->count\
    \ > 0);\n            node->count -= num;\n            node->count_distinct -=\
    \ (num == num_x);\n        }\n        assert(node->x == x);   // \u8449\u306B\u3044\
    \u308B\n\n        // x \u304C\u6B8B\u308B\u3068\u304D\u306F\u7D42\u4E86\n    \
    \    if (num < num_x) {\n            return;\n        }\n\n        //\u3000\u8449\
    \u304C\u6D88\u3048\u308B\n        this->root.get()->count_distinct--;\n\n    \
    \    // node \u3092\u9023\u7D50\u30EA\u30B9\u30C8\u304B\u3089\u524A\u9664\u3059\
    \u308B\n        node->prev->next = node->next;  // \u81EA\u5206\u306E\u5DE6\u306F\
    \u81EA\u5206\u3092\u6307\u3057\u3066\u3044\u308B\u306E\u3067\uFF0C\u53F3\u3092\
    \u6307\u3059\u3088\u3046\u306B\u66F4\u65B0\n        node->next->prev = node->prev;\
    \  // \u81EA\u5206\u306E\u53F3\u306E\u81EA\u5206\u3092\u6307\u3057\u3066\u3044\
    \u308B\u306E\u3067\uFF0C\u5DE6\u3092\u6307\u3059\u3088\u3046\u306B\u66F4\u65B0\
    \n\n        // node \u304B\u3089\u6839\u3078\u4E0A\u308A\uFF0C\u4E0D\u8981\u306A\
    \u30CE\u30FC\u30C9\u3092\u524A\u9664\u3059\u308B\n        auto u = node;\n   \
    \     for (i = 0; i < bit_size; ++i) {\n            int b = this->get_ith_bit(x,\
    \ i);\n            u = u->parent;\n            u->child[b].release();\n      \
    \      u->child[b] = nullptr;\n            // \u53CD\u5BFE\u306E\u5B50\u4F9B\u304C\
    \u5B58\u5728\u3059\u308C\u3070\u7D42\u4E86\n            if (u->child[1 - b] !=\
    \ nullptr) {\n                break;\n            }\n        }\n\n        // jump\
    \ \u3092\u66F4\u65B0\u3059\u308B\n        int b = this->get_ith_bit(x, i);\n \
    \       assert(u->child[b] == nullptr);\n        if (u->child[0] == nullptr) {\n\
    \            u->jump = node->next;\n        } else {\n            u->jump = node->prev;\n\
    \        }\n\n        u = u->parent;\n        i++;\n        for (; i < bit_size;\
    \ ++i) {\n            b = this->get_ith_bit(x, i);\n            if (u->jump ==\
    \ node) {\n                if (u->child[0] == nullptr) {\n                   \
    \ u->jump = node->next;\n                } else {\n                    u->jump\
    \ = node->prev;\n                }\n            }\n            assert(u->count\
    \ > 0);\n            u = u->parent;\n        }\n    }\n\n    std::pair<T, T> find_median()\
    \ {\n        const int m = this->size();\n        assert(m > 0);\n        if (m\
    \ % 2 == 0) {\n            return {this->find_kth_min_element(m / 2 - 1), this->find_kth_min_element(m\
    \ / 2)};\n        } else {\n            return {this->find_kth_min_element(m /\
    \ 2), this->find_kth_min_element(m / 2)};\n        }\n    }\n\n    // \u6728\u306B\
    \u306A\u3044\u5024\u306E\u3046\u3061\uFF0C\u5C0F\u3055\u3044\u65B9\u304B\u3089\
    \ k \u756A\u76EE\u306E\u5024\u3092\u53D6\u5F97(0-origin)\n    T find_mex(long\
    \ long k) const {\n        long long maxi_leaf = (long long) 1 << bit_size;\n\n\
    \        // k \u756A\u76EE\u306E\u5024\u306F\u6728\u306E\u5916\u5074\u306B\u3042\
    \u308B\n        if (k + 1 >= maxi_leaf - this->root.get()->count_distinct) {\n\
    \            return (k - this->root.get()->count_distinct) + maxi_leaf;\n    \
    \    }\n\n        T ans = 0;\n        maxi_leaf /= 2;\n        auto node = this->root.get();\n\
    \        for (int i = bit_size - 1; i >= 0; --i) {\n            const int num_left_leaf\
    \ = (node->child[0] == nullptr) ? 0 : node->child[0]->count_distinct;\n\n    \
    \        // \u5DE6\u5074\u306E\u90E8\u5206\u6728\u5185\u306B\u3042\u308B\n   \
    \         if (k + 1 <= maxi_leaf - num_left_leaf) {\n                if (node->child[0]\
    \ == nullptr) {\n                    ans += k;\n                    break;\n \
    \               }\n                node = node->child[0].get();\n            }\
    \ else {\n                k -= (maxi_leaf - num_left_leaf);\n\n              \
    \  ans |= ((T) 1 << i);\n                if (node->child[1] == nullptr) {\n  \
    \                  ans += k;\n                    break;\n                }\n\
    \                node = node->child[1].get();\n            }\n            maxi_leaf\
    \ /= 2;\n        }\n\n        return ans;\n    }\n\n    // v\u304C\u3042\u308B\
    \u304B\n    bool exist(const T x) const {\n        assert(x >= 0);\n        return\
    \ this->count(x) > 0;\n    }\n\n    // x \u306E\u51FA\u73FE\u56DE\u6570\n    int\
    \ count(const T x) const {\n        assert(x >= 0);\n        auto node = this->root.get();\n\
    \        for (int i = bit_size - 1; i >= 0; --i) {\n            const auto b =\
    \ this->get_ith_bit(x, i);\n            if (node->child[b] == nullptr) {\n   \
    \             return 0;\n            }\n            node = node->child[b].get();\n\
    \            assert(node->count > 0);\n        }\n        assert(node->x == x);\n\
    \        assert(node->count > 0);\n        return node->count;\n    }\n\n    //\
    \ x \u3088\u308A\u5C0F\u3055\u3044\u5024\u306E\u51FA\u73FE\u56DE\u6570\n    long\
    \ long count_less_than(const T x) const {\n        assert(x >= 0);\n        long\
    \ long count = 0;\n        auto node = this->root.get();\n\n        for (int i\
    \ = bit_size - 1; i >= 0; --i) {\n            const auto b = this->get_ith_bit(x,\
    \ i);\n            // bit \u304C 0 \u306E\u65B9\u306B\u3042\u308B\u51FA\u73FE\u56DE\
    \u6570\u3092\u3059\u3079\u3066\u8DB3\u3059\n            if (b == 1 and node->child[0]\
    \ != nullptr) {\n                count += node->child[0]->count;\n           \
    \ }\n            if (node->child[b] == nullptr) {\n                break;\n  \
    \          }\n            node = node->child[b].get();\n        }\n\n        return\
    \ count;\n    }\n\n    // x \u3088\u308A\u5927\u304D\u3044\u5024\u306E\u51FA\u73FE\
    \u56DE\u6570\n    int count_more_than(const T x) const {\n        assert(x >=\
    \ 0);\n        return this->size() - this->count_less_than(x) - this->count(x);\n\
    \    }\n\n    // \u96C6\u5408\u5185\u3067\u6700\u5927\u306E\u5024\n    T find_max_element()\
    \ const {\n        return this->find_kth_max_element(0);\n    }\n\n    // \u96C6\
    \u5408\u5185\u3067\u6700\u5C0F\u306E\u5024\n    T find_min_element() const {\n\
    \        return this->find_kth_min_element(0);\n    }\n\n    // \u96C6\u5408\u5185\
    \u3067\u5C0F\u3055\u3044\u9806\u306B\u6570\u3048\u3066 k \u756A\u76EE\u306E\u5024\
    (0-origin)\n    // k = 0 \u3067\u6700\u5C0F\u5024\n    T find_kth_min_element(int\
    \ k) const {\n        if (k < 0 or k >= this->size()) {\n            return this->NOTFOUND;\n\
    \        }\n\n        T ans = 0;\n        auto node = this->root.get();\n    \
    \    for (int i = bit_size - 1; i >= 0; --i) {\n\n            const bool exist0\
    \ = node->child[0] != nullptr;\n            const bool exist1 = node->child[1]\
    \ != nullptr;\n            assert(exist0 or exist1);\n\n            bool go_node0;\n\
    \            if (exist0 and exist1) {\n                if (k < node->child[0]->count)\
    \ {\n                    go_node0 = true;\n                } else {\n        \
    \            go_node0 = false;\n                    k -= node->child[0]->count;\n\
    \                }\n            } else {\n                go_node0 = exist0;\n\
    \            }\n\n            if (go_node0) {\n                node = node->child[0].get();\n\
    \            } else {\n                ans |= ((T) 1 << i);\n                node\
    \ = node->child[1].get();\n            }\n        }\n\n        return ans;\n \
    \   }\n\n    // k \u756A\u76EE\u306B\u5927\u304D\u3044\u5024(0-based)\n    //\
    \ k = 0 \u3067\u6700\u5927\u5024\n    T find_kth_max_element(const int k) const\
    \ {\n        if (k < 0 or k >= this->size()) {\n            return this->NOTFOUND;\n\
    \        }\n        return this->find_kth_min_element(this->size() - 1 - k);\n\
    \    }\n\n    // x \u4EE5\u4E0B\u3067\u6700\u5927\u306E\u30CE\u30FC\u30C9\n  \
    \  const Node<T> *predecessor(const T x) const {\n        assert(x >= 0);\n\n\
    \        auto node = this->root.get();\n        for (int i = bit_size - 1; i >=\
    \ 0; --i) {\n            const auto b = this->get_ith_bit(x, i);\n           \
    \ if (node->child[b] == nullptr) {\n                if (b == 1) {\n          \
    \          // node \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306B\u304A\
    \u3051\u308B\u6700\u5C0F\u306E\u8449\u3092\u6307\u3059\n                    return\
    \ std::ref(node->jump);\n                } else {\n                    return\
    \ std::ref(node->jump->prev);\n                }\n            }\n            node\
    \ = node->child[b].get();\n        }\n        // x \u3092\u898B\u3064\u3051\u305F\
    \n        assert(node->x == x);\n        return std::ref(node);\n    }\n\n   \
    \ // x \u4EE5\u4E0A\u3067\u6700\u5C0F\u306E\u5024\n    const Node<T> *successor(const\
    \ T x) const {\n        assert(x >= 0);\n\n        auto node = this->root.get();\n\
    \        for (int i = bit_size - 1; i >= 0; --i) {\n            const auto b =\
    \ this->get_ith_bit(x, i);\n            if (node->child[b] == nullptr) {\n   \
    \             if (b == 0) {\n                    return std::ref(node->jump);\n\
    \                } else {\n                    return std::ref(node->jump->next);\n\
    \                }\n            }\n            node = node->child[b].get();\n\
    \        }\n        // x \u3092\u898B\u3064\u3051\u305F\n        assert(node->x\
    \ == x);\n        return std::ref(node);\n    }\n\n    // v^x \u3092\u6700\u5C0F\
    \u306B\u3059\u308B\u3088\u3046\u306A x \u3092\u307F\u3064\u3051\u308B\n    T find_xor_min_element(T\
    \ v) const {\n        assert(v >= 0);\n        assert(not this->empty());\n\n\
    \        auto node = this->root.get();\n        T ans = 0;\n        for (int i\
    \ = bit_size - 1; i >= 0; --i) {\n            auto b = (v >> (T) i) & 1u;\n\n\
    \            const bool exist0 = node->child[0] != nullptr;\n            const\
    \ bool exist1 = node->child[1] != nullptr;\n            assert(exist0 or exist1);\n\
    \n            bool go_node0;\n            if (exist0 and exist1) {\n         \
    \       go_node0 = (b == 0);\n            } else {\n                go_node0 =\
    \ exist0;\n            }\n\n            if (go_node0) {\n                node\
    \ = node->child[0].get();\n            } else {\n                ans |= (1u <<\
    \ (unsigned) i);\n                node = node->child[1].get();\n            }\n\
    \        }\n\n        return ans;\n    }\n\n    // v \u4EE5\u5916\u3067 v^x \u3092\
    \u6700\u5C0F\u306B\u3059\u308B\u3088\u3046\u306A x \u3092\u6C42\u3081\u308B\n\
    \    T min_element_xor_without_v(T v) const {\n        assert(false);\n      \
    \  return 0;\n    }\n\n    // v^x \u3092\u6700\u5927\u306B\u3059\u308B\u3088\u3046\
    \u306A x \u3092\u6C42\u3081\u308B\n    T max_element_xor(const T v) const {\n\
    \        assert(v >= 0);\n        assert(not this->empty());\n\n        auto node\
    \ = this->root.get();\n        T ans = 0;\n        for (int i = bit_size - 1;\
    \ i >= 0; --i) {\n            auto b = (v >> (T) i) & 1u;\n\n            const\
    \ bool exist0 = node->child[0] != nullptr;\n            const bool exist1 = node->child[1]\
    \ != nullptr;\n            assert(exist0 or exist1);\n\n            bool go_node0;\n\
    \            if (exist0 and exist1) {\n                go_node0 = (b == 1);\n\
    \            } else {\n                go_node0 = exist0;\n            }\n\n \
    \           if (go_node0) {\n                node = node->child[0].get();\n  \
    \          } else {\n                ans |= (1u << (unsigned) i);\n          \
    \      node = node->child[1].get();\n            }\n        }\n\n        return\
    \ ans;\n    }\n\n    // xor\u3057\u305F\u3068\u304D\u306B\uFF0C\u5C0F\u3055\u3044\
    \u65B9\u304B\u3089\u898B\u3066k\u756A\u76EE\u306E\u6570(0-based)\n    T kth_element_xor(const\
    \ T v, int k) const {\n        assert(v >= 0);\n        assert(this->root->count\
    \ != 0);\n        assert(k < this->root->count);\n        assert(false);\n   \
    \     return 0;\n\n    }\n\n    // \u3059\u3079\u3066\u306E\u8981\u7D20\u306B\u3064\
    \u3044\u3066\uFF0Cv\u3092xor\u3057\u305F\u5024\u306B\u5909\u66F4\u3059\u308B\n\
    \    void xor_all(T v) const {\n        assert(v >= 0);\n        assert(false);\n\
    \    }\n\nprivate:\n    // x \u306E i \u756A\u76EE\u306E bit \u3092\u53D6\u5F97\
    \n    int get_ith_bit(const T x, const int i) const {\n        return (x >> i)\
    \ & 1u;\n    }\n};\n#line 4 \"test/cpp/Tree/BinaryTrie8_predecessor_successor.test.cpp\"\
    \n#include <iostream>\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int N, Q;\n    string T;\n    cin >>\
    \ N >> Q;\n    cin >> T;\n\n    BinaryTrie<unsigned int, 24> bt;\n    for (int\
    \ i = 0; i < (int) T.size(); ++i) {\n        if (T[i] == '1') {\n            bt.insert(i);\n\
    \        }\n    }\n\n    for (int i = 0; i < Q; ++i) {\n        int C, K;\n  \
    \      cin >> C >> K;\n        if (C == 0) {\n            if (not bt.exist(K))\
    \ {\n                bt.insert(K);\n            }\n        } else if (C == 1)\
    \ {\n            if (bt.exist(K)) {\n                bt.erase(K, 1);\n       \
    \     }\n        } else if (C == 2) {\n            cout << bt.exist(K) << endl;\n\
    \        } else if (C == 3) {\n            auto u = bt.successor(K);\n       \
    \     if (u == &bt.DUMMY) {\n                cout << -1 << endl;;\n          \
    \  } else {\n                cout << u->x << endl;\n            }\n        } else\
    \ if (C == 4) {\n            auto u = bt.predecessor(K);\n            if (u ==\
    \ &bt.DUMMY) {\n                cout << -1 << endl;\n            } else {\n  \
    \              cout << u->x << endl;\n            }\n        }\n    }\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    \n#include \"library/cpp/Tree/BinaryTrie.hpp\"\n#include <iostream>\n\nusing namespace\
    \ std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, Q;\n    string T;\n    cin >> N >> Q;\n    cin >> T;\n\n    BinaryTrie<unsigned\
    \ int, 24> bt;\n    for (int i = 0; i < (int) T.size(); ++i) {\n        if (T[i]\
    \ == '1') {\n            bt.insert(i);\n        }\n    }\n\n    for (int i = 0;\
    \ i < Q; ++i) {\n        int C, K;\n        cin >> C >> K;\n        if (C == 0)\
    \ {\n            if (not bt.exist(K)) {\n                bt.insert(K);\n     \
    \       }\n        } else if (C == 1) {\n            if (bt.exist(K)) {\n    \
    \            bt.erase(K, 1);\n            }\n        } else if (C == 2) {\n  \
    \          cout << bt.exist(K) << endl;\n        } else if (C == 3) {\n      \
    \      auto u = bt.successor(K);\n            if (u == &bt.DUMMY) {\n        \
    \        cout << -1 << endl;;\n            } else {\n                cout << u->x\
    \ << endl;\n            }\n        } else if (C == 4) {\n            auto u =\
    \ bt.predecessor(K);\n            if (u == &bt.DUMMY) {\n                cout\
    \ << -1 << endl;\n            } else {\n                cout << u->x << endl;\n\
    \            }\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - library/cpp/Tree/BinaryTrie.hpp
  isVerificationFile: true
  path: test/cpp/Tree/BinaryTrie8_predecessor_successor.test.cpp
  requiredBy: []
  timestamp: '2024-02-19 15:42:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cpp/Tree/BinaryTrie8_predecessor_successor.test.cpp
layout: document
redirect_from:
- /verify/test/cpp/Tree/BinaryTrie8_predecessor_successor.test.cpp
- /verify/test/cpp/Tree/BinaryTrie8_predecessor_successor.test.cpp.html
title: test/cpp/Tree/BinaryTrie8_predecessor_successor.test.cpp
---
