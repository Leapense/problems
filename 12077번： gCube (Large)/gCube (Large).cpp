#include <bits/stdc++.h>
using namespace std;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    fastIO();

    int T;
    cin >> T;

    for (int caseNum = 1; caseNum <= T; ++caseNum)
    {
        int N, M;
        cin >> N >> M;

        vector<double> dimensions(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> dimensions[i];
        }

        vector<double> logPrefixSum(N + 1, 0.0);
        for (int i = 0; i < N; ++i)
        {
            logPrefixSum[i + 1] = logPrefixSum[i] + log(dimensions[i]);
        }

        cout << fixed << setprecision(9);
        cout << "Case #" << caseNum << ":\n";

        for (int i = 0; i < M; ++i)
        {
            int L, R;
            cin >> L >> R;

            int D = R - L + 1;
            double sumLogs = logPrefixSum[R + 1] - logPrefixSum[L];

            double edgeLength = exp(sumLogs / D);
            cout << edgeLength << "\n";
        }
    }

    return 0;
}