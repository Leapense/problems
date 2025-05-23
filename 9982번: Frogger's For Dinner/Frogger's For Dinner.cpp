#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 차량 정보를 나타내는 구조체
struct Vehicle {
    int row;
    int col;
    int speed;
    int dir; // 방향: -1은 왼쪽, 1은 오른쪽
};

int main() {
    string line;
    vector<vector<int>> grid(8, vector<int>(10));
    while (getline(cin, line)) {
        if (line != "START") continue;

        // 데이터 집합 읽기
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 10; ++j) {
                cin >> grid[i][j];
            }
        }
        getline(cin, line); // 남은 개행 문자 제거
        getline(cin, line); // "END" 읽기

        // 각 시작 열에 대해 시도
        bool success = false;
        for (int start_col = 0; start_col < 10; ++start_col) {
            int frog_row = 0;
            int frog_col = start_col;

            // 차량 초기화
            vector<Vehicle> vehicles;
            for (int i = 0; i < 8; ++i) {
                int speed = -1;
                for (int j = 0; j < 10; ++j) {
                    if (grid[i][j] != 0) {
                        speed = grid[i][j];
                        vehicles.push_back({i + 1, j, speed, (i < 4) ? -1 : 1});
                    }
                }
            }

            // 시간 단계별로 시뮬레이션
            bool alive = true;
            for (int t = 0; t < 9; ++t) {
                // 개구리 이동
                frog_row++;

                // 개구리가 현재 위치에서 차량과 충돌하는지 확인 (개구리가 움직인 후, 차량이 움직이기 전)
                for (const auto& v : vehicles) {
                    if (v.row == frog_row && v.col == frog_col) {
                        alive = false;
                        break;
                    }
                }
                if (!alive) break;

                // 차량 이동
                for (auto& v : vehicles) {
                    int prev_col = v.col;
                    int move = v.speed * v.dir;
                    int new_col = (v.col + move + 100 * 10) % 10; // 음수 방지를 위해 큰 수 곱함

                    // 차량이 이동하면서 개구리를 지나치는지 확인
                    int steps = abs(move);
                    for (int s = 1; s <= steps; ++s) {
                        int intermediate_col = (prev_col + s * v.dir + 100 * 10) % 10;
                        if (v.row == frog_row && intermediate_col == frog_col) {
                            alive = false;
                            break;
                        }
                    }
                    if (!alive) break;

                    v.col = new_col;
                }
                if (!alive) break;

                // 차량이 이동한 후 개구리 위치에 있는지 확인
                for (const auto& v : vehicles) {
                    if (v.row == frog_row && v.col == frog_col) {
                        alive = false;
                        break;
                    }
                }
                if (!alive) break;
            }

            if (alive) {
                success = true;
                break;
            }
        }

        if (success) {
            cout << "LEFTOVER POSSUM" << endl;
        } else {
            cout << "FROGGER" << endl;
        }
    }
    return 0;
}