#include <bits/stdc++.h>
using namespace std;

static int convertTo24Hour(const string &t)
{
    int hour = stoi(t.substr(0, 2));
    int minute = stoi(t.substr(3, 2));
    int second = stoi(t.substr(6, 2));
    string meridiem = t.substr(8, 2);

    if (meridiem == "AM")
    {
        if (hour == 12)
        {
            hour = 0;
        }
    }
    else
    {
        if (hour != 12)
        {
            hour += 12;
        }
    }

    return hour;
}

static string formatHour(int h24)
{
    if (h24 < 12)
    {
        ostringstream oss;
        if (h24 < 10)
            oss << "0" << h24 << "AM";
        else
            oss << h24 << "AM";
        return oss.str();
    }
    else
    {
        int h = (h24 == 12 ? 12 : h24 - 12);
        ostringstream oss;
        if (h < 10)
            oss << "0" << h << "PM";
        else
            oss << h << "PM";
        return oss.str();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, string> firstOccurrence;
    unordered_map<string, unordered_map<int, int>> tellerHourCount;
    unordered_map<string, int> tellerProcessedCount;

    while (true)
    {
        string line;
        if (!std::getline(cin, line))
            break;
        if (line == "ENDOFINPUT")
            break;
        if (line.empty())
            continue;

        vector<string> parts;
        {
            stringstream ss(line);
            string temp;
            while (ss >> temp)
                parts.push_back(temp);
        }

        if (parts.size() < 2)
            continue;

        string teller = parts[0];
        string customer = parts[1];
        string key = teller + " " + customer;

        if (parts.size() == 3)
        {
            string timeStr = parts[2];
            if (firstOccurrence.find(key) == firstOccurrence.end())
            {
                firstOccurrence[key] = timeStr;
            }
            else
            {
                tellerProcessedCount[teller]++;

                int h24 = convertTo24Hour(timeStr);
                tellerHourCount[teller][h24]++;
                firstOccurrence.erase(key);
            }
        }
        else
        {
        }
    }

    vector<pair<string, int>> sortedTellers;
    for (auto &kv : tellerProcessedCount)
    {
        sortedTellers.push_back({kv.first, kv.second});
    }

    sort(sortedTellers.begin(), sortedTellers.end(), [&](auto &a, auto &b)
         {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second; });

    vector<tuple<string, int, string>> results;
    for (auto &p : sortedTellers)
    {
        string teller = p.first;
        int countProcessed = p.second;

        int maxCount = 0, bestHour = -1;
        for (auto &hrCount : tellerHourCount[teller])
        {
            int hr = hrCount.first;
            int c = hrCount.second;
            if (c > maxCount)
            {
                maxCount = c;
                bestHour = hr;
            }
            else if (c == maxCount && hr < bestHour)
            {
                bestHour = hr;
            }
        }

        string peakTime = bestHour == -1 ? "08AM" : formatHour(bestHour);

        results.push_back({teller, countProcessed, peakTime});
    }

    int limit = min((int)results.size(), 3);
    for (int i = 0; i < limit; i++)
    {
        auto &tup = results[i];
        cout << get<0>(tup) << " " << get<1>(tup) << " " << get<2>(tup) << endl;
    }

    return 0;
}