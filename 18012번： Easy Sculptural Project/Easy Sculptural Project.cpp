#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string s;
        cin >> s;

        int pairs = 0, cnt = 0;

        for (char c : s)
        {
            if (c == 'o')
                cnt++;
            else if (cnt > 0)
            {
                pairs++;
                cnt--;
            }
        }

        int valid = 2 * pairs;
        cout << "Data Set " << i << ":\n"
             << s.size() - valid << "\n\n";
    }

    return 0;
}