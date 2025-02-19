#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, C;
    while (cin >> N >> C)
    {
        if (N == 0 || C == 0)
        {
            cout << 0 << "\n";
            continue;
        }

        long long T1 = C / (2 * N);
        long long T2 = T1 + 1;
        long long fT1 = T1 * (C - N * T1);
        long long fT2 = T2 * (C - N * T2);
        if (fT2 > fT1)
        {
            cout << T2 << "\n";
        }
        else
        {
            cout << T1 << "\n";
        }
    }

    return 0;
}