#include <array>
#include <cassert>
#include <vector>



template <typename T=uint64_t, int bit_size=62> class BinaryTrie {
private:
    class Node {
    public:
        std::array<Node*, 2> children;
        int freq;   // 出現頻度
        int count;  // このノードを通る回数

        Node() : count(0) {}
        Node(int count) : count(count) {
        };
    };

    Node *root;
public:
    BinaryTrie() {
        this->root = new Node(0);
    }

    // 集合内の要素数
    unsigned int size() {
        return this->root->count;
    }

    // vを挿入する
    void insert(const T v) {
        Node *node = this->root;
        node->count++;

        for (int i = bit_size - 1; i >= 0; --i) {
            const auto b = (v >> (unsigned int)i) & 1u;
            if (node->children[b] == nullptr) {
                node->children[b] = new Node(0);
            }
            node = node->children[b];
            node->count++;
        }
        node->freq++;
    }

    // vをnum個削除する
    void erase(const T v, int num=1) {
        const int c = count(v);
        assert(num <= c);
        if (c == 0) {
            return;
        }

        Node *node = this->root;
        node->count -= num;

        for (int i = bit_size - 1; i >= 0; --i) {
            const auto b = (v >> (unsigned int)i) & 1u;
            node = node->children[b];
            node->count -= num;
        }
        node->freq -= num;
    }

    // vがあるか
    bool find(const T v) {
        return this->count(v) > 0;
    }

    // vの出現回数
    int count(const T v) {
        Node *node = this->root;

        for (int i = bit_size - 1; i >= 0; --i) {
            auto b = (v >> (unsigned )i) & 1u;
            if (node->children[b] == nullptr or node->children[b]->count <= 0) {
                return 0;
            }
            node = node->children[b];
        }
        return node->freq;
    }

    // vより小さい値の出現回数
    int count_less(const T v) {
        assert(false);
        return 0;
    }

    // 集合内で最大の値
    T max_element() {
        return this->kth_element(this->size() - 1);
    }

    // 集合内で最小の値
    T min_element() {
        return this->kth_element(0);
    }

    // 集合内で小さい順に数えてk番目の値(0-based)
    T kth_element(int k) {
        assert(this->size() != 0);
        assert(k < this->size());

        Node *node = this->root;
        T max_xor = 0;
        for (int i = bit_size - 1; i >= 0; --i) {

            const bool exist0 = (node->children[0] != nullptr and node->children[0]->count > 0);
            const bool exist1 = (node->children[1] != nullptr and node->children[1]->count > 0);
            assert(exist0 or exist1);

            bool go_node0;
            if (exist0 and not exist1) {
                go_node0 = true;
            }
            else if (not exist0 and exist1) {
                go_node0 = false;
            }
            else {
                if (k < node->children[0]->count) {
                    go_node0 = true;
                }
                else {
                    go_node0 = false;
                    k -= node->children[0]->count;
                }
            }

            if (go_node0) {
                node = node->children[0];
            }
            else {
                max_xor |= ((T)1 << i);
                node = node->children[1];
            }
        }

        return max_xor;
    }

    // v以上の最小の数
    T lower_bound(const T v) {
        assert(false);
        return 0;
    }

    // vより大きい最小の数
    T upper_bound(const T v) {
        assert(false);
        return 0;
    }

    // v^xを最小にするようなx
    T min_element_xor(T v) {
        assert(this->size() != 0);

        Node *node = this->root;
        T max_xor = 0;
        for (int i = bit_size - 1; i >= 0; --i) {
            auto b = (v >> (unsigned )i) & 1u;

            const bool exist0 = (node->children[0] != nullptr and node->children[0]->count > 0);
            const bool exist1 = (node->children[1] != nullptr and node->children[1]->count > 0);
            assert(exist0 or exist1);

            bool go_node0;
            if (exist0 and not exist1) {
                go_node0 = true;
            }
            else if (not exist0 and exist1) {
                go_node0 = false;
            }
            else {
                go_node0 = (b == 0);
            }

            if (go_node0) {
                node = node->children[0];
            }
            else {
                max_xor |= (1u << (unsigned)i);
                node = node->children[1];
            }
        }

        return max_xor;
    }

    // v以外でv^xを最小にするようなx
    T min_element_xor_without_v(T v) {
        assert(false);
        return 0;
    }

    // v^xを最大にするようなx
    T max_element_xor(const T v) {
        assert(this->size() != 0);

        Node *node = this->root;
        T max_xor = 0;
        for (int i = bit_size - 1; i >= 0; --i) {
            auto b = (v >> (unsigned)i) & 1u;

            const bool exist0 = (node->children[0] != nullptr and node->children[0]->count > 0);
            const bool exist1 = (node->children[1] != nullptr and node->children[1]->count > 0);
            assert(exist0 or exist1);

            bool go_node0;
            if (exist0 and not exist1) {
                go_node0 = true;
            }
            else if (not exist0 and exist1) {
                go_node0 = false;
            }
            else {
                go_node0 = (b == 1);
            }

            if (go_node0) {
                node = node->children[0];
            }
            else {
                max_xor |= (1u << (unsigned)i);
                node = node->children[1];
            }
        }

        return max_xor;
    }

    // xorしたときに，小さい方から見てk番目の数(0-based)
    T kth_element_xor(const T v, int k) {
        assert(this->root->count != 0);
        assert(k < this->root->count);
        assert(false);
        return 0;

    }

    // すべての要素について，vをxorした値に変更する
    void xor_all(T v) {
        assert(false);
    }
};

// 連続部分列のxorの最大値 O(n log(max v))
uint64_t maximum_subarray_xor(std::vector<uint64_t> &v) {
    BinaryTrie<> bt;
    bt.insert(0);

    uint64_t maximum_xor = 0;
    uint64_t pre_xor = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
        pre_xor ^= v[i];
        bt.insert(pre_xor);
        // [(0-i), i]のxorの最大値
        maximum_xor = std::max(maximum_xor, pre_xor ^ bt.max_element_xor(pre_xor));
    }

    return maximum_xor;
}