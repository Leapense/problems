#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        string S;
        cin >> S;

        string ans = "";
        ans.push_back(S[0]);

        for (size_t i = 1; i < S.size(); i++)
        {
            if (S[i] >= ans[0])
            {
                ans.insert(ans.begin(), S[i]);
            }
            else
            {
                ans.push_back(S[i]);
            }
        }

        cout << "Case #" << t << ": " << ans;
        if (t != T)
            cout << "\n";
    }

    return 0;
}