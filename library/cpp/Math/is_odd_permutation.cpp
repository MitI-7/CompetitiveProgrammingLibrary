#include <vector>

// 偶置換か奇置換か判定する
// A は 0 から N - 1 の順列であること
// O(N)
template<typename T>
bool is_odd_permutation(std::vector<T> &A) {
    const int N = A.size();
    int num_cycle = 0;
    std::vector<bool> used(N);
    for (int u = 0; u < N; ++u) {
        if (used[u]) {
            continue;
        }
        int v = u;
        while (not used[v]) {
            used[v] = true;
            v = A[v];
        }
        num_cycle++;
    }

    return num_cycle % 2;
}