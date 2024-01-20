#define PROBLEM "https://atcoder.jp/contests/abc259/tasks/abc259_c"

#include "library/cpp/Compression/run_length_encoding.cpp"
#include <iostream>

using namespace std;

bool solve(string &S, string &T) {
    auto s = run_length_encoding(S);
    auto t = run_length_encoding(T);

    if (s.size() != t.size()) {
        return false;
    }

    for (int i = 0; i < (int) s.size(); ++i) {
        if (s[i].first != t[i].first) {
            return false;
        }
        if (s[i].second > t[i].second) {
            return false;
        }
        if (s[i].second < t[i].second and s[i].second == 1) {
            return false;
        }
    }

    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S, T;
    cin >> S >> T;

    if (solve(S, T)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}