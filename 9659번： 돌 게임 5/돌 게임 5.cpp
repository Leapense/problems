#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    if (N % 2 == 1) {
        cout << "SK";
    } else {
        cout << "CY";
    }

    return 0;
}