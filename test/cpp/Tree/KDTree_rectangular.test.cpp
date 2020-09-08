#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C"
#include "library/cpp/Tree/KDTree.hpp"

#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    KDTree kd(N);
    int X, Y;
    for (int i = 0; i < N; i++) {
        cin >> X >> Y;
        kd.add_point(i, X, Y);
    }
    kd.build();

    int Q;
    cin >> Q;
    int sx, tx, sy, ty;
    for(int i = 0; i < Q; ++i) {
        cin >> sx >> tx >> sy >> ty;
        auto ans = kd.rectangular(sx, tx, sy, ty);
        sort(ans.begin(), ans.end());
        for (int j = 0; j < (int)ans.size(); ++j) {
            cout << ans[j].id << endl;
        }
        cout << endl;;
    }

    return 0;
}