#include <iostream>
#include <string>
#include <tuple>
#include <limits>

using namespace std;

tuple<int, int, int> kadane(const string &s, bool redDominant)
{
    int bestSum = -numeric_limits<int>::max();
    int bestL = 0, bestR = 0;
    int currSum = 0;
    int currL = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int val = 0;
        if (redDominant)
        {
            val = (s[i] == 'R' ? 1 : -1);
        }
        else
        {
            val = (s[i] == 'B' ? 1 : -1);
        }

        if (currSum + val < val)
        {
            currSum = val;
            currL = i;
        }
        else
        {
            currSum += val;
        }

        if (currSum > bestSum || (currSum == bestSum && (currL < bestL || (currL == bestL && i < bestR))))
        {
            bestSum = currSum;
            bestL = currL;
            bestR = i;
        }
    }

    return {bestSum, bestL, bestR};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;

    auto [redSum, redL, redR] = kadane(s, true);
    auto [blueSum, blueL, blueR] = kadane(s, false);

    if (redSum > blueSum)
    {
        cout << redL + 1 << " " << redR + 1;
    }
    else if (blueSum > redSum)
    {
        cout << blueL + 1 << " " << blueR + 1;
    }
    else
    {
        if (redL < blueL || (redL == blueL && redR < blueR))
        {
            cout << redL + 1 << " " << redR + 1;
        }
        else
        {
            cout << blueL + 1 << " " << blueR + 1;
        }
    }

    return 0;
}