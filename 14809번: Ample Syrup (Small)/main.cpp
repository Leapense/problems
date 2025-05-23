#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int N, K;
        cin >> N >> K;
        vector<pair<ll, ll>> pancakes(N);
        for (int i = 0; i < N; i++)
        {
            cin >> pancakes[i].first >> pancakes[i].second;
        }
        long double ans = 0.0;
        long double PI = acosl(-1.0L);
        for (int i = 0; i < N; i++)
        {
            ll r = pancakes[i].first, h = pancakes[i].second;
            long double base = PI * r * r + 2.0L * PI * r * h;
            vector<long double> others;
            for (int j = 0; j < N; j++)
            {
                if (j == i)
                    continue;
                if (pancakes[j].first <= r)
                    others.push_back(2.0L * PI * pancakes[j].first * pancakes[j].second);
            }
            sort(others.begin(), others.end(), greater<long double>());
            if (others.size() < K - 1)
                continue;
            long double sum = base;
            for (int k = 0; k < K - 1; k++)
            {
                sum += others[k];
            }
            ans = max(ans, sum);
        }
        cout << "Case #" << t << ": " << fixed << ans << "\n";
    }
    return 0;
}