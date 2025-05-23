#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    int maxVal = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
    }
    vector<int> freq(maxVal + 1, 0);
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    vector<int> pref(maxVal + 1, 0);
    for (int m = 1; m <= maxVal; m++)
    {
        pref[m] = pref[m - 1] + freq[m];
    }
    int ans = n;
    for (int m = 0; m <= maxVal; m++)
    {
        int cost = m + (n - pref[m]);
        ans = min(ans, cost);
    }
    cout << ans << "\n";
    return 0;
}
