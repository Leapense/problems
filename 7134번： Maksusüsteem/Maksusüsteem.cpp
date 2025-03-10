#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<long long> C(N);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> C[i];
    }
    C[N - 1] = 0;
    vector<int> P(N);
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }

    int M;
    cin >> M;
    vector<long long> S(M);

    for (int i = 0; i < M; i++)
    {
        cin >> S[i];
    }

    vector<long long> cumulative(N, 0);
    cumulative[0] = C[0];
    for (int i = 1; i < N - 1; i++)
    {
        cumulative[i] = cumulative[i - 1] + C[i];
    }

    vector<double> tax_prefix(N, 0.0);
    tax_prefix[0] = C[0] * P[0] / 100.0;

    for (int i = 1; i < N - 1; i++)
    {
        tax_prefix[i] = tax_prefix[i - 1] + C[i] * P[i] / 100.0;
    }

    cout << fixed << setprecision(2);
    for (int i = 0; i < M; i++)
    {
        long long income = S[i];
        double tax = 0.0;
        if (N == 1)
        {
            tax = income * P[0] / 100.0;
            cout << tax << "\n";
            continue;
        }

        auto it = lower_bound(cumulative.begin(), cumulative.end() - 1, income);
        int idx = it - cumulative.begin();
        if (it == cumulative.end() - 1 && income > cumulative[N - 2])
        {
            tax = tax_prefix[N - 2] + (income - cumulative[N - 2]) * P[N - 1] / 100.0;
        }
        else
        {
            if (it != cumulative.begin())
            {
                tax = tax_prefix[idx - 1] + (income - cumulative[idx - 1]) * P[idx] / 100.0;
            }
            else
            {
                tax += income * P[0] / 100.0;
            }
        }

        cout << tax << "\n";
    }

    return 0;
}