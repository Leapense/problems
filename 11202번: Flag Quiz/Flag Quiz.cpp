#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string question;
    getline(cin, question);

    string n_line;
    getline(cin, n_line);

    int N = stoi(n_line);

    vector<string> alternatives(N);
    for (int i = 0; i < N; i++) {
        getline(cin, alternatives[i]);
    }

    auto split = [&](const string& s) -> vector<string>{
        vector<string> parts;
        size_t start = 0;
        while(start < s.size()){
            size_t pos = s.find(", ", start);
            if(pos == string::npos){
                parts.push_back(s.substr(start));
                break;
            }
            parts.push_back(s.substr(start, pos - start));
            start = pos + 2;
        }
        return parts;
    };

    vector<vector<string>> parsed(N);
    for (int i = 0; i < N; i++) {
        parsed[i] = split(alternatives[i]);
    }

    vector<int> max_changes(N, 0);
    for (int i = 0; i < N; i++) {
        int current_max = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int diffs = 0;

            for (int k = 0; k < parsed[i].size(); k++) {
                if (parsed[i][k] != parsed[j][k]) diffs++;
            }
            if (diffs > current_max) current_max = diffs;
        }
        max_changes[i] = current_max;
    }

    int min_max = INT32_MAX;
    for (int i = 0; i < N; i++) {
        if (max_changes[i] < min_max) {
            min_max = max_changes[i];
        }
    }

    for (int i = 0; i < N; i++) {
        if (max_changes[i] == min_max) {
            cout << alternatives[i] << "\n";
        }
    }

    return 0;
}