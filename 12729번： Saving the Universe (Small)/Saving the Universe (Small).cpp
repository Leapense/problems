#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int S;
        cin >> S;
        vector<string> engines(S);
        cin.ignore();
        for (int i = 0; i < S; i++)
        {
            getline(cin, engines[i]);
        }

        int Q;
        cin >> Q;
        cin.ignore();
        vector<string> queries(Q);
        for (int i = 0; i < Q; i++)
        {
            getline(cin, queries[i]);
        }
        if (Q == 0)
        {
            cout << "Case #" << t << ": " << 0;
            if (t < T)
                cout << "\n";
            continue;
        }

        int switches = 0;
        int currentEngine = -1;
        auto nextOccurrence = [&](int start, int engineIndex) -> int
        {
            for (int i = start; i < Q; i++)
            {
                if (queries[i] == engines[engineIndex])
                {
                    return i;
                }
            }

            return Q;
        };

        int bestOccurrence = -1;
        for (int i = 0; i < S; i++)
        {
            if (engines[i] == queries[0])
                continue;

            int occ = nextOccurrence(0, i);
            if (occ > bestOccurrence)
            {
                bestOccurrence = occ;
                currentEngine = i;
            }
        }

        for (int i = 0; i < Q; i++)
        {
            if (queries[i] == engines[currentEngine])
            {
                int best = -1;
                int candidate = currentEngine;
                for (int j = 0; j < S; j++)
                {
                    if (engines[j] == queries[i])
                        continue;

                    int occ = nextOccurrence(i, j);
                    if (occ > best)
                    {
                        best = occ;
                        candidate = j;
                    }
                }

                currentEngine = candidate;
                switches++;
            }
        }

        cout << "Case #" << t << ": " << switches;
        if (t < T)
            cout << "\n";
    }

    return 0;
}