#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Solves a problem related to 2D coordinates.
 * @param type The type of the problem. 1 if the problem is about polar coordinates, 2 if the problem is about Cartesian coordinates.
 * @param a The first coordinate.
 * @param b The second coordinate.
 * @return A pair containing the result of the problem. If the problem is about polar coordinates, the first element of the pair is the radius and the second element is the angle in radians. If the problem is about Cartesian coordinates, the first element is the x-coordinate and the second element is the y-coordinate.
 */
pair<double, double> solveCase(int type, double a, double b)
{
    if (type == 1)
    {
        double r = hypot(a, b);
        double theta = atan2(b, a);
        if (r == 0)
            theta = 0;
        else if (theta < 0)
            theta += 2 * M_PI;
        return {r, theta};
    }
    else
    {
        double x = a * cos(b);
        double y = a * sin(b);
        return {x, y};
    }
}

/**
 * @brief Solve the 2D coordinate conversion problem.
 *
 * @param[in]  T  The number of test cases.
 * @param[in]  type  The type of conversion. 1 for polar to cartesian, 2 for cartesian to polar.
 * @param[in]  a  The first coordinate.
 * @param[in]  b  The second coordinate.
 *
 * @details
 * Reads the number of test cases T and then T times reads type and two double
 * precision floating point numbers a and b. Depending on the type it converts
 * the given coordinates from polar to cartesian or vice versa. The result is
 * printed with 8 digits of precision.
 *
 * @return 0.
 */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int type;
        double a, b;
        cin >> type >> a >> b;
        auto [c, d] = solveCase(type, a, b);
        cout << fixed << setprecision(8) << c << " " << d << "\n";
    }

    return 0;
}