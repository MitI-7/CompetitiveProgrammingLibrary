#include "library/cpp/Geometry/Point.hpp"
#include <numeric>
#include <utility>

// 平面上の線分
template<class T=long long>
class Line {
public:
    constexpr static const double epsilon = 1e-9;
    Point<T> a;
    Point<T> b;

    Line() = default;

    Line(const Point<T> a, const Point<T> b) : a(a), b(b) {}

    // line の傾き．有理数で返す
    // line が縦で傾きが無限になってしまう場合は (1, 0) とする
    std::pair<T, T> slope() {
        auto dx = this->a.x - this->b.x;
        auto dy = this->a.y - this->b.y;
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

    // y 切片．有理数で返す
    // line が縦で y 切片がない場合は {-start.x, 0} を返す
    std::pair<T, T> y_intercept() {
        auto [dy, dx] = this->slope();
        return {dx * this->a.y - dy * this->a.x, dx};
    }

    // 線分上に point があるか判定
    bool on_line(const Point<T> &point) const {
        const auto ax = this->a.x;
        const auto ay = this->a.y;
        const auto bx = this->b.x;
        const auto by = this->b.y;

        const auto px = point.x;
        const auto py = point.y;

        const auto l1 = (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
        const auto l2 = (px - ax) * (px - ax) + (py - ay) * (py - ay);
        const auto c = (bx - ax) * (px - ax) + (by - ay) * (py - ay);

        return c >= 0 and c * c == l1 * l2 and l1 >= l2;
    };

    // line と並行かどうか判定する
    bool is_parallel(const Line<T> &line) const {
        const auto y1 = this->a.y - this->b.y;
        const auto x1 = this->a.x - this->b.x;
        const auto y2 = line.a.y - line.b.y;
        const auto x2 = line.a.x - line.b.x;
        const auto p1 = Point<T>(y1, x1);
        const auto p2 = Point<T>(y2, x2);

        // 外積が0なら平行
        return p1.cross(p2) == 0;
    }

    // line と直行かどうか判定する
    bool is_orthogonal(const Line<T> &line) const {
        const auto y1 = this->a.y - this->b.y;
        const auto x1 = this->a.x - this->b.x;
        const auto y2 = line.a.y - line.b.y;
        const auto x2 = line.a.x - line.b.x;
        const auto p1 = Point<T>(y1, x1);
        const auto p2 = Point<T>(y2, x2);

        // 内積が0なら直行
        return p1.dot(p2) == 0;
    }

    // line と交わっているか判定する
    bool is_intersection(const Line<T> &line) const {
        T ay1 = this->a.y;
        T ax1 = this->a.x;
        T ay2 = this->b.y;
        T ax2 = this->b.x;
        T by1 = line.a.y;
        T bx1 = line.a.x;
        T by2 = line.b.y;
        T bx2 = line.b.x;

        const auto ta = (bx1 - bx2) * (ay1 - by1) + (by1 - by2) * (bx1 - ax1);
        const auto tb = (bx1 - bx2) * (ay2 - by1) + (by1 - by2) * (bx1 - ax2);
        const auto tc = (ax1 - ax2) * (by1 - ay1) + (ay1 - ay2) * (ax1 - bx1);
        const auto td = (ax1 - ax2) * (by2 - ay1) + (ay1 - ay2) * (ax1 - bx2);

        // 一方の線分上にもう一方の端点がのっている
        if (this->on_line(line.a) or on_line(line.b)) {
            return true;
        }
        if (line.on_line(this->a) or line.on_line(this->b)) {
            return true;
        }

        // 端点を含まないで交わる
        // tc * td < 0 && ta * tb < 0
        bool a = (ta != 0 and tb != 0 and ((ta < 0) != (tb < 0)));
        bool b = (tc != 0 and td != 0 and ((tc < 0) != (td < 0)));

        return a and b;
    }
    
    // 交点
};
