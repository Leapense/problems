#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static long long parse_cents(const char *s) {
    long long euros = 0;
    int i = 0;
    while (s[i] && s[i] != '.') {
        euros = euros * 10 + (s[i] - '0');
        ++i;
    }

    long long cents = euros * 100;
    if (s[i] == '.') {
        int c1 = (s[i + 1] ? s[i + 1] - '0' : 0);
        int c2 = (s[i + 2] ? s[i + 2] - '0' : 0);
        cents += c1 * 10 + c2;
    }

    return cents;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    long long S = 0;
    long long c[5] = {0,0,0,0,0};
    for (int i = 0; i < n; ++i) {
        char buf[32];
        if (scanf("%31s", buf) != 1) return 0;
        long long x = parse_cents(buf);
        S += x;
        c[x % 5]++;
    }

    long long D = 0;
    D += 1 * c[1];
    D += 2 * c[2];

    long long pair = (c[3] < c[4] ? c[3] : c[4]);
    D += 2 * pair;
    c[3] -= pair;
    c[4] -= pair;

    D += 2 * (c[4] / 3);
    c[4] %= 3;

    D += 1 * (c[3] / 2);
    c[3] %= 2;

    long long ans = S - D;
    printf("%lld.%02lld\n", ans / 100, ans % 100);
    return 0;
}