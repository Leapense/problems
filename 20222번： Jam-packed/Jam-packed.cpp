#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;

    ll boxes = (n + k - 1) / k;
    ll m = n / boxes;

    cout << m << endl;

    return 0;
}