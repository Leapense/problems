#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> split(const string &s, char d)
{
    vector<string> r;
    size_t i = 0, j;
    while ((j = s.find(d, i)) != string::npos)
    {
        r.push_back(s.substr(i, j - i));
        i = j + 1;
    }
    r.push_back(s.substr(i));
    return r;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true)
    {
        string s1;
        if (!getline(cin, s1))
            break;
        if (s1 == ".")
            break;
        string s2;
        getline(cin, s2);
        vector<string> t1 = split(s1, '\"'), t2 = split(s2, '\"');
        if (t1.size() != t2.size())
        {
            cout << "DIFFERENT\n";
            continue;
        }
        bool ok = true;
        int diffCount = 0;
        for (size_t i = 0; i < t1.size(); i++)
        {
            if (i % 2 == 0)
            {
                if (t1[i] != t2[i])
                {
                    ok = false;
                    break;
                }
            }
            else
            {
                if (t1[i] != t2[i])
                    diffCount++;
            }
        }
        if (!ok)
            cout << "DIFFERENT\n";
        else if (diffCount == 0)
            cout << "IDENTICAL\n";
        else if (diffCount == 1)
            cout << "CLOSE\n";
        else
            cout << "DIFFERENT\n";
    }
    return 0;
}