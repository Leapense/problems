#include <bits/stdc++.h>
using namespace std;

int n, nstar, nbang;
int caseCount = 0;

void backtrack(string &current, int length, int cstar, int cbang)
{
    if ((int)current.size() == length)
    {
        cout << current << "\n";
        return;
    }
    if (cstar < nstar)
    {
        current.push_back('*');
        backtrack(current, length, cstar + 1, 0);
        current.pop_back();
    }
    if (cbang < nbang)
    {
        current.push_back('!');
        backtrack(current, length, 0, cbang + 1);
        current.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        cin >> n >> nstar >> nbang;
        if (!cin || (n == 0 && nstar == 0 && nbang == 0))
            break;
        cout << "Sequence set " << ++caseCount << "\n";
        string s;
        backtrack(s, n, 0, 0);
    }

    return 0;
}