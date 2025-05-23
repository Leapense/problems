#include <iostream>
#include <string>
#include <numeric>

using namespace std;

bool check(const string &str, const string &candidate)
{
    int lenStr = str.size(), lenCandidate = candidate.size();
    if (lenStr % lenCandidate != 0)
        return false;

    for (int i = 0; i < lenStr; i++)
    {
        if (str[i] != candidate[i % lenCandidate])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int g = gcd(s.size(), t.size());

    string candidate = s.substr(0, g);

    if (check(s, candidate) && check(t, candidate))
        cout << candidate;
    else
        cout << "NO";

    return 0;
}