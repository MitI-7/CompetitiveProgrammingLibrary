#include <cassert>

// 閉区間[l1, r1] と [l2, r2] に重なりがあるか判定
template<typename T>
bool is_range_overlap(T l1, T r1, T l2, T r2) {
    assert(l1 <= r1);
    assert(l2 <= r2);
    
    // l2 in [l1, r1]
    if (l1 <= l2 and l2 <= r1) {
        return true;
    }
    // r2 in [l1, r1]
    if (l1 <= r2 and r2 <= r1) {
        return true;
    }
    // l1 in [l2, r2]
    if (l2 <= l1 and l1 <= r2) {
        return true;
    }
    // r1 in [l2, r2]
    if (l2 <= r1 and r1 <= r2) {
        return true;
    }
    return false;
}