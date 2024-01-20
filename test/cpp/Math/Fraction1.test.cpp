#define PROBLEM "https://atcoder.jp/contests/abc225/tasks/abc225_e"

#include "library/cpp/Math/Fraction.hpp"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<pair<Fraction<long long>, Fraction<long long>>> v(N);
    for (int i = 0; i < N; ++i) {
        long long X, Y;
        cin >> X >> Y;
        v[i].first = Fraction(Y, X - 1);
        v[i].second = Fraction(Y - 1, X);
    }
    sort(v.begin(), v.end());

    int ans = 1;
    Fraction now = v[0].first;
    for(int i = 1; i < N; ++i) {
        if (v[i].second >= now) {
            now = v[i].first;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}