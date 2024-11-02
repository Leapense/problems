#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int t1_score = 0, t2_score = 0;
    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;

    t1_score = a1 + (a2 * 2) + (a3 * 3);
    t2_score = b1 + (b2 * 2) + (b3 * 3);

    if (t1_score > t2_score) cout << "1\n";
    else if (t1_score < t2_score) cout << "2\n";
    else cout << "0\n";

    return 0;
}