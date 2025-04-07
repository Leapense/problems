#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<long long> A(N);
    long long total = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        total += A[i];
    }

    long long T = total / N;

    long long congestion = 0;
    long long prefixDiff = 0;

    for (int i = 0; i < N - 1; i++)
    {
        prefixDiff += (A[i] - T);
        congestion += abs(prefixDiff);
    }

    cout << congestion << "\n";
    return 0;
}