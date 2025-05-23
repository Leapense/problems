#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long K;
    cin >> n >> K;

    vector<long long> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int j = n - 1;
    while (j > 0 && (a[j] - a[j - 1]) <= K)
        j--;

    cout << n - j << "\n";
    return 0;
}