#include <bits/stdc++.h>
using namespace std;

// Returns the minimum number of adjacent swaps to make 's' a palindrome,
// or -1 if it is impossible.
long long minSwapsToMakePalindrome(const string &s)
{
    int n = (int)s.size();
    vector<int> freq(256, 0);
    for (char c : s)
        freq[(unsigned char)c]++;

    int oddCount = 0;
    for (int c = 0; c < 256; c++)
    {
        if (freq[c] % 2 != 0)
            oddCount++;
    }
    // Palindrome feasibility check
    if ((n % 2 == 0 && oddCount != 0) || (n % 2 == 1 && oddCount != 1))
    {
        return -1; // Impossible
    }

    long long swaps = 0;
    vector<char> arr(s.begin(), s.end());
    int left = 0, right = n - 1;

    while (left < right)
    {
        int l = left, r = right;
        // try to match arr[l] with something from the right
        while (arr[l] != arr[r])
            r--;
        if (l == r)
        {
            // We found the 'middle' char in an odd length palindrome
            // swap it towards the middle
            swap(arr[r], arr[r + 1]);
            swaps++;
            continue;
        }
        else
        {
            // bring the matched char to the 'right' position
            for (int i = r; i < right; i++)
            {
                swap(arr[i], arr[i + 1]);
                swaps++;
            }
            left++;
            right--;
        }
    }
    return swaps;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Test inputs (T=10)
    vector<string> inputs = {
        "a",
        "ab",
        "aa",
        "abcba",
        "raccaer",
        "2a2aD",
        "aaaa",
        "aabb",
        "xyz",
        "ab1ba"};

    // Expected outputs for each input
    // (If it's impossible, we use -1 internally to represent it;
    //  in the final output, we will print "Impossible" instead of -1.)
    vector<long long> expected = {
        0,  // a
        -1, // ab -> Impossible
        0,  // aa
        0,  // abcba
        2,  // raccaer
        3,  // 2a2aD
        0,  // aaaa
        2,  // aabb
        -1, // xyz -> Impossible
        0   // ab1ba
    };

    for (int i = 0; i < (int)inputs.size(); i++)
    {
        long long result = minSwapsToMakePalindrome(inputs[i]);
        cout << "Test " << i + 1 << ": Input=\"" << inputs[i] << "\"\n";
        cout << "  Computed = ";
        if (result == -1)
            cout << "Impossible\n";
        else
            cout << result << "\n";

        cout << "  Expected = ";
        if (expected[i] == -1)
            cout << "Impossible\n";
        else
            cout << expected[i] << "\n";

        if (result == expected[i])
            cout << "  => PASS\n\n";
        else
            cout << "  => FAIL\n\n";
    }

    return 0;
}
