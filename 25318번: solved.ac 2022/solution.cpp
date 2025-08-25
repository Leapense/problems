#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdint>
#include <cmath>

using i64 = long long;

static inline i64 days_from_civil(int y, int m, int d) {
    y -= m <= 2;
    const int era = (y >= 0 ? y : y - 399) / 400;
    const unsigned yoe = static_cast<unsigned>(y - era * 400);
    const unsigned m_adj = static_cast<unsigned>(m + (m > 2 ? -3 : 9));
    const unsigned doy = (153U * m_adj + 2U) / 5U + static_cast<unsigned>(d) - 1U;
    const unsigned doe = yoe * 365U + yoe / 4U - yoe / 100U + doy;
    return static_cast<i64>(era) * 146097LL + static_cast<i64>(doe) - 719468LL;
}

static inline i64 to_seconds(int y, int m, int d, int hh, int mm, int ss) {
    const i64 seconds_per_day = 86400LL;
    return days_from_civil(y, m, d) * seconds_per_day
         + static_cast<i64>(hh) * 3600LL
         + static_cast<i64>(mm) * 60LL
         + static_cast<i64>(ss);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) return 0;
    if (n == 0) {
        std::cout << 0 << '\n';
        return 0;
    }

    std::vector<i64> ts(n);
    std::vector<int> lv(n);
    for (int i = 0; i < n; ++i) {
        std::string date, time;
        int L;
        std::cin >> date >> time >> L;
        int Y, M, D, h, m, s;
        std::sscanf(date.c_str(), "%d/%d/%d", &Y, &M, &D);
        std::sscanf(time.c_str(), "%d:%d:%d", &h, &m, &s);
        ts[i] = to_seconds(Y, M, D, h, m, s);
        lv[i] = L;
    }

    const long double seconds_per_day = 86400.0L;
    const long double days_in_year = 365.0L;
    const i64 tN = ts.back();
    long double sum_w = 0.0L, sum_p = 0.0L;

    for (int i = 0; i < n; ++i) {
        long double years = static_cast<long double>(tN - ts[i]) / (days_in_year * seconds_per_day);
        long double p_date = std::powl(0.5L, years);
        long double p_index = std::powl(0.9L, static_cast<long double>(n - i - 1));
        long double p = p_date > p_index ? p_date : p_index;
        sum_w += p * static_cast<long double>(lv[i]);
        sum_p += p;
    }

    long double x = sum_w / sum_p;
    int ans = static_cast<int>(std::floor(x + 0.5L));
    std::cout << ans << '\n';
    return 0;
}