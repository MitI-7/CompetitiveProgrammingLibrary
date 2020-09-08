#include <vector>
#include <set>
#include <unordered_map>


template <class T=long long> class CoordinateCompression {
public:
    int no = 0;
    std::unordered_map<T, int> zip;    // 元の値 -> 圧縮した値
    std::unordered_map<int, T> unzip;  // 圧縮した値 -> 元の値

    CoordinateCompression() {
    }

    CoordinateCompression(const std::vector<T> &v) {
        this->build(v);
    }

    CoordinateCompression(const std::set<T> &v) {
        this->build(v);
    }

    void build(const std::vector<T> &v) {
        std::set<T> s(v.begin(), v.end());
        this->build(s);
    }

    void build(const std::set<T> &s) {
        for (auto x : s) {
            this->zip[x] = this->no;
            this->unzip[this->no] = x;
            this->no++;
        }
    }

    // デバッグ用(恒等写像)
    void debug_build(const std::vector<T> &v) {
        std::set<T> s(v.begin(), v.end());
        this->debug_build(s);
    }
    void debug_build(const std::set<T> &s) {
        for (auto x : s) {
            this->zip[x] = x;
            this->unzip[x] = x;
        }
    }
};
