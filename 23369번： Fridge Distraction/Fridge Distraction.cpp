#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    vector<char> order;

    for (int i = 0; i < n; i++)
        order.push_back('a' + i);

    int acc = 0;
    vector<char> seq;

    while (acc < t)
    {
        int remaining = t - acc;
        int pos = -1;
        char chosen = 'a';
        for (int i = n - 1; i >= 0; i--)
        {
            if ((i + 1) <= remaining)
            {
                pos = i + 1;
                chosen = order[i];
                break;
            }
        }
        if (pos == -1)
        {
            cout << 0 << endl
                 << endl;
            return 0;
        }
        acc += pos;
        seq.push_back(chosen);
        auto it = find(order.begin(), order.end(), chosen);

        if (it != order.end())
        {
            order.erase(it);
            order.insert(order.begin(), chosen);
        }
    }

    cout << seq.size() << endl;
    for (int i = 0; i < seq.size(); i++)
        cout << seq[i] << (i < seq.size() - 1 ? " " : "\n");

    return 0;
}