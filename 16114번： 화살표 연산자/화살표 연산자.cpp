#include <iostream>

using namespace std;

int main(void)
{
    int X, N;
    cin >> X >> N;

    if (N == 0)
    {
        if (X > 0)
            cout << "INFINITE";
        else
            cout << 0;
        return 0;
    }

    if (N == 1)
    {
        if (X < 0)
            cout << "INFINITE";
        else
            cout << 0;
        return 0;
    }

    if (N >= 2 && (N % 2) == 1)
    {
        cout << "ERROR";
        return 0;
    }

    int k = N / 2;
    if (X <= 0)
    {
        cout << 0;
        return 0;
    }

    int count = (X - 1) / k;
    cout << count;

    return 0;
}