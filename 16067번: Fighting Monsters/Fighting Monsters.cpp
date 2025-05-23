#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> monsters(n);
    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < n; i++)
    {
        cin >> monsters[i];
        pos[monsters[i]].push_back(i + 1);
    }
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(1);
    while (true)
    {
        int nxt = fib[fib.size() - 1] + fib[fib.size() - 2];
        if (nxt > 1000000)
            break;
        fib.push_back(nxt);
    }
    for (size_t i = 0; i + 1 < fib.size(); i++)
    {
        int a = fib[i], b = fib[i + 1];
        if (a == b)
        {
            if (pos[a].size() >= 2)
            {
                cout << pos[a][0] << " " << pos[a][1];
                return 0;
            }
        }
        else
        {
            if (pos.count(a) && pos.count(b))
            {
                cout << pos[a][0] << " " << pos[b][0];
                return 0;
            }
        }
    }
    cout << "impossible";
    return 0;
}
