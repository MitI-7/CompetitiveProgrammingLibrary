#define PROBLEM "https://atcoder.jp/contests/abc205/tasks/abc205_d"

#include "library/cpp/Tree/BinaryTrie.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    BinaryTrie<unsigned long long, 60> bt;
    bt.insert(0);
    for (int i = 0; i < N; ++i) {
        unsigned long long A;
        cin >> A;
        bt.insert(A);
    }

    vector<unsigned long long> ans;
    for (int i = 0; i < Q; ++i) {
        unsigned long long K;
        cin >> K;
        K--;
        cout << bt.find_mex(K) << endl;
    }
    
    return 0;
}