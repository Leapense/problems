#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        if (N == 1)
        {
            cout << 1 << "\n";
            continue;
        }

        vector<int> digits;

        for (int d = 9; d >= 2; d--)
        {
            while (N % d == 0)
            {
                digits.push_back(d);
                N /= d;
            }
        }

        if (N != 1)
        {
            cout << -1 << "\n";
            continue;
        }

        sort(digits.begin(), digits.end());
        cout << digits.size() << "\n";
    }

    return 0;
}