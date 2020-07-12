#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"
#include "library/cpp/DynamicProgramming/longest_increasing_subsequence.cpp"

#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
    	cin >> A[i];
    }

    cout << longest_increasing_subsequence(A, true) << endl;

    return 0;
}