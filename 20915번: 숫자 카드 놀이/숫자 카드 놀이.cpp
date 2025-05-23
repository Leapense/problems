#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Function to convert vector of digits (sorted in descending order) into a number
long long formNumber(const vector<int> &digits)
{
    long long num = 0;
    for (int d : digits)
    {
        num = num * 10 + d;
    }
    return num;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> cards;
        // Convert string digits to integers and transform '6' to '9'
        for (char c : s)
        {
            int digit = c - '0';
            if (digit == 6)
                digit = 9;
            cards.push_back(digit);
        }

        long long maxProduct = 0;

        // Use bitmask to generate every possible partition into two groups.
        // We iterate from 1 to (1<<n)-1, but we must skip partitions where all bits are 0 or all are 1.
        int totalMasks = 1 << n;
        for (int mask = 1; mask < totalMasks - 1; mask++)
        {
            vector<int> groupA, groupB;

            // Partition the cards according to the bitmask
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                    groupA.push_back(cards[i]);
                else
                    groupB.push_back(cards[i]);
            }

            // Sort digits in descending order to maximize the number
            sort(groupA.rbegin(), groupA.rend());
            sort(groupB.rbegin(), groupB.rend());

            long long numA = formNumber(groupA);
            long long numB = formNumber(groupB);
            long long product = numA * numB;
            if (product > maxProduct)
            {
                maxProduct = product;
            }
        }

        cout << maxProduct << "\n";
    }

    return 0;
}