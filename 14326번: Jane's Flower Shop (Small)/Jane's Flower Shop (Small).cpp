#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        int M;
        cin >> M;
        vector<double> C(M + 1);
        for (int i = 0; i <= M; i++)
            cin >> C[i];
        auto f = [&](double r) -> double
        {double sum=-C[0];for(int i=1;i<=M;i++){sum+=C[i]/pow(1+r,i);}return sum; };
        double lo = -0.999999999, hi = 1.0;
        for (int iter = 0; iter < 100; iter++)
        {
            double mid = (lo + hi) / 2.0;
            if (f(mid) > 0)
                lo = mid;
            else
                hi = mid;
        }
        double ans = (lo + hi) / 2.0;
        cout << "Case #" << tc << ": " << fixed << setprecision(12) << ans << "\n";
    }
    return 0;
}
