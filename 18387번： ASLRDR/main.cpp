#include <bits/stdc++.h>
using namespace std;

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

        vector<int> freq(256, 0);
        for (char c : s)
            freq[(unsigned char)c]++;

        int oddCount = 0;

        for (int c = 0; c < 256; c++)
        {
            if (freq[c] % 2 != 0)
                oddCount++;
        }

        if ((n % 2 == 0 && oddCount != 0) || (n % 2 == 1 && oddCount != 1))
        {
            cout << "Impossible\n";
            continue;
        }

        long long swaps = 0;

        vector<char> arr(s.begin(), s.end());
        int left = 0, right = n - 1;

        while (left < right)
        {
            int l = left, r = right;
            while (arr[l] != arr[r])
                r--;
            if (l == r)
            {
                swap(arr[r], arr[r + 1]);
                swaps++;
                continue;
            }
            else
            {
                for (int i = r; i < right; i++)
                {
                    swap(arr[i], arr[i + 1]);
                    swaps++;
                }
                left++;
                right--;
            }
        }
        cout << swaps << "\n";
    }

    return 0;
}