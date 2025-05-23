#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int N;
    cin >> N;

    cin.ignore();

    const int shiftDurations[4] = {4, 6, 4, 10};
    vector<vector<string>> shifts(N * 7, vector<string>(4));

    for (int week = 0; week < N; ++week) {
        vector<vector<string>> weekShifts(4, vector<string>(7));
        for (int shiftTime = 0; shiftTime < 4; ++shiftTime) {
            string line;
            getline(cin, line);

            size_t pos = 0;

            for (int day = 0; day < 7; ++day) {
                while (pos < line.size() && line[pos] == ' ') pos++;
                size_t nextPos = line.find(' ', pos);
                if (nextPos == string::npos) nextPos = line.size();
                weekShifts[shiftTime][day] = line.substr(pos, nextPos - pos);
                pos = nextPos;
            }
        }

        for (int day = 0; day < 7; ++day) {
            for (int shiftTime = 0; shiftTime < 4; ++shiftTime) {
                shifts[week * 7 + day][shiftTime] = weekShifts[shiftTime][day];
            }
        }
    }

    unordered_map<string, int> totalHours;

    int totalDays = N * 7;
    for (int day = 0; day < totalDays; ++day) {
        bool isWorkDay = true;
        for (int shiftTime = 0; shiftTime < 4; ++shiftTime) {
            if (shifts[day][shiftTime] == "-") {
                isWorkDay = false;
                break;
            }
        }
        if (!isWorkDay) continue;

        for (int shiftTime = 0; shiftTime < 4; ++shiftTime) {
            string name = shifts[day][shiftTime];
            totalHours[name] += shiftDurations[shiftTime];
        }
    }

    if (totalHours.empty()) {
        cout << "Yes\n";
    } else {
        int maxHours = 0, minHours = INT_MAX;
        for (auto &entry : totalHours) {
            maxHours = max(maxHours, entry.second);
            minHours = min(minHours, entry.second);
        }

        if (maxHours - minHours <= 12) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}