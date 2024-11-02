//=====================================================================
//   21361번:    Robotdammsugaren                   
//   @date:   2024-10-17              
//   @link:   https://www.acmicpc.net/problem/21361  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int R, C, N;
    cin >> R >> C >> N;
    string commands;
    cin >> commands;
    vector<string> grid(R);
    int sx = -1, sy = -1;
    for (int i = 0; i < R; ++i) {
        cin >> grid[i];
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 'O') {
                sx = i;
                sy = j;
            }
        }
    }
    vector<vector<bool>> cleaned(R, vector<bool>(C, false));
    cleaned[sx][sy] = true;
    int x = sx, y = sy;
    for (char cmd : commands) {
        int dx = 0, dy = 0;
        if (cmd == '^') dx = -1;
        else if (cmd == 'v') dx = 1;
        else if (cmd == '<') dy = -1;
        else if (cmd == '>') dy = 1;
        while (true) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) break;
            if (grid[nx][ny] == '#') break;
            x = nx;
            y = ny;
            cleaned[x][y] = true;
        }
    }
    int count = 0;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (cleaned[i][j])
                ++count;
    cout << count << endl;
    return 0;
}