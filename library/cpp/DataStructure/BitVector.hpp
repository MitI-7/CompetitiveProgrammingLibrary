class BitVector {
private:
    uint64_t size;
    std::vector<bool> vec;
    std::vector<uint64_t> cumulative_sum;
    uint64_t numOne = 0;

public:
    explicit BitVector(uint64_t n) : size(n) {
        this->vec.resize(n);
        this->cumulative_sum.resize(n + 1);
    }

    // B[pos] = bit
    void setBit(uint64_t bit, uint64_t pos){
        assert(bit == 0 or bit == 1);
        assert(pos < this->size);
        this->vec[pos] = bit;
    }

    // B[pos]
    uint64_t access(uint64_t pos) {
        assert(pos < this->size);
        return this->vec[pos];
    }

    void build(){
        for (int i = 0; i < (int)this->size; ++i) {
            this->cumulative_sum[i + 1] = this->cumulative_sum[i] + this->vec[i];
        }
        this->numOne = this->cumulative_sum[this->size];
    }

    // B[0, pos)のbitの数
    uint64_t rank(uint64_t bit, uint64_t pos) {
        assert(bit == 0 or bit == 1);
        assert(pos <= this->size);

        if (bit) { return this->cumulative_sum[pos]; }
        else     { return pos - this->cumulative_sum[pos]; }
    }

    // rank番目のbitの位置 + 1(rankは1-origin)
    uint64_t select(const uint64_t bit, const uint64_t rank) {
        assert(bit == 0 or bit == 1);
        assert(rank > 0);
        if (bit == 0 and rank > this->size - this-> numOne) { return NOTFOUND; }
        if (bit == 1 and rank > this-> numOne)              { return NOTFOUND; }

        long long left = -1;
        long long right = this->size;
        while (right - left > 1) {
            const long long pos = (left + right) / 2;
            if (this->rank(bit, pos) < rank) {
                left = pos;
            } else {
                right = pos;
            }
        }

        return left + 1;
    }

    uint64_t getNumOne() const {
        return numOne;
    }
};


