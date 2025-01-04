#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    
    vector<string> sentence(n);
    for (auto &s : sentence) cin >> s;
    
    unordered_set<string> unique_words(sentence.begin(), sentence.end());
    int m;
    cin >> m;

    unordered_map<string, vector<pair<string, bool>>> dict;
    string d, e, c;

    for (int i = 0; i < m; i++) {
        cin >> d >> e >> c;
        if (unique_words.find(d) != unique_words.end()) {
            dict[d].emplace_back(e, c == "correct");
        }
    }

    bool single = true;

    for (auto &word : sentence) {
        if (dict[word].size() != 1) {
            single = false;
            break;
        }
    }

    if (single) {
        vector<string> translations;
        bool correct = true;
        for (auto &word : sentence) {
            auto &trans = dict[word][0];
            translations.push_back(trans.first);
            if (!trans.second) correct = false;
        }
        for (int i = 0; i < translations.size(); i++) {
            if (i > 0) cout << " ";
            cout << translations[i];
        }
        cout << "\n" << (correct ? "correct" : "incorrect") << "\n";
    } else {
        unsigned long long correct_trans = 1, total_trans = 1;
        for (auto &word : sentence) {
            int cnt_correct = 0, cnt_total=dict[word].size();
            for (auto &[te, isc] : dict[word]) {
                if (isc) cnt_correct++;
            }
            correct_trans *= cnt_correct;
            total_trans *= cnt_total;
        }

        unsigned long long incorrect_trans = total_trans - correct_trans;
        cout << correct_trans << " correct\n" << incorrect_trans << " incorrect\n";
    }

    return 0;
}