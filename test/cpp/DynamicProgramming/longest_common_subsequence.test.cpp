#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"
#include "library/cpp/DynamicProgramming/longest_common_subsequence.cpp"

#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        string s, t;
        cin >> s;
        cin >> t;

        cout << longest_common_subsequence(s, t) << endl;
    }

    return 0;
}