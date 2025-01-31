#include <bits/stdc++.h>
using namespace std;

class CarDifference
{
public:
    int N;
    CarDifference(int n) : N(n) {}

    void solve()
    {
        long long max_diff = (long long)N * (N - 1) / 2;
        cout << max_diff << "\n";
        vector<long long> max_set;

        for (int i = 0; i < N; i++)
        {
            max_set.push_back(1LL << i);
        }

        for (int i = 0; i < N; i++)
        {
            if (i > 0)
                cout << " ";
            cout << max_set[i];
        }
        cout << "\n";

        long long min_diff = N - 1;
        cout << min_diff << "\n";
        vector<long long> min_set;
        for (int i = 0; i < N; i++)
        {
            min_set.push_back(1 + i);
        }

        for (int i = 0; i < N; i++)
        {
            if (i > 0)
                cout << " ";
            cout << min_set[i];
        }

        cout << "\n";
    }
};

int main()
{
    int N;
    cin >> N;

    CarDifference cd(N);
    cd.solve();

    return 0;
}