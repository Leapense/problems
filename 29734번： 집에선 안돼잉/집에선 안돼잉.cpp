#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N, M, T, S, Zip, Dok;

    cin >> N >> M >> T >> S;

    Zip = N + (N - 1) / 8 * S;
    Dok = T + M + (M - 1) / 8 * (2 * T + S);

    if (Zip < Dok) cout << "Zip\n" << Zip;
    else cout << "Dok\n" << Dok;

    return 0;
}