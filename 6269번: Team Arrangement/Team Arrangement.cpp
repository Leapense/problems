#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Interval {
    int start, end;
};

struct Player {
    int number;
    string name;
    char role;
    vector<Interval> intervals;
    int totalYears;

    void computeTotalYears() {
        totalYears = 0;
        for (auto& interval : intervals) {
            totalYears += interval.end - interval.start + 1;
        }
    }
};

int main() {
    while (true) {
        vector<Player> players(22);
        for (int i = 0; i < 22; ++i) {
            string line;
            getline(cin, line);
            if (line == "0") return 0;
            Player player;
            size_t pos = 0;
            while (pos < line.size() && line[pos] == ' ') ++pos;
            size_t next = line.find(' ', pos);
            player.number = stoi(line.substr(pos, next - pos));
            pos = next + 1;
            next = line.find(' ', pos);
            player.name = line.substr(pos, next - pos);
            pos = next + 1;
            player.role = line[pos];
            pos += 2;
            while (pos < line.size()) {
                while (pos < line.size() && line[pos] == ' ') ++pos;
                if (pos >= line.size()) break;
                next = line.find('-', pos);
                int startYear = stoi(line.substr(pos, next - pos));
                pos = next + 1;
                next = line.find(' ', pos);
                int endYear;
                if (next == string::npos) {
                    endYear = stoi(line.substr(pos));
                    pos = line.size();
                } else {
                    endYear = stoi(line.substr(pos, next - pos));
                    pos = next + 1;
                }
                player.intervals.push_back({startYear, endYear});
            }
            player.computeTotalYears();
            players[i] = player;
        }
        string formationLine;
        getline(cin, formationLine);
        if (formationLine == "0") return 0;
        int numDefenders, numMidfielders, numStrikers;
        sscanf(formationLine.c_str(), "%d-%d-%d", &numDefenders, &numMidfielders, &numStrikers);
        vector<Player> goalkeepers, defenders, midfielders, strikers;
        for (auto& player : players) {
            if (player.role == 'G') goalkeepers.push_back(player);
            else if (player.role == 'D') defenders.push_back(player);
            else if (player.role == 'M') midfielders.push_back(player);
            else if (player.role == 'S') strikers.push_back(player);
        }
        sort(goalkeepers.begin(), goalkeepers.end(), [](const Player& a, const Player& b) {
            return a.number < b.number;
        });
        sort(defenders.begin(), defenders.end(), [](const Player& a, const Player& b) {
            return a.number < b.number;
        });
        sort(midfielders.begin(), midfielders.end(), [](const Player& a, const Player& b) {
            return a.number < b.number;
        });
        sort(strikers.begin(), strikers.end(), [](const Player& a, const Player& b) {
            return a.number < b.number;
        });
        if (goalkeepers.size() < 1 || defenders.size() < numDefenders ||
            midfielders.size() < numMidfielders || strikers.size() < numStrikers) {
            cout << "IMPOSSIBLE TO ARRANGE" << endl << endl;
            continue;
        }
        vector<Player> selectedPlayers;
        selectedPlayers.push_back(goalkeepers[0]);
        for (int i = 0; i < numDefenders; ++i) selectedPlayers.push_back(defenders[i]);
        for (int i = 0; i < numMidfielders; ++i) selectedPlayers.push_back(midfielders[i]);
        for (int i = 0; i < numStrikers; ++i) selectedPlayers.push_back(strikers[i]);
        Player captain = selectedPlayers[0];
        for (auto& player : selectedPlayers) {
            if (player.totalYears > captain.totalYears ||
                (player.totalYears == captain.totalYears && player.number > captain.number)) {
                captain = player;
            }
        }
        cout << captain.number << " " << captain.name << " " << captain.role << endl;
        vector<Player> restPlayers;
        for (auto& player : selectedPlayers) {
            if (player.number != captain.number) restPlayers.push_back(player);
        }
        sort(restPlayers.begin(), restPlayers.end(), [](const Player& a, const Player& b) {
            if (a.role != b.role) {
                if (a.role == 'G') return true;
                if (b.role == 'G') return false;
                if (a.role == 'D') return true;
                if (b.role == 'D') return false;
                if (a.role == 'M') return true;
                if (b.role == 'M') return false;
                return false;
            }
            return a.number < b.number;
        });
        for (auto& player : restPlayers) {
            cout << player.number << " " << player.name << " " << player.role << endl;
        }
        cout << endl;
    }
    return 0;
}