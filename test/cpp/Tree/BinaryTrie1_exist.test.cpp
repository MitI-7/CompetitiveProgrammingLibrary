#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_7_A"

#include "library/cpp/Tree/BinaryTrie.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int Q;
    cin >> Q;

    BinaryTrie<unsigned int, 30> bt;
    for (int i = 0; i < Q; ++i) {
        int QUERY, X;
        cin >> QUERY >> X;
        if (QUERY == 0) {
            if (not bt.exist(X)) {
                bt.insert(X);
            }
            cout << bt.size() << endl;
        } else if (QUERY == 1) {
            cout << bt.exist(X) << endl;
        }
    }

    return 0;
}