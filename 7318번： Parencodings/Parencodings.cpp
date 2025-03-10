#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> P(n);
        for (int i = 0; i < n; i++)
        {
            cin >> P[i];
        }

        int len = 2 * n;
        vector<char> S(len + 1, '(');
        vector<int> order(len + 1, 0);
        vector<int> pos(n);

        for (int i = 0; i < n; i++)
        {
            int r = P[i] + i + 1;
            pos[i] = r;
            S[r] = ')';
            order[r] = i + 1;
        }

        vector<int> cum(len + 1, 0);
        for (int i = 1; i <= len; i++)
        {
            cum[i] = cum[i - 1] + (S[i] == ')');
        }

        vector<int> W(n + 1, 0);
        stack<int> st;
        for (int i = 1; i <= len; i++)
        {
            if (S[i] == '(')
            {
                st.push(i);
            }
            else
            {
                int l = st.top();
                st.pop();
                int ord = order[i];
                W[ord] = cum[i] - cum[l - 1];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << W[i] << (i == n ? "\n" : " ");
        }
    }

    return 0;
}