#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;

    while (getline(cin, line))
    {
        if (line == "0")
            break;
        stringstream ss(line);

        int n;
        char colon;

        ss >> n >> colon;
        vector<int> perm(n);
        for (int i = 0; i < n; i++)
            ss >> perm[i];

        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[perm[i]] = i;

        bool anti = true;
        for (int j = 0; j < n && anti; j++)
        {
            for (int i = 0; i < j && anti; i++)
            {
                int candidate = 2 * perm[j] - perm[i];
                if (candidate < 0 || candidate >= n)
                    continue;
                if (pos[candidate] > j)
                {
                    anti = false;
                    break;
                }
            }
        }

        cout << (anti ? "yes" : "no") << "\n";
    }

    return 0;
}