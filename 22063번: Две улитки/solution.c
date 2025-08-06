#include <stdio.h>
#include <math.h>

static double dmin(double a, double b) { return a < b ? a : b; }
static int sgn(double x, double eps) { return (x > eps) - (x < -eps); }

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    const double eps = 1e-12;
    while (t--) {
        double a1, b1, a2, b2, z;
        scanf("%lf %lf %lf %lf %lf", &a1, &b1, &a2, &b2, &z);

        double remain = z;
        double phase_len = 12.0;
        double rel_speed = a1 - a2;
        double rel_height = 0.0;
        double answer = 0.0;
        int day = 1;

        while (remain > eps) {
            double step = dmin(remain, phase_len);
            if (fabs(rel_speed) < eps) {
                if (rel_height > eps) answer += step;
            } else {
                double h0 = rel_height;
                double h1 = h0 + rel_speed * step;
                int s0 = sgn(h0, eps);
                int s1 = sgn(h1, eps);

                if (s0 == 0) s0 = sgn(rel_speed, eps);
                if (s1 == 0) s1 = sgn(rel_speed, eps);

                if (s0 == s1) {
                    if (s0 > 0) answer += step;
                } else {
                    double tc = -h0 / rel_speed;
                    if (s0 > 0) answer += tc;
                    if (s1 > 0) answer += step - tc;
                }
            }

            rel_height += rel_speed * step;
            remain -= step;
            phase_len -= step;

            if (phase_len < eps) {
                day ^= 1;
                rel_speed = day ? (a1 - a2) : (b2 - b1);
                phase_len = 12.0;
            }
        }
        printf("%.10f\n", answer);
    }
    return 0;
}