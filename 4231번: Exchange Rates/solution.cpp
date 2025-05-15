#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

double floor2(double x)
{
    return floor(x * 100.0) / 100.0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        int d;
        cin >> d;
        if (d == 0) break;

        vector<double> rate(d);
        for (int i = 0; i < d; ++i) cin >> rate[i];

        double cad = 1000.0, usd = 0.0;
        for (int i = 0; i < d; ++i) {
            double new_cad = cad;
            double new_usd = usd;

            new_usd = max(new_usd, floor2(cad * 0.97 / rate[i]));
            new_cad = max(new_cad, floor2(usd * 0.97 * rate[i]));
            
            cad = new_cad;
            usd = new_usd;
        }

        cout << fixed << setprecision(2) << cad << "\n";
    }

    return 0;
}