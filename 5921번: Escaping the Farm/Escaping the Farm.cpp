#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> weights(N);
    for (int i = 0; i < N; i++)
    {
        cin >> weights[i];
    }

    int maxCount = 0;
    int totalSubsets = 1 << N;
    for (int mask = 1; mask < totalSubsets; mask++)
    {
        int count = 0;
        int carryOccurred = 0;
        vector<int> digitSum(12, 0);
        for (int i = 0; i < N; i++)
        {
            if (mask & (1 << i))
            {
                count++;
                int num = weights[i];
                int pos = 0;
                while (num > 0)
                {
                    digitSum[pos] += num % 10;
                    num /= 10;
                    pos++;
                }
            }
        }

        for (int sum : digitSum)
        {
            if (sum >= 10)
            {
                carryOccurred = 1;
                break;
            }
        }
        if (!carryOccurred)
        {
            maxCount = max(maxCount, count);
        }
    }

    cout << maxCount;

    return 0;
}