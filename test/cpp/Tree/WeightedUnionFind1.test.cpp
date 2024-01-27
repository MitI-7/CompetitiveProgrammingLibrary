#define PROBLEM "https://atcoder.jp/contests/abc328/tasks/abc328_f"

#include "library/cpp/Tree/WeightedUnionFind.hpp"
#include <iostream>

using namespace std;


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    WeightedUnionFind<long long> wuf(N);

    vector<int> ans;
    for (int i = 0; i < Q; ++i) {
        int A, B, D;
        cin >> A >> B >> D;
        A--;
        B--;

        if (wuf.unite(A, B, -D)) {
            ans.emplace_back(i + 1);
        }
    }

    for (int i = 0; i < (int) ans.size(); ++i) {
        if (i != 0) {
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;

    return 0;
}