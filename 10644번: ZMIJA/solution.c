#include <stdio.h>
#include <stdlib.h>

enum { NO_APPLE = -1 };

int main(void) {
    int rows = 0;
    int cols = 0;

    if (scanf("%d %d", &rows, &cols) != 2) {
        return 0;
    }

    int *left  = calloc((size_t)rows, sizeof *left);
    int *right = calloc((size_t)rows, sizeof *right);
    if (!left || !right) {
        return 0;
    }

    for (int r = 0; r < rows; ++r) {
        left[r]  = cols;
        right[r] = NO_APPLE;
    }

    char *buf = malloc((size_t)cols + 4);
    for (int r = 0; r < rows; ++r) {
        scanf("%s", buf);
        for (int c = 0; c < cols; ++c) {
            if (buf[c] == 'J') {
                if (left[r]  > c) { left[r]  = c; }
                if (right[r] < c) { right[r] = c; }
            }
        }
    }
    free(buf);

    int top = rows;
    for (int r = 0; r < rows; ++r) {
        if (right[r] != NO_APPLE) {
            top = r;
            break;
        }
    }
    if (top == rows) {
        printf("0\n");
        return 0;                     // 사과 없음
    }

    long long ans  = 0;
    int       cur  = 0;               // 현재 열
    int       dir  = +1;              // +1: →, -1: ←

    for (int r = rows - 1; ; --r, dir = -dir) {
        /* 1) 현재 행의 사과 처리 */
        if (right[r] != NO_APPLE) {
            if (dir == +1) {
                if (cur < left[r]) {
                    ans += left[r] - cur;
                    cur  = left[r];
                }
                ans += right[r] - cur;
                cur  = right[r];
            } else {                  /* dir == -1 */
                if (cur > right[r]) {
                    ans += cur - right[r];
                    cur  = right[r];
                }
                ans += cur - left[r];
                cur  = left[r];
            }
        }

        /* 2) 종료 조건 */
        if (r == top) {
            break;
        }

        /* 3) 위 행(next)의 제약 충족 */
        int next = r - 1;
        if (right[next] != NO_APPLE) {
            if (dir == +1) {          /* next는 ← */
                int need = right[next];
                if (cur < need) {
                    ans += need - cur;
                    cur  = need;
                }
            } else {                  /* dir == -1, next는 → */
                int need = left[next];
                if (cur > need) {
                    ans += cur - need;
                    cur  = need;
                }
            }
        }

        /* 4) B 버튼 */
        ++ans;
    }

    printf("%lld\n", ans);

    free(left);
    free(right);
    return 0;
}