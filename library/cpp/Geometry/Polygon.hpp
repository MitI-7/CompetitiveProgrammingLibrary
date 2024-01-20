#include <cmath>
#include <vector>
#include "Point.hpp"

template<class T>
class Polygon {
public:
    const int n;
    const std::vector<Point<T>> points;

    // points: 多角形の隣り合った点を反時計回りの順番で格納したもの
    explicit Polygon(const std::vector<Point<T>> &points) : n(points.size()), points(points) {}

    // 多角形の面積の 2 倍を求める
    // 凸でなくてもいい
    // 1/2 |sum_i x_i * y_(i+1) - x_(i+1) * y_i|
    T double_polygon_area() const {
        T area = 0;
        for (int i = 0; i < this->n; ++i) {
            area += this->points[i].x * this->points[(i + 1) % this->n].y
                    - this->points[(i + 1) % this->n].x * this->points[i].y;
        }
        return std::abs(area);
    }

    // 凸多角形かどうか判定する
    [[nodiscard]] bool is_convex() const {
        for (int i = 0; i < this->n; ++i) {
            auto a = this->points[i % this->n];
            auto b = this->points[(i + 1) % this->n];
            auto c = this->points[(i + 2) % this->n];

            const auto y1 = b.y - a.y;
            const auto x1 = b.x - a.x;
            const auto y2 = c.y - b.y;
            const auto x2 = c.x - b.x;

            const auto p1 = Point<T>(x1, y1);
            const auto p2 = Point<T>(x2, y2);

            if (p1.cross(p2) > 0) {
                return false;
            }
        }

        return true;
    }
};