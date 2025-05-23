#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll count_C = 0, count_CO = 0, count_COW = 0;
    for (char c : S)
    {
        if (c == 'C')
            count_C++;
        else if (c == 'O')
            count_CO += count_C;
        else if (c == 'W')
            count_COW += count_CO;
    }
    cout << count_COW;

    return 0;
}