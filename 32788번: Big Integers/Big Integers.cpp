#include <iostream>
#include <string>
using namespace std;

int charValue(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    return c - 'A' + 36;
}

bool isSmallerNumeric(const string &s1, const string &s2)
{
    if (s1.size() != s2.size())
        return s1.size() < s2.size();

    for (size_t i = 0; i < s1.size(); i++)
    {
        int v1 = charValue(s1[i]);
        int v2 = charValue(s2[i]);
        if (v1 != v2)
            return v1 < v2;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        string candidate = (s1 < s2) ? s1 : s2;
        string numericMin = isSmallerNumeric(s1, s2) ? s1 : s2;

        cout << ((candidate == numericMin) ? "YES" : "NO") << "\n";
    }

    return 0;
}