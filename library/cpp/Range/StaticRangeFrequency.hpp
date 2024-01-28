#include <unordered_map>
#include <vector>

// vec の区間 [l, r) に出現するある整数値 x の個数をカウントするクエリに答える
class StaticRangeFrequency {
public:
    int n;
private:
    std::vector<int> vec;
    std::unordered_map<int, std::vector<int>> idx_list;  // 各値の出現する index

public:
    explicit StaticRangeFrequency(std::vector<int> &vec) : n((int) vec.size()), vec(vec) {
        for (int i = 0; i < int(vec.size()); ++i) {
            this->idx_list[vec[i]].emplace_back(i);
        }
    }

    // vec[i]
    int get(const int i) const {
        return this->vec[i];
    }

    // x を vec の末尾に追加
    void emplace_back(const int x) {
        this->vec.emplace_back(x);
        this->idx_list[x].emplace_back(this->n);
        this->n++;
    }

    // x の個数を求める
    int count(const int x) const {
        if (not this->idx_list.contains(x)) {
            return 0;
        }
        return int(this->idx_list.at(x).size());
    }

    // vec[l, r) に存在する x の個数を求める
    int range_count(int l, int r, int x) const {
        if (this->count(x) == 0) {
            return 0;
        }

        const auto begin = this->idx_list.at(x).begin();
        const auto end = this->idx_list.at(x).end();
        auto it_left = std::lower_bound(begin, end, l);
        if (it_left == end) {
            return 0;
        }

        auto it_right = std::lower_bound(begin, end, r);
        return (int) std::distance(it_left, it_right);
    }
};