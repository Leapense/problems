#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string initial_time_str;
    cin >> initial_time_str;

    int hh = stoi(initial_time_str.substr(0, 2));
    int mm = stoi(initial_time_str.substr(3, 2));
    int current_time = hh * 60 + mm;

    int areas[6];
    for (int i = 0; i < 6; i++)
    {
        cin >> areas[i];
    }

    int L;
    cin >> L;
    cin.ignore();

    bool sealed[6] = {false};

    for (int i = 0; i < L; i++)
    {
        string line;
        getline(cin, line);

        istringstream iss(line);
        vector<string> parts;

        string part;

        while (iss >> part)
        {
            parts.push_back(part);
        }

        string time_str = parts[0];
        string event_type = parts[1];

        if (event_type == "^")
        {
            int current_time_mod = current_time % 720;
            if (current_time_mod % 120 == 0)
            {
                continue;
            }

            double current_hour = current_time_mod / 60.0;
            int area = -1;

            if (0 < current_hour && current_hour < 2)
            {
                area = 1;
            }
            else if (2 < current_hour && current_hour < 4)
            {
                area = 2;
            }
            else if (4 < current_hour && current_hour < 6)
            {
                area = 3;
            }
            else if (6 < current_hour && current_hour < 8)
            {
                area = 4;
            }
            else if (8 < current_hour && current_hour < 10)
            {
                area = 5;
            }
            else if (10 < current_hour && current_hour < 12)
            {
                area = 6;
            }

            if (area != -1)
            {
                sealed[area - 1] = true;
            }
        }
        else
        {
            string item = event_type;
            int add_minutes = 0;

            if (item == "10MIN")
            {
                add_minutes = 10;
            }
            else if (item == "30MIN")
            {
                add_minutes = 30;
            }
            else if (item == "50MIN")
            {
                add_minutes = 50;
            }
            else if (item == "2HOUR")
            {
                add_minutes = 2 * 60;
            }
            else if (item == "4HOUR")
            {
                add_minutes = 4 * 60;
            }
            else if (item == "9HOUR")
            {
                add_minutes = 9 * 60;
            }

            current_time += add_minutes;
            current_time %= 720;
        }
    }

    int sealed_count = 0;

    for (int i = 0; i < 6; i++)
    {
        if (sealed[i])
            sealed_count++;
    }

    if (sealed_count == 6)
    {
        cout << 0 << endl;
        return 0;
    }

    int sum = 0;

    for (int i = 0; i < 6; i++)
    {
        if (!sealed[i])
        {
            sum += areas[i];
        }
    }

    sum = min(sum, 100);

    cout << sum << endl;

    return 0;
}