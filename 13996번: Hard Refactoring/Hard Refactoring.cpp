#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>
#include <limits>

using namespace std;

struct Interval
{
    int L, R;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int MIN_VAL = -32768;
    constexpr int MAX_VAL = 32767;

    vector<Interval> intervals;
    string line;

    while (getline(cin, line))
    {
        if (line.size() >= 3 && line.substr(line.size() - 3) == " ||")
        {
            line = line.substr(0, line.size() - 3);
        }

        istringstream iss(line);
        string token;
        int L = MIN_VAL, R = MAX_VAL;
        bool lowerSet = false, upperSet = false;

        iss >> token;
        iss >> token;

        if (token == ">=")
        {
            int value;
            iss >> value;
            L = value;
            lowerSet = true;
        }
        else if (token == "<=")
        {
            int value;
            iss >> value;
            R = value;
            upperSet = true;
        }

        if (iss >> token)
        {
            iss >> token;
            iss >> token;

            if (token == "<=")
            {
                int value;
                iss >> value;
                R = value;
                upperSet = true;
            }
            else if (token == ">=")
            {
                int value;
                iss >> value;
                L = value;
                lowerSet = true;
            }
        }

        if (L <= R)
        {
            intervals.push_back({L, R});
        }
    }

    if (intervals.empty())
    {
        cout << "false";
        return 0;
    }

    ranges::sort(intervals, [](const Interval &a, const Interval &b)
                 { return a.L < b.L; });

    vector<Interval> merged;
    for (const auto &inter : intervals)
    {
        if (merged.empty() || merged.back().R < inter.L - 1)
        {
            merged.push_back(inter);
        }
        else
        {
            merged.back().R = max(merged.back().R, inter.R);
        }
    }

    if (merged.size() == 1 && merged.front().L <= MIN_VAL && merged.front().R >= MAX_VAL)
    {
        cout << "true";
        return 0;
    }

    if (merged.empty())
    {
        cout << "false";
        return 0;
    }

    for (size_t i = 0; i < merged.size(); i++)
    {
        const auto &inter = merged[i];
        string out;
        if (inter.L == MIN_VAL)
        {
            out = "x <= " + to_string(inter.R);
        }
        else if (inter.R == MAX_VAL)
        {
            out = "x >= " + to_string(inter.L);
        }
        else
        {
            out = "x >= " + to_string(inter.L) + " && x <= " + to_string(inter.R);
        }

        if (i != merged.size() - 1)
            cout << out << " ||" << "\n";
        else
            cout << out;
    }

    return 0;
}