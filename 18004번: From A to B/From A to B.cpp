#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    cin >> a >> b;
    long long operations = 0;

    if (a <= b)
    {
        cout << (b - a) << "\n";
        return 0;
    }

    while (a > b)
    {
        if (a % 2 == 0)
        {
            a /= 2;
            operations++;
        }
        else
        {
            a++;
            operations++;
        }
    }

    operations += (b - a);
    cout << operations << "\n";

    return 0;
}