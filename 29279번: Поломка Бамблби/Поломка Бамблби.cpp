#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + (a[i] == 1 ? 0 : 1);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int cnt = prefix[r] - prefix[l - 1];

        if (cnt == 0)
        {
            cout << 2 << "\n";
        }
        else
        {
            cout << 1 << "\n";
        }
    }

    return 0;
}