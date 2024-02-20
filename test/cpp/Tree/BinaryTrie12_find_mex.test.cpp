#define PROBLEM "https://atcoder.jp/contests/abc245/tasks/abc245_b"

#include "library/cpp/Tree/BinaryTrie.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    BinaryTrie<unsigned int, 15> bt;
    for (int i = 0; i < N; ++i) {
        unsigned int A;
        cin >> A;
        bt.insert(A);
    }
    cout << bt.find_mex(0) << endl;

    return 0;
}