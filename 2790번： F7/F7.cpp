#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> B(N);

    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    vector<long long> b = B;
    sort(b.begin(), b.end(), greater<long long>());

    vector<long long> A(N);
    for (int k = 0; k < N; k++)
    {
        A[k] = b[k] + (k + 1);
    }

    vector<long long> prefixMaxA(N), suffixMaxA(N);
    prefixMaxA[0] = A[0];

    for (int i = 1; i < N; i++)
    {
        prefixMaxA[i] = max(prefixMaxA[i - 1], A[i]);
    }

    suffixMaxA[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        suffixMaxA[i] = max(suffixMaxA[i + 1], A[i]);
    }

    vector<bool> hamperPossible(N, true);
    for (int k = 0; k < N; k++)
    {
        long long leftCond = true;
        if (k > 0)
        {
            long long lhs = prefixMaxA[k - 1];
            long long rhs = b[k] + N;
            if (lhs > rhs)
                leftCond = false;
        }

        long long rightCond = true;
        if (k < N - 1)
        {
            long long lhs = suffixMaxA[k + 1];
            long long rhs = b[k] + (N + 1);
            if (lhs > rhs)
                rightCond = false;
        }
        hamperPossible[k] = (leftCond && rightCond);
    }

    unordered_set<long long> possibleScores;
    possibleScores.reserve(N);

    for (int k = 0; k < N; k++)
    {
        if (hamperPossible[k])
        {
            possibleScores.insert(b[k]);
        }
    }

    long long answer = 0;
    for (long long score : B)
    {
        if (possibleScores.count(score))
        {
            answer++;
        }
    }

    cout << answer << "\n";

    return 0;
}