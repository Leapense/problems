#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

bool isPrime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

void dfs(int idx, int count, int currentSum, int N, int M, const vector<int> &weights, set<int> &primeSums)
{
    if (count == M)
    {
        if (isPrime(currentSum))
        {
            primeSums.insert(currentSum);
        }
        return;
    }

    if (idx >= N)
        return;

    dfs(idx + 1, count + 1, currentSum + weights[idx], N, M, weights, primeSums);
    dfs(idx + 1, count, currentSum, N, M, weights, primeSums);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> weights(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> weights[i];
    }

    set<int> primeSums;
    dfs(0, 0, 0, N, M, weights, primeSums);

    if (primeSums.empty())
    {
        cout << -1 << "\n";
    }
    else
    {
        for (int sum : primeSums)
            cout << sum << " ";
        cout << "\n";
    }

    return 0;
}