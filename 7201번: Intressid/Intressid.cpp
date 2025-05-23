#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    double P, D, N;
    cin >> P >> D >> N;

    double annual_expenses = (P - D) * 12.0;

    double M = pow(1.0 + N / 100.0, 1.0 / 12.0) - 1.0;

    double balance = 0.0;
    int years = 0;

    while(true) {
        years++;
        double interest = balance * (N / 100.0);

        for (int m = 1; m <= 12; m++) {
            int K = 12 - m;
            if (K > 0) {
                interest += D * (pow(1.0 + M, K) - 1.0);
            }
        }

        interest = floor(interest * 100.0 + 0.5) / 100.0;

        if (interest >= annual_expenses) {
            cout << years;
            return 0;
        }

        balance += 12.0 * D + interest;
    }

    return 0;
}