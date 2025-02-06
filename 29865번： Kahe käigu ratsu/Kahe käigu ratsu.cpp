#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

pair<int, int> notation_to_coords(string notation)
{
    return {notation[1] - '1', notation[0] - 'a'};
}

string coords_to_notation(int r, int c)
{
    string notation = "";
    notation += (char)('a' + c);
    notation += (char)('1' + r);
    return notation;
}

bool is_valid(int r, int c)
{
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

int main()
{
    string start_notation;
    cin >> start_notation;

    pair<int, int> start_coords = notation_to_coords(start_notation);
    int start_r = start_coords.first;
    int start_c = start_coords.second;

    vector<pair<int, int>> knight_moves = {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    set<pair<int, int>> reachable_positions;

    for (auto move1 : knight_moves)
    {
        int r1 = start_r + move1.first;
        int c1 = start_c + move1.second;

        if (is_valid(r1, c1))
        {
            for (auto move2 : knight_moves)
            {
                int r2 = r1 + move2.first;
                int c2 = c1 + move2.second;

                if (is_valid(r2, c2))
                {
                    reachable_positions.insert({r2, c2});
                }
            }
        }
    }

    reachable_positions.insert({start_r, start_c});

    vector<string> result_notations;
    for (const auto &pos : reachable_positions)
    {
        result_notations.push_back(coords_to_notation(pos.first, pos.second));
    }

    sort(result_notations.begin(), result_notations.end());

    for (const string &notation : result_notations)
    {
        cout << notation << endl;
    }

    return 0;
}