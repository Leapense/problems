#include <iostream>
#include <array>
#include <queue>
#include <string>
#include <limits>

constexpr int BOARD_SIZE = 8;
constexpr std::array<std::pair<int, int>, 8> KNIGHT_MOVES{{{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}}};

int calculateShortestKnightPath(int startX, int startY, int targetX, int targetY)
{
    std::array<std::array<bool, BOARD_SIZE>, BOARD_SIZE> visited{};
    std::array<std::array<int, BOARD_SIZE>, BOARD_SIZE> distance{};

    for (auto &row : distance)
    {
        row.fill(std::numeric_limits<int>::max());
    }

    std::queue<std::pair<int, int>> positions;
    positions.push({startX, startY});
    visited[startY][startX] = true;
    distance[startY][startX] = 0;
    while (!positions.empty())
    {
        auto [x, y] = positions.front();
        positions.pop();
        if (x == targetX && y == targetY)
        {
            break;
        }

        for (const auto &move : KNIGHT_MOVES)
        {
            int nextX = x + move.first;
            int nextY = y + move.second;
            if (nextX >= 0 && nextX < BOARD_SIZE && nextY >= 0 && nextY < BOARD_SIZE && !visited[nextY][nextX])
            {
                visited[nextY][nextX] = true;
                distance[nextY][nextX] = distance[y][x] + 1;
                positions.push({nextX, nextY});
            }
        }
    }
    return distance[targetY][targetX];
}

int main()
{
    std::string source;
    std::string destination;
    while (std::cin >> source >> destination)
    {
        int startX = source[0] - 'a';
        int startY = source[1] - '1';
        int targetX = destination[0] - 'a';
        int targetY = destination[1] - '1';
        int moves = calculateShortestKnightPath(startX, startY, targetX, targetY);

        std::cout << "To get from " << source << " to " << destination << " takes " << moves << " knight moves." << std::endl;
    }

    return 0;
}