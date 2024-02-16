#define PROBLEM "https://atcoder.jp/contests/abc102/tasks/abc102_c"

#include "library/cpp/DataStructure/DynamicMedian.hpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    DynamicMedian dm;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        dm.insert(A - (i + 1));
    }
    cout << dm.absolute() << endl;

    return 0;
}