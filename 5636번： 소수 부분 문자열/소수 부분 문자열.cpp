#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXP = 100000;
vector<bool> sieve(MAXP + 1, true);

void buildSieve()
{
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= MAXP; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= MAXP; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    buildSieve();
    string s;

    while (cin >> s && s != "0")
    {
        int ans = 0;
        int n = s.size();

        for (int len = 1; len <= 5; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int num = 0;
                for (int j = i; j < i + len; j++)
                {
                    num = num * 10 + (s[j] - '0');
                }
                if (num <= MAXP && sieve[num])
                {
                    ans = max(ans, num);
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}