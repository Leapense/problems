#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct Planet
{
    int A, B;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P;
    cin >> N >> P;

    vector<Planet> planets(N);
    for (int i = 0; i < N; i++)
    {
        cin >> planets[i].A >> planets[i].B;
    }

    ll fuel = planets[P - 1].A;
    int count = 1;

    vector<Planet> candidates;
    for (int i = 0; i < N; i++)
    {
        if (i == P - 1)
            continue;
        if (planets[i].A >= planets[i].B)
            candidates.push_back(planets[i]);
    }

    sort(candidates.begin(), candidates.end(), [](const Planet &p1, const Planet &p2)
         { return p1.B < p2.B; });

    for (auto &p : candidates)
    {
        if (fuel >= p.B)
        {
            fuel = fuel - p.B + p.A;
            count++;
        }
        else
        {
            break;
        }
    }

    cout << fuel << "\n"
         << count << "\n";
    return 0;
}