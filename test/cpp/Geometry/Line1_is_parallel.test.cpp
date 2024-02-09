#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A"

#include "library/cpp/Geometry/Line.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    for (int t = 0; t < N; ++t) {
        int x0, y0, x1, y1, x2, y2, x3, y3;
        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Line line1(Point(x0, y0), Point(x1, y1));
        Line line2(Point(x2, y2), Point(x3, y3));

        if (line1.is_parallel(line2)) {
            cout << 2 << endl;
        }
        else if (line1.is_orthogonal(line2)) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }

    return 0;
}
