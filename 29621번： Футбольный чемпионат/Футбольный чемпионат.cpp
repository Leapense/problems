#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

struct Team {
    string name;
    int points;
};

bool cmp(const Team& a, const Team& b) {
    if (a.points != b.points) {
        return a.points > b.points;
    }
    return a.name < b.name;
}

int get_rank(vector<Team> teams, string vasya, string opponent, int vasya_add, int opponent_add) {
    for (auto &team : teams) {
        if (team.name == vasya) team.points += vasya_add;
        if (team.name == opponent) team.points += opponent_add;
    }

    sort(teams.begin(), teams.end(), cmp);

    for (int i = 0; i < teams.size(); i++) {
        if (teams[i].name == vasya) return i+1;
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;

    string vasya, opponent;

    cin >> vasya >> opponent;

    vector<Team> teams(n);

    for (int i = 0; i < n; i++) {
        cin >> teams[i].name >> teams[i].points;
    }

    int rank_win = get_rank(teams, vasya, opponent, 3, 0);
    int rank_draw = get_rank(teams, vasya, opponent, 1, 1);
    int rank_lose = get_rank(teams, vasya, opponent, 0, 3);

    cout << rank_win << " " << rank_draw << " " << rank_lose << "\n";

    return 0;
}