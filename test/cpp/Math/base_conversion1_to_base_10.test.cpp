#define PROBLEM "https://atcoder.jp/contests/abc220/tasks/abc220_b"

#include "library/cpp/Math/base_conversion.cpp"
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int K;
    string A, B;
    cin >> K >> A >> B;

    vector<int> a, b;
    for (int x: A) {
        a.emplace_back(x - '0');
    }
    for (int x: B) {
        b.emplace_back(x - '0');
    }
    cout << to_base_10(a, K) * to_base_10(b, K) << endl;

    return 0;
}