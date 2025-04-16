#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int N = 5; // 보드 크기
int min_moves = numeric_limits<int>::max(); // 최소 이동 횟수 (초기값: 최대 정수)

// 이동 방향 (상, 하, 좌, 우)
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// 보드 범위 확인 함수
bool is_valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

// DFS 함수
// r, c: 현재 위치
// apples_eaten: 현재까지 먹은 사과 개수
// moves: 현재까지 이동 횟수
// board: 현재 보드 상태 (값으로 전달하여 각 경로마다 독립적인 상태 유지)
void dfs(int r, int c, int apples_eaten, int moves, vector<vector<int>> board) {

    // 가지치기: 현재 이동 횟수가 이미 찾은 최소값보다 크거나 같으면 더 탐색할 필요 없음
    if (moves >= min_moves) {
        return;
    }

    // 기저 조건: 사과 3개를 먹었으면 최소 이동 횟수 갱신
    if (apples_eaten == 3) {
        min_moves = min(min_moves, moves);
        return;
    }

    // 4방향 탐색
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i]; // 다음 행
        int nc = c + dc[i]; // 다음 열

        // 다음 위치가 유효한지 확인 (범위 내, 장애물 아님)
        if (is_valid(nr, nc) && board[nr][nc] != -1) {
            
            // 다음 상태를 위해 현재 보드 상태 복사
            vector<vector<int>> next_board = board;
            int next_apples = apples_eaten;
            int value_at_next = next_board[nr][nc]; // 다음 칸의 값 (사과 또는 빈칸)

            // 다음 칸에 사과가 있다면
            if (value_at_next == 1) {
                next_apples++;          // 먹은 사과 개수 증가
                next_board[nr][nc] = 0; // 사과를 먹었으므로 빈칸(0)으로 변경
            }

            // 현재 위치(r, c)를 떠나므로 장애물(-1)로 변경
            next_board[r][c] = -1;

            // 재귀 호출: 다음 위치로 이동
            dfs(nr, nc, next_apples, moves + 1, next_board);
        }
    }
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> initial_board(N, vector<int>(N));
    int total_apples = 0; // 보드 상의 총 사과 개수

    // 보드 정보 입력
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> initial_board[i][j];
            if (initial_board[i][j] == 1) {
                total_apples++;
            }
        }
    }

    int start_r, start_c;
    cin >> start_r >> start_c; // 학생의 시작 위치 입력

    // 최적화: 보드에 사과가 3개 미만이면 목표 달성 불가능
    if (total_apples < 3) {
        cout << -1 << endl;
        return 0;
    }
    
    // 시작 위치가 사과인 경우 처리 (문제에서는 빈칸이라고 했지만, 혹시 모를 경우 대비)
    // 이 문제에서는 시작 위치가 항상 빈칸(0)이므로 이 부분은 필요 없음.
    // int initial_apples_eaten = 0;
    // if (initial_board[start_r][start_c] == 1) {
    //     initial_apples_eaten = 1;
    //     initial_board[start_r][start_c] = 0; 
    // }

    // DFS 시작
    dfs(start_r, start_c, 0, 0, initial_board);

    // 결과 출력
    if (min_moves == numeric_limits<int>::max()) {
        cout << -1 << endl; // 3개의 사과를 먹는 것이 불가능한 경우
    } else {
        cout << min_moves << endl; // 최소 이동 횟수 출력
    }

    return 0;
}