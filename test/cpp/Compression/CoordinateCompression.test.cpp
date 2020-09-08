#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A"
#include "library/cpp/Algorithm/Imos.hpp"
#include "library/cpp/Compression/CoordinateCompression.hpp"

#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> allX(N), allY(N);
    vector<long long> X1(N), Y1(N), X2(N), Y2(N);
    for (int i = 0; i < N; ++i) {
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];

        allX.emplace_back(X1[i]);
        allX.emplace_back(X2[i]);
        allY.emplace_back(Y1[i]);
        allY.emplace_back(Y2[i]);

    }
    allX.emplace_back(1000000001);
    allY.emplace_back(1000000001);

    CoordinateCompression<long long> cx(allX);
    CoordinateCompression<long long> cy(allY);

    Imos imos(4100, 4100);
    for (int i = 0; i < N; ++i) {
        int y1 = cy.zip[Y1[i]];
        int x1 = cx.zip[X1[i]];
        int y2 = cy.zip[Y2[i]];
        int x2 = cx.zip[X2[i]];
        imos.add(y1, x1, y2, x2);
    }
    imos.build();

    long long area = 0;
    for (int y = 0; y < (int)imos.field.size() - 1; ++y) {
        for (int x = 0; x < (int)imos.field[0].size() - 1; ++x) {
            if (imos.field[y][x]) {
                area += (cx.unzip[x + 1] - cx.unzip[x]) * (cy.unzip[y + 1] - cy.unzip[y]);
            }
        }
    }

    cout << area << endl;

    return 0;
}