#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int N;
    while (cin >> N)
    {
        int n = N / 2;
        long double prob = 1.0L;
        for (int i = 1; i < n; i++)
        {
            prob *= (2.0L * i) / (2.0L * i - 1);
        }

        prob /= (2.0L * n - 1);
        cout << fixed << setprecision(5) << prob << "\n";
    }

    return 0;
}