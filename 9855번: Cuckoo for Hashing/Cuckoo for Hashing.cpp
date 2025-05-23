#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n1, n2, m;
    int case_num = 1;

    while (cin >> n1 >> n2 >> m)
    {
        if (n1 == 0 && n2 == 0 && m == 0)
            break;
        vector<int> T1(n1, -1);
        vector<int> T2(n2, -1);

        vector<int> inserts(m);
        for (auto &x : inserts)
            cin >> x;

        for (auto x : inserts)
        {
            int current = x;
            bool inT1 = true;

            while (true)
            {
                if (inT1)
                {
                    int pos = current % n1;
                    if (T1[pos] == -1)
                    {
                        T1[pos] = current;
                        break;
                    }
                    else
                    {
                        swap(current, T1[pos]);
                        inT1 = false;
                    }
                }
                else
                {
                    int pos = current % n2;
                    if (T2[pos] == -1)
                    {
                        T2[pos] = current;
                        break;
                    }
                    else
                    {
                        swap(current, T2[pos]);
                        inT1 = true;
                    }
                }
            }
        }

        cout << "Case " << case_num++ << ":\n";

        bool hasT1 = false;
        for (auto val : T1) {
            if (val != -1) {
                hasT1 = true;
                break;
            }
        }

        if (hasT1)
        {
            cout << "Table 1\n";
            for (int i = 0; i < n1; ++i)
            {
                if (T1[i] != -1) {
                    cout << i << ":" << T1[i] << "\n";
                }
            }
        }

        bool hasT2 = false;
        for (auto val : T2) {
            if (val != -1) {
                hasT2 = true;
                break;
            }
        }

        if (hasT2) {
            cout << "Table 2\n";
            for (int i = 0; i < n2; ++i) {
                if (T2[i] != -1) {
                    cout << i << ":" << T2[i] << "\n";
                }
            }
        }
    }

    return 0;
}