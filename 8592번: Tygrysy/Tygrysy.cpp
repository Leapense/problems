/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8592                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8592                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 11:27:56 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
struct Tiger
{
    ll r;
    ll k;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Tiger> tigers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tigers[i].r >> tigers[i].k;
    }
    sort(tigers.begin(), tigers.end(), [](const Tiger &a, const Tiger &b)
         { return a.r > b.r; });
    multiset<double> enclosures;
    for (auto &t : tigers)
    {
        double r = (double)t.r;
        double newThresh = r / t.k;
        auto it = enclosures.lower_bound(r);
        if (it == enclosures.begin())
        {
            enclosures.insert(newThresh);
        }
        else
        {
            it--;
            double cur = *it;
            enclosures.erase(it);
            double updated = max(cur, newThresh);
            enclosures.insert(updated);
        }
    }
    cout << enclosures.size() << "\n";
    return 0;
}
