#include "library/cpp/Tree/LazySegmentTree.hpp"

// 区間最小値，区間加算
template<typename T>
T range_minimum_query_range_add_operation_op(const T left_value, const T right_value) {
    return std::min(left_value, right_value);
}

template<typename T>
T range_minimum_query_range_add_operation_mapping(const T value, const T lazy_value, const int len) {
    return value + lazy_value;
}

template<typename T>
T range_minimum_query_range_add_operation_composition(const T old_lazy_value, const T new_lazy_value) {
    return old_lazy_value + new_lazy_value;
}

template<typename T>
T range_minimum_query_range_add_operation_unit() {
    return std::numeric_limits<T>::max() / 3;
}

template<typename T>
T range_minimum_query_range_add_operation_lazy_unit() {
    return 0;
}

template<typename T>
auto make_range_minimum_query_range_add_operation(const int n, const T initial_value) {
    return LazySegmentTree<T,
            range_minimum_query_range_add_operation_op,
            range_minimum_query_range_add_operation_mapping,
            range_minimum_query_range_add_operation_composition,
            range_minimum_query_range_add_operation_unit,
            range_minimum_query_range_add_operation_lazy_unit>(n, initial_value);
}

// 区間最小値，区間更新
template<typename T>
T range_minimum_query_range_update_operation_unit() {
    return std::numeric_limits<T>::max() / 3;
}

template<typename T>
T range_minimum_query_range_update_operation_lazy_unit() {
    return -1;
}

template<typename T>
T range_minimum_query_range_update_operation_op(const T left_value, const T right_value) {
    return std::min(left_value, right_value);
}

template<typename T>
T range_minimum_query_range_update_operation_mapping(const T value, const T lazy_value, const int len) {
    if (lazy_value == range_minimum_query_range_update_operation_lazy_unit<T>()) {
        return value;
    }
    return lazy_value;
}

template<typename T>
T range_minimum_query_range_update_operation_composition(const T old_lazy_value, const T new_lazy_value) {
    if (new_lazy_value == range_minimum_query_range_update_operation_lazy_unit<T>()) {
        return old_lazy_value;
    }
    return new_lazy_value;
}

template<typename T>
auto make_range_minimum_query_range_update_operation(const int n, const T initial_value) {
    return LazySegmentTree<T,
            range_minimum_query_range_update_operation_op,
            range_minimum_query_range_update_operation_mapping,
            range_minimum_query_range_update_operation_composition,
            range_minimum_query_range_update_operation_unit,
            range_minimum_query_range_update_operation_lazy_unit>(n, initial_value);
}


// 区間合計，区間加算
template<typename T>
T range_sum_query_range_add_operation_op(const T left_value, const T right_value) {
    return left_value + right_value;
}

template<typename T>
T range_sum_query_range_add_operation_mapping(const T value, const T lazy_value, const int len) {
    return value + lazy_value * len;
}

template<typename T>
T range_sum_query_range_add_operation_composition(const T old_lazy_value, const T new_lazy_value) {
    return old_lazy_value + new_lazy_value;
}

template<typename T>
T range_sum_query_range_add_operation_unit() {
    return 0;
}

template<typename T>
T range_sum_query_range_add_operation_lazy_unit() {
    return 0;
}

template<typename T>
auto make_range_sum_query_range_add_operation(const int n, const T initial_value) {
    return LazySegmentTree<T,
            range_sum_query_range_add_operation_op,
            range_sum_query_range_add_operation_mapping,
            range_sum_query_range_add_operation_composition,
            range_sum_query_range_add_operation_unit,
            range_sum_query_range_add_operation_lazy_unit>(n, initial_value);
}


// 区間合計，区間更新
template<typename T>
T range_sum_query_range_update_operation_unit() {
    return 0;
}

template<typename T>
T range_sum_query_range_update_operation_lazy_unit() {
    return std::numeric_limits<T>::max() / 3;
}

template<typename T>
T range_sum_query_range_update_operation_op(const T left_value, const T right_value) {
    return left_value + right_value;
}

