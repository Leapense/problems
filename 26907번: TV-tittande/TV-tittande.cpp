#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int parseTime(const string &s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    return h * 60 + m;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    vector<vector<bool>> isCommercial(N, vector<bool>(1440, false));

    for (int c = 0; c < N; ++c) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        int ri;
        ss >> ri;

        for (int i = 0; i < ri; ++i) {
            string ad;
            ss >> ad;

            size_t dash = ad.find('-');
            int start = parseTime(ad.substr(0, dash));
            int end = parseTime(ad.substr(dash + 1));
            for (int t = start; t <= end; ++t) {
                if (t >= 0 && t < 1440) {
                    isCommercial[c][t] = true;
                }
            }
        }
    }

    vector<int> totalWatched(N, 0);
    int t = 0;
    int c = 0;

    while (t < 1440) {
        if (isCommercial[c][t]) {
            t += 1;
            c = (c + 1) % N;
        } else {
            int t1 = t;
            while (t1 < 1440 && !isCommercial[c][t1]) {
                t1++;
            }
            totalWatched[c] += t1 - t;
            t = t1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << totalWatched[i] << "\n";
    }

    return 0;
}