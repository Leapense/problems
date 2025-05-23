#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int MAX_WEIGHT = 200000;
    vector<int> freq(MAX_WEIGHT + 2, 0);
    vector<int> weights(n);
    long long totalSum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
        totalSum += weights[i];
        freq[weights[i]]++;
    }

    long long prefixSum = 0;

    for (int t = 1; t <= MAX_WEIGHT + 1; t++)
    {
        long long sumLess = prefixSum;
        long long sumEqual = (long long)freq[t] * t;
        long long sumGreater = totalSum - prefixSum - sumEqual;

        if (sumLess == sumGreater)
        {
            cout << t << "\n";
            return 0;
        }

        if (t <= MAX_WEIGHT)
        {
            prefixSum += (long long)freq[t] * t;
        }
    }

    return 0;
}