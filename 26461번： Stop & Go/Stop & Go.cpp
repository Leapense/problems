#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, L;
    cin >> N >> L;

    vector<pair<int, pair<int, int>>> lights;

    for (int i = 0; i < N; i++)
    {
        int x, g, r;
        cin >> x >> g >> r;
        lights.push_back({x, {g, r}});
    }

    sort(lights.begin(), lights.end());
    long long t = 0, prev = 0;

    for (auto light : lights)
    {
        int x = light.first, g = light.second.first, r = light.second.second;
        t += x - prev;
        int cycle = g + r;
        int mod = t % cycle;
        if (mod >= g)
        {
            t += cycle - mod;
        }

        prev = x;
    }

    t += L - prev;
    cout << t << "\n";

    return 0;
}