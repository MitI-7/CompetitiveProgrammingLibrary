template<typename T> std::vector<T> make_random_vector(int n) {
    std::random_device rnd;
    std::mt19937 mt(rnd());
    std::vector<T> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = mt() % 100;
    }
    return v;
}