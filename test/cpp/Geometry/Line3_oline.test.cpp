#define PROBLEM "https://atcoder.jp/contests/abc181/tasks/abc181_c"

#include "library/cpp/Geometry/Line.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<Point<long long>> points(N);
    for (int i = 0; i < N; ++i) {
        long long X, Y;
        cin >> X >> Y;
        points[i] = {X, Y};
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                if (i == j or i == k or j == k) {
                    continue;
                }
                Line line(points[i], points[j]);
                if (line.on_line(points[k])) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
