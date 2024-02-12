#include <array>
#include <cassert>
#include <limits>
#include <memory>
#include <vector>

template<typename T>
class Node {
public:
    T x;                 // 葉の値
    int count;           // このノードを通る回数
    int count_distinct;  // このノードを頂点とする葉の個数(=種類数)

    // 左の子と右の子
    std::array<std::unique_ptr<Node>, 2> child = {nullptr, nullptr};

    // 葉のとき，左の葉と右の葉を指す（存在しない場合は DUMMYを指す）
    Node *prev;
    Node *next;

    Node *parent;

    // 左の子を持たないときは、この node を根とする部分木における最小の葉を指す
    // 右の子を持たないときは、この node を根とする部分木における最大の葉を指す
    // Trie が空のときは DUMMY を指す
    Node *jump;

    Node() : x(0), count(0), count_distinct(0), prev(nullptr), next(nullptr), parent(nullptr), jump(nullptr) {}

    Node(const T x, int count) : x(x), count(count), count_distinct(0), prev(nullptr), next(nullptr), parent(nullptr), jump(nullptr) {};
};

template<typename T=uint64_t, int bit_size = 64>
class BinaryTrie {
private:
public:
    std::unique_ptr<Node<T>> root;
    const T NOTFOUND = std::numeric_limits<T>::max();
    Node<T> DUMMY;

    BinaryTrie() {
        this->root = std::make_unique<Node<T>>();
        root->jump = &DUMMY;
        DUMMY.jump = &DUMMY;
        DUMMY.x = NOTFOUND;
        DUMMY.prev = DUMMY.next = &DUMMY;
    }

    // 集合の要素数
    [[nodiscard]] int size() const {
        return this->root->count;
    }

    // 集合の種類数(= 葉の個数)
    [[nodiscard]] int distinct() const {
        return this->root->count_distinct;
    }

    [[nodiscard]] bool empty() const {
        return this->root->count == 0;
    }

    // x を num 個挿入する
    void insert(const T x, const int num = 1) {
        assert(x >= 0);
        auto node = this->root.get();
        node->count += num;

        const bool exist = this->exist(x);

        int i = bit_size - 1;
        // 木の終端ノードにたどり着くまで下る
        for (; i >= 0; --i) {
            const int b = this->get_ith_bit(x, i);
            if (node->child[b] == nullptr) {
                break;
            }
            node = node->child[b].get();
            assert(node->count >= 1);
            node->count += num;
            node->count_distinct += not exist;
        }
        // すでに葉がある
        if (i == -1) {
            assert(node->x == x);
            return;
        }

        // 新しい種類の数値が追加された
        this->root.get()->count_distinct++;

        // x の左の葉と右の葉を取得
        assert(node->jump != nullptr);
        const int b = this->get_ith_bit(x, i);
        auto *left_leaf = (b == 1) ? node->jump : node->jump->prev;
        auto *right_leaf = left_leaf->next;
        node->jump = nullptr;
        assert(left_leaf != nullptr);

        // 葉までの経路を作る
        for (; i >= 0; --i) {
            const int b = this->get_ith_bit(x, i);
            assert(node->child[b] == nullptr);
            node->child[b] = std::make_unique<Node<T>>();
            node->child[b]->parent = node;
            node = node->child[b].get();
            node->count += num;
            node->count_distinct++;
        }
        node->x = x;

        // x を連結リストに追加
        node->prev = left_leaf;
        node->next = right_leaf;
        left_leaf->next = node;
        right_leaf->prev = node;

        // 根に戻りながら，jump を更新する
        auto u = node->parent;
        while (u != nullptr) {
            if ((u->child[0] == nullptr and (u->jump == nullptr or u->jump->x > x)) or
                (u->child[1] == nullptr and (u->jump == nullptr or u->jump->x < x))) {
                u->jump = node;
            }
            u = u->parent;
        }
    }

