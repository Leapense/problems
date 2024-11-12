#include <bits/stdc++.h>
using namespace std;

struct Participant {
    string name;
    int score;
    bool isHidden;
    int rank;
};

Participant parseParticipant(const string& s) {
    Participant p;
    size_t pos_name = s.find("\"name\":\"");
    if (pos_name == string::npos) {
        // Error
    }
    pos_name += 8;
    size_t pos_end_name = s.find("\"", pos_name);
    p.name = s.substr(pos_name, pos_end_name - pos_name);

    size_t pos_score = s.find("\"score\":", pos_end_name);
    if (pos_score == string::npos) {
        // Error
    }
    pos_score += 8;
    size_t pos_end_score = s.find(",", pos_score);
    string score_str = s.substr(pos_score, pos_end_score - pos_score);
    p.score = stoi(score_str);

    size_t pos_hidden = s.find("\"isHidden\":", pos_end_score);
    if (pos_hidden == string::npos) {
        // Error
    }

    pos_hidden += 11;
    size_t pos_end_hidden = s.find("}", pos_hidden);
    string hidden_str = s.substr(pos_hidden, pos_end_hidden - pos_hidden);
    p.isHidden = (hidden_str == "1") ? true : false;

    return p;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    cin.ignore();
    vector<string> lines(N);
    for (int i = 0; i < N; i++) {
        getline(cin, lines[i]);
    }

    vector<Participant> participants;
    participants.reserve(N);

    for (int i = 0; i < N; i++) {
        string s = lines[i];
        if (i == 0) {
            size_t pos = s.find('[');
            if (pos != string::npos) {
                s.erase(pos, 1);
            }
        }

        if (i == N - 1) {
            size_t pos = s.find(']');
            if (pos != string::npos) {
                s.erase(pos, 1);
            }
        }

        if (i != N - 1) {
            size_t pos = s.find_last_of(',');
            if (pos != string::npos) {
                s.erase(pos, 1);
            }
        }

        Participant p = parseParticipant(s);
        participants.push_back(p);
    }
    sort(participants.begin(), participants.end(), [&](const Participant &a, const Participant &b) -> bool {
        if (a.score != b.score) return a.score > b.score;
        return a.name < b.name;
    });

    int current_rank = 1;
    int previous_score = -1;

    for (int i = 0; i < N; i++) {
        if (participants[i].score != previous_score) {
            participants[i].rank = i + 1;
            previous_score = participants[i].score;
            current_rank = participants[i].rank;
        } else {
            participants[i].rank = current_rank;
        }
    }

    vector<Participant> visible;

    for (auto &p : participants) {
        if (!p.isHidden) {
            visible.push_back(p);
        }
    }

    sort(visible.begin(), visible.end(), [&](const Participant &a, const Participant &b) -> bool{
        if(a.rank != b.rank) return a.rank < b.rank;
        return a.name < b.name;
    });

    for (auto &p : visible) {
        cout << p.rank << " " << p.name << " " << p.score << "\n";
    }

    return 0;
}