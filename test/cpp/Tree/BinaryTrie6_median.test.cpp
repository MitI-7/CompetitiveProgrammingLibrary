#define PROBLEM "https://atcoder.jp/contests/abc102/tasks/abc102_c"

#include "library/cpp/Tree/BinaryTrie.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int base = 200000;
    vector<int> A(N);
    BinaryTrie<unsigned int, 32> bt;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        A[i] = base + A[i] - (i + 1);
        bt.insert(A[i]);
    }
    const auto [m1, m2] = bt.find_median();

    long long ans1 = 0;
    for (auto a: A) {
        ans1 += abs(a - (long long) m1);
    }
    cout << ans1 << endl;

    return 0;
}
