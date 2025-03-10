/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9367                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9367                           #+#        #+#      #+#    */
/*   Solved: 2025/02/28 11:05:41 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Car
{
    int price, pickup, kmCost;
};
struct Spy
{
    bool inconsistent = false;
    int cost = 0;
    string car = "";
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;
        map<string, Car> cars;

        for (int i = 0; i < n; i++)
        {
            string name;
            int p, q, k;
            cin >> name >> p >> q >> k;
            cars[name] = {p, q, k};
        }

        map<string, Spy> spies;

        for (int i = 0; i < m; i++)
        {
            int t;
            string spyName;
            char event;
            cin >> t >> spyName >> event;
            if (spies.find(spyName) == spies.end())
            {
                spies[spyName] = Spy();
            }

            if (event == 'p')
            {
                string carName;
                cin >> carName;
                if (spies[spyName].car != "")
                {
                    spies[spyName].inconsistent = true;
                }
                else
                {
                    spies[spyName].car = carName;
                    spies[spyName].cost += cars[carName].pickup;
                }
            }
            else if (event == 'r')
            {
                int d;
                cin >> d;
                if (spies[spyName].car == "")
                {
                    spies[spyName].inconsistent = true;
                }
                else
                {
                    string carName = spies[spyName].car;
                    spies[spyName].cost += d * cars[carName].kmCost;
                    spies[spyName].car = "";
                }
            }
            else if (event == 'a')
            {
                int s;
                cin >> s;
                if (spies[spyName].car == "")
                {
                    spies[spyName].inconsistent = true;
                }
                else
                {
                    string carName = spies[spyName].car;
                    int damageCost = (cars[carName].price * s + 99) / 100;
                    spies[spyName].cost += damageCost;
                }
            }
        }

        vector<pair<string, Spy>> sortedSpies(spies.begin(), spies.end());
        sort(sortedSpies.begin(), sortedSpies.end(), [](auto &a, auto &b)
             { return a.first < b.first; });
        for (auto &p : sortedSpies)
        {
            if (p.second.car != "" || p.second.inconsistent)
            {
                cout << p.first << " INCONSISTENT\n";
            }
            else
            {
                cout << p.first << " " << p.second.cost << "\n";
            }
        }
    }
    return 0;
}