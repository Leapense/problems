#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <iomanip>
#include "gtest/gtest.h"

using namespace std;

const double EPS = 1e-9;

double basicAngle(char c) {
    switch(c) {
        case 'N': return 0.0;
        case 'E': return 90.0;
        case 'S': return 180.0;
        case 'W': return 270.0;
        default: assert(false); return 0.0;
    }
}

double angleDiff(double a, double b) {
    double diff = fabs(a - b);
    if (diff > 180.0) diff = 360.0 - diff;
    return diff;
}

double mod360(double a) {
    a = fmod(a, 360.0);
    if (a < 0) a += 360.0;
    return a;
}

double computeAngle(const string &s) {
    int n = s.size();
    if (n == 1) {
        return basicAngle(s[0]);
    } else if (n == 2) {
        if (s == "NE") return 45.0;
        if (s == "SE") return 135.0;
        if (s == "SW") return 225.0;
        if (s == "NW") return 315.0;

        assert(false);
        return 0.0;
    } else {
        string sub = s.substr(1);
        double a = computeAngle(sub);
        double t = basicAngle(s[0]);

        int m = n - 1;
        double step = 360.0 / (1 << (m + 1));

        double cwDiff = mod360(t - a);
        double ccwDiff = mod360(a - t);
        bool cw;
        double arc;

        if (cwDiff <= ccwDiff) {
            cw = true;
            arc = cwDiff;
        } else {
            cw = false;
            arc = ccwDiff;
        }

        double r = fmod(a, step);
        double candidate;

        if (cw) {
            if (fabs(r) < EPS) {
                candidate = a + step;
            } else {
                candidate = a + (step - r);
            }
        } else {
            if (fabs(r) < EPS) {
                candidate = a - step;
            } else {
                candidate = a - r;
            }
        }

        candidate = mod360(candidate);

        double diff;
        if(cw) {
            diff = mod360(candidate - a);
        } else {
            diff = mod360(a - candidate);
        }

        double mid;
        if (cw) {
            mid = a + diff / 2.0;
        } else {
            mid = a - diff / 2.0;
        }

        mid = mod360(mid);
        return mid;
    }
}

double solve(const string &X, const string &Y) {
    double angleX = computeAngle(X);
    double angleY = computeAngle(Y);
    return angleDiff(angleX, angleY);
}

TEST(CompassTest, Sample1) {
    string X = "N", Y = "S";
    double res = solve(X, Y);
    EXPECT_NEAR(res, 180.0, 1e-6);
}

TEST(CompassTest, Sample2) {
    string X = "NNE", Y = "SSSE";
    double res = solve(X, Y);
    EXPECT_NEAR(res, 146.25, 1e-6);
}

TEST(CompassTest, Sample3) {
    string X = "ENE", Y = "NW";
    double res = solve(X, Y);
    EXPECT_NEAR(res, 112.5, 1e-6);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}