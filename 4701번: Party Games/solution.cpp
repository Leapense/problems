#include <bits/stdc++.h>
using namespace std;

string separator(const string &A, const string &B)
{
    if (B.rfind(A, 0) == 0)
        return A;
    size_t i = 0;
    while (i < A.size() && i < B.size() && A[i] == B[i])
        ++i;
    string prefix = A.substr(0, i);
    char a = A[i], b = B[i];
    if (a + 1 < b)
    {
        string res = prefix;
        res.push_back(a + 1);
        return res;
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
        vector<string> names(n);

        for (auto &s : names)
            in >> s;
        sort(names.begin(), names.end());

        string A = names[n / 2 - 1], B = names[n / 2];
        out << separator(A, B) << '\n';
    }
}

int main()
{
    solve(cin, cout);
    return 0;
}