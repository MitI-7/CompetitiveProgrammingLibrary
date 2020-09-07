#include <vector>
#include <string>
#include <cassert>
#include <random>


std::string generate_parentheses(const int n) {
    assert(n % 2 == 0);

    std::string p;
    for (int i = 0; i < n / 2; ++i) {
        p += "(";
    }
    for (int i = 0; i < n / 2; ++i) {
        p += ")";
    }

    std::random_device rnd;
    std::mt19937 mt(rnd());
    for (int i = 0; i < 1000; ++i) {
        int a = mt() % n;
        int b = mt() % n;

        if (p[a] == p[b]) {
            continue;
        }

        swap(p[a], p[b]);
        if (not is_valid_parentheses(p)) {
            swap(p[a], p[b]);
        }
    }

    return p;
}