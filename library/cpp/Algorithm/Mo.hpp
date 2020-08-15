#include <vector>
#include <cmath>
#include <algorithm>

std::vector<int> A;
// 1回の伸縮の計算量がaのときO(a(N + Q)sqrt(N))
// 左のポインタの移動はO(Q sqrt(N))，右はO(N aqrt(N))
class Mo {
    struct Query {
        int id;
        int left;
        int right;
    };

public:
    int num_query;                   // クエリの数
    std::vector<Query> query;        // クエリ
    const int num_bucket;            // バケットの数
    int now_left = 0, now_right = 0; // 現在見ている区間[now_left, now_right)

    Mo(const int n, const int num_query) : num_query(num_query), num_bucket((int) sqrt(n)) {
        this->counter.resize(n);
        this->query.resize(num_query);
    }

    // [l, r)
    void add_query(int id, int l, int r) {
        this->query[id].id = id;
        this->query[id].left = l;
        this->query[id].right = r;
    }

    // クエリをソートする
    void build() {
        std::sort(this->query.begin(), this->query.end(), [&](const Query &lhs, const Query &rhs)->bool {
            const unsigned int left_bucket = lhs.left / this->num_bucket;
            const unsigned int right_bucket = rhs.left / this->num_bucket;
            // クエリの左が所属するバケットが違うなら，クエリの左で比較(=所属するバケットで比較)
            if (left_bucket != right_bucket) {
                return left_bucket < right_bucket;
            }

            // 定数倍高速化
            // 奇数のバケットだけ右のソート順を逆にして，バケットを移動したときのnow_rightを移動する距離を短くする
            if (left_bucket & 1u) {
                return lhs.right < rhs.right;
            }

            return lhs.right > rhs.right;
        });
    }

    std::vector<int> solve() {
        std::vector<int> ans(this->num_query);

        int query_ans = 0;
        for (int i = 0; i < this->num_query; ++i) {
            const int id = this->query[i].id;
            const int left = this->query[i].left;
            const int right = this->query[i].right;

            // [now_left, now_right)をqueryの[left, right)になるように調整
            while (left < this->now_left) {
                this->add(--this->now_left, query_ans);
            }
            while (this->now_left < left) {
                this->del(this->now_left++, query_ans);
            }

            while (this->now_right < right) {
                this->add(this->now_right++, query_ans);
            }
            while (this->now_right > right) {
                this->del(--this->now_right, query_ans);
            }

            ans[id] = query_ans;
        }

        return ans;
    }

private:
    // 問題特有のデータ
    std::vector<int> counter;

    // // A[idx]が追加されたときの操作
    // inline void add(const int idx, int &query_ans) {
    //     ++counter[A[idx]];
    //     query_ans += (counter[A[idx]] == 1);
    // }

    // // A[idx]が削除されたときの操作
    // inline void del(const int idx, int &query_ans) {
    //     --counter[A[idx]];
    //     query_ans -= (counter[A[idx]] == 0);
    // }

    // A[idx]が追加されたときの操作
    inline void add(const int idx, int &query_ans) {
        ++counter[A[idx]];
        query_ans += (counter[A[idx]] == 1);
        query_ans -= (counter[A[idx]] == 2);
    }

    // A[idx]が削除されたときの操作
    inline void del(const int idx, int &query_ans) {
        --counter[A[idx]];
        query_ans += (counter[A[idx]] == 1);
        query_ans -= (counter[A[idx]] == 0);
    }
};