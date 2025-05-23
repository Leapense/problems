#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string l, r;
    cin >> l >> r;

    if (l.size() < r.size())
    {
        cout << r.size() << "\n";
        return 0;
    }

    int n = l.size();
    int diffIndex = -1;

    for (int i = 0; i < n; i++)
    {
        if (l[i] != r[i])
        {
            diffIndex = i;
            break;
        }
    }

    if (diffIndex == -1)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << n - diffIndex << "\n";
    }

    return 0;
}