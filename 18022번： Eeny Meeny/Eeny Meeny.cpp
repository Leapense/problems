#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string word;
    vector<string> rhyme_words;

    while (cin >> word && word != "\n") {
        rhyme_words.push_back(word);
        if (cin.peek() == '\n') break;
    }

    int m = rhyme_words.size();

    int n;
    cin >> n;

    vector<string> kids(n);
    for (int i = 0; i < n; ++i) {
        cin >> kids[i];
    }

    vector<string> team1, team2;

    int current_index = 0;
    bool isTeam1Turn = true;

    while (!kids.empty()) {
        int selected_index = (current_index + m - 1) % kids.size();
        string selected_kid = kids[selected_index];

        if (isTeam1Turn) {
            team1.push_back(selected_kid);
        } else {
            team2.push_back(selected_kid);
        }

        kids.erase(kids.begin() + selected_index);

        current_index = selected_index;
        if (current_index >= kids.size()) {
            current_index = 0;
        }

        isTeam1Turn = !isTeam1Turn;
    }

    cout << team1.size() << "\n";
    for (auto &kid : team1) {
        cout << kid << "\n";
    }

    cout << team2.size() << "\n";
    for (auto &kid : team2) {
        cout << kid << "\n";
    }

    return 0;
}