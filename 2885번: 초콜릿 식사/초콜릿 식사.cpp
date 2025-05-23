#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int K;
    cin >> K;

    int n = 0;
    while ((1 << n) < K)
        n++;
    int S = (1 << n);

    vector<int> available(n + 1, 0);
    available[n] = 1;

    int splits = 0;

    for (int i = n; i >= 0; i--)
    {
        int need = ((K >> i) & 1);
        if (available[i] < need)
        {
            int j = i + 1;
            while (j <= n && available[j] == 0)
                j++;
            while (j > i)
            {
                available[j]--;
                available[j - 1] += 2;
                splits++;
                j--;
            }
        }

        available[i] -= need;

        if (i > 0)
        {
            available[i - 1] += available[i] / 2;
        }
    }

    cout << S << " " << splits << "\n";
    return 0;
}