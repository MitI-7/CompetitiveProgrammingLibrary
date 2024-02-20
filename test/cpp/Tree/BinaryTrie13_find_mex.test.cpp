#define PROBLEM "https://atcoder.jp/contests/abc330/tasks/abc330_e"

#include "library/cpp/Tree/BinaryTrie.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    BinaryTrie<unsigned int, 30> bt;
    vector<unsigned int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        bt.insert(A[i]);
    }

    for (int i = 0; i < Q; ++i) {
        unsigned int I, X;
        cin >> I >> X;
        I--;
        bt.erase(A[I]);
        A[I] = X;
        bt.insert(A[I]);

        cout << bt.find_mex(0) << endl;
    }

    return 0;
}