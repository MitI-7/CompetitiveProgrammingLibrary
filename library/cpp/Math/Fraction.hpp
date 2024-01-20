template<typename T=long long>
class Fraction {
public:
    T numerator;
    T denominator;

public:
    Fraction() : numerator(0), denominator(1) {
    }

    Fraction(T n, T d) : numerator(n), denominator(d) {
        // assert(d != 0);
        auto c = this->gcd(n, d);
        this->numerator = n / c;
        this->denominator = d / c;
    }

    Fraction<T> operator+(const Fraction<T> &o) const {
        auto n = this->numerator * o.denominator + o.numerator * this->denominator;
        auto d = this->denominator * o.denominator;
        auto c = this->gcd(n, d);
        return {n / c, d / c};
//        return {n, d};
    }

    Fraction<T> operator-(const Fraction<T> &o) const {
        auto n = this->numerator * o.denominator - o.numerator * this->denominator;
        auto d = this->denominator * o.denominator;
        auto c = this->gcd(n, d);
        return {n / c, d / c};
    }

    Fraction<T> operator*(const Fraction<T> &o) const {
        auto n = this->numerator * o.numerator;
        auto d = this->denominator * o.denominator;
        auto c = this->gcd(n, d);
        return {n / c, d / c};
    }

    Fraction<T> operator/(const Fraction<T> &o) const {
        auto n = this->numerator * o.denominator;
        auto d = this->denominator * o.numerator;
        auto c = this->gcd(n, d);
        return {n / c, d / c};
    }

    bool operator==(const Fraction<T> &o) const {
        return this->numerator * o.denominator == o.numerator * this->denominator;
    }

    bool operator==(const T n) const {
        return this->numerator == n * this->denominator;
    }

    bool operator>(const Fraction<T> &o) const {
        return this->numerator * o.denominator > o.numerator * this->denominator;
    }

    bool operator>=(const Fraction<T> &o) const {
        return this->numerator * o.denominator >= o.numerator * this->denominator;
    }

    bool operator>(const T n) const {
        return this->numerator > n * this->denominator;
    }

    bool operator>=(const T n) const {
        return this->numerator >= n * this->denominator;
    }

    bool operator<(const Fraction<T> &o) const {
        return this->numerator * o.denominator < o.numerator * this->denominator;
    }

    bool operator<=(const Fraction<T> &o) const {
        return this->numerator * o.denominator <= o.numerator * this->denominator;
    }

    bool operator<(const T n) const {
        return this->numerator < n * this->denominator;
    }

    bool operator<=(const T n) const {
        return this->numerator <= n * this->denominator;
    }

private:
    T gcd(const T a, const T b) {
        if (b == 0) { return a; }
        return this->gcd(b, a % b);
    }
};