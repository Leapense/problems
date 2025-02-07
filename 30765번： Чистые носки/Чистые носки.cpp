#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long d;
    cin >> n >> d;

    vector<long long> socks(n);
    for (int i = 0; i < n; i++)
    {
        cin >> socks[i];
    }

    sort(socks.begin(), socks.end());

    int days = 0;
    for (int i = 0; i < n - 1;)
    {
        if (socks[i + 1] - socks[i] <= d)
        {
            days++;
            i += 2;
        }
        else
        {
            i++;
        }
    }

    cout << days << "\n";
    return 0;
}