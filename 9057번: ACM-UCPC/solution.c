/*
 * 2025-05-28 / C23
 * 컴파일 예시 : clang -std=c23 -O2
 * SonarQube C-rule을 고려한 명확한 변수 이름 사용
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TEAM 1000
#define MAX_STR  32
#define MAX_PICK 60

typedef struct {
    char  name[MAX_STR];
    char  school[MAX_STR];
    int   solved;
    int   penalty;
} Team;

static int cmp_team(const void *a, const void *b)
{
    const Team *x = a, *y = b;
    if (x->solved != y->solved) { return y->solved - x->solved; }
    return x->penalty - y->penalty;
}

typedef struct {
    char  school[MAX_STR];
    int   total;
    int   selected;
} SchoolInfo;

static int find_school(SchoolInfo *arr, int cnt, const char *key)
{
    for (int i = 0; i < cnt; ++i) {
        if (strcmp(arr[i].school, key) == 0) { return i; }
    }
    return -1;
}

int main(void)
{
    int tc;
    if (scanf("%d", &tc) != 1) { return 0; }

    while (tc-- > 0) {
        int n;
        scanf("%d", &n);

        Team teams[MAX_TEAM];
        for (int i = 0; i < n; ++i) {
            scanf("%31s %31s %d %d",
                  teams[i].name, teams[i].school,
                  &teams[i].solved, &teams[i].penalty);
        }

        qsort(teams, (size_t)n, sizeof(Team), cmp_team);

        /* 학교 정보 테이블 구축 */
        SchoolInfo schools[MAX_TEAM];
        int sc_cnt = 0;
        for (int i = 0; i < n; ++i) {
            int idx = find_school(schools, sc_cnt, teams[i].school);
            if (idx < 0) {
                idx = sc_cnt++;
                strcpy(schools[idx].school, teams[i].school);
                schools[idx].total = schools[idx].selected = 0;
            }
            ++schools[idx].total;
        }

        bool picked[MAX_TEAM] = { false };
        int  picked_cnt = 0;
        char worst_team[MAX_STR] = "";

        auto int ceil_half(int x) { return (x + 1) / 2; } /* C23 로컬 함수 */

        for (int pass = 0; pass < 2 && picked_cnt < (n < MAX_PICK ? n : MAX_PICK); ++pass) {
            for (int i = 0; i < n && picked_cnt < (n < MAX_PICK ? n : MAX_PICK); ++i) {
                if (picked[i]) { continue; }

                int sc_idx = find_school(schools, sc_cnt, teams[i].school);
                int sel = schools[sc_idx].selected;
                if (sel >= ceil_half(schools[sc_idx].total)) { continue; }

                bool ok = true;
                if (pass == 0) { /* 1차 규칙 */
                    int rank = i + 1;
                    if (rank <= 10)      { ok = (sel <= 3); }
                    else if (rank <= 20) { ok = (sel <= 2); }
                    else if (rank <= 30) { ok = (sel <= 1); }
                    else                 { ok = (sel == 0); }
                }
                /* pass == 1 : 2차 충원 → ❶만 유지 */

                if (ok) {
                    picked[i] = true;
                    ++schools[sc_idx].selected;
                    ++picked_cnt;
                    strcpy(worst_team, teams[i].name);
                }
            }
        }
        puts(worst_team);
    }
    return 0;
}
