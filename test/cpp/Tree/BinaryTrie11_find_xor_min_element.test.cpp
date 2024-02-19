#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "library/cpp/Tree/BinaryTrie.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int Q;
    cin >> Q;

    BinaryTrie bt;
    for (int i = 0; i < Q; ++i) {
        int QUERY;
        int X;
        cin >> QUERY >> X;
        if (QUERY == 0) {
            bt.insert(X);
        }
        else if (QUERY == 1) {
            bt.erase(X, bt.count(X));
        }
        else {
            cout << (X ^ bt.find_xor_min_element(X)) << endl;
        }
    }

    return 0;
}