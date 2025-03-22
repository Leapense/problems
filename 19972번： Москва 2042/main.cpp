#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

#ifdef UNIT_TESTS
#include <gtest/gtest.h>
#endif

const double PI = acos(-1.0);

struct Ring
{
    int r;
    int dir;
};

inline double toRadians(double degrees)
{
    return degrees * PI / 180.0;
}

double circularDistance(double R, double a_s, double a_t, int dir)
{
    double diff = fabs(a_s - a_t);
    if (dir == 0)
    {
        diff = min(diff, 2 * PI - diff);
    }
    else if (dir == 1)
    {
        if (a_t < a_s)
        {
            diff = a_t - a_s + 2 * PI;
        }
        else
        {
            diff = a_t - a_s;
        }
    }
    else if (dir == -1)
    {
        if (a_s < a_t)
        {
            diff = a_s - a_t + 2 * PI;
        }
        else
        {
            diff = a_s - a_t;
        }
    }

    return R * diff;
}

double computeMinDistance(const vector<Ring> &rings, double Rs, double Rt, double a_s, double a_t)
{
    double best = 1e18;
    for (const auto &ring : rings)
    {
        double R = ring.r;
        double radialCost = fabs(R - Rs) + fabs(R - Rt);
        double circularCost = circularDistance(R, a_s, a_t, ring.dir);
        best = min(best, radialCost + circularCost);
    }

    return best;
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Ring> rings(n);

    for (int i = 0; i < n; i++)
    {
        cin >> rings[i].r >> rings[i].dir;
    }

    vector<double> radials(m);
    for (int j = 0; j < m; j++)
    {
        long long A;
        cin >> A;
        double angle_deg = static_cast<double>(A) / 1e6;
        radials[j] = toRadians(angle_deg);
    }

    int i_s, j_s, i_t, j_t;
    cin >> i_s >> j_s >> i_t >> j_t;

    double Rs = rings[i_s - 1].r;
    double Rt = rings[i_t - 1].r;
    double a_s = radials[j_s - 1];
    double a_t = radials[j_t - 1];

    double ans = computeMinDistance(rings, Rs, Rt, a_s, a_t);
    cout << fixed << setprecision(10) << ans << "\n";

    return 0;
}
#endif

#ifdef UNIT_TESTS

TEST(Moscow2042Test, SampleTest)
{
    vector<Ring> rings = {{1, 0}, {7, 1}, {8, -1}};
    vector<double> radials;
    {
        long long A_vals[4] = {0, 90000000, 180000000, 270000000};
        for (int i = 0; i < 4; i++)
        {
            double angle_deg = static_cast<double>(A_vals[i]) / 1e6;
            radials.push_back(toRadians(angle_deg));
        }
    }

    double Rs = rings[3 - 1].r;
    double a_s = radials[1 - 1];
    double Rt = rings[3 - 1].r;
    double a_t = radials[2 - 1];

    double ans = computeMinDistance(rings, Rs, Rt, a_s, a_t);
    double expected = 12.99557428756427634;
    EXPECT_NEAR(ans, expected, 1e-4);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif