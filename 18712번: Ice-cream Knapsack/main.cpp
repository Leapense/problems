#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
struct Ice
{
    int c;
    int h;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> C(n), H(n);
        for (int i = 0; i < n; i++)
        {
            cin >> C[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> H[i];
        }
        vector<Ice> ice(n);
        for (int i = 0; i < n; i++)
        {
            ice[i] = {C[i], H[i]};
        }
        sort(ice.begin(), ice.end(), [](const Ice &a, const Ice &b)
             { return a.c < b.c; });

        int m = ice[k - 1].c;
        vector<Ice> U;
        for (auto &x : ice)
        {
            if (x.c <= m)
                U.push_back(x);
        }
        sort(U.begin(), U.end(), [](const Ice &a, const Ice &b)
             { return a.h > b.h; });

        ll ans = 0;
        for (int i = 0; i < k; i++)
        {
            ans += U[i].h;
        }

        cout << m << " " << ans << "\n";
    }

    return 0;
}