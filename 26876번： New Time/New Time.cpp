#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int time_to_minutes(const string& time_str) {
    int hours = stoi(time_str.substr(0, 2));
    int minutes = stoi(time_str.substr(3, 2));
    return hours * 60 + minutes;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string initial_time, target_time;
    cin >> initial_time >> target_time;

    int initial = time_to_minutes(initial_time);
    int target = time_to_minutes(target_time);

    const int DAY_MINUTES = 24 * 60;

    int diff;

    if (target >= initial) {
        diff = target - initial;
    } else {
        diff = DAY_MINUTES - initial + target;
    }

    int button_B = diff / 60;
    int button_A = diff % 60;

    int total_presses = button_B + button_A;

    cout << total_presses;

    return 0;
}