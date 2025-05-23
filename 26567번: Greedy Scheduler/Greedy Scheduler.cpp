#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;
    while (m--)
    {
        int n, c;
        cin >> n >> c;
        vector<long long> times(c);
        for (int i = 0; i < c; i++)
        {
            cin >> times[i];
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        for (int i = 1; i <= n; i++)
        {
            pq.push({0, i});
        }

        vector<int> result(c);
        for (int i = 0; i < c; i++)
        {
            auto [finishTime, cashier] = pq.top();
            pq.pop();
            result[i] = cashier;
            pq.push({finishTime + times[i], cashier});
        }

        for (int i = 0; i < c; i++)
        {
            cout << result[i];
            if (i < c - 1)
                cout << " ";
        }

        cout << "\n";
    }

    return 0;
}