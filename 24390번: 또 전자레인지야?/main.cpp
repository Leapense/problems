#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string timeStr;
    cin >> timeStr;

    int M = stoi(timeStr.substr(0, 2));
    int S = stoi(timeStr.substr(3, 2));
    int T = M * 60 + S;

    int option1 = 0;
    int temp = T;
    option1 += temp / 600; temp %= 600;
    option1 += temp / 60; temp %= 60;
    option1 += temp / 10;
    option1 += 1;

    int option2 = 1e9;

    if (T >= 30) {
        int remaining = T - 30;
        int count = 0;
        count += remaining / 600; remaining %= 600;
        count += remaining / 60; remaining %= 60;
        count += remaining / 30; remaining %= 30;
        count += remaining / 10;
        option2 = 1 + count;
    }

    int ans = min(option1, option2);
    cout << ans << "\n";
    return 0;
}
