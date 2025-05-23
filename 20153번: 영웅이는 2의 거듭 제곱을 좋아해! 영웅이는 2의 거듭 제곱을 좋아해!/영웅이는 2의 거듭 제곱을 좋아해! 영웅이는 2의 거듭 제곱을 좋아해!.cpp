#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    int x = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        x ^= A[i];
    }

    int best = x;
    for (int i = 0; i < N; i++)
    {
        best = max(best, x ^ A[i]);
    }

    string answer = to_string(best);
    cout << answer << answer;

    return 0;
}