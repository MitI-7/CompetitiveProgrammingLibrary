#include <cassert>
#include <set>

template<typename T>
class TopK {
private:
    T top_k_sum = 0;            // 上位 k 件の合計
    int k;
    const bool reverse;         // 小さい順にする
    std::multiset<T> top_k;     // 上位 k 件
    std::multiset<T> reserve;   // 補欠

public:
    // reverse = false の場合，大きい順に k 件を管理．trueの場合，小さい順に k 件を管理する
    explicit TopK(const int k, const bool reverse = false) : k(k), reverse(reverse) {
        assert(k >= 0);
    }

    // 現在の要素数を求める
    [[nodiscard]] int size() const {
        return this->top_k.size() + this->reserve.size();
    }

    // k を変更する
    // O(abs(new_k - k))
    void change_k(const int new_k) {
        assert(new_k >= 0);

        if (new_k == this->k) {
            return;
        }

        this->k = new_k;
        this->balance();
    }

    // 上位 k 件の合計を求める
    // O(1)
    [[nodiscard]] T get_top_k_sum() {
        if (this->reverse) {
            return this->top_k_sum * -1;
        }
        return this->top_k_sum;
    }

    // 1 番目の値を求める
    [[nodiscard]] T get_top() {
        assert(this->size() > 0);
        if (this->reverse) {
            return *this->top_k.rbegin() * -1;
        }
        return *this->top_k.rbegin();
    }

    // k 番目の値を求める
    [[nodiscard]] T get_top_k() {
        assert(this->size() > 0);
        if (this->reverse) {
            return *this->top_k.begin() * -1;
        }
        return *this->top_k.begin();
    }

    // O(log n)
    void insert(T x) {
        if (this->reverse) {
            x *= -1;
        }
        this->top_k.insert(x);
        this->top_k_sum += x;
        this->balance();
    }

    // O(log n)
    void erase(T x) {
        if (this->reverse) {
            x *= -1;
        }

        // 補欠にいるなら，補欠から削除するだけ
        {
            const auto it = this->reserve.find(x);
            if (it != this->reserve.end()) {
                this->reserve.erase(it);
                return;
            }
        }

        {
            const auto it = this->top_k.find(x);
            if (it != this->top_k.end()) {
                this->top_k_sum -= x;
                this->top_k.erase(it);
                this->balance();
            }
        }
    }

private:
    void balance() {
        // top k が k 個以上あるなら最小の要素を補欠に送る
        while ((int) this->top_k.size() > this->k) {
            auto mini = this->top_k.begin();
            this->top_k_sum -= *mini;
            this->reserve.insert(*mini);
            this->top_k.erase(mini);
        }

        // top k が k に満たないなら補欠から最大の要素を送る
        while ((int) this->top_k.size() < this->k and not this->reserve.empty()) {
            auto maxi = this->reserve.rbegin();
            this->top_k_sum += *maxi;
            this->top_k.insert(*maxi);
            this->reserve.erase((++maxi).base());
        }
    }
};