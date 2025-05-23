#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int N;
        cin >> N;
        unordered_map<string, string> itinerary;
        unordered_set<string> destinations;

        string source, dest;

        for (int i = 0; i < N; i++)
        {
            cin >> source >> dest;
            itinerary[source] = dest;
            destinations.insert(dest);
        }
        string start;

        for (auto &p : itinerary)
        {
            if (destinations.find(p.first) == destinations.end())
            {
                start = p.first;
                break;
            }
        }

        cout << "Case #" << t << ":";
        while (itinerary.find(start) != itinerary.end())
        {
            string next = itinerary[start];
            cout << " " << start << "-" << next;
            start = next;
        }

        if (t < T)
            cout << "\n";
    }

    return 0;
}