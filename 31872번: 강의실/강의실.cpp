#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<long long> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    long long total = A[N - 1];

    vector<long long> gaps;

    gaps.push_back(A[0] - 0);

    for (int i = 1; i < N; i++)
    {
        gaps.push_back(A[i] - A[i - 1]);
    }

    sort(gaps.begin(), gaps.end(), greater<long long>());

    for (int i = 0; i < K && i < gaps.size(); i++)
    {
        total -= gaps[i];
    }

    if (total < 0)
    {
        total = 0;
    }

    cout << total << "\n";

    return 0;
}