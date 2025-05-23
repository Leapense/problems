#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    int k = min(n, 10);

    vector<long long> candidates;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (i == j)
                continue;
            string s = to_string(nums[i]) + to_string(nums[j]);
            candidates.push_back(stoll(s));
        }
    }

    sort(candidates.begin(), candidates.end());
    cout << candidates[2] << "\n";

    return 0;
}