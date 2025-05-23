#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double t, r, v;
    cin >> t >> r >> v;

    double v_min = v - (2 * r / t);
    v_min = max(0.0, v_min);

    cout << fixed << setprecision(6) << v_min << endl;

    return 0;
}