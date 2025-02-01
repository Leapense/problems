#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    double x;
    cin >> n >> x;

    double *a = new double[n];
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i] * a[i];
    }

    if (sum == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << fixed << setprecision(10) << a[i] << (i == n - 1 ? "\n" : " ");
        }
    }
    else
    {
        double factor = sqrt(x * n / sum);
        for (int i = 0; i < n; i++)
        {
            cout << fixed << setprecision(10) << a[i] * factor << (i == n - 1 ? "\n" : " ");
        }
    }

    delete[] a;
    return 0;
}