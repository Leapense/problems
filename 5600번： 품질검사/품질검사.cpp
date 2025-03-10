#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    int total = a + b + c;
    vector<int> state(total + 1, -1);

    int N;
    cin >> N;

    struct Test
    {
        int x, y, z, r;
    };
    vector<Test> tests;

    for (int i = 0; i < N; i++)
    {
        int x, y, z, r;
        cin >> x >> y >> z >> r;
        tests.push_back({x, y, z, r});
    }

    for (auto &t : tests)
    {
        if (t.r == 1)
        {
            state[t.x] = 1;
            state[t.y] = 1;
            state[t.z] = 1;
        }
    }

    bool updated = true;
    while (updated)
    {
        updated = false;
        for (auto &t : tests)
        {
            if (t.r == 0)
            {
                int cntGood = 0;
                if (state[t.x] == 1)
                    cntGood++;
                if (state[t.y] == 1)
                    cntGood++;
                if (state[t.z] == 1)
                    cntGood++;
                if (cntGood == 2)
                {
                    if (state[t.x] != 1 && state[t.x] != 0)
                    {
                        state[t.x] = 0;
                        updated = true;
                    }
                    if (state[t.y] != 1 && state[t.y] != 0)
                    {
                        state[t.y] = 0;
                        updated = true;
                    }
                    if (state[t.z] != 1 && state[t.z] != 0)
                    {
                        state[t.z] = 0;
                        updated = true;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= total; i++)
    {
        if (state[i] == -1)
            cout << 2 << "\n";
        else
            cout << state[i] << "\n";
    }

    return 0;
}