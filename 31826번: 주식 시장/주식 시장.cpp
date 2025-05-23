#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    const int MIN_PRICE = 7000;
    const int MAX_PRICE = 13000;
    const int STEP = 10;

    int size = (MAX_PRICE - MIN_PRICE) / STEP + 1;

    vector<int> buy(size, 0);
    vector<int> sell(size, 0);

    int currentPrice = 10000;

    for (int i = 0; i < N; i++)
    {
        int p, x, f;
        cin >> p >> x >> f;

        int idx = (p - MIN_PRICE) / STEP;

        if (f == 1)
        {
            if (sell[idx] > 0)
            {
                int deal = min(sell[idx], x);
                sell[idx] -= deal;
                x -= deal;
                currentPrice = p;
            }
            if (x > 0)
            {
                buy[idx] += x;
            }
        }
        else
        {
            if (buy[idx] > 0)
            {
                int deal = min(buy[idx], x);
                buy[idx] -= deal;
                x -= deal;
                currentPrice = p;
            }

            if (x > 0)
            {
                sell[idx] += x;
            }
        }
    }

    cout << currentPrice << "\n";

    return 0;
}