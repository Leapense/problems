#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int t;
    cin >> t;
    double r;
    double factor = sqrt(6) + sqrt(2) + 2;
    while (t--)
    {
        cin >> r;
        double side = r * factor;
        double area = side * side;
        cout << fixed << setprecision(5) << area << endl;
    }

    return 0;
}