#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> A(N);
    long long total = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        total += A[i];
    }

    if (total % 2 == 1)
    {
        cout << 1;
        return 0;
    }

    long long prefix = 0;

    for (int i = 0; i < N - 1; i++)
    {
        prefix += A[i];

        if (prefix % 2 == 0)
        {
            cout << 1;
            return 0;
        }
    }

    cout << 0;
    return 0;
}