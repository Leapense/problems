#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> a(N);

    for (int &x : a)
    {
        cin >> x;
    }

    vector<int> b(N);

    for (int &x : b)
    {
        cin >> x;
    }

    if (N == 1)
    {
        if (a[0] == b[0])
            cout << "0\n";
        else
            cout << "-1\n";
        return 0;
    }

    int count = 0;

    for (int i = 0; i < N - 1; i++)
    {
        if (a[i] != b[i])
        {
            int x = a[i] ^ b[i];
            a[i] ^= x;
            a[i + 1] ^= x;
            count++;
        }
    }

    if (a[N - 1] == b[N - 1])
    {
        cout << count;
    }
    else
    {
        cout << "-1";
    }

    return 0;
}