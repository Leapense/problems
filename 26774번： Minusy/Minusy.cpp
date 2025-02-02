#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;

    vector<pair<char, long long>> st;
    long long ans = 0;

    for (char c : s)
    {
        if (c == '+')
        {
            if (!st.empty() && st.back().first == '+')
            {
                st.back().second++;
            }
            else
            {
                st.push_back({'+', 1});
            }
        }
        else
        {
            if (!st.empty() && st.back().first == '-')
            {
                st.back().second++;
            }
            else
            {
                st.push_back({'-', 1});
            }

            while (!st.empty() && st.back().first == '-' && st.back().second >= 2)
            {
                long long x = st.back().second;
                st.pop_back();
                long long plusCount = x / 2;
                long long leftover = x % 2;
                if (plusCount > 0)
                {
                    if (!st.empty() && st.back().first == '+')
                    {
                        st.back().second += plusCount;
                    }
                    else
                    {
                        st.push_back({'+', plusCount});
                    }
                }

                if (leftover == 1)
                {
                    if (!st.empty() && st.back().first == '-')
                    {
                        st.back().second++;
                    }
                    else
                    {
                        st.push_back({'-', 1});
                    }
                }
            }
        }
    }

    for (auto &p : st)
    {
        if (p.first == '+')
        {
            ans = max(ans, p.second);
        }
    }

    cout << ans << "\n";

    return 0;
}