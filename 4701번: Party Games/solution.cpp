#include <bits/stdc++.h>
using namespace std;

string best(const string &A, const string &B)
{
    if (B.rfind(A, 0) == 0)
        return A;
    for (size_t i = 0; i < A.size(); ++i)
    {
        if (A[i] == 'Z')
            continue;
        string t = A.substr(0, i) + char(A[i] + 1);
        if (t < B)
            return t;
    }
    return A;
}

void solve(istream &in, ostream &out)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true)
    {
        int n;
        if (!(in >> n) || n == 0)
            break;
        vector<string> v(n);
        for (auto &s : v)
            in >> s;
        sort(v.begin(), v.end());
        out << best(v[n / 2 - 1], v[n / 2]) << "\n";
    }
}

int main()
{
    solve(cin, cout);

    return 0;
}