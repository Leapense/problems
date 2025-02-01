#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    while (n--)
    {
        double r;
        cin >> r;
        double area = 34.383 * r * r;
        cout << fixed << setprecision(5) << area << "\n";
    }

    return 0;
}