template<typename T>
T range_sum_query_range_update_operation_mapping(const T value, const T lazy_value, const int len) {
    if (lazy_value == range_sum_query_range_update_operation_lazy_unit<T>()) {
        return value;
    }
    return lazy_value * len;
}

template<typename T>
T range_sum_query_range_update_operation_composition(const T old_lazy_value, const T new_lazy_value) {
    if (new_lazy_value == range_sum_query_range_update_operation_lazy_unit<T>()) {
        return old_lazy_value;
    }
    return new_lazy_value;
}

template<typename T>
auto make_range_sum_query_range_update_operation(const int n, const T initial_value) {
    return LazySegmentTree<T,
            range_sum_query_range_update_operation_op,
            range_sum_query_range_update_operation_mapping,
            range_sum_query_range_update_operation_composition,
            range_sum_query_range_update_operation_unit,
            range_sum_query_range_update_operation_lazy_unit>(n, initial_value);
}

template<typename T>
auto make_range_sum_query_range_update_operation(const std::vector<T> &v) {
    return LazySegmentTree<T,
            range_sum_query_range_update_operation_op,
            range_sum_query_range_update_operation_mapping,
            range_sum_query_range_update_operation_composition,
            range_sum_query_range_update_operation_unit,
            range_sum_query_range_update_operation_lazy_unit>(v);
}



/*
template<typename T>
Mode <T> range_minimum_query_update() {
    const T lazy_unit = -1;
    return Mode < T > {
            [](T a, T b) { return std::min(a, b); },
            [=](T a, T b) { return b == lazy_unit ? a : b; },
            [=](T a, T b) { return b == lazy_unit ? a : b; },
            [=](T a, int len) { return a; },
            std::numeric_limits<T>::max() / 3,
            lazy_unit,
    };
}

template<typename T>
Mode <T> range_minimum_query_add() {
    return Mode < T > {
            [](T a, T b) { return std::min(a, b); },
            [](T a, T b) { return a + b; },
            [](T a, T b) { return a + b; },
            [](T a, int len) { return a; },
            std::numeric_limits<T>::max() / 3,
            0,
    };
}

template<typename T>
Mode <T> range_maximum_query_update() {
    const T lazy_unit = -1;
    return Mode < T > {
            [](T a, T b) { return std::max(a, b); },
            [=](T a, T b) { return b == lazy_unit ? a : b; },
            [=](T a, T b) { return b == lazy_unit ? a : b; },
            [](T a, int len) { return a; },
            std::numeric_limits<T>::min() / 3,
            lazy_unit,
    };
}

template<typename T>
Mode <T> range_maximum_query_add() {
    return Mode < T > {
            [](T a, T b) { return std::max(a, b); },
            [](T a, T b) { return a + b; },
            [](T a, T b) { return a + b; },
            [](T a, int len) { return a; },
            std::numeric_limits<T>::min() / 3,
            0,
    };
}

template<typename T>
Mode <T> range_summation_query_update() {
    const T lazy_unit = std::numeric_limits<T>::max() / 3;
    return Mode < T > {
            [](T a, T b) { return a + b; },
            [=](T a, T b) { return b == lazy_unit ? a : b; },
            [=](T a, T b) { return b == lazy_unit ? a : b; },
            [=](T a, int len) { return a == lazy_unit ? a : a * len; },
            0,
            lazy_unit,
    };
}

template<typename T>
Mode <T> range_summation_query_add() {
    return Mode < T > {
            [](T a, T b) { return a + b; },
            [](T a, T b) { return a + b; },
            [](T a, T b) { return a + b; },
            [](T a, int len) { return a * len; },
            0,
            0,
    };
}

// 区間min更新
template<typename T>
T &chmin(T &a, const T &b) { return a = std::min(a, b); }

template<typename T>
Mode <T> range_minimum_query_min() {
    return Mode < T > {
            [](T a, T b) { return std::min(a, b); },
            [](T a, T b) { return chmin(a, b); },
            [](T a, T b) { return chmin(a, b); },
            [](T a, int len) { return a; },
            std::numeric_limits<T>::max() / 3,
            std::numeric_limits<T>::max() / 3,
    };
}
*/