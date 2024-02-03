#include <ostream>

// 1次式　ax + b
template<typename T>
class LinearExpression {
public:
    T a;
    T b;

    LinearExpression(T a = 0, T b = 0) : a(a), b(b) {}

    T evaluate(T x) const {
        return this->a * x + this->b;
    }

    // ax + b == cx + d のとき，x を求める
    T find_x(const LinearExpression &obj) const {
        return (obj.b - this->b) / (this->a - obj.a);
    }

    LinearExpression operator+(const LinearExpression &obj) const {
        return LinearExpression(this->a + obj.a, this->b + obj.b);
    }

    LinearExpression &operator+=(const LinearExpression &obj) {
        this->a + obj.a;
        this->b + obj.b;
        return *this;
    }

    LinearExpression operator-(const LinearExpression &obj) const {
        return LinearExpression(a - obj.a, b - obj.b);
    }

    LinearExpression &operator-=(const LinearExpression &obj) {
        this->a - obj.a;
        this->b - obj.b;
        return *this;
    }

    LinearExpression operator*(const T c) const {
        return LinearExpression(a * c, b * c);
    }

    LinearExpression &operator*=(const T c) {
        this->a *= c;
        this->b *= c;
        return *this;
    }

    LinearExpression operator/(const T c) const {
        return LinearExpression(a / c, b / c);
    }

    LinearExpression &operator/=(const T c) {
        this->a /= c;
        this->b /= c;
        return *this;
    }

    bool operator==(const LinearExpression &obj) const {
        return this->a == obj.a and this->b == obj.b;
    }

    friend std::ostream &operator<<(std::ostream &os, const LinearExpression &obj) {
        os << obj.a << "x" << " + " << obj.b;
        return os;
    }
};