#define PROBLEM "https://atcoder.jp/contests/abc248/tasks/abc248_e"

#include "library/cpp/Geometry/Line.hpp"
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<Point<long long>> A(N);
    for (int i = 0; i < N; ++i) {
        long long X, Y;
        cin >> X >> Y;
        A[i] = Point(X, Y);
    }

    if (K == 1) {
        cout << "Infinity" << endl;
        return 0;
    }

    set<pair<pair<long long, long long>, pair<long long, long long>>> ans;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            Line<long long> line(A[i], A[j]);

            int count = 0;
            for (int k = 0; k < N; ++k) {
                count += line.on_line(A[k]);
            }

            if (count >= K) {
                auto p1 = line.slope();
                auto p2 = line.y_intercept();
                ans.insert({p1, p2});
            }
        }
    }
    cout << ans.size() << endl;

    return 0;
}
