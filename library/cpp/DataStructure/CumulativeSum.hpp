#include <cassert>
#include <vector>

template<typename T>
class CumulativeSum {
private:
    std::vector<T> memo;

public:
    CumulativeSum() {
    }

    CumulativeSum(const std::vector<T> &line) {
        this->build(line);
    }

    void build(const std::vector<T> &line) {
        this->memo = std::vector<T>(line.size() + 1, 0);
        for (int i = 0; i < int(line.size()); ++i) {
            this->memo[i + 1] = this->memo[i] + line[i];
        }
    }

    // sum[left, right)
    T sum(const int left, const int right) const {
        assert(right >= left);
        return this->memo[right] - this->memo[left];
    }

    T sum_circle(const long long left, const long long right) const {
        // TODO
        return 0;
    }
};