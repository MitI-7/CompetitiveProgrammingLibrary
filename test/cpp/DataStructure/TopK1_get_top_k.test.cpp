#define PROBLEM "https://atcoder.jp/contests/abc234/tasks/abc234_d"

#include "library/cpp/DataStructure/TopK.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    TopK<int> top_k(K);

    for (int i = 0; i < N; ++i) {
        top_k.insert(P[i]);
        if (i >= K - 1) {
            cout << top_k.get_top_k() << endl;
        }
    }

    return 0;
}