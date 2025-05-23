#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <limits>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    cin.ignore();
    while (T--)
    {
        string costs_line, combos_line;
        getline(cin, costs_line);
        getline(cin, combos_line);
        map<string, int> costMap;
        stringstream ss(costs_line);
        while (ss.good())
        {
            string token;
            getline(ss, token, ',');
            if (token.empty())
                continue;
            auto pos = token.find(':');
            string name = token.substr(0, pos);
            int cost = stoi(token.substr(pos + 1));
            costMap[name] = cost;
        }
        int ans = numeric_limits<int>::max();
        stringstream ssc(combos_line);
        while (ssc.good())
        {
            string combination;
            getline(ssc, combination, '|');
            if (combination.empty())
                continue;
            int maxCost = 0;
            stringstream ssd(combination);
            while (ssd.good())
            {
                string cond;
                getline(ssd, cond, '&');
                if (cond.empty())
                    continue;
                maxCost = max(maxCost, costMap[cond]);
            }
            ans = min(ans, maxCost);
        }
        cout << ans << "\n";
    }
    return 0;
}
