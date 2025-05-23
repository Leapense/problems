#include "main.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> rearrangePools(const vector<int> &temps)
{
    int n = temps.size();
    vector<int> sorted = temps;
    sort(sorted.begin(), sorted.end());
    vector<int> res;
    int mid = (n - 1) / 2;
    res.push_back(sorted[mid]);

    int left = mid - 1, right = mid + 1;
    bool toggle = true;
    while (left >= 0 || right < n)
    {
        if (toggle)
        {
            if (right < n)
            {
                res.push_back(sorted[right]);
                right++;
            }
            toggle = false;
        }
        else
        {
            if (left >= 0)
            {
                res.push_back(sorted[left]);
                left--;
            }

            toggle = true;
        }
    }

    return res;
}

#ifndef UNIT_TESTS
int main()
{
    int n;
    cin >> n;

    vector<int> temps(n);

    for (int i = 0; i < n; i++)
    {
        cin >> temps[i];
    }
    vector<int> res = rearrangePools(temps);
    for (auto t : res)
    {
        cout << t << " ";
    }

    cout << "\n";

    return 0;
}
#endif