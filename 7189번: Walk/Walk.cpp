#include <bits/stdc++.h>
using namespace std;

int parse_time(const string& s) {
    int total = 0;
    int num = 0;

    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else {
            if (c == 'm') {
                total += num * 60;
            } else if(c == 's') {
                total += num;
            }

            num = 0;
        }
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    double total_distance = 0.0;
    long long total_duration = 0;

    string duration_str, kiirusega_str, speed_str;

    for (int i = 0; i < N; i++) {
        cin >> duration_str >> kiirusega_str >> speed_str;

        if (speed_str.size() >= 3 && speed_str.substr(speed_str.size() - 3) == "/km") {
            speed_str = speed_str.substr(0, speed_str.size() - 3);
        }

        int duration_sec = parse_time(duration_str);
        int speed_sec_per_km = parse_time(speed_str);
        double distance = (double)duration_sec / speed_sec_per_km;

        total_distance += distance;
        total_duration += duration_sec;
    }

    double distance_m = total_distance * 1000.0;
    long long distance_m_rounded = round(distance_m);

    double total_time_hours = (double)total_duration / 3600.0;
    double avg_speed = total_distance / total_time_hours;

    cout << distance_m_rounded << "m\n";

    cout << fixed << setprecision(3) << avg_speed << "km/h\n";
    return 0;
}