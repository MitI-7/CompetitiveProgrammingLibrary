#define PROBLEM "https://atcoder.jp/contests/abc187/tasks/abc187_b"

#include "library/cpp/Geometry/Line.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<Point<int>> points(N);

    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;
        points[i] = Point(X, Y);
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            Line line(points[i], points[j]);
            auto p = line.slope();
            if (p.second == 0) {
                continue;
            }
            if (-1.0 <= (double) p.first / p.second and (double) p.first / p.second <= 1.0) {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
