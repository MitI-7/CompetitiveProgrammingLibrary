#define PROBLEM "https://atcoder.jp/contests/abc151/tasks/abc151_f"
#define ERROR 1e-10

#include "library/cpp/Geometry/SmallestEnclosingCircle.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<Point> v;
    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;
        v.emplace_back(X, Y);
    }

    SmallestEnclosingCircle sec(v);
    auto [p, r] = sec.solve();
    cout << fixed << setprecision(18) << r << endl;

    return 0;
}