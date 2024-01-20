#include <algorithm>
#include <vector>
#include "library/cpp/Tree/FenwickTree.hpp"

// j < i かつ v[j] > v[i] の組の個数である転倒数を求める
// vの要素が大きい場合座標圧縮をすること
// O(n log n)
template<typename T>
long long inversion_number(const std::vector<T> &v) {
    int max_v = (int) *std::max_element(v.begin(), v.end());
    FenwickTree<long long> ft(max_v + 10);

    long long ans = 0;
    for (int i = 0; i < (int) v.size(); ++i) {
        ans += i - ft.sum(v[i]);
        ft.add(v[i], 1);
    }
    return ans;
}