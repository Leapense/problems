#include "main.h"
#include <iostream>
#include <vector>

using namespace std;

int oddGCDMatching(const vector<int> &A)
{
    int oddCount = 0, evenCount = 0;
    for (int num : A)
    {
        if (num % 2 == 0)
            ++evenCount;
        else
            ++oddCount;
    }

    if (oddCount < evenCount)
        return oddCount;
    else
        return evenCount + (oddCount - evenCount) / 2;
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    cout << oddGCDMatching(A);
    return 0;
}
#endif