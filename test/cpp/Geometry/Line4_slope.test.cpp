#define PROBLEM "https://atcoder.jp/contests/abc181/tasks/abc181_c"

#include "library/cpp/Geometry/Line.hpp"
#include <iostream>
#include <set>
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
        points[i] = {X, Y};
    }

    for (int i = 0; i < N; ++i) {
        set<pair<int, int>> s;
        for (int j = 0; j < N; ++j) {
            if (i == j) {
                continue;
            }
            Line line(points[i], points[j]);
            if (s.contains(line.slope())) {
                cout << "Yes" << endl;
                return 0;
            }
            s.emplace(line.slope());
        }
    }
    cout << "No" << endl;

    return 0;
}
