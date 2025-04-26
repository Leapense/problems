#include <bits/stdc++.h>
using namespace std;
struct P
{
    long long x, y;
    int id;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    vector<P> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].x >> v[i].y;
        v[i].id = i + 1;
    }
    sort(v.begin(), v.end(), [](const P &a, const P &b)
         {
        if(a.x!=b.x) return a.x<b.x;
        return a.y<b.y; });
    for (int i = 0; i < n - 1; ++i)
        cout << v[i].id << ' ' << v[i + 1].id << '\n';
    return 0;
}