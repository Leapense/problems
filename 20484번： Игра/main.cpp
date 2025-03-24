#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;

    int L = n.size();

    vector<bool> dp(L + 1, false);

    dp[L] = true;

    for (int i = L - 1; i >= 1; i--)
    {
        bool win = false;

        if (!dp[i + 1])
        {
            win = true;
        }

        if (!win && n[i - 1] < '9')
        {
            if ((i % 2) == (L % 2))
            {
                win = true;
            }
        }

        char minAllowed = (i == 1) ? '1' : '0';
        if (!win && n[i - 1] > minAllowed)
        {
            if ((i % 2) != (L % 2))
            {
                win = true;
            }
        }

        dp[i] = win;
    }

    cout << (dp[1] ? "First" : "Second") << "\n";

    return 0;
}