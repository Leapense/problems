#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TeamStats {
    string name;
    int points = 0;
    int wins = 0;
    int draws = 0;
    int losses = 0;
    int goals_scored = 0;
    int goals_received = 0;
};

bool compareTeams(const TeamStats &a, const TeamStats &b) {
    if (a.points != b.points)
        return a.points > b.points;
    if (a.wins != b.wins)
        return a.wins > b.wins;
    if (a.draws != b.draws)
        return a.draws > b.draws;
    if (a.losses != b.losses)
        return a.losses < b.losses;
    if ((a.goals_scored) != (b.goals_scored))
        return (a.goals_scored) > (b.goals_scored);
    if ((a.goals_received) != (b.goals_received))
        return (a.goals_received) < (b.goals_received);
    return a.name < b.name;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int M;
        cin >> M;
        cin.ignore();
        map<string, TeamStats> teams;
        for (int i = 0; i < M; ++i) {
            string line;
            getline(cin, line);

            // 수동으로 문자열 파싱
            size_t pos1 = line.find('[');
            size_t pos2 = line.find('-');
            size_t pos3 = line.find(']');
            string team1 = line.substr(0, pos1 - 1);
            int goals1 = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
            int goals2 = stoi(line.substr(pos2 + 2, pos3 - pos2 - 2));
            string team2 = line.substr(pos3 + 2);

            if (teams.find(team1) == teams.end())
                teams[team1].name = team1;
            if (teams.find(team2) == teams.end())
                teams[team2].name = team2;

            teams[team1].goals_scored += goals1;
            teams[team1].goals_received += goals2;
            teams[team2].goals_scored += goals2;
            teams[team2].goals_received += goals1;

            if (goals1 > goals2) {
                teams[team1].wins++;
                teams[team1].points += 3;
                teams[team2].losses++;
            } else if (goals1 == goals2) {
                teams[team1].draws++;
                teams[team2].draws++;
                teams[team1].points += 1;
                teams[team2].points += 1;
            } else {
                teams[team2].wins++;
                teams[team2].points += 3;
                teams[team1].losses++;
            }
        }

        vector<TeamStats> team_list;
        for (auto &entry : teams) {
            team_list.push_back(entry.second);
        }

        //sort(team_list.begin(), team_list.end(), compareTeams);

        for (size_t i = 0; i < team_list.size(); ++i) {
            cout << team_list[i].name << "," << team_list[i].points << "," << team_list[i].wins << "," << team_list[i].draws << "," << team_list[i].losses << "," << team_list[i].goals_scored << "," << team_list[i].goals_received << endl;
        }

        if (T)
            cout << endl;
    }

    return 0;
}
