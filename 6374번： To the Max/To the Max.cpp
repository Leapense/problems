#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    vector<vector<int>> arr(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    int maxSum = -127 * 100 * 100;

    for (int start = 0; start < N; start++)
    {
        vector<int> temp(N, 0);
        for (int end = start; end < N; end++)
        {
            for (int k = 0; k < N; k++)
            {
                temp[k] += arr[end][k];
            }

            int currentMax = temp[0];
            int currentSum = temp[0];

            for (int k = 1; k < N; k++)
            {
                currentSum = max(temp[k], currentSum + temp[k]);
                currentMax = max(currentMax, currentSum);
            }
            maxSum = max(maxSum, currentMax);
        }
    }

    cout << maxSum << "\n";

    return 0;
}