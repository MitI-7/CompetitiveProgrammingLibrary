#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E"
#include "library/cpp/DynamicProgramming/levenshtein_distance.cpp"

#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S, T;
    cin >> S;
    cin >> T;
    
    cout << levenshtein_distance(S, T) << endl;

    return 0;
}