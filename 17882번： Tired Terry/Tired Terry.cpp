#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p, d;
    cin >> n >> p >> d;

    string pattern;
    cin >> pattern;

    vector<int> sleep(n, 0);

    for (int i = 0; i < n; i++)
    {
        sleep[i] = (pattern[i] == 'Z') ? 1 : 0;
    }

    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + sleep[i];
    }

    int tiredCount = 0;

    for (int i = 0; i < n; i++)
    {
        int windowSum;
        int start = i - p + 1;

        if (start >= 0)
        {
            windowSum = prefix[i + 1] - prefix[start];
        }
        else
        {
            int L = start + n;
            windowSum = (prefix[n] - prefix[L]) + prefix[i + 1];
        }

        if (windowSum < d)
        {
            tiredCount++;
        }
    }

    cout << tiredCount << endl;

    return 0;
}