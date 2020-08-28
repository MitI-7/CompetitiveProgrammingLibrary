#include <cmath>
#include <vector>


class Point {
public:
    double x;
    double y;

    Point(): x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
};

class SmallestEnclosingCircle {
private:
    double min_x;
    double max_x;
    double min_y;
    double max_y;

public:
    SmallestEnclosingCircle() {}

    // 最小包含円の半径
    double solve(const std::vector<Point> &points) {
        this->min_x = this->max_x = points[0].x;
        this->min_y = this->max_y = points[0].y;

        for (const auto &p : points) {
            this->min_x = std::min(this->min_x, p.x);
            this->max_x = std::max(this->max_x, p.x);
            this->min_y = std::min(this->min_y, p.y);
            this->max_y = std::max(this->max_y, p.y);
        }

        double l = this->min_x - 1.0;
        double r = this->max_x + 1.0;

        // x座標で3分探索
        for (int _ = 0; _ < 100; ++_) {
            const double c1 = (l * 2 + r) / 3.0;
            const double c2 = (l + r * 2) / 3.0;

            if (g(c1, points) > g(c2, points)) {
                l = c1;
            } else {
                r = c2;
            }
        }

        return g(l, points);
    }

private:

    // 点aと点bの距離
    double dist(const Point &a, const Point &b) {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }

    // nowから最も遠い点までの距離
    double max_distance(const Point &now, const std::vector<Point> &points) {
        double res = 0;
        for (const auto p : points) {
            res = std::max(res, dist(now, p));
        }
        return res;
    }

    // x座標を決めたときの，y軸の距離を最小化
    double g(const double x, const std::vector<Point> &points) {
        double l = this->min_y - 1.0;
        double r = this->max_y + 1.0;

        for (int _ = 0; _ < 100; ++_) {
            double c1 = (l * 2 + r) / 3;
            double c2 = (l + r * 2) / 3;

            if (max_distance(Point(x, c1), points) > max_distance(Point(x, c2), points)) {
                l = c1;
            } else {
                r = c2;
            }
        }

        return max_distance(Point(x, l), points);
    }
};