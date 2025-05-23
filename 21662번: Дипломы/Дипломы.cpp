#include <iostream>
using namespace std;
using ll = long long;

/**
 * @brief      Solves the problem 21662번： Дипломы (Diplomas).
 *
 * @details    Reads the width, height, and number of diplomas.
 *             Uses binary search to find the smallest size of square
 *             that can accomodate all diplomas.
 *             Outputs the size of the square.
 *
 * @return     0 on success.
 */
int main()
{
    ll w, h, n;
    cin >> w >> h >> n;

    ll left = 0, right = 1;
    while ((right / w) * (right / h) < n)
        right *= 2;
    while (left + 1 < right)
    {
        ll mid = left + (right - left) / 2;
        if ((mid / w) * (mid / h) >= n)
            right = mid;
        else
            left = mid;
    }

    cout << right;

    return 0;
}