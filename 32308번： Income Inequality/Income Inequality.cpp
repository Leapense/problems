#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> wealth(n);
    long long total_wealth = 0;

    for (int i = 0; i < n; ++i) {
        cin >> wealth[i];
        total_wealth += wealth[i];
    }

    sort(wealth.rbegin(), wealth.rend());

    long long accumulated_wealth = 0;
    double max_difference = 0.0;

    for (int i = 0; i < n; ++i) {
        accumulated_wealth += wealth[i];
        double x = (i + 1) * 100.0 / n;
        double y = (accumulated_wealth * 100.0) / total_wealth;

        max_difference = max(max_difference, y - x);
    }

    cout << fixed << setprecision(6) << max_difference << "\n";

    return 0;
}