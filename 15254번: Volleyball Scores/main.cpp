#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int K;
    cin >> K;
    for (int ds = 1; ds <= K; ds++)
    {
        int t;
        cin >> t;
        vector<string> seq(t);
        for (int i = 0; i < t; i++)
        {
            cin >> seq[i];
        }
        int scoreA = 0, scoreB = 0;
        int idx = 0;
        int expectedServeTeam = -1;
        bool wrongServe = false;
        while (idx < t)
        {
            if (seq[idx] == "A" || seq[idx] == "B" || seq[idx] == "X")
                break;
            int servePlayer = stoi(seq[idx]);
            int serveTeam = (servePlayer <= 6 ? 0 : 1);
            if (expectedServeTeam != -1 && serveTeam != expectedServeTeam)
            {
                wrongServe = true;
                break;
            }
            idx++;
            int lastPlayer = servePlayer;
            int consecutive = 1;
            bool afterServe = true;
            bool pointEnded = false;
            int errorTeam = -1;
            while (idx < t && !pointEnded)
            {
                if (seq[idx] == "A" || seq[idx] == "B" || seq[idx] == "X")
                {
                    char c = seq[idx][0];
                    if (c == 'A')
                        errorTeam = 0;
                    else if (c == 'B')
                        errorTeam = 1;
                    else
                        errorTeam = (lastPlayer <= 6 ? 0 : 1);
                    pointEnded = true;
                    idx++;
                    break;
                }
                else
                {
                    int curPlayer = stoi(seq[idx]);
                    int curTeam = (curPlayer <= 6 ? 0 : 1);
                    if (curPlayer == lastPlayer)
                    {
                        errorTeam = curTeam;
                        pointEnded = true;
                    }
                    else if (afterServe && curTeam == serveTeam)
                    {
                        errorTeam = curTeam;
                        pointEnded = true;
                    }
                    else if (curTeam == (lastPlayer <= 6 ? 0 : 1))
                    {
                        consecutive++;
                        if (consecutive >= 4)
                        {
                            errorTeam = curTeam;
                            pointEnded = true;
                        }
                    }
                    else
                    {
                        consecutive = 1;
                    }
                    lastPlayer = curPlayer;
                    afterServe = false;
                    idx++;
                    if (pointEnded)
                        break;
                }
            }
            if (pointEnded)
            {
                if (errorTeam != -1)
                {
                    int winningTeam = (errorTeam == 0 ? 1 : 0);
                    if (winningTeam == 0)
                        scoreA++;
                    else
                        scoreB++;
                }
                expectedServeTeam = 1 - serveTeam;
            }
        }
        cout << "Data Set " << ds << ":\n";
        if (wrongServe)
            cout << "Wrong Serve\n\n";
        else
            cout << scoreA << " " << scoreB << "\n\n";
    }
    return 0;
}
