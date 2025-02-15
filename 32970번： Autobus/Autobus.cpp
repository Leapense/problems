#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

struct Bus
{
    string from, to;
    int dep;
    int arr;
};

int toMinutes(const string &timeStr)
{
    int h, m;
    char colon;
    istringstream iss(timeStr);
    iss >> h >> colon >> m;
    return h * 60 + m;
}

int main()
{
    int n;
    cin >> n;

    vector<Bus> buses;

    string line;
    getline(cin, line);

    for (int i = 0; i < n; i++)
    {
        getline(cin, line);
        istringstream iss(line);
        string cities, times;
        iss >> cities >> times;

        size_t dash = cities.find('-');
        string from = cities.substr(0, dash);
        string to = cities.substr(dash + 1);

        size_t pos = times.find("--");
        string depStr = times.substr(0, pos);
        string arrStr = times.substr(pos + 2);

        int dep = toMinutes(depStr);
        int arr = toMinutes(arrStr);

        buses.push_back({from, to, dep, arr});
    }

    const int DAY = 1440;
    int best = numeric_limits<int>::max();

    for (const auto &bus1 : buses)
    {
        if (bus1.from == "Zagreb" && bus1.to == "Graz")
        {
            int effArr1 = bus1.arr;
            if (bus1.arr < bus1.dep)
            {
                effArr1 += DAY;
            }

            effArr1 += 1;

            for (const auto &bus2 : buses)
            {
                if (bus2.from == "Graz" && bus2.to == "Wroclaw")
                {
                    int duration2;
                    if (bus2.arr < bus2.dep)
                    {
                        duration2 = (bus2.arr + DAY - bus2.dep) + 1;
                    }
                    else
                    {
                        duration2 = (bus2.arr - bus2.dep) + 1;
                    }

                    int k = 0;
                    while (bus2.dep + k * DAY <= effArr1)
                    {
                        k++;
                    }

                    int effDep2 = bus2.dep + k * DAY;
                    int effArr2 = effDep2 + duration2;

                    int totalTime = effArr2 - bus1.dep;

                    if (totalTime < best)
                    {
                        best = totalTime;
                    }
                }
            }
        }
    }

    if (best == numeric_limits<int>::max())
    {
        cout << "NEMOGUCE" << endl;
    }
    else
    {
        int hours = best / 60;
        int minutes = best % 60;

        cout << hours << ":";
        if (minutes < 10)
            cout << "0";
        cout << minutes << endl;
    }

    return 0;
}