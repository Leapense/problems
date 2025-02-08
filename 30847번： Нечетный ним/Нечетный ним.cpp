#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long oddCount = 0;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (a % 2 == 1)
        {
            oddCount++;
        }
    }

    if (oddCount % 2 == 1)
    {
        cout << "Misha\n";
    }
    else
    {
        cout << "Gleb\n";
    }

    if (oddCount % 2 == 0)
    {
        cout << "Misha\n";
    }
    else
    {
        cout << "Gleb\n";
    }

    return 0;
}