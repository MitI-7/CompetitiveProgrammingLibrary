#include <algorithm>
#include <vector>
#include <cassert>


class Node {
public:
    int location;   // Pointのindex
    int parent;     // 未使用
    int left;       // 左のノードのindex
    int right;      // 右のノードのindex

    Node() {}
    Node(int parent, int left, int right) : parent(parent), left(left), right(right) {}
};

class Point {
public:
    int id;
    long long x;
    long long y;

    Point() {}
    Point(int id, long long x, long long y) : id(id), x(x), y(y) {}

    bool operator<(const Point &p) const {
        return id < p.id;
    }
};

bool lessX(const Point &p1, const Point &p2) { return p1.x < p2.x; }
bool lessY(const Point &p1, const Point &p2) { return p1.y < p2.y; }

class KDTree {
    static const int NIL = -1;
    const int N;
    std::vector<Point> points;
    std::vector<Node> nodes;
    int node_idx = 0;
    int root;

public:
    // Nは点の数
    KDTree(int N) : N(N) {
    }

    // (x, y)に点を追加
    void add_point(int id, long long x, long long y) {
        points.emplace_back(Point(id, x, y));
        nodes.emplace_back(Node(NIL, NIL, NIL));
    }

    // O(N log^2 N)
    void build() {
        this->root = makeKDTree(0, N, 0);
    }

    // x1 <= x <= x2 and y1 <= y <= y2を満たす点を取得
    std::vector<Point> rectangular(long long x1, long long x2, long long y1, long long y2) const {
        assert(x1 <= x2 and y1 <= y2);
        std::vector<Point> ans;
        this->rectangular(this->root, x1, x2, y1, y2, 0, ans);
        return ans;
    }

    // 点(x, y)を中心とする半径r以下に含まれる点を取得(円周上を含む)
    std::vector<Point> radius(long long x, long long y, long long r) const {
        std::vector<Point> ans;
        this->radius(this->root, x, y, r, 0, ans);
        return ans;
    }

    // 点(x, y)に一番近い点を見つける
    int nearest_neighbor(long long x, long long y) {
        return -1;
    }

private:
    // 作成したノード番号を返す
    int makeKDTree(const int l, const int r, const int depth) {
        if (not (l < r)) {
            return NIL;
        }

        if (depth % 2 == 0) {
            std::sort(points.begin() + l, points.begin() + r, lessX);
        } else {
            std::sort(points.begin() + l, points.begin() + r, lessY);
        }

        const int mid = (l + r) / 2;
        const int t = node_idx++;
        nodes[t].location = mid;
        nodes[t].left = makeKDTree(l, mid, depth + 1);
        nodes[t].right = makeKDTree(mid + 1, r, depth + 1);

        return t;
    }

    void rectangular(int v, long long x1, long long x2, long long y1, long long y2, int depth, std::vector<Point> &ans) const {
        const auto x = points[nodes[v].location].x;
        const auto y = points[nodes[v].location].y;

        if (x1 <= x and x <= x2 and y1 <= y and y <= y2) {
            ans.emplace_back(points[nodes[v].location]);
        }

        if (depth % 2 == 0) {
            if (nodes[v].left != NIL and x1 <= x) {
                rectangular(nodes[v].left, x1, x2, y1, y2, depth + 1, ans);
            }
            if (nodes[v].right != NIL and x <= x2) {
                rectangular(nodes[v].right, x1, x2, y1, y2, depth + 1, ans);
            }
        } else {
            if (nodes[v].left != NIL and y1 <= y) {
                rectangular(nodes[v].left, x1, x2, y1, y2, depth + 1, ans);

            }
            if (nodes[v].right != NIL and y <= y2) {
                rectangular(nodes[v].right, x1, x2, y1, y2, depth + 1, ans);
            }
        }
    }

    // not sqrt
    long long euclidean_distance2(long long x1, long long y1, long long x2, long long y2) const {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }

    void radius(int v, const long long tx, const long long ty, const long long r, const int depth, std::vector<Point> &ans) const {
        const auto x = points[nodes[v].location].x;
        const auto y = points[nodes[v].location].y;

        if (this->euclidean_distance2(x, y, tx, ty) <= r * r) {
            ans.emplace_back(points[nodes[v].location]);
        }

        if (depth % 2 == 0) {
            // 範囲内なら無条件で進む
            if ((tx - x) * (tx - x) <= r * r) {
                if (nodes[v].left != NIL) {
                    radius(nodes[v].left, tx, ty, r, depth + 1, ans);
                }
                if (nodes[v].right != NIL) {
                    radius(nodes[v].right, tx, ty, r, depth + 1, ans);
                }
            }
            else {
                // xを小さくすると範囲内にいけるかも
                if (nodes[v].left != NIL and x > tx) {
                    radius(nodes[v].left, tx, ty, r, depth + 1, ans);
                }
                // xを小さくすると範囲内にいけるかも
                if (nodes[v].right != NIL and x < tx) {
                    radius(nodes[v].right, tx, ty, r, depth + 1, ans);
                }
            }
        } else {
            // 範囲内なら無条件で進む
            if ((ty - y) * (ty - y) <= r * r) {
                if (nodes[v].left != NIL) {
                    radius(nodes[v].left, tx, ty, r, depth + 1, ans);
                }
                if (nodes[v].right != NIL) {
                    radius(nodes[v].right, tx, ty, r, depth + 1, ans);
                }
            }
            else {
                // yを小さくすると範囲内にいけるかも
                if (nodes[v].left != NIL and y > ty) {
                    radius(nodes[v].left, tx, ty, r, depth + 1, ans);
                }
                // yを小さくすると範囲内にいけるかも
                if (nodes[v].right != NIL and y < ty) {
                    radius(nodes[v].right, tx, ty, r, depth + 1, ans);
                }
            }
        }
    }
};