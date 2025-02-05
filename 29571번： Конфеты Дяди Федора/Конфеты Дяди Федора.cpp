#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    long long n;
    cin >> n;

    if (n == 0)
    {
        cout << "YES";
        return 0;
    }

    int maxA = 2100;
    vector<long long> tetra(maxA + 1, 0);

    for (int i = 1; i <= maxA; i++)
    {
        tetra[i] = (long long)i * (i + 1) * (i + 2) / 6;
    }

    for (int a = 2; a <= maxA; a++)
    {
        for (int b = 1; b < a; b++)
        {
            long long diff = tetra[a] - tetra[b];
            if (diff == n)
            {
                cout << "YES";
                return 0;
            }

            if (diff < n)
            {
                break;
            }
        }
    }

    cout << "NO";
    return 0;
}