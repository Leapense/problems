#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> forward(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> forward[i];

    vector<int> status(N + 1, -1);
    for (int i = 1; i <= N; i++)
    {
        if (status[i] != -1)
            continue;
        vector<int> path;
        int cur = i;
        while (true)
        {
            if (cur == 0)
            {
                for (int v : path)
                {
                    status[v] = 0;
                }
                break;
            }

            if (status[cur] != -1)
            {
                int val = status[cur];
                for (int v : path)
                {
                    status[v] = val;
                }

                break;
            }

            bool found = false;
            for (int v : path)
            {
                if (v == cur)
                {
                    found = true;
                    break;
                }
            }

            if (found)
            {
                for (int v : path)
                {
                    status[v] = 1;
                }

                break;
            }

            path.push_back(cur);
            cur = forward[cur];
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (status[i] == 0)
            ans++;
    }

    cout << ans;
    return 0;
}