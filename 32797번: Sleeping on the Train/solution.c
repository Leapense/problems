#include <stdio.h>
#include <stdint.h>

static long long solve_dir(long long n, long long t, long long a, long long b, const long long *s, int init_dir) {
    long long turns = 0;
    int dir = init_dir;

    long long cur;
    if (dir == +1) {
        if (s[0] >= a) {

        } else {
            turns += 1;
            dir = -1;
        }
    } else {
        if (a == 1) return (long long)4e18;
        if (s[0] <= a - 1) {

        } else {
            turns += 1;
            dir = +1;
        }
    }
    cur = s[0];

    for (long long i = 1; i < t; ++i) {
        if (dir == +1) {
            if (s[i] >= cur) {

            } else {
                turns += 1;
                dir = -1;
            }
        } else {
            if (s[i] <= cur) {

            } else {
                turns += 1;
                dir = +1;
            }
        }
        cur = s[i];
    }

    if (dir == +1) {
        if (b >= cur + 1) {

        } else {
            turns += 1;
        }
    } else {
        if (b <= cur) {

        } else {
            turns += 1;
        }
    }

    return turns;
}

int main(void) {
    long long n, t, a, b;
    if (scanf("%lld %lld %lld %lld", &n, &t, &a, &b) != 4) return 0;
    static long long s[100000 + 5];
    for (long long i = 0; i < t; ++i) scanf("%lld", &s[i]);

    long long INF = (long long)4e18;
    long long ans = INF;

    if (a == 1) {
        ans = solve_dir(n, t, a, b, s, +1);
    } else if (a == n) {
        ans = solve_dir(n, t, a, b, s, -1);
    } else {
        long long v1 = solve_dir(n, t, a, b, s, +1);
        long long v2 = solve_dir(n, t, a, b, s, -1);
        ans = (v1 < v2 ? v1 : v2);
    }
    
    printf("%lld\n", ans);
    return 0;
}