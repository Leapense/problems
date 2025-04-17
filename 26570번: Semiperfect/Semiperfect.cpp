#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool dfs_semiperfect(const vector<int> &divs, const vector<ll> &suffix, int idx, ll sum, ll target)
{
    if (sum == target)
        return true;
    if (idx >= (int)divs.size())
        return false;
    // 남은 약수들의 합으로도 목표를 못 채우면 실패
    if (sum + suffix[idx] < target)
        return false;
    // 1) 현재 약수 포함
    if (sum + divs[idx] <= target)
    {
        if (dfs_semiperfect(divs, suffix, idx + 1, sum + divs[idx], target))
            return true;
    }
    // 2) 현재 약수 제외
    return dfs_semiperfect(divs, suffix, idx + 1, sum, target);
}

bool is_semiperfect(int m)
{
    vector<int> divs;
    divs.reserve(64);
    ll sum_div = 0;
    // 약수 구하기 (자기 자신 제외)
    for (int i = 1; i * 1ll * i <= m; ++i)
    {
        if (m % i == 0)
        {
            if (i < m)
            {
                divs.push_back(i);
                sum_div += i;
            }
            int j = m / i;
            if (j != i && j < m)
            {
                divs.push_back(j);
                sum_div += j;
            }
        }
    }
    // 부족수면 탈락
    if (sum_div < m)
        return false;

    // 내림차순 정렬 & suffix sum
    sort(divs.begin(), divs.end(), greater<>());
    vector<ll> suffix(divs.size());
    for (int i = (int)divs.size() - 1; i >= 0; --i)
    {
        suffix[i] = divs[i] + (i + 1 < (int)divs.size() ? suffix[i + 1] : 0LL);
    }
    // 백트래킹 판정
    return dfs_semiperfect(divs, suffix, 0, 0LL, m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    while (n--)
    {
        int m;
        cin >> m;
        cout << (is_semiperfect(m) ? "Semiperfect\n" : "NOT Semiperfect\n");
    }
    return 0;
}