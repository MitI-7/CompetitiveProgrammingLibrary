#include <algorithm>
#include <cmath>
#include <vector>

// 1 回の伸縮の計算量が a のとき O(a * N * sqrt(Q))
template<class T, T (*add)(int, T), T (*del)(int, T)>
class Mo {
    struct Query {
        int id;
        int left;
        int right;
    };

public:
    const int num_query;             // クエリの数
    std::vector<Query> queries;      // クエリ
    const int num_bucket;            // バケットの数

private:
    int now_left = 0, now_right = 0; // 現在見ている区間[now_left, now_right)

public:
    // n: 配列の長さ
    // num_query: クエリの個数
    // bucket = sqrt(3) * N / sqrt(2 * Q)
    Mo(const int n, const int num_query) : num_query(num_query), queries(num_query), num_bucket(std::max<int>(1, (double) n / std::max<double>(1.0, sqrt(num_query * 2.0 / 3.0)))) {}

    // [l, r)
    void add_query(const int id, const int l, const int r) {
        this->queries[id].id = id;
        this->queries[id].left = l;
        this->queries[id].right = r;
    }

    std::vector<T> solve() {
        this->sort_queries();

        std::vector<T> ans(this->num_query);

        T now_ans = 0;
        for (const auto [id, left, right]: this->queries) {

            // [now_left, now_right) を queryの [left, right) になるように調整
            // now_left を左にずらす
            while (left < this->now_left) {
                now_ans = add(--this->now_left, now_ans);
            }
            // now_right を右にずらす
            while (this->now_right < right) {
                now_ans = add(this->now_right++, now_ans);
            }
            // now_left を右にずらす
            while (this->now_left < left) {
                now_ans = del(this->now_left++, now_ans);
            }
            // now_right を左にずらす
            while (this->now_right > right) {
                now_ans = del(--this->now_right, now_ans);
            }

            ans[id] = now_ans;
        }

        return ans;
    }

private:
    // クエリをソートする
    void sort_queries() {
        std::sort(this->queries.begin(), this->queries.end(), [&](const Query &l, const Query &r) -> bool {
            const unsigned int left_bucket = l.left / this->num_bucket;     // クエリ l の所属するバケット
            const unsigned int right_bucket = r.left / this->num_bucket;    // クエリ r の所属するバケット

            // クエリ [L, R) の L の所属するバケットが違うなら，L の所属するバケットで比較
            if (left_bucket != right_bucket) {
                return left_bucket < right_bucket;
            }
            else {
                // 定数倍高速化
                // 奇数番目のバケットだけ右のソート順を逆にして，バケットを移動したときの now_right を移動する距離を短くする
                if (left_bucket & 1u) {
                    return l.right < r.right;
                }
                else {
                    return l.right > r.right;
                }
            }
        });
    }
};

/*
// 問題特有のデータ
std::vector<int> A;

// A[idx] が追加されたときの状態の変化と答えを計算
template<class T>
T add(const int idx, T query_ans) {
    T diff = 0; // 答えの変化量
    {
        // ここに処理を書く
    }
    return query_ans + diff;
}

// A[idx] が削除されたときの状態の変化と答えを計算
template<class T>
T del(const int idx, T query_ans) {
    T diff = 0; // 答えの変化量
    {
        // ここに処理を書く
    }
    return query_ans + diff;
}
*/

/*
//(例) 区間 [l, r) の種類数をカウント
std::vector<int> A;
std::vector<int> color;

// A[idx] が追加されたときの状態の変化と答えを計算
template<class T>
T add(const int idx, T query_ans) {
    color[A[idx]]++;
    query_ans += (color[A[idx]] == 1);
    return query_ans;
}

// A[idx] が削除されたときの状態の変化と答えを計算
template<class T>
T del(const int idx, T query_ans) {
    color[A[idx]]--;
    query_ans -= (color[A[idx]] == 0);
    return query_ans;
}
*/