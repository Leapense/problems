#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

struct Bus
{
    string from, to;
    int dep; // departure time in minutes (0-1439)
    int arr; // arrival time in minutes (0-1439)
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
    string line;
    getline(cin, line); // consume newline

    vector<Bus> buses;
    for (int i = 0; i < n; i++)
    {
        getline(cin, line);
        // Format: "City1-City2 h:mm--h:mm"
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

    // Try each bus from Zagreb to Graz.
    for (const auto &bus1 : buses)
    {
        if (bus1.from == "Zagreb" && bus1.to == "Graz")
        {
            // We simulate taking this bus on day0 and day1.
            for (int i = 0; i < 2; i++)
            {
                int offset = i * DAY;
                // If the trip goes overnight, add 1440 minutes.
                int extra1 = (bus1.arr < bus1.dep ? DAY : 0);
                int abs_dep1 = bus1.dep + offset;
                int eff_arr1 = bus1.arr + extra1 + 1 + offset; // effective arrival time

                // For each bus from Graz to Wroclaw.
                for (const auto &bus2 : buses)
                {
                    if (bus2.from == "Graz" && bus2.to == "Wroclaw")
                    {
                        // Determine bus2's duration (including the extra minute)
                        int duration2;
                        if (bus2.arr < bus2.dep)
                            duration2 = (bus2.arr + DAY - bus2.dep) + 1;
                        else
                            duration2 = (bus2.arr - bus2.dep) + 1;

                        // Decide on which day bus2 is taken.
                        // Since timetable repeats, compare bus2.dep with eff_arr1 modulo DAY.
                        int modArrival = eff_arr1 % DAY;
                        int j = (bus2.dep > modArrival ? i : i + 1);
                        int abs_dep2 = bus2.dep + j * DAY;

                        // Check transfer condition (must be strictly greater)
                        if (abs_dep2 <= eff_arr1)
                            continue; // should not happen given our j formula

                        int eff_arr2 = abs_dep2 + duration2;
                        int totalTime = eff_arr2 - abs_dep1;
                        if (totalTime < best)
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
