#include <cstdio>
#include <cstring>

int main() {
    int T;
    scanf("%d", &T);
    for(int caseNum = 1; caseNum <= T; ++caseNum) {
        int grid[6][6];
        bool valid = true;
        // 그리드 입력 받기
        for(int i = 0; i < 6; ++i) {
            for(int j = 0; j <6; ++j) {
                scanf("%d", &grid[i][j]);
                // 숫자가 1부터 6 사이인지 검사
                if(grid[i][j] <1 || grid[i][j]>6)
                    valid = false;
            }
        }
        // 행 검사
        for(int i = 0; i <6 && valid; ++i) {
            bool seen[7] = {false};
            for(int j = 0; j <6; ++j) {
                int num = grid[i][j];
                if(seen[num]) {
                    valid = false;
                    break;
                }
                seen[num] = true;
            }
        }
        // 열 검사
        for(int j = 0; j <6 && valid; ++j) {
            bool seen[7] = {false};
            for(int i = 0; i <6; ++i) {
                int num = grid[i][j];
                if(seen[num]) {
                    valid = false;
                    break;
                }
                seen[num] = true;
            }
        }
        // 2x3 블록 검사
        int blockStarts[6][2] = {{0,0}, {0,3}, {2,0}, {2,3}, {4,0}, {4,3}};
        for(int b = 0; b <6 && valid; ++b) {
            int r = blockStarts[b][0];
            int c = blockStarts[b][1];
            bool seen[7] = {false};
            for(int i = r; i < r+2; ++i) {
                for(int j = c; j < c+3; ++j) {
                    int num = grid[i][j];
                    if(seen[num]) {
                        valid = false;
                        break;
                    }
                    seen[num] = true;
                }
                if(!valid) break;
            }
        }
        // 메인 대각선 검사
        if(valid) {
            bool seen[7] = {false};
            for(int i = 0; i <6; ++i) {
                int num = grid[i][i];
                if(seen[num]) {
                    valid = false;
                    break;
                }
                seen[num] = true;
            }
        }
        if(valid) {
            bool seen[7] = {false};
            for(int i = 0; i <6; ++i) {
                int num = grid[i][5 - i];
                if(seen[num]) {
                    valid = false;
                    break;
                }
                seen[num] = true;
            }
        }
        // 결과 출력
        printf("Case#%d: %d\n", caseNum, valid ? 1 : 0);
    }
    return 0;
}