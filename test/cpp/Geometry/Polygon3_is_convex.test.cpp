#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B&lang=ja"

#include "library/cpp/Geometry/Polygon.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector <Point<int>> points(N);
    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;
        points[i] = {X, Y};
    }
    
    Polygon<int> polygon(points);
    cout << polygon.is_convex() << endl;

    return 0;
}
