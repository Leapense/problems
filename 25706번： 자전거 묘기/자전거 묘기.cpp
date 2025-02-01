#include <iostream>
#include <vector>
using namespace std;

class BikeStunts
{
public:
    void solve()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        vector<int> jump(N + 1);
        for (int i = 1; i <= N; i++)
        {
            cin >> jump[i];
        }

        vector<int> dp(N + 2, 0);

        dp[N] = 1;

        for (int i = N - 1; i >= 1; i--)
        {
            if (jump[i] == 0)
            {
                dp[i] = 1 + dp[i + 1];
            }
            else
            {
                int landing = i + jump[i] + 1;

                if (landing <= N)
                {
                    dp[i] = 1 + dp[landing];
                }
                else
                {
                    dp[i] = 1;
                }
            }
        }
        for (int i = 1; i <= N; i++)
        {
            cout << dp[i] << (i == N ? "\n" : " ");
        }
    }
};

int main()
{
    BikeStunts bs;
    bs.solve();

    return 0;
}