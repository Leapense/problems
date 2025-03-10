/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8587                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8587                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 11:04:25 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll ans = 1;
    for (int i = 1; i <= n; i++)
    {
        int cnt = n - (lower_bound(a.begin(), a.end(), i) - a.begin());
        int available = cnt - (n - i);
        if (available <= 0)
        {
            cout << 0;
            return 0;
        }

        ans = (ans * available) % MOD;
    }

    cout << ans;

    return 0;
}