#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> sell;
        map<int, int, greater<int>> buy;
        int lastStockPrice = -1;
        for (int i = 0; i < n; i++)
        {
            string orderType;
            int shares;
            string sharesWord, atWord;
            int price;
            cin >> orderType >> shares >> sharesWord >> atWord >> price;
            if (orderType == "buy")
            {
                int remaining = shares;
                while (remaining > 0 && !sell.empty() && sell.begin()->first <= price)
                {
                    int dealPrice = sell.begin()->first;
                    int dealShares = min(remaining, sell.begin()->second);
                    lastStockPrice = dealPrice;
                    remaining -= dealShares;
                    sell.begin()->second -= dealShares;
                    if (sell.begin()->second == 0)
                        sell.erase(sell.begin());
                }
                if (remaining > 0)
                    buy[price] += remaining;
            }
            else
            {
                int remaining = shares;
                while (remaining > 0 && !buy.empty() && buy.begin()->first >= price)
                {
                    int dealPrice = price;
                    int dealShares = min(remaining, buy.begin()->second);
                    lastStockPrice = dealPrice;
                    remaining -= dealShares;
                    buy.begin()->second -= dealShares;
                    if (buy.begin()->second == 0)
                        buy.erase(buy.begin());
                }
                if (remaining > 0)
                    sell[price] += remaining;
            }
            string ask = sell.empty() ? "-" : to_string(sell.begin()->first);
            string bid = buy.empty() ? "-" : to_string(buy.begin()->first);
            string stock = lastStockPrice == -1 ? "-" : to_string(lastStockPrice);
            cout << ask << " " << bid << " " << stock << "\n";
        }
    }
    return 0;
}
