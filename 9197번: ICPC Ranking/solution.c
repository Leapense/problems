#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TEAMS 50
#define MAX_PROBS 10

typedef struct {
    int solvedCount;
    int penalty;
    bool accepted[MAX_PROBS + 1];
    int wrongCount[MAX_PROBS + 1];
    int teamId;
} Team;

static void initTeam(Team *team, int id, int P) {
    team->solvedCount = 0;
    team->penalty = 0;
    team->teamId = id;

    for (int i = 1; i <= P; ++i) {
        team->accepted[i] = false;
        team->wrongCount[i] = 0;
    }
}

static int compareTeam(const void *a, const void *b) {
    const Team *t1 = (const Team*) a;
    const Team *t2 = (const Team*) b;
    if (t1->solvedCount != t2->solvedCount) {
        return (t2->solvedCount - t1->solvedCount);
    }
    return (t1->penalty - t2->penalty);
}

int main(void)
{
    int M, T, P, R;
    while (scanf("%d %d %d %d", &M, &T, &P, &R) == 4) {
        if (M == 0 && T == 0 && P == 0 && R == 0) {
            break;
        }

        Team teams[MAX_TEAMS];
        for (int i = 0; i < T; ++i)
        {
            initTeam(&teams[i], i + 1, P);
        }

        for (int i = 0; i < R; ++i)
        {
            int m, t, p, j;
            scanf("%d %d %d %d", &m, &t, &p, &j);
            Team *cur = &teams[t - 1];
            if (cur->accepted[p]) {
                continue;
            }
            if (j == 0) {
                cur->accepted[p] = true;
                cur->solvedCount += 1;
                cur->penalty += m + cur->wrongCount[p] * 20;
            } else {
                cur->wrongCount[p] += 1;
            }
        }
        qsort(teams, T, sizeof(Team), compareTeam);

        bool firstGroup = true;
        for (int i = 0; i < T; ) {
            int j = i;
            while (j < T && teams[j].solvedCount == teams[i].solvedCount && teams[j].penalty == teams[i].penalty) {
                ++j;
            }

            for (int x = i; x < j - 1; ++x) {
                for (int y = x + 1; y < j; ++y) {
                    if (teams[x].teamId < teams[y].teamId) 
                    {
                        Team tmp = teams[x];
                        teams[x] = teams[y];
                        teams[y] = tmp;
                    }
                }
            }

            if (!firstGroup) {
                putchar(',');
            }
            firstGroup = false;
            for (int k = i; k < j; ++k) {
                if (k > i) {
                    putchar('=');
                }
                printf("%d", teams[k].teamId);
            }

            i = j;
        }

        putchar('\n');
    }

    return 0;
}