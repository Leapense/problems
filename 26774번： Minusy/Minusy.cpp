#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Segment
{
    char ch;
    int cnt;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    vector<Segment> seg;
    seg.push_back({s[0], 1});
    for (int i = 1; i < n; i++)
    {
        if (s[i] == seg.back().ch)
            seg.back().cnt++;
        else
            seg.push_back({s[i], 1});
    }
    int m = seg.size();
    int ans = 0;
    bool hasPlus = false;
    for (auto &p : seg)
    {
        if (p.ch == '+')
        {
            hasPlus = true;
            ans = max(ans, p.cnt);
        }
    }
    if (!hasPlus)
    {
        cout << (n / 2) << "\n";
        return 0;
    }
    vector<int> left_merged(m, 0), right_merged(m, 0);
    for (int i = 0; i < m; i++)
    {
        if (seg[i].ch == '+')
        {
            if (i - 1 >= 0 && seg[i - 1].ch == '-' && seg[i - 1].cnt % 2 == 0)
            {
                int prev = (i - 2 >= 0 ? left_merged[i - 2] : 0);
                left_merged[i] = prev + (seg[i - 1].cnt / 2) + seg[i].cnt;
            }
            else
            {
                left_merged[i] = seg[i].cnt;
            }
            ans = max(ans, left_merged[i]);
        }
    }
    for (int i = m - 1; i >= 0; i--)
    {
        if (seg[i].ch == '+')
        {
            if (i + 1 < m && seg[i + 1].ch == '-' && seg[i + 1].cnt % 2 == 0)
            {
                int nxt = (i + 2 < m ? right_merged[i + 2] : 0);
                right_merged[i] = seg[i].cnt + (seg[i + 1].cnt / 2) + nxt;
            }
            else
            {
                right_merged[i] = seg[i].cnt;
            }
            ans = max(ans, right_merged[i]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (seg[i].ch == '-')
        {
            int conv = seg[i].cnt / 2;
            if (i > 0 && i < m - 1 && seg[i - 1].ch == '+' && seg[i + 1].ch == '+')
            {
                ans = max(ans, max(left_merged[i - 1] + conv, right_merged[i + 1] + conv));
            }
            if (i == 0 && m > 1 && seg[i + 1].ch == '+')
            {
                ans = max(ans, conv + right_merged[i + 1]);
            }
            if (i == m - 1 && m > 1 && seg[i - 1].ch == '+')
            {
                ans = max(ans, left_merged[i - 1] + conv);
            }
            if (m == 1)
            {
                ans = max(ans, conv);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}