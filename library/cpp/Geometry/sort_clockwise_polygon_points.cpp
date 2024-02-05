#include <algorithm>
#include <vector>

struct Point {
    int x, y;
};

// 多角形を連続する点によって表しているとき，
// 左上(xが最小の中でyが最小のもの)の頂点から開始する反時計回りの点にソートする
// 全ての角が 90 度または 270 度で単純であること
// 偶数番目は縦線，奇数番目は横線になる．(0-origin)
void sort_clockwise_polygon_points(std::vector<Point> &points) {
    int left_up_idx = 0;
    for (int i = 0; i < (int) points.size(); ++i) {
        if (points[i].x < points[left_up_idx].x) {
            left_up_idx = i;
        } else if (points[i].x == points[left_up_idx].x and points[i].y > points[left_up_idx].y) {
            left_up_idx = i;
        }
    }

    // left_up を先頭にもってくる
    std::rotate(points.begin(), points.begin() + left_up_idx, points.end());

    // points の順序が時計回りになっている場合，反時計回りにする
    if (points[0].x != points[1].x) {
        std::reverse(points.begin() + 1, points.end());
    }
}