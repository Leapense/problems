#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<string> grid(N);
    for (int i = 0; i < N; i++)
    {
        cin >> grid[i];
    }

    // 군인의 중심 좌표와 방향 찾기
    // 방향: 0: 오른쪽, 1: 아래쪽, 2: 왼쪽, 3: 위쪽
    int centerR = -1, centerC = -1, dir = -1;
    bool found = false;
    for (int i = 0; i < N && !found; i++)
    {
        for (int j = 0; j < M && !found; j++)
        {
            char ch = grid[i][j];
            if (ch == '-')
            {
                // 수평 군인: 가운데는 '-'
                centerR = i;
                centerC = j;
                if (j - 1 >= 0 && j + 1 < M)
                {
                    if (grid[i][j - 1] == '/' && grid[i][j + 1] == '\\')
                        dir = 0; // 오른쪽
                    else if (grid[i][j - 1] == '\\' && grid[i][j + 1] == '/')
                        dir = 2; // 왼쪽
                }
                found = true;
            }
            else if (ch == '|')
            {
                // 수직 군인: 가운데는 '|'
                centerR = i;
                centerC = j;
                if (i - 1 >= 0 && i + 1 < N)
                {
                    if (grid[i - 1][j] == '\\' && grid[i + 1][j] == '/')
                        dir = 3; // 위쪽
                    else if (grid[i - 1][j] == '/' && grid[i + 1][j] == '\\')
                        dir = 1; // 아래쪽
                }
                found = true;
            }
        }
    }

    // 명령 처리
    string command;
    getline(cin, command); // 개행 제거
    for (int i = 0; i < K; i++)
    {
        getline(cin, command);
        if (command == "Left turn")
        {
            dir = (dir + 3) % 4;
        }
        else if (command == "Right turn")
        {
            dir = (dir + 1) % 4;
        }
        else if (command == "About turn")
        {
            dir = (dir + 2) % 4;
        }
        else if (command == "Forward step")
        {
            // 이동은 군인이 바라보는 방향과 상관없이 무조건 위쪽(행-1)
            centerR -= 1;
        }
    }

    // 최종 격자 (모두 '.'으로 초기화)
    vector<string> ans(N, string(M, '.'));

    // 최종 군인 그리기: 군인의 모양은 방향에 따라 다름.
    // 여기서 centerR, centerC는 군인의 가운데 셀(중심)로 간주
    if (dir == 0)
    { // 오른쪽 → 수평: 왼쪽 '/', 가운데 '-', 오른쪽 '\\'
        ans[centerR][centerC - 1] = '/';
        ans[centerR][centerC] = '-';
        ans[centerR][centerC + 1] = '\\';
    }
    else if (dir == 2)
    { // 왼쪽 → 수평: 왼쪽 '\\', 가운데 '-', 오른쪽 '/'
        ans[centerR][centerC - 1] = '\\';
        ans[centerR][centerC] = '-';
        ans[centerR][centerC + 1] = '/';
    }
    else if (dir == 1)
    { // 아래쪽 → 수직: 위 '/', 가운데 '|', 아래 '\\'
        ans[centerR - 1][centerC] = '/';
        ans[centerR][centerC] = '|';
        ans[centerR + 1][centerC] = '\\';
    }
    else if (dir == 3)
    { // 위쪽 → 수직: 위 '\\', 가운데 '|', 아래 '/'
        ans[centerR - 1][centerC] = '\\';
        ans[centerR][centerC] = '|';
        ans[centerR + 1][centerC] = '/';
    }

    // 결과 출력
    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}