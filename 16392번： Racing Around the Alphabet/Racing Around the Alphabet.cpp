#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    const double PI = acos(-1);
    const double radius = 30.0;
    const double angleStep = 2 * PI / 28;

    for (int i = 0; i < n; i++)
    {
        string aphorism;
        getline(cin, aphorism);
        double totalDistance = 0.0;
        auto getIndex = [&](char c) -> int
        {
            if (c >= 'A' && c <= 'Z')
                return c - 'A';
            if (c == ' ')
                return 26;
            return 27;
        };

        int prev = getIndex(aphorism[0]);
        for (size_t j = 1; j < aphorism.size(); j++)
        {
            int curr = getIndex(aphorism[j]);
            int diff = abs(curr - prev);
            if (diff > 14)
                diff = 28 - diff;
            totalDistance += radius * angleStep * diff;
            prev = curr;
        }

        double time = totalDistance / 15.0 + aphorism.size();
        cout << fixed << setprecision(10) << time << "\n";
    }

    return 0;
}