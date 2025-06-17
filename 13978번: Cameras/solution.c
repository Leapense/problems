#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100000

static bool has_cam[MAX_N + 1];

int main(void)
{
    int n = 0, k = 0, r = 0;
    if (scanf("%d %d %d", &n, &k, &r) != 3) {
        return 0;
    }

    for (int i = 0; i < k; ++i) {
        int pos = 0;
        scanf("%d", &pos);
        has_cam[pos] = true;
    }

    int cam_cnt = 0;
    for (int i = 1; i <= r; ++i) {
        cam_cnt += has_cam[i];
    }

    int answer = 0;
    for (int left = 1; left <= n - r + 1; ++left) {
        int right = left + r - 1;

        for (int pos = right; cam_cnt < 2 && pos >= left; --pos) {
            if (!has_cam[pos]) {
                has_cam[pos] = true;
                ++cam_cnt;
                ++answer;
            }
        }

        cam_cnt -= has_cam[left];
        if (right + 1 <= n) {
            cam_cnt += has_cam[right + 1];
        }
    }

    printf("%d\n", answer);
    return 0;
}