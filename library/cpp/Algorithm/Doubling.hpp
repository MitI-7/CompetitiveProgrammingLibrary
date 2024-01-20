#include <cassert>
#include <vector>

template<typename T>
class Doubling {
    const int LOG;
    std::vector<std::vector<T>> table;  //table[k][i] = iのk回遷移先の値
    bool initialized;

public:
    // n: function(x) の x の最大値
    // max_k: function 関数を適用する回数 k の最大値
    Doubling(int n, long long max_k) : LOG(64 - __builtin_clzll(max_k)), initialized(false) {
        this->table.assign(LOG, std::vector<T>(n, -1));
    }

    // xの遷移先
    // function(x) = y
    void function(const int x, const T y) {
        assert(not this->initialized);
        this->table[0][x] = y;
    }

    // a に function 関数を k 回適用したときの値
    // O(log k)
    T query(T a, unsigned long long k) {
        if (not this->initialized) {
            this->build();
        }
        for (int i = this->LOG - 1; i >= 0; i--) {
            if ((k >> i) & 1) {
                a = this->table[i][a];
            }
        }

        return a;
    }

private:
    // O(N log max_k)
    void build() {
        for (int k = 0; k + 1 < this->LOG; ++k) {
            for (int i = 0; i < int(this->table[k].size()); ++i) {
                if (this->table[k][i] == -1) {
                    this->table[k + 1][i] = -1;
                }
                else {
                    this->table[k + 1][i] = this->table[k][this->table[k][i]];
                }
            }
        }
        this->initialized = true;
    }
};