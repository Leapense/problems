#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int K;
        double R;
        cin >> K >> R;

        if (K == 0 && R == 0.0)
            break;
        vector<int> nums;
        for (int i = 0; i < K; i++)
        {
            int N, M;
            cin >> N >> M;
            nums.push_back(N);
        }

        sort(nums.begin(), nums.end());
        int sections = 0;
        int i = 0;
        while (i < K)
        {
            int start = i;
            while (i < K && nums[i] <= (double)nums[start] * R)
            {
                i++;
            }
            sections++;
        }

        cout << sections << "\n";
    }

    return 0;
}