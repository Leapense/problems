#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "main.h"

using namespace std;

long long formNumber(const vector<int> &digits)
{
    long long num = 0;
    for (int d : digits)
    {
        num = num * 10 + d;
    }

    return num;
}

long long getMaxProduct(const string &cards)
{
    int n = cards.size();
    vector<int> digits;

    for (char c : cards)
    {
        int d = c - '0';
        if (d == 6)
            d = 9;
        digits.push_back(d);
    }

    long long maxProduct = 0;
    int totalMasks = 1 << n;

    for (int mask = 1; mask < totalMasks - 1; mask++)
    {
        vector<int> groupA, groupB;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                groupA.push_back(digits[i]);
            }
            else
            {
                groupB.push_back(digits[i]);
            }
        }

        sort(groupA.rbegin(), groupA.rend());
        sort(groupB.rbegin(), groupB.rend());

        long long numA = formNumber(groupA);
        long long numB = formNumber(groupB);
        long long product = numA * numB;
        maxProduct = max(maxProduct, product);
    }

    return maxProduct;
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        string cards;
        cin >> cards;
        cout << getMaxProduct(cards) << "\n";
    }

    return 0;
}
#endif