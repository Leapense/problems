#include <bits/stdc++.h>
using namespace std;

int count_vowels(const string &s)
{
    int cnt = 0;
    for (char c : s)
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            cnt++;
    return cnt;
}

int main()
{
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        string s;
        cin >> s;
        bool flag = false;
        int N = s.length();
        for (int i = 0; i < N && !flag; i++)
        {
            for (int j = i; j < N && !flag; j++)
            {
                string sub = s.substr(i, j - i + 1);
                int L = sub.length();
                for (int start_len = 1; start_len <= (L - 1) / 2 && !flag; start_len++)
                {
                    int end_len = start_len;
                    int middle_len = L - 2 * start_len;
                    if (middle_len >= 1)
                    {
                        string start = sub.substr(0, start_len);
                        string end = sub.substr(L - end_len, end_len);
                        if (start == end)
                        {
                            int sc_start = count_vowels(start);
                            int sc_middle = count_vowels(sub.substr(start_len, middle_len));
                            if (sc_start >= 2 && sc_middle >= 1)
                            {
                                flag = true;
                            }
                        }
                    }
                }
            }
        }
        cout << "Case #" << tc << ": " << (flag ? "Spell!" : "Nothing.") << '\n';
    }
}