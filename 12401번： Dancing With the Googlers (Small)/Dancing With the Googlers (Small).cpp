#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int N, S, p;
        cin >> N >> S >> p;
        vector<int> totals(N);

        for (int i = 0; i < N; i++)
        {
            cin >> totals[i];
        }

        int result = 0;
        int surpriseLeft = S;
        for (int t : totals)
        {
            int nonSurpriseBest = (t + 2) / 3;
            if (nonSurpriseBest >= p)
            {
                result++;
            }
            else if (surpriseLeft > 0 && t >= 2)
            {
                int surpriseBest = (t + 4) / 3;
                if (surpriseBest >= p)
                {
                    result++;
                    surpriseLeft--;
                }
            }
        }

        cout << "Case #" << tc << ": " << result << "\n";
    }

    return 0;
}