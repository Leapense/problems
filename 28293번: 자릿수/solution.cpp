#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;

    long double result = b * log10((long double)a);
    long long digits = (long long)floor(result) + 1;

    cout << digits << "\n";
    return 0;
}