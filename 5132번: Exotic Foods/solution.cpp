#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    if (!(cin >> K))
        return 0;

    for (int tc = 1; tc <= K; ++tc)
    {
        int n;
        cin >> n;

        long long take = 0;
        long long leave = 0;

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;

            long long new_take = leave + x;
            long long new_leave = max(take, leave);

            take = new_take;
            leave = new_leave;
        }

        cout << "Data Set " << tc << ":\n"
             << max(take, leave) << "\n\n";
    }

    return 0;
}