#define PROBLEM "https://atcoder.jp/contests/abc207/tasks/abc207_d"

#include "library/cpp/Geometry/Point.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<Point<double>> S(N), T(N);
    Point<double> s_m, t_m;

    for (int i = 0; i < N; ++i) {
        cin >> S[i].x >> S[i].y;
        s_m += S[i];
        S[i] *= N;
    }

    for (int i = 0; i < N; ++i) {
        cin >> T[i].x >> T[i].y;
        t_m += T[i];
        T[i] *= N;
    }

    for (int i = 0; i < N; ++i) {
        S[i] -= s_m;
        T[i] -= t_m;
    }

    for (int i = 0; i < N; ++i) {
        if (S[i].x != 0 || S[i].y != 0) {
            swap(S[i], S[0]);
        }
    }

    sort(T.begin(), T.end(), Point<double>::xy_sort_cmp_key);
    for (int i = 0; i < N; ++i) {
        // T[i] と S[0] を一致させる
        const double r = T[i].radian() - S[0].radian();

        vector<Point<double>> s2(N);
        for (int j = 0; j < N; ++j) {
            s2[j] = S[j].rotate(r);
        }
        sort(s2.begin(), s2.end(), Point<double>::xy_sort_cmp_key);

        if (s2 == T) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
