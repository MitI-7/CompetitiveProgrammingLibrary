#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include "library/cpp/DataStructure/BinaryTrie.hpp"

#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Q;
    cin >> Q;

    BinaryTrie bt;
    for (int i = 0; i < Q; ++i) {
        int QUERY;
        uint64_t X;
        cin >> QUERY >> X;
        if (QUERY == 0) {
            bt.insert(X);
        }
        else if (QUERY == 1) {
            bt.erase(X, bt.count(X));
        }
        else {
            cout << (X ^ bt.min_element_xor(X)) << endl;
        }
    }

    return 0;
}