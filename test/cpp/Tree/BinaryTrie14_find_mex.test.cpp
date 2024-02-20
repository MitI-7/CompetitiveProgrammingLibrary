#define PROBLEM "https://atcoder.jp/contests/abc194/tasks/abc194_e"

#include "library/cpp/Tree/BinaryTrie.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    BinaryTrie<unsigned int, 30> bt;
    vector<unsigned int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    unsigned int ans = 1 << 30;
    for (int i = 0; i < M; ++i) {
        bt.insert(A[i]);
    }
    ans = min(ans, bt.find_mex(0));

    for (int i = M; i < N; ++i) {
        bt.erase(A[i - M]);
        bt.insert(A[i]);
        ans = min(ans, bt.find_mex(0));
    }
    cout << ans << endl;

    return 0;
}