#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> s(n);
    for (auto &x : s)
        cin >> x;
    int total = accumulate(s.begin(), s.end(), 0);
    for (int i = 0; i < n; i++)
    {
        bool ok = true;
        for (int j = 0; j < n; j++)
            if (j != i && s[i] < s[j])
            {
                ok = false;
                break;
            }
        if (ok)
        {
            int sum = total - s[i];
            if (s[i] <= sum)
            {
                vector<int> order;
                order.push_back(i + 1);
                for (int j = 0; j < n; j++)
                    if (j != i)
                        order.push_back(j + 1);
                for (int k = 0; k < order.size(); k++)
                    cout << order[k] << (k < order.size() - 1 ? " " : "\n");
                return 0;
            }
        }
    }
    cout << "impossible\n";

    return 0;
}