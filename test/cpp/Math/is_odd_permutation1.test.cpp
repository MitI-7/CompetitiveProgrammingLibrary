#define PROBLEM "https://atcoder.jp/contests/abc296/tasks/abc296_f"

#include "library/cpp/Math/is_odd_permutation.cpp"
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

bool solve(vector<int> &A, vector<int> &B) {
    {
        auto C = A;
        auto D = B;
        std::sort(C.begin(), C.end());
        std::sort(D.begin(), D.end());
        if (C != D) {
            return false;
        }
    }

    {
        set<int> s(A.begin(), A.end());
        if (s.size() != A.size()) {
            return true;
        }
    }

    return is_odd_permutation(A) == is_odd_permutation(B);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        A[i]--;
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
        B[i]--;
    }

    if (solve(A, B)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}