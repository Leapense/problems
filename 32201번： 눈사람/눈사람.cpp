#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N), B(N);
    unordered_map<int, int> initialRank;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        initialRank[A[i]] = i + 1;
    }

    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    int maxIncrease = -1e9;
    vector<int> improvements(N);

    for (int i = 0; i < N; i++)
    {
        int initPos = initialRank[B[i]];
        int finalPos = i + 1;
        improvements[i] = initPos - finalPos;
        if (improvements[i] > maxIncrease)
        {
            maxIncrease = improvements[i];
        }
    }

    bool first = true;
    for (int i = 0; i < N; i++)
    {
        if (improvements[i] == maxIncrease)
        {
            if (!first)
                cout << " ";
            cout << B[i];
            first = false;
        }
    }

    cout << "\n";

    return 0;
}