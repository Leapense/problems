#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Appointment
{
    int absDay;
    int cost;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_map<string, Appointment> appointmentMap;

    for (int i = 0; i < N; i++)
    {
        string name;
        int week, day, cost;
        cin >> name >> week >> day >> cost;

        int absDay = (week - 1) * 7 + day;
        appointmentMap[name] = {absDay, cost};
    }

    vector<int> validDays;

    for (int i = 0; i < N; i++)
    {
        string name;
        int money;
        cin >> name >> money;

        Appointment app = appointmentMap[name];
        if (money >= app.cost)
        {
            validDays.push_back(app.absDay);
        }
    }

    sort(validDays.begin(), validDays.end());
    validDays.erase(unique(validDays.begin(), validDays.end()), validDays.end());

    int maxStreak = 0;
    int currentStreak = 0;

    if (validDays.empty())
    {
        cout << 0 << "\n";
        return 0;
    }

    currentStreak = 1;
    maxStreak = 1;

    for (size_t i = 1; i < validDays.size(); i++)
    {
        if (validDays[i] == validDays[i - 1] + 1)
        {
            currentStreak++;
        }
        else
        {
            currentStreak = 1;
        }

        maxStreak = max(maxStreak, currentStreak);
    }

    cout << maxStreak << "\n";
    return 0;
}