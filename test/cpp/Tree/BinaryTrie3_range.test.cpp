#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_7_C"

#include "library/cpp/Tree/BinaryTrie.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int Q;
    cin >> Q;

    BinaryTrie<unsigned int, 30> bt;
    vector<int> ans;
    for (int i = 0; i < Q; ++i) {
        int QUERY;
        unsigned int X, L, R;
        cin >> QUERY;
        if (QUERY == 0) {
            cin >> X;
            if (not bt.exist(X)) {
                bt.insert(X);
            }
            cout << bt.size() << endl;
        } else if (QUERY == 1) {
            cin >> X;
            cout << bt.exist(X) << endl;
        } else if (QUERY == 2) {
            cin >> X;
            bt.erase(X);
        } else if (QUERY == 3) {
            cin >> L >> R;
            auto u = bt.successor(L);
            while (u != &bt.DUMMY and u->x <= R) {
                cout << u->x << endl;
                u = u->next;
            }
        }
    }

    return 0;
}