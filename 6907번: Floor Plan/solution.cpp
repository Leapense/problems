#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int flooring, rows, cols;
    cin >> flooring >> rows >> cols;

    vector<string> grid(rows);
    for (int i = 0; i < rows; i++) {
        cin >> grid[i];
    }

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<int> roomSizes;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                int roomSize = 0;

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    roomSize++;

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == '.' && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }

                roomSizes.push_back(roomSize);
            }
        }
    }

    sort(roomSizes.begin(), roomSizes.end(), greater<int>());

    int roomsFloored = 0;
    int flooringUsed = 0;

    for (int size : roomSizes) {
        if (flooringUsed + size <= flooring) {
            flooringUsed += size;
            roomsFloored++;
        } else {
            break;
        }
    }

    int leftover = flooring - flooringUsed;

    if (roomsFloored == 1) {
        cout << "1 room, " << leftover << " square metre(s) left over" << endl;
    } else {
        cout << roomsFloored << " rooms, " << leftover << " square metre(s) left over" << endl;
    }

    return 0;
}