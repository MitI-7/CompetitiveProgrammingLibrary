#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include "library/cpp/Tree/BinaryTrie.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    string T;
    cin >> N >> Q;
    cin >> T;

    BinaryTrie<unsigned int, 24> bt;
    for (int i = 0; i < (int) T.size(); ++i) {
        if (T[i] == '1') {
            bt.insert(i);
        }
    }

    for (int i = 0; i < Q; ++i) {
        int C, K;
        cin >> C >> K;
        if (C == 0) {
            if (not bt.exist(K)) {
                bt.insert(K);
            }
        } else if (C == 1) {
            if (bt.exist(K)) {
                bt.erase(K, 1);
            }
        } else if (C == 2) {
            cout << bt.exist(K) << endl;
        } else if (C == 3) {
            auto u = bt.successor(K);
            if (u == &bt.DUMMY) {
                cout << -1 << endl;;
            } else {
                cout << u->x << endl;
            }
        } else if (C == 4) {
            auto u = bt.predecessor(K);
            if (u == &bt.DUMMY) {
                cout << -1 << endl;
            } else {
                cout << u->x << endl;
            }
        }
    }

    return 0;
}