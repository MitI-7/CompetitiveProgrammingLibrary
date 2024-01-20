#define PROBLEM "https://atcoder.jp/contests/abc127/tasks/abc127_f"

#include "library/cpp/DataStructure/DynamicMedian.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int Q;
    cin >> Q;

    DynamicMedian dm;

    long long total_b = 0;
    for (int i = 0; i < Q; ++i) {
        int T;
        cin >> T;
        if (T == 1) {
            long long A, B;
            cin >> A >> B;
            dm.insert(A);
            total_b += B;
        } else {
            auto [x, _] = dm.find_median();
            auto a = dm.absolute();
            cout << x << " " << a + total_b << endl;
        }
    }

    return 0;
}