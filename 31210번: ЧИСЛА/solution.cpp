#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

/* -------------------------------------------------
 * 핵심 로직 함수 : 단위 테스트와 main 둘 다 사용
 * -------------------------------------------------*/
ull find_number(ull x, int k)
{
    const string ones18(18, '1'); // "111...1" 18자
    size_t n = to_string(x).size();
    ull best = ULLONG_MAX;

    auto push_candidate = [&](const string &s)
    {
        if (s.front() == '0')
            return; // 선행 0 금지
        if (s.size() > 19)
            return; // overflow safety
        ull val = stoull(s);
        if (val >= x)
            best = min(best, val);
    };

    for (size_t L : {n, n + 1})
    {
        if (L == 0 || L > 18)
            continue;
        /* 1) 모든 자릿수 동일 */
        for (char d = '1'; d <= '9'; ++d)
        {
            push_candidate(string(L, d));
        }

        /* 2) k == 1 : 한 자릿수만 다름 */
        if (k == 1)
        {
            for (char base = '0'; base <= '9'; ++base)
            {
                string s(L, base);
                for (size_t pos = 0; pos < L; ++pos)
                {
                    for (char diff = '0'; diff <= '9'; ++diff)
                    {
                        if (diff == base)
                            continue;
                        s[pos] = diff;
                        push_candidate(s);
                    }
                    s[pos] = base; // 복원
                }
            }
        }
    }
    return best;
}

/* -------------------- 표준 입출력 --------------------*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ull x;
    int k;
    if (!(cin >> x))
        return 0;
    cin >> k;
    cout << find_number(x, k) << '\n';
    return 0;
}