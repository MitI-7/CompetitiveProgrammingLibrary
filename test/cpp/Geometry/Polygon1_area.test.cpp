#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A&lang=ja"

#include "library/cpp/Geometry/Polygon.hpp"
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector <Point<double>> points(N);
    for (int i = 0; i < N; ++i) {
        double X, Y;
        cin >> X >> Y;
        points[i] = {X, Y};
    }

    Polygon<double> polygon(points);
    cout << setprecision(1) << fixed << polygon.double_polygon_area() / 2.0 << endl;

    return 0;
}
