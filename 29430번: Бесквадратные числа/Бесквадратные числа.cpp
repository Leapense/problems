#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k;
    cin >> k;

    int a, b;
    cin >> a >> b;
    int range = b - a + 1;

    vector<bool> isSquarefree(range, true);

    for (int i = 2; (long long)i * i <= b; i++)
    {
        int sq = i * i;
        int start = ((a + sq - 1) / sq) * sq;
        for (int j = start; j <= b; j += sq)
        {
            isSquarefree[j - a] = false;
        }
    }

    long long count = 0;
    for (int i = 0; i < range; i++)
    {
        if (isSquarefree[i])
        {
            count++;
            if (count == k)
            {
                cout << a + i;
                return 0;
            }
        }
    }

    return 0;
}