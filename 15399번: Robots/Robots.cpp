#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct EnergySource
{
    int a, s;
};

double calculateDistance(const vector<EnergySource> &sources)
{
    double distance = 0, velocity = 0;
    for (const auto &src : sources)
    {
        distance += velocity * src.s + 0.5 * src.a * src.s * src.s;
        velocity += src.a * src.s;
    }

    return distance;
}

int main()
{
    int n;
    cin >> n;

    vector<EnergySource> sources(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> sources[i].a >> sources[i].s;
    }

    double defaultDistance = calculateDistance(sources);
    sort(sources.begin(), sources.end(), [](const EnergySource &a, const EnergySource &b)
         { return a.a > b.a; });

    double optimalDistance = calculateDistance(sources);

    cout << fixed << setprecision(1) << (optimalDistance - defaultDistance) << "\n";

    return 0;
}