#define PROBLEM "https://atcoder.jp/contests/abc241/tasks/abc241_d"

#include "library/cpp/Tree/BinaryTrie.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int Q;
    cin >> Q;

    BinaryTrie<long long> bt;

    for (int i = 0; i < Q; ++i) {
        int QUERY, K;
        long long X;
        cin >> QUERY >> X;
        if (QUERY == 1) {
            bt.insert(X);
        } else if (QUERY == 2) {
            cin >> K;
            K--;
            const auto num = bt.count_less_than(X + 1);
            auto ans = bt.find_kth_min_element(num - K - 1);
            if (ans == bt.NOTFOUND) {
                ans = -1;
            }
            cout << ans << endl;
        } else {
            cin >> K;
            K--;
            const auto num = bt.count_less_than(X);

            auto ans = bt.find_kth_min_element(num + K);
            if (ans == bt.NOTFOUND) {
                ans = -1;
            }
            cout << ans << endl;
        }
    }

    return 0;
}