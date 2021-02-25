#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2911"
#define ERROR "1e-6"

#include "library/cpp/Algorithm/SimplexMethod.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>

const long double PI = acos(-1.0);
template<class T> inline double euclidean_distance(T y1, T x1, T y2, T x2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<double> X(N);
    vector<double> Y(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }

    vector<vector<double>> dist(N, vector<double>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            dist[i][j] = dist[j][i] = euclidean_distance(X[i], Y[i], X[j], Y[j]);
        }
    }

    vector<double> nearest(N, 100000000);
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            nearest[i] = std::min(nearest[i], dist[i][j]);
            nearest[j] = std::min(nearest[j], dist[i][j]);
        }
    }

    vector<vector<double>> A(N * (N - 1) / 2, vector<double>(N));
    vector<double> b(N * (N - 1) / 2);
    vector<double> c(N, 1);

    int no = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (nearest[i] + nearest[j] > dist[i][j] + 1e-9) {
                A[no][i] = 1.0;
                A[no][j] = 1.0;
                b[no] = dist[i][j];
                no++;
            }
        }
    }

    A.resize(no);
    b.resize(no);

    int m = A.size();
    for (int i = 0; i < A.size(); ++i) {
        A[i].resize(N + m);
        A[i][i + N] = 1.0;
    }

    SimplexMethod solver(MAXIMIZE);
    auto status = solver.solve(A, b, c);
    if (status != OPTIMAL) {
        cout << "status:" << status << endl;
        return 0;
    }

    cout << std::fixed << std::setprecision(10) << solver.objective * 2 * PI << endl;

    return 0;
}