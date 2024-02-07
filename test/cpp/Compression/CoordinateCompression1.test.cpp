#define PROBLEM "https://atcoder.jp/contests/abc213/tasks/abc213_c"

#include "library/cpp/Compression/CoordinateCompression.hpp"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int H, W, N;
    cin >> H >> W >> N;

    vector<pair<int, int>> cards(N);
    CoordinateCompression<int> cy, cx;
    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        cards[i] = {A, B};
        cy.add(A);
        cx.add(B);
    }

    for (auto [a, b]: cards) {
        cout << cy.zip(a) + 1 << " " << cx.zip(b) + 1 << endl;
    }

    return 0;
}