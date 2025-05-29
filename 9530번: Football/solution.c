#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

static int compare_ints(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

int main(void)
{
    int N;
    int64_t G;
    if (scanf("%d %" SCNd64, &N, &G) != 2) {
        return 1;
    }

    int win_count = 0;
    int draw_count = 0;
    int *deficits = malloc(N * sizeof(int));
    if (deficits == NULL) {
        return 1; // 메모리 할당 실패
    }
    
    int def_count = 0;

    for (int i = 0; i < N; ++i) {
        int S, R;
        scanf("%d %d", &S, &R);
        if (S > R) {
            win_count++;
        } else if (S == R) {
            draw_count++;
        } else {
            deficits[def_count++] = R - S;
        }
    }

    // 초기 점수: 승리 3점, 무승부 1점
    int64_t points = (int64_t)win_count * 3 + draw_count;

    // 1) 무승부 -> 승리 전환
    int64_t convert_draws = G < draw_count ? G : draw_count;
    G -= convert_draws;
    points += convert_draws * 2; // 무승부 1점 -> 승리 3점 (+2점)

    // 2) 패배 경기 △ 오름차순 정렬
    qsort(deficits, def_count, sizeof(int), compare_ints);

    // 3) 패배 -> 승리 혹은 무승부 전환
    for (int i = 0; i < def_count && G > 0; ++i) {
        int d = deficits[i];
        if (G >= d + 1) {
            G -= d + 1;
            points += 3;
        } else if (G >= d) {
            G -= d;
            points += 1;
        } else {
            break;
        }
    }

    printf("%" PRId64 "\n", points);
    free(deficits);
    return 0;
}