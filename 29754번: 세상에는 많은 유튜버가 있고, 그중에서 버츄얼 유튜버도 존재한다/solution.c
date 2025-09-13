#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAMES 100
#define NAME_LEN 21
#define MAX_WEEKS 52

typedef struct {
    int cnt;
    int64_t mins;
} Week;

typedef struct {
    char name[NAME_LEN];
    Week w[MAX_WEEKS];
    int usedWeeks;
} Person;

static int toMin(const char *hhmm) {
    int h = 0, m = 0;
    sscanf(hhmm, "%d:%d", &h, &m);
    return h * 60 + m;
}

static int find_person(Person *arr, int u, const char *name) {
    for (int i = 0; i < u; i++) {
        if (strcmp(arr[i].name, name) == 0) return i;
    }
    return -1;
}

static int cmp_name(const void *a, const void *b) {
    const Person *pa = (const Person*)a;
    const Person *pb = (const Person*)b;
    return strcmp(pa->name, pb->name);
}

int main(void) {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 0;
    int W = M / 7;

    Person ppl[MAX_NAMES];
    int U = 0;

    for (int i = 0; i < MAX_NAMES; i++) {
        ppl[i].name[0] = '\0';
        ppl[i].usedWeeks = 0;
        for (int w = 0; w < MAX_WEEKS; w++) {
            ppl[i].w[w].cnt = 0;
            ppl[i].w[w].mins = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        char name[NAME_LEN], s[6], e[6];
        int day;
        scanf("%20s %d %5s %5s", name, &day, s, e);
        int idx = find_person(ppl, U, name);
        if (idx < 0) {
            idx = U++;
            strcpy(ppl[idx].name, name);
        }

        int w = (day - 1) / 7;
        int dur = toMin(e) - toMin(s);
        ppl[idx].w[w].cnt += 1;
        ppl[idx].w[w].mins += dur;
        if (ppl[idx].usedWeeks < w + 1) ppl[idx].usedWeeks = w + 1;
    }

    qsort(ppl, U, sizeof(Person), cmp_name);

    int printed = 0;
    for (int i = 0; i < U; i++) {
        bool ok = true;
        if (ppl[i].usedWeeks < W) {

        }
        for (int w = 0; w < W; w++) {
            int cnt = ppl[i].w[w].cnt;
            int64_t mins = ppl[i].w[w].mins;
            if (cnt < 5 || mins < 3600) {
                ok = false;
                break;
            }
        }

        if (ok) {
            printf("%s\n", ppl[i].name);
            printed++;
        }
    }

    if (printed == 0) puts("-1");
    return 0;
}