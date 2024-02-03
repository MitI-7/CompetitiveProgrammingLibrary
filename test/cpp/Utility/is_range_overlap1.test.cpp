#define PROBLEM "https://atcoder.jp/contests/abc207/tasks/abc207_c"

#include "library/cpp/Utility/is_range_overlap.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; ++i) {
        int T, L, R;
        cin >> T >> L >> R;
        L *= 2;
        R *= 2;
        if (T == 2) {
            R--;
        } else if (T == 3) {
            L++;
        } else if (T == 4) {
            L++;
            R--;
        }
        v[i] = {L, R};
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            const auto [l1, r1] = v[i];
            const auto [l2, r2] = v[j];
            ans += is_range_overlap(l1, r1, l2, r2);
        }
    }
    cout << ans << endl;

    return 0;
}