#define PROBLEM "https://atcoder.jp/contests/abc234/tasks/abc234_d"

#include "library/cpp/Tree/BinaryTrie.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    K--;

    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    BinaryTrie<> bt;
    for (int i = 0; i < K; ++i) {
        bt.insert(P[i]);
    }

    for (int i = K; i < N; ++i) {
        bt.insert(P[i]);
        cout << bt.find_kth_max_element(K) << endl;
    }

    return 0;
}