// solve.cpp
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using i128 = __int128_t;

bool defeat_one_base(i128 &cur, const vector<int64> &floors)
{
    vector<int64> enemies;
    int items = 0;

    for (int64 x : floors)
        (x == -1 ? items : enemies.emplace_back(x));

    sort(enemies.begin(), enemies.end());

    for (int64 e : enemies)
    {
        while (cur <= e)
        {
            if (!items)
                return false; // 아이템 바닥 → 실패
            --items;
            cur <<= 1; // 두 배
        }
        cur += e; // 적 전투력 흡수
    }
    // 남은 아이템 모두 사용
    while (items--)
        cur <<= 1;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    int64 P_init;
    if (!(cin >> N >> M >> P_init))
        return 0;

    i128 cur = P_init;
    vector<int64> floors(M);

    for (int base = 0; base < N; ++base)
    {
        for (int j = 0; j < M; ++j)
            cin >> floors[j];
        if (!defeat_one_base(cur, floors))
        {
            cout << 0 << '\n';
            return 0;
        }
        if (cur > (i128)1e18)
            cur = (i128)1e18; // 안전 상한
    }
    cout << 1 << '\n';
    return 0;
}