    // x を num 個削除する
    // x が num 個未満しかない場合はすべて削除する
    void erase(const T x, int num = 1) {
        assert(x >= 0);
        int num_x = this->count(x);
        if (num_x == 0) {
            return;
        }

        num = std::min(num, num_x);

        auto node = this->root.get();
        node->count -= num;

        int i = bit_size - 1;

        // x を含む葉 u を見つける
        for (; i >= 0; --i) {
            int b = this->get_ith_bit(x, i);
            assert(node->child[b] != nullptr);
            node = node->child[b].get();
            assert(node->count > 0);
            node->count -= num;
            node->count_distinct -= (num == num_x);
        }
        assert(node->x == x);   // 葉にいる

        // x が残るときは終了
        if (num < num_x) {
            return;
        }

        //　葉が消える
        this->root.get()->count_distinct--;

        // node を連結リストから削除する
        node->prev->next = node->next;  // 自分の左は自分を指しているので，右を指すように更新
        node->next->prev = node->prev;  // 自分の右の自分を指しているので，左を指すように更新

        // node から根へ上り，不要なノードを削除する
        auto u = node;
        for (i = 0; i < bit_size; ++i) {
            int b = this->get_ith_bit(x, i);
            u = u->parent;
            u->child[b].release();
            u->child[b] = nullptr;
            // 反対の子供が存在すれば終了
            if (u->child[1 - b] != nullptr) {
                break;
            }
        }

        // jump を更新する
        int b = this->get_ith_bit(x, i);
        assert(u->child[b] == nullptr);
        if (u->child[0] == nullptr) {
            u->jump = node->next;
        } else {
            u->jump = node->prev;
        }

        u = u->parent;
        i++;
        for (; i < bit_size; ++i) {
            b = this->get_ith_bit(x, i);
            if (u->jump == node) {
                if (u->child[0] == nullptr) {
                    u->jump = node->next;
                } else {
                    u->jump = node->prev;
                }
            }
            assert(u->count > 0);
            u = u->parent;
        }
    }

    std::pair<T, T> find_median() {
        const int m = this->size();
        assert(m > 0);
        if (m % 2 == 0) {
            return {this->find_kth_min_element(m / 2 - 1), this->find_kth_min_element(m / 2)};
        } else {
            return {this->find_kth_min_element(m / 2), this->find_kth_min_element(m / 2)};
        }
    }

    // 木にない値のうち，小さい方から k 番目の値を取得(0-origin)
    T find_mex(long long k) const {
        long long maxi_leaf = (long long) 1 << bit_size;

        // k 番目の値は木の外側にある
        if (k + 1 >= maxi_leaf - this->root.get()->count_distinct) {
            return (k - this->root.get()->count_distinct) + maxi_leaf;
        }

        T ans = 0;
        maxi_leaf /= 2;
        auto node = this->root.get();
        for (int i = bit_size - 1; i >= 0; --i) {
            const int num_left_leaf = (node->child[0] == nullptr) ? 0 : node->child[0]->count_distinct;

            // 左側の部分木内にある
            if (k + 1 <= maxi_leaf - num_left_leaf) {
                if (node->child[0] == nullptr) {
                    ans += k;
                    break;
                }
                node = node->child[0].get();
            } else {
                k -= (maxi_leaf - num_left_leaf);

                ans |= ((T) 1 << i);
                if (node->child[1] == nullptr) {
                    ans += k;
                    break;
                }
                node = node->child[1].get();
            }
            maxi_leaf /= 2;
        }

        return ans;
    }

    // vがあるか
    bool exist(const T x) const {
        assert(x >= 0);
        return this->count(x) > 0;
    }

    // x の出現回数
    int count(const T x) const {
        assert(x >= 0);
        auto node = this->root.get();
        for (int i = bit_size - 1; i >= 0; --i) {
            const auto b = this->get_ith_bit(x, i);
            if (node->child[b] == nullptr) {
                return 0;
            }
            node = node->child[b].get();
            assert(node->count > 0);
        }
        assert(node->x == x);
        assert(node->count > 0);
        return node->count;
    }

    // x より小さい値の出現回数
    long long count_less_than(const T x) const {
        assert(x >= 0);
        long long count = 0;
        auto node = this->root.get();

        for (int i = bit_size - 1; i >= 0; --i) {
            const auto b = this->get_ith_bit(x, i);
            // bit が 0 の方にある出現回数をすべて足す
            if (b == 1 and node->child[0] != nullptr) {
                count += node->child[0]->count;
            }
            if (node->child[b] == nullptr) {
                break;
            }
            node = node->child[b].get();
        }

        return count;
    }

    // x より大きい値の出現回数
    int count_more_than(const T x) const {
        assert(x >= 0);
        return this->size() - this->count_less_than(x) - this->count(x);
    }

    // 集合内で最大の値
    T find_max_element() const {
        return this->find_kth_max_element(0);
    }

    // 集合内で最小の値
    T find_min_element() const {
        return this->find_kth_min_element(0);
    }

