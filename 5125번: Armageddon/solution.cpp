#include <bits/stdc++.h>
using namespace std;

string solve(istream &in)
{
    int K;
    if (!(in >> K))
        return "";
    constexpr double R = 6378.1;
    const double PI = acos(-1.0);
    ostringstream out;
    out.setf(ios::fixed);
    out << setprecision(2);
    for (int i = 1; i <= K; i++)
    {
        double xa, a_deg, sa, sm;
        in >> xa >> a_deg >> sa >> sm;
        double theta = (a_deg * PI / 180.0) / 2.0;
        double dmin = R / sin(theta);
        double tfire = (xa - dmin) / sa - (dmin - R) / sm;
        out << "Data Set " << i << ":\n";
        if (tfire < -1e-9)
        {
            out << "Oh no!\n\n";
            continue;
        }
        if (tfire < 0)
            tfire = 0;
        double ans = round(tfire * 100.0) / 100.0;
        if (ans < 0)
            ans = 0;
        out << ans << "\n\n";
    }
    return out.str();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve(cin);
    return 0;
}
