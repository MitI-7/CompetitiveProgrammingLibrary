#define PROBLEM "https://atcoder.jp/contests/abc281/tasks/abc281_e"

#include "library/cpp/DataStructure/TopK.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    TopK<long long> top_k(K, true);

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        top_k.insert(A[i]);

        if (i >= M) {
            top_k.erase(A[i - M]);
        }

        if (i >= M - 1) {
            cout << top_k.get_top_k_sum();
            if (i != N - 1) {
                cout << " ";
            }
        }
    }
    cout << endl;

    return 0;
}