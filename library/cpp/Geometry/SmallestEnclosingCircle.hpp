#include <cmath>
#include <vector>

class Point {
public:
    double x;
    double y;

    Point() : x(0), y(0) {}

    Point(double x, double y) : x(x), y(y) {}
};

// 点を含む最小半径の円を求める
class SmallestEnclosingCircle {
private:
    double min_x;
    double max_x;
    double min_y;
    double max_y;
    std::vector<Point> points;

public:
    SmallestEnclosingCircle(const std::vector<Point> &points) : points(points) {
        this->min_x = this->max_x = points[0].x;
        this->min_y = this->max_y = points[0].y;

        for (const auto &p: points) {
            this->min_x = std::min(this->min_x, p.x);
            this->max_x = std::max(this->max_x, p.x);
            this->min_y = std::min(this->min_y, p.y);
            this->max_y = std::max(this->max_y, p.y);
        }
    }

    // 最小包含円の中心点と半径
    std::pair<Point, double> solve() const {
        // x 座標で 3 分探索
        double l = this->min_x - 1.0;
        double r = this->max_x + 1.0;
        for (int _ = 0; _ < 100; ++_) {
            const double x1 = (l * 2 + r) / 3.0;
            const double x2 = (l + r * 2) / 3.0;

            if (this->g(x1).second > this->g(x2).second) {
                l = x1;
            }
            else {
                r = x2;
            }
        }

        const double x = l;
        const auto [y, d] = this->g(x);
        return {Point(x, y), std::sqrt(d)};
    }

private:
    // 点aと点bのユークリッド距離の2乗
    double euclidean_distance2(const Point &a, const Point &b) const {
        const double dx = a.x - b.x;
        const double dy = a.y - b.y;
        return dx * dx + dy * dy;
    }

    // 点p から最も遠い点までの距離
    double max_distance(const Point &p) const {
        double res = 0;
        for (const auto q: points) {
            res = std::max(res, this->euclidean_distance2(p, q));
        }
        return res;
    }

    // x座標を決めたときの，y軸の距離を最小化
    // {y, 最長距離の2乗}を返す
    std::pair<double, double> g(const double x) const {
        double l = this->min_y - 1.0;
        double r = this->max_y + 1.0;

        for (int _ = 0; _ < 100; ++_) {
            const double y1 = (l * 2 + r) / 3.0;
            const double y2 = (l + r * 2) / 3.0;

            if (this->max_distance(Point(x, y1)) > this->max_distance(Point(x, y2))) {
                l = y1;
            }
            else {
                r = y2;
            }
        }

        const auto y = l;
        return {y, this->max_distance(Point(x, y))};
    }
};