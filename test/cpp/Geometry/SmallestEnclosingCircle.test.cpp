#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2423"
#include "library/cpp/Geometry/SmallestEnclosingCircle.hpp"

#include <iostream>
#include <assert.h>
#include <algorithm>

const double EPS = 1e-9;

using namespace std;

// iさんをhole[j]に割り当てられるか
bool can_assign(int i, int j, vector<bool> &used, vector<double> &holes, vector<double> &dists) {
    vector<double> rest_dists;
    for (int k = i + 1; k < (int)dists.size(); ++k) {
        rest_dists.emplace_back(dists[k]);
    }
    sort(rest_dists.rbegin(), rest_dists.rend());

    vector<double> rest_holes;
    for (int k = 0; k < (int)holes.size(); ++k) {
        if (k != j and not used[k]) {
            rest_holes.emplace_back(holes[k]);
        }
    }
    sort(rest_holes.rbegin(), rest_holes.rend());

    assert(rest_holes.size() >= rest_dists.size());
    for (int k = 0; k < (int)rest_dists.size(); ++k) {
        if (rest_holes[k] < rest_dists[k]) {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<double> holes(N);
    for (int i = 0; i < N; ++i) {
        cin >> holes[i];
    }

    vector<double> dist(M);
    for (int i = 0; i < M; ++i) {
        int P;
        cin >> P;
        vector<Point> points(P);

        for (int j = 0; j < P; ++j) {
            cin >> points[j].x >> points[j].y;
        }

        SmallestEnclosingCircle sec;
        dist[i] = sec.solve(points) - EPS;
    }

    vector<int> ans(M, -1);
    vector<bool> used(N);
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (not used[j] and dist[i] <= holes[j]) {
                if (can_assign(i, j, used, holes, dist)) {
                    ans[i] = j;
                    used[j] = true;
                    break;
                }
            }
        }
        if (ans[i] == -1) {
            cout << "NG" << endl;
            return 0;
        }
    }

    for (int i = 0; i < M; ++i) {
        cout << ans[i] + 1 << endl;
    }

    return 0;
}