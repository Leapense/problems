#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    while (k--)
    {
        string S;
        int N;
        cin >> S >> N;
        unordered_set<char> unique;
        for (char c : S)
            unique.insert(c);
        unordered_set<char> found;
        int misses = 0;
        for (int i = 0; i < N; i++)
        {
            char g;
            cin >> g;
            if (found.size() == unique.size())
                continue;
            if (unique.count(g))
            {
                if (!found.count(g))
                {
                    found.insert(g);
                    if (found.size() == unique.size())
                        break;
                }
            }
            else
            {
                misses++;
                if (misses == 9)
                    break;
            }
        }
        cout << S << "\n";
        if (misses == 0)
        {
            cout << "SAFE\n\n";
            continue;
        }
        if (misses >= 1)
            cout << "  O" << "\n";
        if (misses >= 2)
        {
            string line2 = "";
            if (misses >= 2)
                line2.push_back('+');
            if (misses >= 3)
                line2.push_back('=');
            if (misses >= 4)
                line2.push_back('|');
            if (misses >= 5)
                line2.push_back('=');
            if (misses >= 6)
                line2.push_back('+');
            cout << line2 << "\n";
        }
        if (misses >= 7)
            cout << "  |" << "\n";
        if (misses >= 8)
        {
            string line4 = " ";
            line4.push_back('/');
            if (misses >= 9)
            {
                line4.push_back(' ');
                line4.push_back('\\');
            }
            cout << line4 << "\n";
        }
        cout << "\n";
    }
    return 0;
}