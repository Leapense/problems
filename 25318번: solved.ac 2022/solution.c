#include <stdio.h>
#include <stdint.h>
#include <math.h>

static inline long long days_from_civil(int y, int m, int d) {
    y -= m <= 2;
    int era = (y >= 0 ? y : y - 399) / 400;
    unsigned yoe = (unsigned)(y - era * 400);
    unsigned m_adj = (unsigned)(m + (m > 2 ? -3 : 9));
    unsigned doy = (153U * m_adj + 2U) / 5U + (unsigned)d - 1U;
    unsigned doe = yoe * 365U + yoe / 4U - yoe / 100U + doy;
    return (long long)era * 146097LL + (long long)doe - 719468LL;
}

static inline long long to_seconds(int y, int m, int d, int hh, int mm, int ss) {
    const long long SECONDS_PER_DAY = 86400LL;
    long long days = days_from_civil(y, m, d);
    return days * SECONDS_PER_DAY + (long long)hh * 3600LL + (long long)mm * 60LL + (long long)ss;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    long long ts[1000];
    int lv[1000];
    for (int i = 0; i < n; ++i) {
        int Y, M, D, h, m, s, L;
        if (scanf("%d/%d/%d %d:%d:%d %d", &Y, &M, &D, &h, &m, &s, &L) != 7) return 0;
        ts[i] = to_seconds(Y, M, D, h, m, s);
        lv[i] = L;
    }
    const long double SECONDS_PER_DAY = 86400.0L;
    const long double DAYS_IN_YEAR = 365.0L;
    const long long tN = ts[n - 1];
    long double sum_w = 0.0L;
    long double sum_p = 0.0L;
    for (int i = 0; i < n; ++i) {
        long double years = (long double)(tN - ts[i]) / (DAYS_IN_YEAR * SECONDS_PER_DAY);
        long double p_date = powl(0.5L, years);
        long double p_index = powl(0.9L, (long double)(n - i - 1));
        long double p = p_date > p_index ? p_date : p_index;
        sum_w += p * (long double)lv[i];
        sum_p += p;
    }
    long double x = sum_w / sum_p;
    int ans = (int)floorl(x + 0.5L);
    printf("%d\n", ans);
    return 0;
}