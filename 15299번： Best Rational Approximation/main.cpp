#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int K, M;
        double x;

        cin >> K >> M >> x;

        if (x == 0.0)
        {
            cout << K << " 0/1\n";
            continue;
        }

        pair<ll, ll> left = {0, 1}, right = {1, 1}, best = left;

        double bestErr = fabs(x - double(left.first) / left.second);
        if (fabs(x - double(right.first) / right.second) < bestErr)
        {
            best = right;
            bestErr = fabs(x - double(right.first) / right.second);
        }

        while (true)
        {
            ll mediant_p = left.first + right.first;
            ll mediant_q = left.second + right.second;
            if (mediant_q > M)
                break;

            double mediant_val = double(mediant_p) / mediant_q;
            double err = fabs(x - mediant_val);
            if (err < bestErr)
            {
                best = {mediant_p, mediant_q};
                bestErr = err;
            }

            if (mediant_val < x)
                left = {mediant_p, mediant_q};
            else
                right = {mediant_p, mediant_q};
        }

        ll k = (M - left.second) / right.second;
        ll candidate_p = left.first + k * right.first;
        ll candidate_q = left.second + k * right.second;

        double candidate_err = fabs(x - double(candidate_p) / candidate_q);
        if (candidate_err < bestErr)
        {
            best = {candidate_p, candidate_q};
        }

        cout << K << " " << best.first << "/" << best.second << "\n";
    }

    return 0;
}