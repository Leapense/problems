// 파일명 예시: matrix_solution_c23.c
// 컴파일 옵션 예시: gcc -std=c23 -O2 -Wall matrix_solution_c23.c -o matrix_c23

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int m, n;
    // 1) m, n 입력 받기
    if (scanf("%d %d", &m, &n) != 2) {
        // 입력 형식 오류 시 종료
        return 0;
    }

    // 2) A와 B 행렬을 동적 할당
    int (*A)[100] = malloc(sizeof(int[m][100]));
    int (*B)[100] = malloc(sizeof(int[m][100]));
    if (A == NULL || B == NULL) {
        return 0;
    }

    // 3) A 행렬 입력
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    // 4) B 행렬 입력
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // 5) D 행렬 계산: D[i][j] = B[i][j] - A[i][j]
    int D[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            D[i][j] = B[i][j] - A[i][j];
        }
    }

    // 6) 일관성 검사: D[i][j] - D[i][0] == D[0][j] - D[0][0] 인지 확인
    int base = D[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (D[i][j] - D[i][0] != D[0][j] - base) {
                // 불가능한 경우
                printf("-1\n");
                free(A);
                free(B);
                return 0;
            }
        }
    }

    // 7) w의 범위 구하기
    //    LB = max( max_i(-D[i][0]), max_j(D[0][j] - D[0][0]) )
    //    UB = min( min_i(9 - D[i][0]), min_j(9 + D[0][j] - D[0][0]) )
    int LB = -1000000000;  // 충분히 작은 수로 초기화
    int UB =  1000000000;  // 충분히 큰 수로 초기화

    // i 반복: 0 ≤ D[i][0] + w ≤ 9  =>  -D[i][0] ≤ w ≤ 9 - D[i][0]
    for (int i = 0; i < m; i++) {
        int low_i  = -D[i][0];
        int high_i = 9 - D[i][0];
        if (low_i  > LB) LB = low_i;
        if (high_i < UB) UB = high_i;
    }
    // j 반복: 0 ≤ w + D[0][0] - D[0][j] ≤ 9  =>  D[0][j] - D[0][0] ≤ w ≤ 9 + D[0][j] - D[0][0]
    for (int j = 0; j < n; j++) {
        int low_j  = D[0][j] - base;
        int high_j = 9 + D[0][j] - base;
        if (low_j  > LB) LB = low_j;
        if (high_j < UB) UB = high_j;
    }

    // 8) w 가능한지 확인
    if (LB > UB) {
        printf("-1\n");
        free(A);
        free(B);
        return 0;
    }

    // 9) 사전 순 최소화를 위해 w = LB 고정
    int w = LB;

    // 10) r[i] 계산 및 하나씩 연결하여 출력
    // r[i] = D[i][0] + w
    // 이미 0 ≤ r[i] ≤ 9이 보장된다
    for (int i = 0; i < m; i++) {
        int ri = D[i][0] + w;
        // 한 자리 정수이므로 %1d 형식
        printf("%d", ri);
    }
    printf("\n");

    free(A);
    free(B);
    return 0;
}
