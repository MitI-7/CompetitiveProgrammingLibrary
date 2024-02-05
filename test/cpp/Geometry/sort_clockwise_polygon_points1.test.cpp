#define PROBLEM "https://atcoder.jp/contests/abc211/tasks/abc211_f"

#include "library/cpp/Geometry/sort_clockwise_polygon_points.cpp"
#include "library/cpp/Tree/FenwickTreeRange.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<tuple<int, int, int, int>> events;
    for (int i = 0; i < N; ++i) {
        vector<Point> points;
        int M;
        cin >> M;
        for (int j = 0; j < M; ++j) {
            int X, Y;
            cin >> X >> Y;
            points.emplace_back(X, Y);
        }
        sort_clockwise_polygon_points(points);
        for (int j = 0; j < M; j += 2) {
            auto p1 = points[j];
            auto p2 = points[j + 1];
            assert(p1.x == p2.x);
            events.emplace_back(p1.x, 0, p1.y, p2.y);
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int X, Y;
        cin >> X >> Y;
        events.emplace_back(X, 1, Y, i);
    }

    vector<int> ans(Q);
    FenwickTreeRange<int> ftr(100100);
    sort(events.begin(), events.end());
    for (auto [_, t, b, c]: events) {
        if (t == 0) {
            if (b > c) {
                ftr.add(c, b, 1);
            } else {
                ftr.add(b, c, -1);
            }
        } else {
            ans[c] = ftr.access(b);
        }
    }

    for (auto a: ans) {
        cout << a << endl;
    }

    return 0;
}
