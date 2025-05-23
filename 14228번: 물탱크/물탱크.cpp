#include <bits/stdc++.h>

using namespace std;

bool simulate(const vector<long long> &t, const vector<long long> &x, double R, double C)
{
    double water = 0.0, maxWater = 0.0;
    for (size_t i = 0; i < t.size(); ++i)
    {
        water = max(water + (x[i] - R) * t[i], 0.0);
        maxWater = max(maxWater, water);
    }

    return maxWater <= C;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, C;
    cin >> n >> C;

    vector<long long> t(n), x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    double low = 0.0, high = *max_element(x.begin(), x.end());

    for (int iter = 0; iter < 100; ++iter)
    {
        double mid = (low + high) / 2;
        if (simulate(t, x, mid, C))
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    double answer = high;
    string formatted = format("{:.9f}", answer);
    cout << formatted << "\n";

    return 0;
}