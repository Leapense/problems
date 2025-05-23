#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> phi(MAX + 1);
    for (int i = 0; i <= MAX; i++)
    {
        phi[i] = i;
    }

    for (int i = 2; i <= MAX; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= MAX; j += i)
            {
                phi[j] -= phi[j] / i;
            }
        }
    }

    vector<int> prefix(MAX + 1, 0);
    for (int i = 1; i <= MAX; i++)
    {
        prefix[i] = prefix[i - 1] + phi[i];
    }

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        cout << 2 * prefix[N] + 1 << "\n";
    }

    return 0;
}