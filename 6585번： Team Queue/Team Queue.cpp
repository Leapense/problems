#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    int scenario = 1;

    while (cin >> t)
    {
        if (t == 0)
            break;
        unordered_map<int, int> teamOf;
        for (int i = 0; i < t; i++)
        {
            int n;
            cin >> n;
            while (n--)
            {
                int x;
                cin >> x;
                teamOf[x] = i;
            }
        }
        queue<int> teamQueue;
        vector<queue<int>> teamMembers(t);
        vector<bool> inQueue(t, false);
        cout << "Scenario #" << scenario++ << "\n";

        string cmd;

        while (cin >> cmd)
        {
            if (cmd == "STOP")
                break;
            if (cmd == "ENQUEUE")
            {
                int x;
                cin >> x;
                int team = teamOf[x];
                if (!inQueue[team])
                {
                    teamQueue.push(team);
                    inQueue[team] = true;
                }
                teamMembers[team].push(x);
            }
            else if (cmd == "DEQUEUE")
            {
                int team = teamQueue.front();
                cout << teamMembers[team].front() << "\n";
                teamMembers[team].pop();
                if (teamMembers[team].empty())
                {
                    teamQueue.pop();
                    inQueue[team] = false;
                }
            }
        }
        cout << "\n";
    }

    return 0;
}