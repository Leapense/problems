#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<unsigned int> train(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int t, x;
            cin >> t >> x;
            train[t] |= (1u << (x - 1));
        }
        else if (op == 2)
        {
            int t, x;
            cin >> t >> x;
            train[t] &= ~(1u << (x - 1));
        }
        else if (op == 3)
        {
            int t;
            cin >> t;
            train[t] = (train[t] << 1) & ((1u << 20) - 1);
        }
        else if (op == 4)
        {
            int t;
            cin >> t;
            train[t] >>= 1;
        }
    }

    set<unsigned int> states;
    for (int i = 1; i <= n; i++)
    {
        states.insert(train[i]);
    }

    cout << states.size() << "\n";
    return 0;
}