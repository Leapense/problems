#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int t;
    cin >> t;

    cin.ignore();

    while(t--) {
        string P, Q;
        getline(cin, P);
        getline(cin, P);
        getline(cin, Q);

        int min_cost = P.length() + 2;

        string result = "*" + P + "*";

        int lenQ = Q.length();
        int lenP = P.length();

        for (int backspaces = 0; backspaces <= lenQ; ++backspaces) {
            int prefix_len = lenQ - backspaces;
            string prompt = Q.substr(0, prefix_len);

            if (P.substr(0, prefix_len) == prompt) {
                int insertions = lenP - prefix_len;
                int total_cost = backspaces + insertions + 1;

                if (total_cost < min_cost) {
                    min_cost = total_cost;
                    result = string(backspaces, '<') + P.substr(prefix_len) + "*";
                }
            }
        }
        cout << result;
        if (t) cout << "\n";
    }

    return 0;
}