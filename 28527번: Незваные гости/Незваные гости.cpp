#include <iostream>
#include <vector>

using namespace std;

class UninvitedGuests
{
public:
    void solve()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n, m;
        cin >> n >> m;

        vector<int> plusCount(n + 1, 0), minusCount(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            int x;
            char ch;
            cin >> x >> ch;

            if (ch == '+')
            {
                plusCount[x]++;
            }
            else
            {
                minusCount[x]++;
            }
        }

        vector<int> minVisitors(n + 1, 0), maxVisitors(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (plusCount[i] == 0)
            {
                minVisitors[i] = 0;
                maxVisitors[i] = 0;
            }
            else
            {
                int diff = plusCount[i] - minusCount[i];
                minVisitors[i] = (diff > 0 ? diff : 1);
                maxVisitors[i] = plusCount[i];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout << minVisitors[i] << (i == n ? "\n" : " ");
        }
        for (int i = 1; i <= n; i++)
        {
            cout << maxVisitors[i] << (i == n ? "\n" : " ");
        }
    }
};

int main()
{
    UninvitedGuests solver;
    solver.solve();
    return 0;
}