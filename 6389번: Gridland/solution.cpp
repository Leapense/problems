#include <bits/stdc++.h>
using namespace std;

static double computeTourLength(int m, int n)
{
    if ((m % 2 == 0) || (n % 2 == 0))
    {
        return static_cast<double>(m) * n;
    }

    return static_cast<double>(m) * n - 1.0 + M_SQRT2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int scenarios;

    if (!(cin >> scenarios) || scenarios <= 0)
    {
        return EXIT_FAILURE;
    }

    for (int i = 1; i <= scenarios; ++i)
    {
        int m, n;
        cin >> m >> n;
        double length = computeTourLength(m, n);

        cout << "Scenario #" << i << ":\n"
             << fixed << setprecision(2)
             << length << "\n\n";
    }

    return EXIT_SUCCESS;
}