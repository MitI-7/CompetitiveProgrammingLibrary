#define PROBLEM "https://atcoder.jp/contests/abc259/tasks/abc259_b"
#define ERROR 1e-6

#include "library/cpp/Geometry/Point.hpp"
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    double A, B, D;
    cin >> A >> B >> D;

    double theta = D * (M_PI / 180.0);

    Point<double> p(A, B);
    auto ans = p.rotate(theta);
    cout << setprecision(10) << fixed << ans.x << " " << ans.y << endl;

    return 0;
}
