#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) {
        return EXIT_FAILURE;
    }

    for (int tc = 1; tc <= N; ++tc) {
        int S;
        cin >> S;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<string> engines(S);
        for (auto &name : engines) {
            getline(cin, name);
        }

        int Q;
        cin >> Q;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<bool> seen(S, false);
        int countSeen = 0;
        int switches = 0;
        string query;

        while (Q--) {
            getline(cin, query);
            int id = find(engines.begin(), engines.end(), query) - engines.begin();

            if (id < 0 || id >= S) {
                continue;
            }

            if (!seen[id]) {
                seen[id] = true;
                ++countSeen;
            }

            if (countSeen == S) {
                ++switches;
                fill(seen.begin(), seen.end(), false);
                seen[id] = true;
                countSeen = 1;
            }
        }

        cout << "Case #" << tc << ": " << switches << "\n";
    }

    return EXIT_SUCCESS;
}