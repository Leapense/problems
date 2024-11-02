#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int A;
    string time_str;

    while(cin >> A >> time_str) {
        if (A == -1 && time_str == "00:00:00") break;

        int HH = stoi(time_str.substr(0,2));
        int MM = stoi(time_str.substr(3,2));
        int SS = stoi(time_str.substr(6,2));

        double t0 = HH * 3600 + MM * 60 + SS;
        A = A % 360;

        double B = A;

        double n = ceil((11 * t0 / 120 - B) / 360);

        double T = (120 * (B + 360 * n)) / 11;

        while (T < t0) {
            n += 1;
            T = (120 * (B + 360 * n)) / 11;
        }

        long long total_seconds = (long long)T;

        int h = (total_seconds / 3600) % 24;
        int m = (total_seconds % 3600) / 60;
        int s = total_seconds % 60;

        cout << setfill('0') << setw(2) << h << ":"
             << setfill('0') << setw(2) << m << ":"
             << setfill('0') << setw(2) << s << endl;
    }

    return 0;
}