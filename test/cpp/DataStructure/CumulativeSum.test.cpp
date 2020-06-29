#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0516"
#include "library/cpp/DataStructure/CumulativeSum.hpp"

#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    while (true) {
        long long N, K;
        cin >> N >> K;
        if (N == 0 and K == 0) {
            break;
        }

        vector<long long> v(N);
        for (int i = 0; i < N; ++i) {
            cin >> v[i];
        }

        CumulativeSum<long long> cs(v);
        long long ans = -10000000000;
        for (int i = 0; i < N - K + 1; ++i) {
            ans = max(ans, cs.sum(i, i + K));
        }

        cout << ans << endl;
    }

    return 0;
}