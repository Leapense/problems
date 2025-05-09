#include <iostream>

struct Point
{
    long long x, y;
    bool operator==(const Point &other) const
    {
        return x == other.x && y == other.y;
    }
};

Point calculate_jump_point(long long xs, long long ys, long long xe, long long ye, long long dx, long long dy)
{
    long long t_denominator = dx * dx + dy * dy;
    if (t_denominator == 0)
    {
        return {xe, ye};
    }
    else
    {
        long long val_xe_xs = xe - xs;
        long long val_ye_ys = ye - ys;

        long long dot_product_term = val_xe_xs * dx + val_ye_ys * dy;
        long long t_numerator = -dot_product_term;

        if (t_numerator < 0)
        {
            return {xe, ye};
        }
        else
        {
            long long jump_x_num = xe * t_denominator + t_numerator * dx;
            long long jump_y_num = ye * t_denominator + t_numerator * dy;

            long long jump_x = jump_x_num / t_denominator;
            long long jump_y = jump_y_num / t_denominator;

            return {jump_x, jump_y};
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Point &p)
{
    return os << "(" << p.x << ", " << p.y << ")";
}

#ifndef UNIT_TEST
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long xs_in, ys_in, xe_in, ye_in, dx_in, dy_in;
    std::cin >> xs_in >> ys_in;
    std::cin >> xe_in >> ye_in >> dx_in >> dy_in;

    Point result = calculate_jump_point(xs_in, ys_in, xe_in, ye_in, dx_in, dy_in);
    std::cout << result.x << " " << result.y << "\n";

    return 0;
}
#endif