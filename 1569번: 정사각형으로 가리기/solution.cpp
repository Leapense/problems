#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

struct Point
{
    int x, y;
};

bool is_on_boundary(Point p, int sq_min_x, int sq_min_y, int L)
{
    if (L <= 0)
        return false;

    int sq_max_x = sq_min_x + L;
    int sq_max_y = sq_min_y + L;

    bool on_vertical_side = (p.x == sq_min_x || p.x == sq_max_x) && (p.y >= sq_min_y && p.y <= sq_max_y);
    bool on_horizontal_side = (p.y == sq_min_y || p.y == sq_max_y) && (p.x >= sq_min_x && p.x <= sq_max_x);

    return on_vertical_side || on_horizontal_side;
}

bool check_square(const std::vector<Point> &points, int sq_min_x, int sq_min_y, int L)
{
    if (L <= 0)
        return false;
    for (const auto &p : points)
    {
        if (!is_on_boundary(p, sq_min_x, sq_min_y, L))
        {
            return false;
        }
    }

    return true;
}

int solve()
{
    int N;
    std::cin >> N;
    std::vector<Point> points(N);

    int glob_min_x = std::numeric_limits<int>::max();
    int glob_max_x = std::numeric_limits<int>::min();
    int glob_min_y = std::numeric_limits<int>::max();
    int glob_max_y = std::numeric_limits<int>::min();

    for (int i = 0; i < N; ++i)
    {
        std::cin >> points[i].x >> points[i].y;
        glob_min_x = std::min(glob_min_x, points[i].x);
        glob_max_x = std::max(glob_max_x, points[i].x);
        glob_min_y = std::min(glob_min_y, points[i].y);
        glob_max_y = std::max(glob_max_y, points[i].y);
    }

    int span_x = glob_max_x - glob_min_x;
    int span_y = glob_max_y - glob_min_y;
    int L_try = std::max(span_x, span_y);

    if (span_x == L_try)
    {
        if (check_square(points, glob_min_x, glob_min_y, L_try))
        {
            return L_try;
        }

        if (check_square(points, glob_min_x, glob_max_y - L_try, L_try))
        {
            return L_try;
        }
    }

    if (span_y == L_try)
    {
        if (check_square(points, glob_min_x, glob_min_y, L_try))
        {
            return L_try;
        }

        if (check_square(points, glob_max_x - L_try, glob_min_y, L_try))
        {
            return L_try;
        }
    }

    return -1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << solve() << std::endl;
    return 0;
}