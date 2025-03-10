#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> perm(n);

    for (int i = 0; i < n; i++)
        cin >> perm[i];
    vector<unsigned long long> fact(n + 1, 1);

    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i;
    unsigned long long rank = 0;

    vector<bool> used(n, false);
    for (int i = 0; i < n; i++)
    {
        int smaller = 0;
        for (int j = 0; j < perm[i]; j++)
        {
            if (!used[j])
                smaller++;
        }
        rank += smaller * fact[n - 1 - i];
        used[perm[i]] = true;
    }

    cout << rank + 1 << "\n";
    return 0;
}