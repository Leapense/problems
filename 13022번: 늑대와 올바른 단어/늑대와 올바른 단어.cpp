#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int i = 0, n = s.size();
    while (i < n)
    {
        if (s[i] != 'w')
        {
            cout << 0;
            return 0;
        }

        int cnt = 0;
        while (i < n && s[i] == 'w')
        {
            cnt++;
            i++;
        }

        for (char ch : {'o', 'l', 'f'})
        {
            for (int j = 0; j < cnt; j++)
            {
                if (i >= n || s[i] != ch)
                {
                    cout << 0;
                    return 0;
                }
                i++;
            }
        }
    }

    cout << 1;
    return 0;
}