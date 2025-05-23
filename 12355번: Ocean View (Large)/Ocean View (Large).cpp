#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int N;
        cin >> N;
        vector<int> houses(N);
        for (int i = 0; i < N; i++)
        {
            cin >> houses[i];
        }

        vector<int> lis;
        for (int h : houses)
        {
            auto it = lower_bound(lis.begin(), lis.end(), h);
            if (it == lis.end())
            {
                lis.push_back(h);
            }
            else
            {
                *it = h;
            }
        }

        int answer = N - (int)lis.size();
        cout << "Case #" << tc << ": " << answer;
        if (tc < T)
            cout << "\n";
    }

    return 0;
}