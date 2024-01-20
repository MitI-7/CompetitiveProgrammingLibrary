#define PROBLEM "https://atcoder.jp/contests/abc306/tasks/abc306_e"

#include "library/cpp/DataStructure/TopK.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, K, Q;
    cin >> N >> K >> Q;

    vector<long long> A(N);

    TopK<long long> top_k(K);
    for (int i = 0; i < N; ++i) {
        top_k.insert(0);
    }

    for (int i = 0; i < Q; ++i) {
        int X, Y;
        cin >> X >> Y;
        X--;
        top_k.erase(A[X]);
        A[X] = Y;
        top_k.insert(A[X]);
        cout << top_k.get_top_k_sum() << endl;
    }

    return 0;
}