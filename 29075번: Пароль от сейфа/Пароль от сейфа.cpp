#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool isPalindrome(const string &s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();

    if (isPalindrome(s))
    {
        cout << "YES";
        return 0;
    }

    int mismatchCount = 0;

    unordered_set<int> candidates;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            mismatchCount++;
            candidates.insert(i);
            candidates.insert(n - 1 - i);
        }
    }

    if (mismatchCount > 2)
    {
        cout << "NO";
        return 0;
    }

    if (n % 2 == 1)
    {
        candidates.insert(n / 2);
    }

    vector<int> cand(candidates.begin(), candidates.end());
    for (int i = 0; i < (int)cand.size(); i++)
    {
        for (int j = i + 1; j < (int)cand.size(); j++)
        {
            string t = s;
            swap(t[cand[i]], t[cand[j]]);
            if (isPalindrome(t))
            {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
    return 0;
}