    // 集合内で小さい順に数えて k 番目の値(0-origin)
    // k = 0 で最小値
    T find_kth_min_element(int k) const {
        if (k < 0 or k >= this->size()) {
            return this->NOTFOUND;
        }

        T ans = 0;
        auto node = this->root.get();
        for (int i = bit_size - 1; i >= 0; --i) {

            const bool exist0 = node->child[0] != nullptr;
            const bool exist1 = node->child[1] != nullptr;
            assert(exist0 or exist1);

            bool go_node0;
            if (exist0 and exist1) {
                if (k < node->child[0]->count) {
                    go_node0 = true;
                } else {
                    go_node0 = false;
                    k -= node->child[0]->count;
                }
            } else {
                go_node0 = exist0;
            }

            if (go_node0) {
                node = node->child[0].get();
            } else {
                ans |= ((T) 1 << i);
                node = node->child[1].get();
            }
        }

        return ans;
    }

    // k 番目に大きい値(0-based)
    // k = 0 で最大値
    T find_kth_max_element(const int k) const {
        if (k < 0 or k >= this->size()) {
            return this->NOTFOUND;
        }
        return this->find_kth_min_element(this->size() - 1 - k);
    }

    // x 以下で最大のノード
    const Node<T> *predecessor(const T x) const {
        assert(x >= 0);

        auto node = this->root.get();
        for (int i = bit_size - 1; i >= 0; --i) {
            const auto b = this->get_ith_bit(x, i);
            if (node->child[b] == nullptr) {
                if (b == 1) {
                    // node を根とする部分木における最小の葉を指す
                    return std::ref(node->jump);
                } else {
                    return std::ref(node->jump->prev);
                }
            }
            node = node->child[b].get();
        }
        // x を見つけた
        assert(node->x == x);
        return std::ref(node);
    }

    // x 以上で最小の値
    const Node<T> *successor(const T x) const {
        assert(x >= 0);

        auto node = this->root.get();
        for (int i = bit_size - 1; i >= 0; --i) {
            const auto b = this->get_ith_bit(x, i);
            if (node->child[b] == nullptr) {
                if (b == 0) {
                    return std::ref(node->jump);
                } else {
                    return std::ref(node->jump->next);
                }
            }
            node = node->child[b].get();
        }
        // x を見つけた
        assert(node->x == x);
        return std::ref(node);
    }

    // v^x を最小にするような x をみつける
    T find_xor_min_element(T v) const {
        assert(v >= 0);
        assert(not this->empty());

        auto node = this->root.get();
        T ans = 0;
        for (int i = bit_size - 1; i >= 0; --i) {
            auto b = (v >> (T) i) & 1u;

            const bool exist0 = node->child[0] != nullptr;
            const bool exist1 = node->child[1] != nullptr;
            assert(exist0 or exist1);

            bool go_node0;
            if (exist0 and exist1) {
                go_node0 = (b == 0);
            } else {
                go_node0 = exist0;
            }

            if (go_node0) {
                node = node->child[0].get();
            } else {
                ans |= (1u << (unsigned) i);
                node = node->child[1].get();
            }
        }

        return ans;
    }

    // v 以外で v^x を最小にするような x を求める
    T min_element_xor_without_v(T v) const {
        assert(false);
        return 0;
    }

    // v^x を最大にするような x を求める
    T max_element_xor(const T v) const {
        assert(v >= 0);
        assert(not this->empty());

        auto node = this->root.get();
        T ans = 0;
        for (int i = bit_size - 1; i >= 0; --i) {
            auto b = (v >> (T) i) & 1u;

            const bool exist0 = node->child[0] != nullptr;
            const bool exist1 = node->child[1] != nullptr;
            assert(exist0 or exist1);

            bool go_node0;
            if (exist0 and exist1) {
                go_node0 = (b == 1);
            } else {
                go_node0 = exist0;
            }

            if (go_node0) {
                node = node->child[0].get();
            } else {
                ans |= (1u << (unsigned) i);
                node = node->child[1].get();
            }
        }

        return ans;
    }

    // xorしたときに，小さい方から見てk番目の数(0-based)
    T kth_element_xor(const T v, int k) const {
        assert(v >= 0);
        assert(this->root->count != 0);
        assert(k < this->root->count);
        assert(false);
        return 0;

    }

    // すべての要素について，vをxorした値に変更する
    void xor_all(T v) const {
        assert(v >= 0);
        assert(false);
    }

private:
    // x の i 番目の bit を取得
    int get_ith_bit(const T x, const int i) const {
        return (x >> i) & 1u;
    }
};