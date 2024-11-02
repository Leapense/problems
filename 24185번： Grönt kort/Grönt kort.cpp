#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin.exceptions(cin.failbit);

    int N, M;
    cin >> N >> M;

    long long T = (M + N - 1) / N + 2;
    if (M == 0 && N % 2 == 1) T++;
    cout << T * 10 << "\n";

    return 0;
}