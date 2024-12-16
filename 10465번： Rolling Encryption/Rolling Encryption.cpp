#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.size();
    int counts[26] = {0};
    for (int i = 0; i < k && i < n; i++)
        counts[s[i] - 'a']++;
    string result;
    for (int i = 0; i < n; i++)
    {
        if (i < k)
        {
            result += s[i];
        }
        else
        {
            char most_freq = 'a';
            int max_count = counts[0];
            for (int j = 1; j < 26; j++)
            {
                if (counts[j] > max_count || (counts[j] == max_count && ('a' + j) < most_freq))
                {
                    max_count = counts[j];
                    most_freq = 'a' + j;
                }
            }
            int shift = most_freq - 'a' + 1;
            char shifted = 'a' + (s[i] - 'a' + shift) % 26;
            result += shifted;
            counts[s[i - k] - 'a']--;
            counts[s[i] - 'a']++;
        }
    }
    cout << result;
}