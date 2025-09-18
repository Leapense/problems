#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned long long N, M;
    if (!(cin >> N >> M)) return 0;
    unsigned long long g = std::gcd(N, M);
    cout << (N / g) << "/" << (M / g) << "\n";
    return 0;
}