#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    vector<pair<char, int>> seg;
    int n = s.size();
    int i = 0;
    while (i < n)
    {
        char cur = s[i];
        int cnt = 0;
        while (i < n && s[i] == cur)
        {
            cnt++;
            i++;
        }
        seg.push_back({cur, cnt});
    }
    vector<int> runs;
    vector<int> oddGaps;
    int curr = 0;
    if (!seg.empty())
    {
        if (seg[0].first == '+')
            curr = seg[0].second;
        else
        {
            if (seg[0].second % 2 == 0)
                curr = seg[0].second / 2;
            else
                curr = 0;
        }
    }
    for (int j = 1; j < seg.size(); j++)
    {
        if (seg[j].first == '+')
        {
            curr += seg[j].second;
        }
        else
        {
            if (seg[j].second % 2 == 0)
            {
                curr += seg[j].second / 2;
            }
            else
            {
                runs.push_back(curr);
                oddGaps.push_back(seg[j].second);
                curr = 0;
            }
        }
    }
    runs.push_back(curr);
    int ans = 0;
    for (int r : runs)
        ans = max(ans, r);
    for (int k = 0; k < oddGaps.size(); k++)
    {
        int gapVal = oddGaps[k] / 2;
        int cand = 0;
        if (k < runs.size() && k + 1 < runs.size())
        {
            cand = max(runs[k] + gapVal, gapVal + runs[k + 1]);
        }
        ans = max(ans, cand);
    }
    cout << ans;
    return 0;
}