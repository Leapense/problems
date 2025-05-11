#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

std::string calculate_hit_or_miss(double t_meters, double x_degrees)
{
    double dist = 0;
    double left = t_meters * 100 - (16.0 / sin(M_PI * x_degrees / 180.0));
    double right = t_meters * 100 + (16.0 / sin(M_PI * x_degrees / 180.0));
    double step = 85.0 / tan(M_PI * x_degrees / 180.0);

    while (dist < right)
    {
        if (left < dist && dist < right)
        {
            return "yes";
        }
        dist += step;
    }
    if (dist >= right)
    {
        return "no";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n_test_cases;
    std::cin >> n_test_cases;

    while (n_test_cases--)
    {
        double t_meters, x_degrees;
        std::cin >> t_meters >> x_degrees;
        std::cout << calculate_hit_or_miss(t_meters, x_degrees) << std::endl;
    }

    return 0;
}