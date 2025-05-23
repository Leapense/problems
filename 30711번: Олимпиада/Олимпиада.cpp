#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    long long c;

    cin >> n >> p >> c;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<long long> sorted = a;
    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < n; i++)
    {
        long long score = a[i];

        int cnt = sorted.end() - upper_bound(sorted.begin(), sorted.end(), score - c);
        cnt--;

        int cnt_fail = sorted.end() - upper_bound(sorted.begin(), sorted.end(), score + c);

        if (cnt < p)
            cout << "Pass\n";
        else if (cnt_fail >= p)
            cout << "Fail\n";
        else
            cout << "Short\n";
    }

    return 0;
}