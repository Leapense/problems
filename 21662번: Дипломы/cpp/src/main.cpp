#include <iostream>
#include "main.h"
using namespace std;

ll solveDiplomas(ll w, ll h, ll n)
{
    ll left = 0, right = 1;
    while ((right / w) * (right / h) < n)
        right *= 2;
    while (left + 1 < right)
    {
        ll mid = left + (right - left) / 2;

        if ((mid / w) * (mid / h) >= n)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }

    return right;
}

#ifndef UNIT_TESTS
int main()
{
    ll w, h, n;
    cin >> w >> h >> n;
    cout << solveDiplomas(w, h, n);
    return 0;
}
#endif