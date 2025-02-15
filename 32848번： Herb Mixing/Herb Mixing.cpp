#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int green, red;
    cin >> green >> red;

    int totalBoost = 0;

    int pairs = min(green, red);
    totalBoost += pairs * 10;
    green -= pairs;

    int groups3 = green / 3;
    totalBoost += groups3 * 10;
    green %= 3;

    int groups2 = green / 2;
    totalBoost += groups2 * 3;
    green %= 2;

    totalBoost += green * 1;

    cout << totalBoost << endl;

    return 0;
}