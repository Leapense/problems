#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);

    int n;
    cin >> n;
    vector<int> theta(n);

    long long sum = 0;
    for (int &x : theta) {
        cin >> x;
        sum += x;
    }

    long long result = (n - 1) * 180 - 2 * sum;

    cout << result << "\n";

    return 0;
}