#include <cassert>
#include <set>
#include <unordered_map>

template<class T=long long>
class CoordinateCompression {
private:
    bool initialized;
    std::set<T> s;

    int no = 0;
    std::unordered_map<T, int> _zip;
    std::unordered_map<int, T> _unzip;
public:
    CoordinateCompression() : initialized(false) {}

    void add(T x) {
        this->s.insert(x);
    }

    int size() {
        if (not this->initialized) {
            this->build();
        }
        return this->no;
    }

    // 元の値 -> 圧縮した値
    int zip(const T x) {
        if (not this->initialized) {
            this->build();
        }
        return this->_zip[x];
    }

    // 圧縮した値 -> 元の値
    T unzip(const int i) {
        if (not this->initialized) {
            this->build();
        }
        assert(this->_unzip.contains(i));
        return this->_unzip[i];
    }

private:
    void build() {
        this->initialized = true;
        for (auto x: this->s) {
            this->_zip[x] = this->no;
            this->_unzip[this->no] = x;
            this->no++;
        }
    }
};