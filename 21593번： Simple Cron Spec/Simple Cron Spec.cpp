#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

vector<int> parseToken(const string &token, int maxVal)
{
    vector<int> res;
    if (token == "*")
    {
        for (int i = 0; i < maxVal; i++)
            res.push_back(i);
        return res;
    }
    auto splitComma = [&](const string &s) -> vector<string>
    {
        vector<string> parts;
        string temp;
        for (char c : s)
        {
            if (c == ',')
            {
                parts.push_back(temp);
                temp = "";
            }
            else
                temp.push_back(c);
        }
        if (!temp.empty())
            parts.push_back(temp);
        return parts;
    };
    vector<string> parts = splitComma(token);
    for (const auto &p : parts)
    {
        auto pos = p.find('-');
        if (pos != string::npos)
        {
            int low = stoi(p.substr(0, pos));
            int high = stoi(p.substr(pos + 1));
            for (int i = low; i <= high; i++)
                res.push_back(i);
        }
        else
        {
            res.push_back(stoi(p));
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    array<bool, 86400> started = {false};

    long long totalStarts = 0;

    for (int i = 0; i < n; i++)
    {
        string hSpec, mSpec, sSpec;
        cin >> hSpec >> mSpec >> sSpec;

        vector<int> hours = parseToken(hSpec, 24);
        vector<int> minutes = parseToken(mSpec, 60);
        vector<int> seconds = parseToken(sSpec, 60);

        totalStarts += (long long)hours.size() * minutes.size() * seconds.size();

        for (auto h : hours)
        {
            for (auto m : minutes)
            {
                for (auto s : seconds)
                {
                    started[h * 3600 + m * 60 + s] = true;
                }
            }
        }
    }
    int secondsWithJob = 0;
    for (auto flag : started)
        if (flag)
            secondsWithJob++;
    cout << secondsWithJob << " " << totalStarts;

    return 0;
}