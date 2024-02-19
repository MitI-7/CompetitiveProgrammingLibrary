#define PROBLEM "https://atcoder.jp/contests/abc241/tasks/abc241_d"

#include "library/cpp/Tree/BinaryTrie.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int Q;
    cin >> Q;

    BinaryTrie<unsigned long long, 64> bt;
    for (int i = 0; i < Q; ++i) {
        int T, K;
        unsigned long long X;
        cin >> T;

        if (T == 1) {
            cin >> X;
            bt.insert(X);
        } else if (T == 2) {
            cin >> X >> K;
            auto u = bt.predecessor(X);
            while (u != &bt.DUMMY) {
                K -= u->count;
                if (K <= 0) {
                    break;
                }
                u = u->prev;
            }

            if (u == &bt.DUMMY) {
                cout << -1 << endl;
            } else {
                cout << u->x << endl;
            }
        } else {
            cin >> X >> K;
            auto u = bt.successor(X);
            while (u != &bt.DUMMY) {
                K -= u->count;
                if (K <= 0) {
                    break;
                }
                u = u->next;
            }

            if (u == &bt.DUMMY) {
                cout << -1 << endl;
            } else {
                cout << u->x << endl;
            }
        }
    }

    return 0;
}