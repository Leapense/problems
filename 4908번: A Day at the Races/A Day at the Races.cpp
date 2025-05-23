#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
using namespace std;
string trim(const string &s)
{
    size_t start = s.find_first_not_of(" \t");
    if (start == string::npos)
        return "";
    size_t end = s.find_last_not_of(" \t");
    return s.substr(start, end - start + 1);
}
struct Driver
{
    string first, last;
    int points;
    int positions[9];
    Driver() : points(0)
    {
        for (int i = 0; i < 9; i++)
            positions[i] = 0;
    }
};
int main()
{
    int n, season = 1;
    while (cin >> n && n)
    {
        cin.ignore();
        map<pair<string, string>, Driver> driverMap;
        map<string, int> teamPoints;
        int pts[8] = {10, 8, 6, 5, 4, 3, 2, 1};
        for (int gp = 0; gp < n; gp++)
        {
            string line;
            do
            {
                getline(cin, line);
            } while (line.empty());
            do
            {
                getline(cin, line);
            } while (line.empty());
            for (int pos = 0; pos < 8; pos++)
            {
                getline(cin, line);
                if (line.empty())
                {
                    pos--;
                    continue;
                }
                istringstream iss(line);
                int rank;
                iss >> rank;
                string first, last;
                iss >> first >> last;
                string team;
                getline(iss, team);
                team = trim(team);
                if (!team.empty() && team.back() == '.')
                    team.pop_back();
                pair<string, string> key = {first, last};
                if (driverMap.find(key) == driverMap.end())
                {
                    Driver d;
                    d.first = first;
                    d.last = last;
                    driverMap[key] = d;
                }
                driverMap[key].points += pts[pos];
                driverMap[key].positions[pos + 1]++;
                teamPoints[team] += pts[pos];
            }
            getline(cin, line);
        }
        vector<pair<pair<string, string>, Driver>> driversVec(driverMap.begin(), driverMap.end());
        sort(driversVec.begin(), driversVec.end(), [](auto &a, auto &b)
             {
            if(a.second.points != b.second.points) return a.second.points > b.second.points;
            for (int i = 1; i <= 8; i++){
                if(a.second.positions[i] != b.second.positions[i])
                    return a.second.positions[i] > b.second.positions[i];
            }
            if(a.first.second == b.first.second)
                return a.first.first < b.first.first;
            return a.first.second < b.first.second; });
        vector<pair<string, int>> teamsVec(teamPoints.begin(), teamPoints.end());
        sort(teamsVec.begin(), teamsVec.end(), [](auto &a, auto &b)
             {
            if(a.second != b.second) return a.second > b.second;
            return a.first < b.first; });
        cout << "Season " << season++ << ":\n";
        cout << "Drivers Standing:\n";
        for (auto &d : driversVec)
            cout << left << setw(25) << (d.first.first + " " + d.first.second) << " " << d.second.points << "\n";
        cout << "\nTeams Standing:\n";
        for (auto &t : teamsVec)
            cout << left << setw(25) << t.first << " " << t.second << "\n";
        cout << "\n";
    }
    return 0;
}
