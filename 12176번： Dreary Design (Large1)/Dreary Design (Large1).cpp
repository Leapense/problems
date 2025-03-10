#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        long long K, V;
        cin >> K >> V;

        long long res = K + 1;
        for (long long d = 1; d <= V; d++)
        {
            res += (K - d + 1) * 6 * d;
        }

        cout << "Case #" << t << ": " << res;
        if (t < T)
            cout << "\n";
    }

    return 0;
}