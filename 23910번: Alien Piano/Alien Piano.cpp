#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int K;
        cin >> K;

        vector<int> A(K);
        for (auto &x : A)
            cin >> x;

        vector<int> prev_cost(5, 0);
        for (int i = 1; i < K; i++)
        {
            vector<int> curr_cost(5, INT32_MAX);
            for (int k = 1; k <= 4; k++)
            {
                for (int kp = 1; kp <= 4; kp++)
                {
                    int cost = prev_cost[kp];
                    if (A[i] > A[i - 1])
                    {
                        if (k <= kp)
                            cost += 1;
                    }
                    else if (A[i] < A[i - 1])
                    {
                        if (k >= kp)
                            cost += 1;
                    }
                    else
                    {
                        if (k != kp)
                            cost += 1;
                    }

                    curr_cost[k] = min(curr_cost[k], cost);
                }
            }

            prev_cost = curr_cost;
        }

        int res;

        if (K == 1)
        {
            res = 0;
        }
        else
        {
            res = *min_element(prev_cost.begin() + 1, prev_cost.end());
        }

        cout << "Case #" << tc << ": " << res << "\n";
    }

    return 0;
}