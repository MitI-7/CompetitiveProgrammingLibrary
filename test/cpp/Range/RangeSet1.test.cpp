#define PROBLEM "https://atcoder.jp/contests/abc256/tasks/abc256_d"

#include "library/cpp/Range/RangeSet.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    RangeSet<int> rs;

    for (int i = 0; i < N; ++i) {
        int L, R;
        cin >> L >> R;
        rs.insert(L, R);
    }

    auto ans = rs.get_covers();
    for (auto [l, r]: ans) {
        cout << l << " " << r << endl;
    }

    return 0;
}