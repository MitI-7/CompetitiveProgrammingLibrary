#include <cmath>
#include <numeric>
#include <ostream>

template<class T>
class Point {
public:
    T x;
    T y;
    int no;
    double EPS = 1e-10;

    Point() : x(0), y(0), no(0) {};

    Point(const T x, const T y, int no = 0, double eps = 1e-10) : x(x), y(y), no(no), EPS(eps) {}

    // 原点を中心として，反時計回りに theta 回転させた点を求める
    Point<T> rotate(double theta) const {
        return Point<T>(this->x * std::cos(theta) - this->y * std::sin(theta),
                        this->x * std::sin(theta) + this->y * std::cos(theta));
    }

    // 内積 (dot product) : a⋅b = |a||b|cosθ
    double dot(const Point<T> &p) const {
        return this->x * p.x + this->y * p.y;
    }

    // 外積 (cross product) : a×b = |a||b|sinθ
    double cross(const Point<T> &p) const {
        return this->y * p.x - this->x * p.y;
    }

    T norm2() const {
        return this->x * this->x + this->y * this->y;
    }

    double radian() const {
        return atan2(this->y, this->x);
    }

    // 傾きを有理数で返す(first / second)
    // 傾きが無限になってしまう場合は (1, 0) とする
    std::pair<T, T> slope() {
        auto dx = this->x;
        auto dy = this->y;
        if (dx < 0) {
            dx = -dx;
            dy = -dy;
        }

        // 縦
        if (dx == 0) {
            dy = 1;
        } else {
            auto g = std::gcd(dx, dy);
            dx /= g;
            dy /= g;
        }

        return {dy, dx};
    }

    Point<T> &operator+=(const Point<T> &p) {
        this->x += p.x;
        this->y += p.y;
        return *this;
    }

    Point<T> operator+(const Point<T> &p) const {
        return Point<T>(this->x + p.x, this->y + p.y);
    }

    Point<T> &operator-=(const Point<T> &p) {
        this->x -= p.x;
        this->y -= p.y;
        return *this;
    }

    Point<T> operator-(const Point<T> &p) const {
        return Point<T>(this->x - p.x, this->y - p.y);
    }

    Point<T> &operator*=(const T d) {
        this->x *= d;
        this->y *= d;
        return *this;
    }

    Point<T> operator*(const T d) const {
        return Point<T>(this->x * d, this->y * d);
    }

    Point<T> operator/(const T d) const {
        return Point<T>(this->x / d, this->y / d);
    }

    bool operator==(const Point<T> &p) const {
        return std::abs(this->x - p.x) <= this->EPS and std::abs(this->y - p.y) <= this->EPS;
    }

    // 象限
    int orthant() const {
        if (std::abs(this->x) < this->EPS and std::abs(this->y) < this->EPS) {
            return 0;
        }
        if (this->y > 0) {
            return this->x > 0 ? 1 : 2;
        } else {
            return this->x < 0 ? 3 : 4;
        }
    }

    // 偏角ソート用(反時計回りにソート)
    // 誤差に注意
    static bool radian_sort_cmp_key(const Point &l, const Point &r) {
        return l.adian() < r.radian();
    }

    // (x, y)でソート
    static bool xy_sort_cmp_key(const Point &l, const Point &r) {
        if (fabs(l.x - r.x) < 1e-10) {
            return l.y < r.y;
        }
        return l.x < r.x;
    }

    friend std::ostream &operator<<(std::ostream &os, const Point<T> &p) {
        os << "(x=" << p.x << ", y=" << p.y << ")";
        return os;
    }
};