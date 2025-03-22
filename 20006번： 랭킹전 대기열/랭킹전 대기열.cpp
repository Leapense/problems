#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Player
{
    int level;
    string nickname;
};

struct Room
{
    int low, high;
    vector<Player> players;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, m;
    cin >> p >> m;

    vector<Room> rooms;

    for (int i = 0; i < p; i++)
    {
        int level;
        string nickname;
        cin >> level >> nickname;

        bool placed = false;
        for (auto &room : rooms)
        {
            if (room.players.size() < static_cast<size_t>(m) && level >= room.low && level <= room.high)
            {
                room.players.push_back({level, nickname});
                placed = true;
                break;
            }
        }

        if (!placed)
        {
            Room newRoom;
            newRoom.low = level - 10;
            newRoom.high = level + 10;
            newRoom.players.push_back({level, nickname});
            rooms.push_back(newRoom);
        }
    }

    for (auto &room : rooms)
    {
        sort(room.players.begin(), room.players.end(), [](const Player &a, const Player &b)
             { return a.nickname < b.nickname; });

        if (room.players.size() == static_cast<size_t>(m))
        {
            cout << "Started!" << "\n";
        }
        else
        {
            cout << "Waiting!" << "\n";
        }

        for (const auto &player : room.players)
        {
            cout << player.level << " " << player.nickname << "\n";
        }
    }

    return 0;
}