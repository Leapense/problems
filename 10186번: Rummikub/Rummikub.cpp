#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct Tile
{
    char color;
    int number;
    string repr;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        vector<Tile> tiles;
        tiles.reserve(14);
        for (int i = 0; i < 14; i++)
        {
            string token;
            cin >> token;
            Tile tile;
            tile.color = token[0];
            tile.number = stoi(token.substr(1));
            tile.repr = token;
            tiles.push_back(tile);
        }

        int bestScore = 0;
        vector<Tile> bestCombo;

        auto cmpTile = [](const Tile &a, const Tile &b)
        {
            if (a.color != b.color)
                return a.color < b.color;
            return a.number < b.number;
        };

        map<int, set<char>> numToColors;
        map<int, vector<Tile>> numToTiles;
        for (auto &tile : tiles)
        {
            numToColors[tile.number].insert(tile.color);
            numToTiles[tile.number].push_back(tile);
        }
        for (auto &entry : numToColors)
        {
            int num = entry.first;
            int distinct = entry.second.size();
            if (distinct >= 3)
            {
                int score = num * (distinct >= 4 ? 4 : 3);
                if (score > bestScore)
                {
                    bestScore = score;
                    vector<Tile> combo;
                    set<char> used;
                    for (auto &tile : numToTiles[num])
                    {
                        if (used.find(tile.color) == used.end())
                        {
                            used.insert(tile.color);
                            combo.push_back(tile);
                        }
                    }
                    sort(combo.begin(), combo.end(), cmpTile);
                    bestCombo = combo;
                }
            }
        }

        map<char, vector<int>> colorToNums;
        for (auto &tile : tiles)
        {
            colorToNums[tile.color].push_back(tile.number);
        }
        for (auto &entry : colorToNums)
        {
            sort(entry.second.begin(), entry.second.end());
            entry.second.erase(unique(entry.second.begin(), entry.second.end()), entry.second.end());
        }

        for (auto &p : colorToNums)
        {
            char color = p.first;
            vector<int> nums = p.second;
            for (size_t i = 0; i < nums.size(); i++)
            {
                int sum = nums[i];
                vector<Tile> run;
                run.push_back({color, nums[i], string(1, color) + to_string(nums[i])});
                for (size_t j = i + 1; j < nums.size(); j++)
                {
                    if (nums[j] == run.back().number + 1)
                    {
                        run.push_back({color, nums[j], string(1, color) + to_string(nums[j])});
                        sum += nums[j];
                        if (run.size() >= 3 && sum > bestScore)
                        {
                            bestScore = sum;
                            vector<Tile> combo = run;
                            sort(combo.begin(), combo.end(), cmpTile);
                            bestCombo = combo;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        if (bestScore == 0)
        {
            cout << "NO GROUPS OR RUNS";
        }
        else
        {
            for (auto &tile : bestCombo)
                cout << tile.repr << " ";
            cout << bestScore;
        }
        cout << "\n";
    }

    return 0;
}
