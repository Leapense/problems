#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> shopProducts(n);
    vector<vector<int>> productShops(m + 1);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        shopProducts[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            int prod;
            cin >> prod;
            shopProducts[i][j] = prod;
            productShops[prod].push_back(i + 1);
        }
    }
    for (int p = 1; p <= m; p++)
    {
        if (productShops[p].empty())
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }

    cout << "\n";

    for (int p = 1; p <= m; p++)
    {
        int last = 0;
        for (int shop : productShops[p])
        {
            if (shop > last)
                last = shop;
        }
        cout << last << " ";
    }

    return 0;
}